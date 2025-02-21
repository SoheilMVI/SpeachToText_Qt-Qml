#include "includes/Uncompressor.h"

Uncompressor::Uncompressor(QObject *parent)
    : QObject{parent}
{}

bool Uncompressor::uncompresse(QString filePath)
{
    QMicroz microz(filePath);
    if(!microz){
        qDebug() << Errors::CantOpenDownloadedFile << filePath;
        return false;
    }
    if(microz.extractAll()){
        qDebug() << Infos::ExtractFinished;
    }else{
        qDebug() << Errors::CantOpenDownloadedFile;
        return false;
    }

    return true;
}
