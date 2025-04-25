#pragma once

#include <QDebug>
#include <QObject>
#include <QString>

struct Warnings : public QObject // ⚠️ Alerts the user about potential issues that may cause problems in the future.
{
    static inline QString pathNotExixst = tr("Model path not exist!");
    static inline QString ModelNotExist = tr("Can't find your model!");
    static inline QString AudioFormatNotSupported = tr("Raw audio format not supported by backend, cannot play audio. Replcaing by default format...");
    static inline QString CanNotOpenModelPath = tr("Can not open model path!");
    static inline QString CanNotRemoveDownloadFile = tr("Dwonloaded file didn't remove!");
};

struct Errors : public QObject // ❌ Indicates a serious issue that may cause certain parts of the application to malfunction.
{
    static inline QString OpenSSLNotSupport = tr("OpenSSL is not supported on this platform!");
    static inline QString CantMakeModelPath = tr("The path didn't create!");
    static inline QString CantOpenDownloadedFile = tr("Microz can't open the file!");
    static inline QString CantExtractDownloadedFile = tr("File didn't extract!");
    static inline QString VoskModelNotCreated = tr("Vosk object didn't created!");
};

struct Infos : public QObject // 🔵 Provides general information to the user, usually without requiring any action. Typically displayed in blue.
{
    static inline QString OpenSSLExist = tr("OpenSSL is supported on this platform.");
    static inline QString ModelDwonloading = tr("Let's downloading en-us model...");
    static inline QString ModelPath = tr("Model path is: ");
    static inline QString DownloadEnLnModel = tr("Can't find any model, let's downloading en-us model...");
    static inline QString DefaultDeviceList = tr("Default device list: ");
    static inline QString AudioFormatInfo = tr("New format: ");
    static inline QString DeviceDescription = tr("Device: ");
    static inline QString RecordingFinished = tr("Recording finished.");
    static inline QString RecordingStarted = tr("Started recording - read from IO device");
    static inline QString DownloadFinished = tr("Download finished.");
    static inline QString ExtractFinished = tr("Extract finished.");
};

struct Success : public QObject // ✅ Indicates a successfully completed action, such as saving data or sending a message. Usually shown in green.
{
    static inline QString PermissionGranted = tr("Permission granted");
    static inline QString DownloadeFileRemoved = tr("Downloade file removed.");
};

struct Debugs : public QObject // Used by developers to display internal system information for debugging purposes.
{
};

struct Fatals : public QObject // 🔥 Similar to an Error but more severe, often causing the system to crash.
{
    static inline QString PermissionDenied = tr("Permission denied!");
};

struct Prompts : public QObject // 📝Asks the user to take a specific action, such as confirming or canceling an operation.
{
    static inline QString pathNotExixst = tr("");
};
