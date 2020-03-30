#ifndef UDP_READ_FROM_LAN_H
#define UDP_READ_FROM_LAN_H

#include <QObject>

struct DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW
{
    public:
    uint8_t target_status;
    uint32_t target_global_id; // id 0 it is car. id 1 (one) it is way of looking and all next it is car pozition
    uint32_t target_local_id;
    uint32_t target_source_id;
    uint64_t timestamp;
    uint8_t confidence;
    uint8_t target_type;
    float azimuth;
    float elevation;
    float distance;
    float size_horizontal;
    float size_vertical;
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
};

class FRAMES_TARGET_ANALYZER_VIEW
{
public:
    DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW car_poztion;
    DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW way_of_looking;
    QVector <DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW> objects_in_one_frame;
};

void InterfaceFromLANToController (FRAMES_TARGET_ANALYZER_VIEW);

static const int target_global_way_of_looking = 2;



#endif // TEMP_H
