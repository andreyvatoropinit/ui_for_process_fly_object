#include "5_model_labels_on_ui.h"

// присвоение имен типа QString всем label
ALL_LABEL_INFORMATION InitAllLabel ()
{
    // вектор label новых целей
    QVector <LEFT_SIDE_NEW_LABEL> vector_left_side_new_label{};

    LEFT_SIDE_NEW_LABEL left_side_new_label{};

    left_side_new_label.label_picture   = "label_24";
    left_side_new_label.label_text_info = "label_15";
    left_side_new_label.label_circle    = "label_13";
    left_side_new_label.label_rhombus   = "label_14";
    left_side_new_label.label_busy = false;
    vector_left_side_new_label.push_back(left_side_new_label);

    left_side_new_label.label_picture   = "label_25";
    left_side_new_label.label_text_info = "label_18";
    left_side_new_label.label_circle    = "label_19";
    left_side_new_label.label_rhombus   = "label_17";
    vector_left_side_new_label.push_back(left_side_new_label);

    left_side_new_label.label_picture   = "label_26";
    left_side_new_label.label_text_info = "label_23";
    left_side_new_label.label_circle    = "label_20";
    left_side_new_label.label_rhombus   = "label_21";
    vector_left_side_new_label.push_back(left_side_new_label);

    left_side_new_label.label_picture   = "label_51";
    left_side_new_label.label_text_info = "label_50";
    left_side_new_label.label_circle    = "label_93";
    left_side_new_label.label_rhombus   = "label_87";
    vector_left_side_new_label.push_back(left_side_new_label);
    
    left_side_new_label.label_picture   = "label_47";
    left_side_new_label.label_text_info = "label_52";
    left_side_new_label.label_circle    = "label_92";
    left_side_new_label.label_rhombus   = "label_59";
    vector_left_side_new_label.push_back(left_side_new_label);
    
    left_side_new_label.label_picture   = "label_48";
    left_side_new_label.label_text_info = "label_46";
    left_side_new_label.label_circle    = "label_64";
    left_side_new_label.label_rhombus   = "label_59";
    vector_left_side_new_label.push_back(left_side_new_label);

    // вектор label подтвержденных целей
    QVector <LEFT_SIDE_ACCEPTED_LABEL>  vector_left_side_accepted_label {};
    LEFT_SIDE_ACCEPTED_LABEL left_side_accepted_label {};
    left_side_accepted_label.label_busy = false;

    left_side_accepted_label.label_picture = "label_31";
    left_side_accepted_label.label_text_info = "label_27";
    left_side_accepted_label.label_circle = "label_34";
    left_side_accepted_label.label_rhombus = "label_28";
    vector_left_side_accepted_label.push_back(left_side_accepted_label);

    left_side_accepted_label.label_picture = "label_29";
    left_side_accepted_label.label_text_info = "label_33";
    left_side_accepted_label.label_circle = "label_32";
    left_side_accepted_label.label_rhombus = "label_35";
    vector_left_side_accepted_label.push_back(left_side_accepted_label);
    
    left_side_accepted_label.label_picture = "label_98";
    left_side_accepted_label.label_text_info = "label_94";
    left_side_accepted_label.label_circle = "label_99";
    left_side_accepted_label.label_rhombus = "label_97";
    vector_left_side_accepted_label.push_back(left_side_accepted_label);

    left_side_accepted_label.label_picture = "label_102";
    left_side_accepted_label.label_text_info = "label_100";
    left_side_accepted_label.label_circle = "label_103";
    left_side_accepted_label.label_rhombus = "label_101";
    vector_left_side_accepted_label.push_back(left_side_accepted_label);
    

    // вектор label отклоненных целей
    QVector <LEFT_SIDE_REFUSED_LABEL> vector_left_side_refused_label{};
    LEFT_SIDE_REFUSED_LABEL left_side_refused_label{};

    left_side_refused_label.label_busy = false;

    left_side_refused_label.label_picture = "label_40";
    left_side_refused_label.label_text_info = "label_36";
    left_side_refused_label.label_circle = "label_43";
    left_side_refused_label.label_rhombus = "label_41";
    vector_left_side_refused_label.push_back(left_side_refused_label);

    left_side_refused_label.label_picture = "label_42";
    left_side_refused_label.label_text_info = "label_39";
    left_side_refused_label.label_circle = "label_38";
    left_side_refused_label.label_rhombus = "label_44";
    vector_left_side_refused_label.push_back(left_side_refused_label);
    
    left_side_refused_label.label_picture = "label_106";
    left_side_refused_label.label_text_info = "label_104";
    left_side_refused_label.label_circle = "label_105";
    left_side_refused_label.label_rhombus = "label_107";
    vector_left_side_refused_label.push_back(left_side_refused_label);

    left_side_refused_label.label_picture = "label_110";
    left_side_refused_label.label_text_info = "label_108";
    left_side_refused_label.label_circle = "label_109";
    left_side_refused_label.label_rhombus = "label_111";
    vector_left_side_refused_label.push_back(left_side_refused_label);

    // переносим всю информацию в переменную
    ALL_LABEL_INFORMATION all_label_information {};
    all_label_information.left_side_new_label = vector_left_side_new_label;
    all_label_information.left_side_accepted_label = vector_left_side_accepted_label;
    all_label_information.left_side_refused_label = vector_left_side_refused_label;

    return all_label_information;
}

