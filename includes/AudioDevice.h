#pragma once

#include <QIODevice>
#include <QList>
#include <QPointF>
#include <QXYSeries>

QT_FORWARD_DECLARE_CLASS(QXYSeries)

class AudioDevice : public QIODevice
{
    Q_OBJECT
public:
    AudioDevice(QXYSeries *series, QObject *parent = nullptr);

    static const int sampleCount = 2000;

protected:
    qint64 readData(char *data, qint64 maxSize) override;
    qint64 writeData(const char *data, qint64 maxSize) override;

private:
    QXYSeries *m_series = nullptr;
    QList<QPointF> m_buffer;
};
