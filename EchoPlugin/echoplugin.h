#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "echointerface.h"

class EchoPlugin : public QObject, public EchoInterface
{
    Q_OBJECT

public:
     Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.EchoInterface") // FILE "echoplugin.json")
     Q_INTERFACES(EchoInterface)

public:
    EchoPlugin() = default;
     QString Echo(const QString &message) override;
};

#endif // ECHOPLUGIN_H