int CalculateCountTargetsOnLabels (ALL_LABEL_INFORMATION all_label_inforamtion)
{
    int count_targets_on_labels = 0;
    
    for (int i = 0; i < all_label_inforamtion.left_side_new_label.size(); i++)
    {
        if (all_label_inforamtion.left_side_new_label[i].id != 0)
        {
            count_targets_on_labels++;
        }
    }
    
    for (int i = 0; i < all_label_inforamtion.left_side_accepted_label.size(); i++)
    {
        if (all_label_inforamtion.left_side_accepted_label[i].id != 0)
        {
            count_targets_on_labels++;
        }
    }
    
    for (int i = 0; i < all_label_inforamtion.left_side_refused_label.size(); i++)
    {
        if (all_label_inforamtion.left_side_refused_label[i].id != 0)
        {
            count_targets_on_labels++;
        }
    }
    
    return count_targets_on_labels;
}

int CalculateCountTargetsOnOneFrame (QVector <TARGET> one_frame)
{
    int count_targets_one_frame = 0;
    
    for (auto index : one_frame)
    {
        if (index.target_conditional != target_deleted)
        {
            count_targets_one_frame++;
        }
    }
    
    return count_targets_one_frame;
}

ALL_LABEL_INFORMATION MoveDataFromOneFrameToLabelInformation (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < one_frame.size(); i++)
    {
        for (int j = 0; j < all_label_information.left_side_new_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_new_label[j].id)
            {
                    all_label_information.left_side_new_label[j].id                 = one_frame[i].id;
                    all_label_information.left_side_new_label[j].dist               = one_frame[i].dist;
                    all_label_information.left_side_new_label[j]._class             = one_frame[i]._class;
                    all_label_information.left_side_new_label[j].azimut             = one_frame[i].azimut;
                    all_label_information.left_side_new_label[j].quarter            = one_frame[i].quarter;
                    all_label_information.left_side_new_label[j].ugol_mesta         = one_frame[i].ugol_mesta;
                    all_label_information.left_side_new_label[j].target_conditional = one_frame[i].target_conditional;
                    all_label_information.left_side_new_label[j].CamId              = one_frame[i].CamId;
                    break;
            }
        }
        
        for (int j = 0; j < all_label_information.left_side_accepted_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_accepted_label[j].id)
            {
                    all_label_information.left_side_accepted_label[j].id                 = one_frame[i].id;
                    all_label_information.left_side_accepted_label[j].dist               = one_frame[i].dist;
                    all_label_information.left_side_accepted_label[j]._class             = one_frame[i]._class;
                    all_label_information.left_side_accepted_label[j].azimut             = one_frame[i].azimut;
                    all_label_information.left_side_accepted_label[j].quarter            = one_frame[i].quarter;
                    all_label_information.left_side_accepted_label[j].ugol_mesta         = one_frame[i].ugol_mesta;
                    all_label_information.left_side_accepted_label[j].target_conditional = one_frame[i].target_conditional;
                    all_label_information.left_side_accepted_label[j].CamId              = one_frame[i].CamId;
                    break;
            }
        }
        
        for (int j = 0; j < all_label_information.left_side_refused_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_refused_label[j].id)
            {
                    all_label_information.left_side_refused_label[j].id                 = one_frame[i].id;
                    all_label_information.left_side_refused_label[j].dist               = one_frame[i].dist;
                    all_label_information.left_side_refused_label[j]._class             = one_frame[i]._class;
                    all_label_information.left_side_refused_label[j].azimut             = one_frame[i].azimut;
                    all_label_information.left_side_refused_label[j].quarter            = one_frame[i].quarter;
                    all_label_information.left_side_refused_label[j].ugol_mesta         = one_frame[i].ugol_mesta;
                    all_label_information.left_side_refused_label[j].target_conditional = one_frame[i].target_conditional;
                    all_label_information.left_side_refused_label[j].CamId              = one_frame[i].CamId;
                    break;
            }
        }
    }

    return all_label_information;
}

