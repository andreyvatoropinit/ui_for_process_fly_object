#include "9_mainwindow.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    if (!QProcess::startDetached("/bin/sh", QStringList{"../copy.sh"})) // run emulate video getting from localhost
           qDebug() << "copy";

    QThread::msleep (250);

    if (!QProcess::startDetached("/bin/sh", QStringList{"launch_video.sh"})) // run emulate video getting from localhost
         qDebug() << "video stream enable";

    return a.exec();
}

