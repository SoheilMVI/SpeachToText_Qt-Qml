#pragma once

#include <QObject>
#include <QDir>

#include "includes/libs/vosk_api.h"
#include "includes/Downloader.h"
#include "includes/Microphon.h"

class Recognizer : public QObject
{
    Q_OBJECT
public:
    explicit Recognizer(QObject *parent = nullptr);

    void start();
    void verifyModelDir();
    void verifyModel();
    void verifyMicrophone();

    bool isModelExist(QString modelName);


public slots:
    void createRecognizer();
    void speachToText(QByteArray data);

signals:
    void tmpData(QString data);
    void newLog(QString data);
    void newData(QString data);


private:
    VoskModel *model;
    VoskRecognizer *recognizer;

    QDir folder;
    QString modelPath;
    QString modelLanguage;

    int block = 16000;
    QString small_Fa = "vosk-model-small-fa-0.42";
    QString small_En = "vosk-model-small-en-us-0.15";

    Downloader *downloader = new Downloader();
    Microphon *microphon = new Microphon();
};