LEFT_SIDE_NEW_LABEL MoveDataFromOneFrameToNewLabel (LEFT_SIDE_NEW_LABEL new_label, TARGET one_target, QVector <int> deleted_id)
{
    for (int i = 0; i < deleted_id.size(); i++)
    {
        if (one_target.id == deleted_id[i])
        {
            return new_label;
        }
    }
    
    new_label.id                 = one_target.id;
    new_label.dist               = one_target.dist;
    new_label._class             = one_target._class;
    new_label.azimut             = one_target.azimut;
    new_label.quarter            = one_target.quarter;
    new_label.ugol_mesta         = one_target.ugol_mesta;
    new_label.CamId              = one_target.CamId;
    
    new_label.label_busy = true;

    return new_label;
}

LEFT_SIDE_ACCEPTED_LABEL MoveDataFromOneFrameToAcceptedLabel (LEFT_SIDE_ACCEPTED_LABEL accepted_label, TARGET one_target, QVector <int> deleted_id)
{  
 
    accepted_label.id                 = one_target.id;
    accepted_label.dist               = one_target.dist;
    accepted_label._class             = one_target._class;
    accepted_label.azimut             = one_target.azimut;
    accepted_label.quarter            = one_target.quarter;
    accepted_label.ugol_mesta         = one_target.ugol_mesta;
    accepted_label.CamId              = one_target.CamId;
    
    accepted_label.label_busy = true;

    return accepted_label;
}

LEFT_SIDE_REFUSED_LABEL MoveDataFromOneFrameToRefusedLabel (LEFT_SIDE_REFUSED_LABEL refused_label, TARGET one_target, QVector <int> deleted_id)
{
    refused_label.id                 = one_target.id;
    refused_label.dist               = one_target.dist;
    refused_label._class             = one_target._class;
    refused_label.azimut             = one_target.azimut;
    refused_label.quarter            = one_target.quarter;
    refused_label.ugol_mesta         = one_target.ugol_mesta;
    refused_label.CamId              = one_target.CamId;

    refused_label.label_busy = true;

    return refused_label;
}

QVector <int> GetVectorIdWhichExistInFrame (QVector <TARGET> one_frame)
{
    QVector <int> vector_one_frame_id {};
    
    for (int i = 0 ; i < one_frame.size(); i++)
    {
        if (one_frame[i].id != 0)
            vector_one_frame_id.push_back(one_frame[i].id);
    }
    
    return vector_one_frame_id; 
}

QVector <int> GetVectorIdInAlLLabels (ALL_LABEL_INFORMATION all_label_information)
{
    QVector <int> vector_all_labels_id {};
  
    for (int j = 0; j < all_label_information.left_side_new_label.size(); j++)
    {
        if (all_label_information.left_side_new_label[j].id != 0)
            vector_all_labels_id.push_back(all_label_information.left_side_new_label[j].id);
    }
    
    for (int j = 0; j < all_label_information.left_side_accepted_label.size(); j++)
    {
        if (all_label_information.left_side_accepted_label[j].id != 0)
            vector_all_labels_id.push_back(all_label_information.left_side_accepted_label[j].id);
    }
    
    for (int j = 0; j < all_label_information.left_side_refused_label.size(); j++)
    {
        if (all_label_information.left_side_refused_label[j].id != 0)
            vector_all_labels_id.push_back(all_label_information.left_side_refused_label[j].id);
    }
    
    return vector_all_labels_id;
}

