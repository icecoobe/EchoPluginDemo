#ifndef ECHOINTERFACE_H
#define ECHOINTERFACE_H

#include <QtPlugin>
#include <QString>

#define EchoInterface_iid "org.qt-project.Qt.Examples.EchoInterface"

class EchoInterface
{
public:
    virtual ~EchoInterface() = default;
    virtual QString Echo(const QString& msg) = 0;
};


Q_DECLARE_INTERFACE(EchoInterface, EchoInterface_iid)

#endif // ECHOINTERFACE_H
