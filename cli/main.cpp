#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>

#include "echointerface.h"

EchoInterface* echo_module;

bool LoadPlugin()
{
    QDir pluginsDir(qApp->applicationDirPath());
    qDebug() << qApp->applicationDirPath() << endl;
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
    {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif

    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();

        qDebug() << __FUNCTION__ << fileName << pluginLoader.errorString() << pluginLoader.isLoaded() << endl;
        if (plugin) {
            QString pluginName = plugin->metaObject()->className();
            qInfo() << "Plugin name: " << pluginName << endl;
            echo_module = qobject_cast<EchoInterface *>(plugin);
            if (echo_module)
                return true;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LoadPlugin();
    if (echo_module)
        qDebug() << echo_module->Echo("sssss") << endl;

    return a.exec();
}
