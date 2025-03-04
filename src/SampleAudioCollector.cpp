#include "SampleAudioCollector.h"
#include "AudioDevice.h"

#include <QDebug>

SampleAudioCollector::SampleAudioCollector()
{
    inputDevice = QMediaDevices::defaultAudioInput();
}

SampleAudioCollector::~SampleAudioCollector()
{
    m_audioSource->stop();
    m_device->close();
    delete m_audioInput;
    delete m_device;
}

void SampleAudioCollector::setAbstractSeries(QAbstractSeries *series)
{
    if (!series)
        return;

    xySeries = qobject_cast<QXYSeries *>(series);
    if (!xySeries)
        return;
    startCollecting();
}

void SampleAudioCollector::startCollecting()
{
    QAudioFormat formatAudio;
    formatAudio.setSampleRate(8000);
    formatAudio.setChannelCount(1);
    formatAudio.setSampleFormat(QAudioFormat::UInt8);

    m_audioSource = new QAudioSource(inputDevice, formatAudio);
    m_audioSource->setBufferSize(200);

    m_device = new AudioDevice(xySeries, this);
    m_device->open(QIODevice::WriteOnly);

    m_audioSource->start(m_device);
}
