#include "includes/Recognizer.h"

Recognizer::Recognizer(QObject *parent)
    : QObject{parent}
{
    connect(downloader , &Downloader::downloadFinished , this , &Recognizer::createRecognizer);
    connect(downloader , &Downloader::logger , this , [this](QString data){
        emit newLog(data);
    });
    connect(microphon , &Microphon::newVoiceRecognized , this , &Recognizer::speachToText);

    modelPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/Model/";
}

void Recognizer::start()
{

    verifyModelDir();
    verifyModel();

}

void Recognizer::verifyModelDir()
{
    if(!folder.exists(modelPath)){
        qDebug() << Warnings::ModelNotExist;
        qDebug() << Infos::ModelDwonloading;
        bool fileCreationState = folder.mkpath(modelPath);
        if(fileCreationState){
            qDebug() << Infos::ModelPath << modelPath;
        }else{
            qDebug() << Errors::CantMakeModelPath;
        }
    }
}

void Recognizer::verifyModel()
{
    if(modelLanguage == "")
        modelLanguage = small_En;

    if(!isModelExist(modelLanguage)){
        qDebug() << Infos::DownloadEnLnModel;
        downloader->startDownloading("https://alphacephei.com/vosk/models/" + modelLanguage + ".zip");
    }else
        createRecognizer();
}

void Recognizer::verifyMicrophone()
{
    microphon->init();
}

bool Recognizer::isModelExist(QString modelName)
{
    QDir folder;
    return folder.exists(modelPath + modelName);
}

void Recognizer::createRecognizer()
{
    verifyMicrophone();

    QByteArray byteArray = (modelPath + modelLanguage).toUtf8();
    const char* modelPathC = byteArray.constData();
    model = vosk_model_new(modelPathC);

    block = microphon->blockSize();
    recognizer = vosk_recognizer_new(model, block);
}

void Recognizer::speachToText(QByteArray data)
{
    if(data.size() < block)
        return;

    int final = vosk_recognizer_accept_waveform(recognizer, data.last(block).data(), block);
    if (final) {
        QString result = vosk_recognizer_result(recognizer);
        result = result.split('"')[3];
        emit newData(result);
    } else {
        QString result = vosk_recognizer_partial_result(recognizer);
        result = result.split('"')[3];
        if(result != "")
            emit tmpData(result);
    }
}
