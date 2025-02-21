#pragma once
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSsl>
#include <QCryptographicHash>
#include <QUrl>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QStandardPaths>

#ifdef Q_OS_ANDROID
    #include <QtCore/private/qandroidextras_p.h>
    #include <QJniObject>
#endif

#include "includes/Uncompressor.h"
#include "includes/Notifs.h"

class Downloader : public QObject {
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    void startDownloading(QString url);

    void requestPermissions(QString permission);
private slots:
    void onReadyRead();
    void onDownloadFinished();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

signals:
    void logger(QString log);
    void downloadFinished();
    void downloadRecivedSize(QString size);

private:
    QString url;
    QString filePath;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile file;
};
