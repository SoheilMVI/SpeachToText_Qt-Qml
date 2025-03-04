#pragma once

#include <QAudioDevice>
#include <QAudioInput>
#include <QAudioSource>
#include <QChartView>
#include <QLineSeries>
#include <QMediaDevices>
#include <QObject>
#include <QValueAxis>
#include <QXYSeries>

QT_FORWARD_DECLARE_CLASS(QAudioDevice)
QT_FORWARD_DECLARE_CLASS(QAudioInput)
QT_FORWARD_DECLARE_CLASS(QAudioSource)
QT_FORWARD_DECLARE_CLASS(QChart)
QT_FORWARD_DECLARE_CLASS(QLineSeries)

class AudioDevice;

class SampleAudioCollector : public QObject
{
    Q_OBJECT
public:
    SampleAudioCollector();
    ~SampleAudioCollector();

    Q_INVOKABLE void setAbstractSeries(QAbstractSeries *series);
    void startCollecting();

private:
    QAudioDevice inputDevice;
    AudioDevice *m_device = nullptr;
    QAudioInput *m_audioInput = nullptr;
    QAudioSource *m_audioSource = nullptr;
    QXYSeries *xySeries = nullptr;
};
