#pragma once

#include <QDir>
#include <QElapsedTimer>
#include <QObject>
#include <QXYSeries>

#include "includes/Downloader.h"
#include "includes/Microphon.h"
#include "includes/libs/vosk_api.h"

class Recognizer : public QObject
{
    Q_OBJECT
public:
    explicit Recognizer(QObject *parent = nullptr);

    Q_INVOKABLE void start();
    void stop();
    void verifyModelDir();
    void verifyModel();
    void verifyMicrophone();

    bool isModelExist(QString modelName);
    void prepareAudioSampleData(QByteArray data);

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
    Microphon *microphon = new Microphon(500);
};
