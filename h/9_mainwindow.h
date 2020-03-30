#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <qudpsocket.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

#include "ui_mainwindow.h"

#include "7_viewer_get_hndl_show_video.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString hostAddress = "127.0.0.1";
    qint16 port_for_view_from_sky = 14551;

    public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject * obj, QEvent *event);
    Ui::MainWindow *ui;
    VideoThreads* video_thread ;

    private slots:
    void on_comboBox_activated(const QString &arg1);
    void setLabel(Mat);
    void readyRead();

    signals:
    void InterfaveFromModelToViewerVideo (QString);

    private:
    QUdpSocket *socket;
};


#endif // MAINWINDOW_H



