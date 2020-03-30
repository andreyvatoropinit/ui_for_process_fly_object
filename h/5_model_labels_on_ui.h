#ifndef _MODEL_WORK_WITH_LABELS_H
#define _MODEL_WORK_WITH_LABELS_H

#include <QVector>
#include <QString>
#include "5_model.h"

class LEFT_SIDE_NEW_LABEL
{
    public:
    QString label_picture;
    QString label_text_info;
    QString label_circle;
    QString label_rhombus;

    bool label_busy;
    bool label_highlighted;
    int id;
    
    int dist; 
    int _class; 
    float azimut;
    int quarter;
    float ugol_mesta;
    
    int target_conditional;
    
    int CamId;
    
    bool target_deleted;
    bool class_changed;
};

class LEFT_SIDE_ACCEPTED_LABEL
{
    public:
    QString label_picture;
    QString label_text_info;
    QString label_circle;
    QString label_rhombus;

    bool label_busy;
    bool label_highlighted;
    uint32_t id;
    
    int dist; 
    int _class; 
    float azimut;
    int quarter;
    float ugol_mesta;
    
    int target_conditional;
    
    int CamId;
    
    bool target_deleted;
    bool class_changed;
};

class LEFT_SIDE_REFUSED_LABEL
{
    public:
    QString label_picture;
    QString label_text_info;
    QString label_circle;
    QString label_rhombus;

    bool label_busy;
    bool label_highlighted;
    int id;
    
    int dist; 
    int _class; 
    float azimut;
    int quarter;
    float ugol_mesta;
    
    int target_conditional;
    
    int CamId;
    
    bool target_deleted;
    bool class_changed;
};



class ALL_LABEL_INFORMATION
{
    public:
    QVector <LEFT_SIDE_NEW_LABEL>      left_side_new_label;
    QVector <LEFT_SIDE_ACCEPTED_LABEL> left_side_accepted_label;
    QVector <LEFT_SIDE_REFUSED_LABEL>  left_side_refused_label;
    QVector <int>  id_deleted_label;
    QString name_little_camera_pressed;
};

void InterfaceFromModelToViewer (ALL_LABEL_INFORMATION);

ALL_LABEL_INFORMATION InitAllLabel ();

ALL_LABEL_INFORMATION ConnectLabelAndTarget (QVector <TARGET>, ALL_LABEL_INFORMATION);

LEFT_SIDE_NEW_LABEL ClearNewLabel (LEFT_SIDE_NEW_LABEL new_label);

LEFT_SIDE_ACCEPTED_LABEL ClearAcceptedLabel (LEFT_SIDE_ACCEPTED_LABEL);

LEFT_SIDE_REFUSED_LABEL ClearRefusedLabel (LEFT_SIDE_REFUSED_LABEL);

#endif // _MODEL_WORK_WITH_LABELS_H
