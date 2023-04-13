#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QPluginLoader>
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
    QApplication a(argc, argv);

    LoadPlugin();
    MainWindow w(echo_module);
    w.show();
    return a.exec();
}
