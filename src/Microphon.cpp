#include "includes/Microphon.h"

Microphon::Microphon() {
    printDevices();
}

void Microphon::init()
{
    verifyFormat();
    createBuffer();

    audio = new QAudioSource(deviceInfo, format, this);
    audio->start(buffer);
    createConnections();
}

void Microphon::verifyFormat()
{
    deviceInfo = QAudioDevice(QMediaDevices::defaultAudioInput());
    qDebug() << Infos::DefaultDeviceList << deviceInfo.description();
    if (!deviceInfo.isFormatSupported(format)) {
        qDebug() << Warnings::AudioFormatNotSupported;

        format = deviceInfo.preferredFormat();
        format.setSampleFormat(QAudioFormat::Int16);
        format.setChannelCount(1);
    }
    qDebug() << Infos::AudioFormatInfo << format;
}

void Microphon::createConnections()
{
    connect(audio, &QAudioSource::stateChanged, this, &Microphon::stateChecker);
    connect(&timer, &QTimer::timeout, this, &Microphon::timerTrigerd);
}

void Microphon::createBuffer()
{
    buffer = new QBuffer(&audioData, this);
    buffer->open(QIODevice::ReadWrite);

    timer.start(500);
}

void Microphon::stop()
{
    audio->stop();
}

void Microphon::printDevices()
{
    const QList<QAudioDevice> devices = QMediaDevices::audioInputs();
    for (const QAudioDevice &device : devices)
        qDebug() << Infos::DeviceDescription << device.description();
}

int Microphon::blockSize()
{
    return format.sampleRate();
}

void Microphon::stateChecker(QAudio::State state)
{
    switch (state) {
    case QAudio::StoppedState:
        if (audio->error() != QAudio::NoError) {
            // Error handling
        } else {
            qDebug() << Infos::RecordingFinished;
        }
        break;

    case QAudio::ActiveState:
        qDebug() << Infos::RecordingStarted;
        break;

    default:
        // ... other cases as appropriate
        break;
    }
}

void Microphon::timerTrigerd()
{
    emit newVoiceRecognized(audioData);
}