LEFT_SIDE_NEW_LABEL ClearNewLabel (LEFT_SIDE_NEW_LABEL new_label)
{
    new_label.id                 = 0;
    new_label.dist               = 0;
    new_label._class             = 0;
    new_label.azimut             = 0;
    new_label.quarter            = 0;
    new_label.ugol_mesta         = 0;
    new_label.label_highlighted  = false;
    new_label.target_conditional = false;
    new_label.CamId              = 0;
    
    new_label.label_busy         = false;   
    new_label.target_deleted     = false;

    return new_label;
}

LEFT_SIDE_ACCEPTED_LABEL ClearAcceptedLabel (LEFT_SIDE_ACCEPTED_LABEL accepted_label)
{
    accepted_label.id                 = 0;
    accepted_label.dist               = 0;
    accepted_label._class             = 0;
    accepted_label.azimut             = 0;
    accepted_label.quarter            = 0;
    accepted_label.ugol_mesta         = 0;
    accepted_label.label_highlighted  = false;
    accepted_label.target_conditional = false;
    accepted_label.CamId              = 0;
    
    accepted_label.label_busy         = false;

    return accepted_label;
}

LEFT_SIDE_REFUSED_LABEL ClearRefusedLabel (LEFT_SIDE_REFUSED_LABEL refused_label)
{
    refused_label.id                 = 0;
    refused_label.dist               = 0;
    refused_label._class             = 0;
    refused_label.azimut             = 0;
    refused_label.quarter            = 0;
    refused_label.ugol_mesta         = 0;
    refused_label.label_highlighted  = false;
    refused_label.target_conditional = false;
    refused_label.CamId              = 0;
    
    refused_label.label_busy              = false;

    return refused_label;
}

ALL_LABEL_INFORMATION DeleteObjectFromLabelsViaID (ALL_LABEL_INFORMATION all_label_information,  QVector <int>  vector_targets_which_dissapear)
{
    for (int i = 0; i < vector_targets_which_dissapear.size(); i++)
    {
        for (int j = 0; j < all_label_information.left_side_new_label.size(); j++)
        {
            if (vector_targets_which_dissapear[i] == all_label_information.left_side_new_label[j].id )
            {
                all_label_information.left_side_new_label[j] = ClearNewLabel (all_label_information.left_side_new_label[j]);
            }
        }
        
        for (int j = 0; j < all_label_information.left_side_accepted_label.size(); j++)
        {
            if (vector_targets_which_dissapear[i] == all_label_information.left_side_accepted_label[j].id )
            {
                all_label_information.left_side_accepted_label[j] = ClearAcceptedLabel (all_label_information.left_side_accepted_label[j]);
            }
        }
        
        for (int j = 0; j < all_label_information.left_side_refused_label.size(); j++)
        {
            if (vector_targets_which_dissapear[i] == all_label_information.left_side_refused_label[j].id )
            {
                all_label_information.left_side_refused_label[j] = ClearRefusedLabel (all_label_information.left_side_refused_label[j]);
            }
        }
    }
       
    return all_label_information;
}

ALL_LABEL_INFORMATION DeleteFromLabelsTargetsWhichNotExist (ALL_LABEL_INFORMATION all_label_information, QVector <TARGET> one_frame)
{
    QVector <int> vector_one_frame_id   = GetVectorIdWhichExistInFrame (one_frame);
    QVector <int> vector_all_labels_id  = GetVectorIdInAlLLabels       (all_label_information);
    
    for (int i = 0; i < vector_one_frame_id.size(); i++)
    {
        for (int j = 0; j < vector_all_labels_id.size(); j++)
        {
            if (vector_one_frame_id[i] ==  vector_all_labels_id[j])
            {
                vector_all_labels_id.erase(vector_all_labels_id.begin() + j);
                j--;
            }
        }
    }
    
    QVector <int> vector_targets_which_dissapear {};
    
    vector_targets_which_dissapear = vector_all_labels_id;
        
    all_label_information = DeleteObjectFromLabelsViaID (all_label_information, vector_targets_which_dissapear);
       
    return all_label_information;
}

