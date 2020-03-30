#include <qdebug.h>
#include "9_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_24->installEventFilter(this);
    ui->label_25->installEventFilter(this);
    ui->label_26->installEventFilter(this);
    ui->label_51->installEventFilter(this);

    ui->label_31->installEventFilter(this);
    ui->label_29->installEventFilter(this);

    ui->label_40->installEventFilter(this);
    ui->label_42->installEventFilter(this);

    ui->label_30->installEventFilter(this);
    ui->label_37->installEventFilter(this);
    ui->label_16->installEventFilter(this);

    ui->label_10->installEventFilter(this);

    video_thread = new VideoThreads;
    qRegisterMetaType<Mat>("Mat");
    connect(video_thread, &VideoThreads::statusUpdated, this, &MainWindow::setLabel);
    video_thread->start();

    connect(this, &MainWindow :: InterfaveFromModelToViewerVideo, video_thread, &VideoThreads :: SlotFromMainThreadToVideoThread);

    // create a QUDP socket
    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, port_for_view_from_sky);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

MainWindow::~MainWindow()
{
    if (!QProcess::startDetached("/bin/sh", QStringList{"close_video_streaming.sh"})) // run emulate video getting from localhost
         qDebug() << "video stream turned off";
    delete ui;
}

