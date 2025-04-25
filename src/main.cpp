#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "includes/Recognizer.h"
#include "includes/SampleAudioCollector.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qDebug() << "STEP 1";
    QQmlApplicationEngine engine;

    qmlRegisterType<Recognizer>("Recognizer", 1, 0, "Recognizer");
    qmlRegisterType<SampleAudioCollector>("SampleAudioCollector", 1, 0, "SampleAudioCollector");

    const QUrl url(QStringLiteral("qrc:/Components/main.qml"));

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl)
        {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