ALL_LABEL_INFORMATION AddTargetsToLabelWhichExistOnLabel (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < one_frame.size(); i++)
    {
        for (int j = 0; j < all_label_information.left_side_new_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_new_label[j].id)
            {
                all_label_information.left_side_new_label[j] =  MoveDataFromOneFrameToNewLabel (all_label_information.left_side_new_label[j],
                                                                                                                                one_frame[i],
                                                                                                                                all_label_information.id_deleted_label);
                break;
            }
        }
        
        for (int j = 0; j < all_label_information.left_side_accepted_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_accepted_label[j].id)
            {
                all_label_information.left_side_accepted_label[j] = MoveDataFromOneFrameToAcceptedLabel (all_label_information.left_side_accepted_label[j],
                                                                                                                                              one_frame[i],
                                                                                                                                              all_label_information.id_deleted_label);
                break;
            }
        }
        
        for (int j = 0; j < all_label_information.left_side_refused_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_refused_label[j].id)
            {
                all_label_information.left_side_refused_label[j] = MoveDataFromOneFrameToRefusedLabel (all_label_information.left_side_refused_label[j],
                                                                                                                                           one_frame[i],
                                                                                                                                           all_label_information.id_deleted_label);
                break;
            }
        }
    }
    
    return all_label_information;
}

QVector <TARGET> DeleteTargetFromFrameWhichAlreadyPlacedOnLabel (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information)
{ 
    for (int i = 0; i < one_frame.size();  i++) // delete target from frame which already placed on UI
    {
        for (int j = 0; j < all_label_information.left_side_new_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_new_label[j].id)
            {
                one_frame.erase(one_frame.begin() + i);
                i--;
                break;
            }
        }
    }  
    
    for (int i = 0; i < one_frame.size();  i++) 
    {
        for (int j = 0; j < all_label_information.left_side_accepted_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_accepted_label[j].id)
            {
                one_frame.erase(one_frame.begin() + i);
                i--;
                break;
            }
        }
    }  
    
    for (int i = 0; i < one_frame.size();  i++) 
    {
        for (int j = 0; j < all_label_information.left_side_refused_label.size(); j++)
        {
            if (one_frame[i].id == all_label_information.left_side_refused_label[j].id)
            {
                one_frame.erase(one_frame.begin() + i);
                i--;
                break;
            }
        }
    }  
        
    return one_frame;
}

ALL_LABEL_INFORMATION AddTargetsToLabelWhichNotExistOnLabel (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information)
{   
    one_frame = DeleteTargetFromFrameWhichAlreadyPlacedOnLabel(one_frame, all_label_information);

    for (int i = 0; i < one_frame.size(); i++) 
    {
        for (int j = 0; j < all_label_information.left_side_new_label.size(); j++)
        {
            if (all_label_information.left_side_new_label[j].label_busy == false)
            {  
                all_label_information.left_side_new_label[j] = MoveDataFromOneFrameToNewLabel (all_label_information.left_side_new_label[j], one_frame[i], all_label_information.id_deleted_label);             
                break;                 
            }
        } 
    }
     
    return all_label_information;
}

// функция размещения существующих целей в label
ALL_LABEL_INFORMATION ConnectLabelAndTarget (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information)
{
    int count_targets_on_frame  = CalculateCountTargetsOnOneFrame (one_frame);
    int count_targets_on_labels = CalculateCountTargetsOnLabels (all_label_information);
     
    if (count_targets_on_frame == count_targets_on_labels) 
    {
       all_label_information = MoveDataFromOneFrameToLabelInformation (one_frame, all_label_information);
    }
    
    else if (count_targets_on_frame < count_targets_on_labels) 
    {
       all_label_information = DeleteFromLabelsTargetsWhichNotExist (all_label_information, one_frame);
       all_label_information = AddTargetsToLabelWhichExistOnLabel   (one_frame, all_label_information);
    }
    
    else if (count_targets_on_frame > count_targets_on_labels) 
    {
       all_label_information = AddTargetsToLabelWhichExistOnLabel    (one_frame, all_label_information);
       all_label_information = AddTargetsToLabelWhichNotExistOnLabel (one_frame, all_label_information);
    }

    return all_label_information;
}
