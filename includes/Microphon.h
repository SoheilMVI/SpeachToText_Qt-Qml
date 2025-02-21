#pragma once

#include <QTimer>
#include <QObject>
#include <QBuffer>
#include <QByteArray>
#include <QSslSocket>
#include <QAudioInput>
#include <QAudioFormat>
#include <QMediaDevices>
#include <QAudioSource>

#include "includes/Notifs.h"

class Microphon : public QObject
{
    Q_OBJECT
public:
    Microphon();
    void init();

    void verifyFormat();
    void createConnections();
    void createBuffer();
    void stop();
    void printDevices();
    int blockSize();


public slots:
    void stateChecker(QAudio::State state);
    void timerTrigerd();

signals:
    void tmpData(QString data);
    void newVoiceRecognized(QByteArray data);

private:
    QAudioFormat format;
    QAudioDevice deviceInfo;
    QAudioSource* audio;
    QBuffer *buffer;
    QByteArray audioData;
    QTimer timer;

};
