#include "mavlink.h"
#include "target_analyzer.h"
#include <9_mainwindow.h>
#include <1_udp_read_from_lan.h>

FRAMES_TARGET_ANALYZER_VIEW LocalStorageOfTargetsMavlinkView (mavlink_analyzer_target_data_t, QString);

bool CheckIdDetected (FRAMES_TARGET_ANALYZER_VIEW one_frame)
{
    for (auto index : one_frame.objects_in_one_frame)
    {
        if (index.target_global_id == 0)
            return false;
    }
    return  true;
}

void MainWindow::readyRead()
{
    QByteArray buffer{};
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    mavlink_message_t message {};
    mavlink_status_t status {};

    for (int pos = 0; pos < buffer.length(); ++pos)
    {
       if (!mavlink_parse_char(0, (uint8_t)buffer[pos], &message, &status))
           continue;
    }

    mavlink_analyzer_target_data_t analyzer_target_data {};

    mavlink_msg_analyzer_target_data_decode(&message, &analyzer_target_data);

    qDebug() << analyzer_target_data.target_global_id;

    LocalStorageOfTargetsMavlinkView (analyzer_target_data, "put_message" );

    if (analyzer_target_data.target_global_id == 0)
         LocalStorageOfTargetsMavlinkView (analyzer_target_data, "error_message" );

    qDebug () << "analyzer_target_data.target_global_id"  << analyzer_target_data.target_global_id;

    if (analyzer_target_data.target_global_id == UINT32_MAX)
    {
        FRAMES_TARGET_ANALYZER_VIEW one_frame_mavlink_view{};

        mavlink_analyzer_target_data_t empty{};
        one_frame_mavlink_view = LocalStorageOfTargetsMavlinkView (empty, "get_message_from_lan");

        InterfaceFromLANToController (one_frame_mavlink_view);
    }
}

FRAMES_TARGET_ANALYZER_VIEW ClearStorage (FRAMES_TARGET_ANALYZER_VIEW information_about_frame)
{
    information_about_frame.objects_in_one_frame.clear();
    memset (&information_about_frame.car_poztion,   0, sizeof (DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW));
    memset (&information_about_frame.way_of_looking,0, sizeof (DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW));
    return information_about_frame;
}

FRAMES_TARGET_ANALYZER_VIEW LocalStorageOfTargetsMavlinkView (mavlink_analyzer_target_data_t one_object_in_target_analyzer_view, QString input_string)
{
    FRAMES_TARGET_ANALYZER_VIEW static static_information_about_frame {}; static float azimut_looking_car = 0; static bool way_of_looking_exist = false;

    if (input_string == "error_message")
    {
        static_information_about_frame = ClearStorage (static_information_about_frame);
        azimut_looking_car = 0; way_of_looking_exist = false;
        return static_information_about_frame;
    }

    if (input_string == "put_message")
    {
        if (one_object_in_target_analyzer_view.target_global_id == target_global_way_of_looking)
        {
            way_of_looking_exist = true;
            static_information_about_frame.way_of_looking.x                = one_object_in_target_analyzer_view.x;
            static_information_about_frame.way_of_looking.y                = one_object_in_target_analyzer_view.y;
            static_information_about_frame.way_of_looking.target_global_id = one_object_in_target_analyzer_view.target_global_id;
            static_information_about_frame.way_of_looking.azimuth          = one_object_in_target_analyzer_view.azimuth;
            static_information_about_frame.way_of_looking.distance         = one_object_in_target_analyzer_view.distance;
        }
        else if (one_object_in_target_analyzer_view.target_global_id > target_global_way_of_looking && one_object_in_target_analyzer_view.target_global_id != UINT32_MAX)
        {
            if (way_of_looking_exist == true)
            {
                DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW one_object {};
                one_object.x                 = one_object_in_target_analyzer_view.x;
                one_object.y                 = one_object_in_target_analyzer_view.y;
                one_object.target_global_id  = one_object_in_target_analyzer_view.target_global_id;
                one_object.azimuth           = one_object_in_target_analyzer_view.azimuth;
                one_object.distance          = one_object_in_target_analyzer_view.distance;
                static_information_about_frame.objects_in_one_frame.push_back(one_object);
            }
        }
        else if (one_object_in_target_analyzer_view.target_global_id == UINT32_MAX)
        {
            DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW flag_that_object_in_one_frame_expired {};
            flag_that_object_in_one_frame_expired.target_global_id  = one_object_in_target_analyzer_view.target_global_id;
            static_information_about_frame.objects_in_one_frame.push_back(flag_that_object_in_one_frame_expired);
        }
    }
    else if (input_string == "get_message_from_lan")
    {
            FRAMES_TARGET_ANALYZER_VIEW one_frame {}; one_frame = static_information_about_frame;
            static_information_about_frame = ClearStorage (static_information_about_frame);
            one_frame.objects_in_one_frame.pop_back();
            azimut_looking_car = 0; way_of_looking_exist = false;
            return one_frame;
    }
    return static_information_about_frame;
}



