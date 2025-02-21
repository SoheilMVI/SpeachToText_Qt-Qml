#pragma once

#include <QObject>
#include <includes/libs/qmicroz.h>

#include "includes/Notifs.h"

class Uncompressor : public QObject
{
    Q_OBJECT
public:
    explicit Uncompressor(QObject *parent = nullptr);

    bool uncompresse(QString filePath);

signals:
};

