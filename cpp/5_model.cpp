#include "5_model_labels_on_ui.h"
#include "5_model_targets_on_ui.h"
#include "9_mainwindow.h"

ALL_LABEL_INFORMATION ChangeClassActiveFigure (ALL_LABEL_INFORMATION all_label_information, QString string_combo_chosen)
{
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].label_highlighted == true)
        {
            all_label_information.left_side_new_label[i]._class = string_combo_chosen.toInt();     
            all_label_information.left_side_new_label[i].class_changed = true;                                     
        }
    }  
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_highlighted == true)
        {
            all_label_information.left_side_accepted_label[i]._class = string_combo_chosen.toInt();
            all_label_information.left_side_accepted_label[i].class_changed = true; 
        }
    }
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_highlighted == true)
        {
            all_label_information.left_side_refused_label[i]._class = string_combo_chosen.toInt();
            all_label_information.left_side_refused_label[i].class_changed = true; 
        }
    }
    
    return all_label_information;
}

QVector <TARGET> CopyClassFromLabelToOneFrameViaId (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        for (int j = 0; j < one_frame.size(); j++)
        {
            if (all_label_information.left_side_new_label[i].id == one_frame[j].id)
            {
                one_frame[j]._class = all_label_information.left_side_new_label[i]._class;
            }
        }
    }  
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        for (int j = 0; j < one_frame.size(); j++)
        {
            if (all_label_information.left_side_accepted_label[i].id == one_frame[j].id)
            {
                one_frame[j]._class = all_label_information.left_side_accepted_label[i]._class;
            }
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        for (int j = 0; j < one_frame.size(); j++)
        {
            if (all_label_information.left_side_refused_label[i].id == one_frame[j].id)
            {
                one_frame[j]._class = all_label_information.left_side_refused_label[i]._class;
            }
        }
    }
    
    return one_frame;
}

QVector <TARGET> MoveDataFromComboBoxToOneFrame (QVector <TARGET> one_frame, ALL_LABEL_INFORMATION all_label_information )
{
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].class_changed == true)
        {
            one_frame = CopyClassFromLabelToOneFrameViaId (one_frame, all_label_information);           
        }
    }  
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].class_changed == true)
        {
            one_frame = CopyClassFromLabelToOneFrameViaId (one_frame, all_label_information);  
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].class_changed == true)
        {
            one_frame = CopyClassFromLabelToOneFrameViaId (one_frame, all_label_information);  
        }
    }
    
    return  one_frame;
}

QVector <TARGET> ConvertObjectsFromMavlinkToTargetsView (QVector <DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW> objects_in_one_frame, float azimut_looking_car)
{
    QVector <TARGET> objects {};

    for (int i = 0; i < objects_in_one_frame.size(); i++)
    {
        TARGET  one_object {};

        if (objects_in_one_frame[i].azimuth < azimut_looking_car)
        {
            float difference = azimut_looking_car - objects_in_one_frame[i].azimuth;
            int number_camera = difference / count_degree_in_one_cam;
            one_object.CamId = count_camera - number_camera;
        }
        else
        {
            float difference = objects_in_one_frame[i].azimuth - azimut_looking_car;
            int number_camera = difference / count_degree_in_one_cam;
            one_object.CamId = 0 + number_camera + offset_because_first_camera_have_number_one;
        }

        float offset_on_screen_from_left_side_in_degree = 0;

        offset_on_screen_from_left_side_in_degree = azimut_looking_car - ((one_object.CamId - offset_because_first_camera_have_number_one) * count_degree_in_one_cam);

        one_object.x_ctr = offset_on_screen_from_left_side_in_degree * count_pixels_in_degree;

        one_object.y_ctr = 0; // todo delele this mock
        one_object.w = 100; // todo delele this mock
        one_object.h = 100;
        one_object.dist = objects_in_one_frame[i].distance;
        one_object._class = 1; // todo delele this mock
        one_object.azimut  = objects_in_one_frame[i].azimuth;
        one_object.id = objects_in_one_frame[i].target_global_id;

        one_object.timestamp = 0;

        if (one_object.azimut >= zero_degree && one_object.azimut <= ninety)
            one_object.quarter = first_quarter;
        else if (one_object.azimut > ninety && one_object.azimut <= one_hundred_and_eighty)
            one_object.quarter = four_quarter;
        else if (one_object.azimut > one_hundred_and_eighty && one_object.azimut <= two_hundred_and_seventy)
            one_object.quarter = third_quarter;
        else if (one_object.azimut > two_hundred_and_seventy && one_object.azimut <= three_hundred_sixty)
            one_object.quarter = second_quarter;

        objects.push_back(one_object);
    }

    return  objects;
}

void InterfaceFromControllerToModel (FRAMES_TARGET_ANALYZER_VIEW one_frame_mavlink_view, QString pressed_label_lan_or_conntroller)
{
    static ALL_LABEL_INFORMATION all_label_information {};

    if (one_frame_mavlink_view.objects_in_one_frame.empty() == true) return;

    bool static flag_just_started = true;
    
    if (flag_just_started == true)
    {
        flag_just_started = false;
        all_label_information = InitAllLabel ();
    }
    
    QVector <DATA_FOR_MAVLINK_TARGET_ANALYZER_VIEW> objects_in_one_frame {};
    objects_in_one_frame = one_frame_mavlink_view.objects_in_one_frame;

    QVector <TARGET> one_frame_target_view {};

    one_frame_target_view = ConvertObjectsFromMavlinkToTargetsView (objects_in_one_frame,  one_frame_mavlink_view.way_of_looking.azimuth);

    one_frame_target_view = MoveDataFromComboBoxToOneFrame (one_frame_target_view, all_label_information);
    
    all_label_information = ConnectLabelAndTarget (one_frame_target_view, all_label_information);
    
    if (pressed_label_lan_or_conntroller != "empty")
        all_label_information = HandlePressedLabel (pressed_label_lan_or_conntroller, all_label_information);

    if (pressed_label_lan_or_conntroller == "label_30" || pressed_label_lan_or_conntroller == "label_37" ||  pressed_label_lan_or_conntroller == "label_16")
        all_label_information = HandlePressedButton (pressed_label_lan_or_conntroller, all_label_information);
    
    if (pressed_label_lan_or_conntroller == "Combo_0" || pressed_label_lan_or_conntroller == "Combo_1" || pressed_label_lan_or_conntroller == "Combo_2" || pressed_label_lan_or_conntroller == "Combo_3" || pressed_label_lan_or_conntroller == "Combo_4" )
        all_label_information = ChangeClassActiveFigure (all_label_information, pressed_label_lan_or_conntroller); // изменяем цель в соот ии с выбором оператора

    if (pressed_label_lan_or_conntroller == "label_10")
        all_label_information.name_little_camera_pressed = pressed_label_lan_or_conntroller;

    InterfaceFromModelToViewer (all_label_information);
}


