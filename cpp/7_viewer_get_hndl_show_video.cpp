#include "ui_mainwindow.h"
#include "9_mainwindow.h"

#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "7_viewer_get_hndl_show_video.h"

QVector <INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME> ConvertDataFromJsonToTargets (QJsonValue jsonValue, QString name_frame)
{
    QVector<INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME> targets{};

    auto one_timestamp  = jsonValue;
    auto timestamp = one_timestamp["timestamp"];

    auto array_objects_in_one_timestamp = one_timestamp["objects"].toArray();

    for (int j = 0; j < array_objects_in_one_timestamp.size(); j++)
    {
        INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME target {};

        QJsonValue one_object = array_objects_in_one_timestamp[j];

        target.h            = one_object["h"]      .toDouble();
        target.w            = one_object["w"]      .toDouble();
        target.x_ctr        = one_object["x_ctr"]  .toDouble();
        target.y_ctr        = one_object["y_ctr"]  .toDouble();

        int left_part_string = 1;

        target.number_frame = name_frame.split("_")[left_part_string].toInt();

        targets.push_back(target);
    }

    return targets;
}

QString GetNameFrame ( )
{
    int static end_name = 0;

    QString number_in_string = QString::number(end_name);

    end_name++;

    QString name = "Frame_" + number_in_string;

    return name;
}

QVector <QVector <INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME>> GetDataAboutFrames ()
{
    QString filename="detections.txt";

    QFile file(filename);

    file.open(QIODevice::ReadOnly);

    QByteArray data = file.readAll();

    QString data_from_json_string = QString::fromStdString(data.toStdString());

    QJsonDocument json_document = QJsonDocument::fromJson(data_from_json_string.toUtf8());

    QJsonObject set_obj = json_document.object();

    QVector <QVector <INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME>> vector_of_frames;

    for (int i = 0; i < set_obj.size(); i++)
    {
        QVector <INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME> local_one_frame_with_objects {};

        QString name_frame = GetNameFrame ();

        QJsonValue jsonValue = set_obj.value(name_frame);

        local_one_frame_with_objects = ConvertDataFromJsonToTargets (jsonValue,name_frame);

        vector_of_frames.push_back(local_one_frame_with_objects);
    }

    return vector_of_frames;
}

void VideoThreads :: SlotFromMainThreadToVideoThread (QString number_little_pressed_camera)
{

    little_camera_for_video_stream = number_little_pressed_camera;
}

void VideoThreads::run()
{
    Mat frame {};

    VideoCapture capture ("rtp://@225.1.1.1:5006");

  //  VideoCapture capture ("rtp://@224.1.1.1:5004"); //224.1.1.1:5004

    if(!capture.isOpened())
        qDebug() << "Error, video not loaded";

    while(true)
    {
        if (little_camera_for_video_stream != "label_10")
        {
            continue;
        }

        bool success = capture.read(frame);

        if(success == false)
        {
            qDebug() << "error in video stream";
            continue;
        }
        else
        {
            int static counter = 0; counter++;

            if (counter == 100)
            {
                counter = 0;
                qDebug() << "video_streaming";
            }

            emit statusUpdated(frame);
        }
    }
}


void MainWindow :: setLabel(Mat frame)
{
    static QVector <QVector <INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME>> vector_of_frames = GetDataAboutFrames ();

    static int vector_index = 0;

    if (vector_index == vector_of_frames.size())
    {
        qDebug() << "exit(EXIT_FAILURE);";
        exit(EXIT_FAILURE);
    }

    QVector <INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME> current_frame = vector_of_frames[vector_index];

    for (int i = 0; i < current_frame.size(); i++) // todo in separate function
    {
        Point center {}; // это точка на картинке. она соот ет входному потоку. т.е. 0 0 это верхний левый угол. 1600 1200 это правый нижний угол.

        float x = current_frame[i].x_ctr;
        float y = current_frame[i].y_ctr;

        center.x = x;
        center.y = y;

        int radius = 0;

        if (current_frame[i].h > current_frame[i].w) radius = current_frame[i].h;
        else radius = current_frame[i].w;

        cv :: circle  ( frame, center, radius, {255,255,255}, 2, LINE_8, false);

        std :: string id = std::to_string(i);

        cv :: putText ( frame,  "id "+id , center, FONT_HERSHEY_COMPLEX_SMALL, 1,{255,255,255}, 2, LINE_8, false);

        cv :: Mat temp(frame.cols,frame.rows,frame.type());
    }

    cvtColor(frame, frame, cv::COLOR_RGB2BGR);

    QImage image= QImage((uchar*) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    QPixmap pixmap{};  pixmap = QPixmap::fromImage(image);

    int w = ui->label_112->width();     int h = ui->label_112->height();

    ui->label_112->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));

    vector_index++;
}
