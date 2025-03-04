#pragma once

#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioSource>
#include <QBuffer>
#include <QByteArray>
#include <QMediaDevices>
#include <QObject>
#include <QSslSocket>
#include <QTimer>

#include "includes/Notifs.h"

class Microphon : public QObject
{
    Q_OBJECT
public:
    Microphon(qint32 timerInterval = 500);
    void init(bool useCustomFormat = false);
    void init(QAudioFormat inputFormat);

    void startAudio();
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
    QAudioSource *audio;
    QBuffer *buffer;
    QByteArray audioData;
    QTimer timer;

    qint32 interval;
};
