#include "includes/Downloader.h"

Downloader::Downloader(QObject *parent)
    : QObject(parent) {

    if(!QSslSocket::supportsSsl()){
        qDebug() << Errors::OpenSSLNotSupport;
    }else{
        qDebug() << Infos::OpenSSLExist;
    }

#ifdef Q_OS_ANDROID
    requestPermissions("android.permission.WRITE_EXTERNAL_STORAGE");
    requestPermissions("android.permission.READ_EXTERNAL_STORAGE");
#endif

}

void Downloader::startDownloading(QString url)
{
    this->url = url;

    filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/Model/" + url.split('/').last();
    qDebug() << filePath;
    file.setFileName(filePath);
    if(!file.open(QIODeviceBase::ReadWrite)){
        qDebug() << Warnings::CanNotOpenModelPath;
    }

    manager = new QNetworkAccessManager(this);

    QUrl urlLink(url);
    QNetworkRequest request(urlLink);

    reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, &Downloader::onDownloadFinished);
    connect(reply, &QNetworkReply::downloadProgress, this, &Downloader::downloadProgress);
    connect(reply, &QNetworkReply::readyRead, this, &Downloader::onReadyRead);
}

void Downloader::requestPermissions(QString permission)
{
    #ifdef Q_OS_ANDROID
        auto r = QtAndroidPrivate::checkPermission(permission).result();
        if (r == QtAndroidPrivate::Denied) {
            r = QtAndroidPrivate::requestPermission(permission).result();
            if (r == QtAndroidPrivate::Denied) {
                qDebug() << Fatals::PermissionDenied;
                emit logger(Fatals::PermissionDenied);
                return;
            }
        }

        qDebug() << Success::PermissionGranted;
        emit logger(Success::PermissionGranted);
    #endif
}

void Downloader::onReadyRead()
{
    if (file.isOpen()) {
        QByteArray newData = reply->readAll();
        file.write(newData);
    }
}

void Downloader::onDownloadFinished()
{
    file.close();
    // reply->deleteLater();
    qDebug() << Infos::DownloadFinished;

    Uncompressor uncompressor;
    if(uncompressor.uncompresse(filePath)){
        qDebug() << Infos::ExtractFinished;
        emit downloadFinished();
    }else{
        qDebug() << Errors::CantOpenDownloadedFile;
    }

    //To-Do
    if(QFile::remove(filePath))
        qDebug() << Success::DownloadeFileRemoved;
    else
        qDebug() << Warnings::CanNotRemoveDownloadFile;

}

void Downloader::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    QString size;
    if(bytesReceived < pow(1024 , 2))
        size = "Downloaded: " + QString::number(bytesReceived / pow(1024 , 1)) + " KB";
    else if(bytesReceived < pow(1024 , 3))
        size = "Downloaded: " + QString::number(bytesReceived / pow(1024 , 2)) + " MB";
    else if(bytesReceived < pow(1024 , 4))
        size = "Downloaded: " + QString::number(bytesReceived / pow(1024 , 3)) + " GB";

    qDebug() << size;
    emit logger(size);
}

