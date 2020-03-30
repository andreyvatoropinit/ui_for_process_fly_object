#ifndef _VIEWER_GET_HNDL_SHOW_VIDEO_H
#define _VIEWER_GET_HNDL_SHOW_VIDEO_H

#include "qthread.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

class VideoThreads : public QThread
{
    Q_OBJECT

    public:
    QString little_camera_for_video_stream;

    void run();

    public slots:
    void SlotFromMainThreadToVideoThread (QString);

    signals:
    void statusUpdated(Mat);
};

struct INFO_ABOUT_OBJECT_ON_VIDEO_IN_ONE_FRAME
{
public:
    int x_ctr;
    int y_ctr;
    int w;
    int h;
    long long int number_frame;
};


#endif // _VIEWER_GET_HNDL_SHOW_VIDEO_H
