#ifndef MODEL_H
#define MODEL_H

#include "1_udp_read_from_lan.h"

enum TARGET_CONDITIONAL
{
    target_new,
    target_deleted,
    target_accepted
};

class TARGET
{
    public:
    float x_ctr; float y_ctr;  float w; float h; int dist; int _class; int CamId; double timestamp;
    float azimut;
    int quarter;
    float ugol_mesta;
    uint32_t id;
    int target_conditional;
};

static const int count_degree_in_one_cam = 10;
static const int count_camera = 36;

static const int offset_because_first_camera_have_number_one = 1;

static const int count_pixels_in_degree = 160;

static const float zero_degree = 0;
static const float ninety = 90;
static const float one_hundred_and_eighty = 180;
static const float two_hundred_and_seventy = 270;
static const float three_hundred_sixty = 360;


static const int first_quarter = 1;
static const int second_quarter = 2;
static const int third_quarter = 3;
static const int four_quarter = 4;

#endif // MODEL_H
