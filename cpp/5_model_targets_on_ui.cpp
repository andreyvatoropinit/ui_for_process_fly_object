#include "5_model_labels_on_ui.h"

ALL_LABEL_INFORMATION ClearAllCells (ALL_LABEL_INFORMATION all_label_information, QString pressed_label) 
{
    if (pressed_label == "clear_all")
    {
        for (int i = 0; i < all_label_information.left_side_new_label.size();i++)
             all_label_information.left_side_new_label[i].label_highlighted = false;
    
        for (int i = 0; i < all_label_information.left_side_accepted_label.size();i++)
            all_label_information.left_side_new_label[i].label_highlighted = false;
     
        for (int i = 0; i < all_label_information.left_side_refused_label.size();i++)
            all_label_information.left_side_refused_label[i].label_highlighted = false;
    }
    else if ( pressed_label == "label_24" || pressed_label == "label_25" || pressed_label == "label_26"  || pressed_label == "label_51" || pressed_label == "label_47"  ||
              pressed_label == "label_48" || pressed_label == "label_31" || pressed_label == "label_29"  || pressed_label == "label_98" || pressed_label == "label_102" ||
              pressed_label == "label_42" || pressed_label == "label_40" || pressed_label == "label_106" || pressed_label == "label_110") 
    {
        for (int i = 0; i < all_label_information.left_side_new_label.size();i++)
        {
            if (all_label_information.left_side_new_label[i].label_picture != pressed_label)
                all_label_information.left_side_new_label[i].label_highlighted = false;
        }
        
        for (int i = 0; i < all_label_information.left_side_accepted_label.size();i++)
        {
            if (all_label_information.left_side_accepted_label[i].label_picture != pressed_label)
                all_label_information.left_side_accepted_label[i].label_highlighted = false;
        }
        
        for (int i = 0; i < all_label_information.left_side_refused_label.size();i++)
        {
            if (all_label_information.left_side_refused_label[i].label_picture != pressed_label)
                all_label_information.left_side_refused_label[i].label_highlighted = false;
        }
    }
    else if (pressed_label == "label_30" || pressed_label == "label_37" || pressed_label == "label_16")
    {
    
    }

    return all_label_information;
}

// функция обработчик действий пользователя
ALL_LABEL_INFORMATION HandlePressedLabel (QString pressed_label, ALL_LABEL_INFORMATION all_label_information)
{
    if (pressed_label == "label_24" || pressed_label == "label_25" || pressed_label == "label_26" || pressed_label == "label_51" || pressed_label == "label_47" || pressed_label == "label_48") // new targets
    {
        for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
        {
            if ( all_label_information.left_side_new_label[i].label_picture == pressed_label && all_label_information.left_side_new_label[i].label_busy == true )
            {
                if (all_label_information.left_side_new_label[i].label_highlighted == true)
                    all_label_information.left_side_new_label[i].label_highlighted = false;
                else
                    all_label_information.left_side_new_label[i].label_highlighted = true;
                break;
            }
        }    
    }
    if (pressed_label == "label_31" || pressed_label == "label_29"  || pressed_label == "label_98"  || pressed_label == "label_102") // accepted label
    {
        for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
        {
            if ( all_label_information.left_side_accepted_label[i].label_picture == pressed_label && all_label_information.left_side_accepted_label[i].label_busy == true)
            {
                if (all_label_information.left_side_accepted_label[i].label_highlighted == true)
                    all_label_information.left_side_accepted_label[i].label_highlighted = false;
                else
                    all_label_information.left_side_accepted_label[i].label_highlighted = true;
                break;
            }
        } 
    }
    if (pressed_label == "label_42" || pressed_label == "label_40" || pressed_label == "label_106" || pressed_label == "label_110") // refused label
    {
        for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
        {
            if ( all_label_information.left_side_refused_label[i].label_picture == pressed_label && all_label_information.left_side_refused_label[i].label_busy == true )
            {
                if (all_label_information.left_side_refused_label[i].label_highlighted == true)
                    all_label_information.left_side_refused_label[i].label_highlighted = false;
                else
                    all_label_information.left_side_refused_label[i].label_highlighted = true;
                break;
            }
        }
    } 
    
    all_label_information = ClearAllCells (all_label_information, pressed_label);  // clear all labels execept active label
   
    return all_label_information;
}

ALL_LABEL_INFORMATION MoveTargetFromNewToAcceptedTargets (LEFT_SIDE_NEW_LABEL left_side_new_label, ALL_LABEL_INFORMATION all_label_information)
{   
    int id_for_delete_in_new_labels = 0;
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_busy == false)
        {
            all_label_information.left_side_accepted_label[i].label_busy = true;
            all_label_information.left_side_accepted_label[i].id         = left_side_new_label.id;
            all_label_information.left_side_accepted_label[i].dist       = left_side_new_label.dist;
            all_label_information.left_side_accepted_label[i]._class     = left_side_new_label._class;
            all_label_information.left_side_accepted_label[i].azimut     = left_side_new_label.azimut;
            all_label_information.left_side_accepted_label[i].ugol_mesta = left_side_new_label.ugol_mesta;
            all_label_information.left_side_accepted_label[i].CamId      = left_side_new_label.CamId;
            
            id_for_delete_in_new_labels = left_side_new_label.id;
            
            break;
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].id == id_for_delete_in_new_labels)
        {
            all_label_information.left_side_new_label[i].label_busy = false;
            all_label_information.left_side_new_label[i].id         = 0;
            all_label_information.left_side_new_label[i].dist       = 0;
            all_label_information.left_side_new_label[i]._class     = 0;
            all_label_information.left_side_new_label[i].azimut     = 0;
            all_label_information.left_side_new_label[i].ugol_mesta = 0;
            all_label_information.left_side_new_label[i].CamId      = 0;
            all_label_information.left_side_new_label[i].quarter    = 0;
            
            break;
        }
    }
     
    all_label_information = ClearAllCells (all_label_information, "clear_all");

    return all_label_information;
}

ALL_LABEL_INFORMATION MoveTargetFromRefusedToAcceptedTargets (LEFT_SIDE_REFUSED_LABEL left_side_refused_label, ALL_LABEL_INFORMATION all_label_information)
{   
    int id_for_delete_in_refused_labels= 0;
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_busy == false)
        {
            all_label_information.left_side_accepted_label[i].label_busy = true;
            all_label_information.left_side_accepted_label[i].id         = left_side_refused_label.id;
            all_label_information.left_side_accepted_label[i].dist       = left_side_refused_label.dist;
            all_label_information.left_side_accepted_label[i]._class     = left_side_refused_label._class;
            all_label_information.left_side_accepted_label[i].azimut     = left_side_refused_label.azimut;
            all_label_information.left_side_accepted_label[i].ugol_mesta = left_side_refused_label.ugol_mesta;
            all_label_information.left_side_accepted_label[i].CamId      = left_side_refused_label.CamId;
            
            id_for_delete_in_refused_labels = left_side_refused_label.id;
            
            break;
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].id == id_for_delete_in_refused_labels)
        {
            all_label_information.left_side_refused_label[i].label_busy = false;
            all_label_information.left_side_refused_label[i].id         = 0;
            all_label_information.left_side_refused_label[i].dist       = 0;
            all_label_information.left_side_refused_label[i]._class     = 0;
            all_label_information.left_side_refused_label[i].azimut     = 0;
            all_label_information.left_side_refused_label[i].ugol_mesta = 0;
            all_label_information.left_side_refused_label[i].CamId      = 0;
            all_label_information.left_side_refused_label[i].quarter    = 0;
            
            break;
        }
    }
    
    all_label_information = ClearAllCells (all_label_information, "clear_all");

    return all_label_information;
}

ALL_LABEL_INFORMATION MoveTargetFromNewToRefusedTargets (LEFT_SIDE_NEW_LABEL left_side_new_label, ALL_LABEL_INFORMATION all_label_information)
{   
    int id_for_delete_in_new_labels = 0;
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_busy == false)
        {
            all_label_information.left_side_refused_label[i].label_busy = true;
            all_label_information.left_side_refused_label[i].id         = left_side_new_label.id;
            all_label_information.left_side_refused_label[i].dist       = left_side_new_label.dist;
            all_label_information.left_side_refused_label[i]._class     = left_side_new_label._class;
            all_label_information.left_side_refused_label[i].azimut     = left_side_new_label.azimut;
            all_label_information.left_side_refused_label[i].ugol_mesta = left_side_new_label.ugol_mesta;
            all_label_information.left_side_refused_label[i].CamId      = left_side_new_label.CamId;
            
            id_for_delete_in_new_labels = left_side_new_label.id;
            
            break;
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].id == id_for_delete_in_new_labels)
        {
            all_label_information.left_side_new_label[i].label_busy = false;
            all_label_information.left_side_new_label[i].id         = 0;
            all_label_information.left_side_new_label[i].dist       = 0;
            all_label_information.left_side_new_label[i]._class     = 0;
            all_label_information.left_side_new_label[i].azimut     = 0;
            all_label_information.left_side_new_label[i].ugol_mesta = 0;
            all_label_information.left_side_new_label[i].CamId      = 0;
            all_label_information.left_side_new_label[i].quarter    = 0;
            
            break;
        }
    }
    
    all_label_information = ClearAllCells (all_label_information, "clear_all");

    return all_label_information;
}

ALL_LABEL_INFORMATION MoveTargetFromAcceptedToRefusedTargets (LEFT_SIDE_ACCEPTED_LABEL left_side_accepted_label, ALL_LABEL_INFORMATION all_label_information)
{   
    int id_for_delete_in_accepted_labels = 0;
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_busy == false)
        {
            all_label_information.left_side_refused_label[i].label_busy = true;
            all_label_information.left_side_refused_label[i].id         = left_side_accepted_label.id;
            all_label_information.left_side_refused_label[i].dist       = left_side_accepted_label.dist;
            all_label_information.left_side_refused_label[i]._class     = left_side_accepted_label._class;
            all_label_information.left_side_refused_label[i].azimut     = left_side_accepted_label.azimut;
            all_label_information.left_side_refused_label[i].ugol_mesta = left_side_accepted_label.ugol_mesta;
            all_label_information.left_side_refused_label[i].CamId      = left_side_accepted_label.CamId;
            
            id_for_delete_in_accepted_labels = left_side_accepted_label.id;
            
            break;
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].id == id_for_delete_in_accepted_labels)
        {
            all_label_information.left_side_accepted_label[i].label_busy = false;
            all_label_information.left_side_accepted_label[i].id         = 0;
            all_label_information.left_side_accepted_label[i].dist       = 0;
            all_label_information.left_side_accepted_label[i]._class     = 0;
            all_label_information.left_side_accepted_label[i].azimut     = 0;
            all_label_information.left_side_accepted_label[i].ugol_mesta = 0;
            all_label_information.left_side_accepted_label[i].CamId      = 0;
            all_label_information.left_side_accepted_label[i].quarter    = 0;
            
            break;
        }
    }
    
    all_label_information = ClearAllCells (all_label_information, "clear_all");

    return all_label_information;
}

ALL_LABEL_INFORMATION MoveTargetFromEveryLabelToDelete (ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].label_highlighted == true)
        {
            all_label_information.left_side_new_label[i].target_deleted = true;
            all_label_information.id_deleted_label.push_back(all_label_information.left_side_new_label[i].id);
            all_label_information.left_side_new_label[i] = ClearNewLabel (all_label_information.left_side_new_label[i]);
            break;
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_highlighted == true)
        {
            all_label_information.left_side_accepted_label[i].target_deleted = true;
            all_label_information.id_deleted_label.push_back(all_label_information.left_side_accepted_label[i].id);
            all_label_information.left_side_accepted_label[i] = ClearAcceptedLabel(all_label_information.left_side_accepted_label[i]);
            break;
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_highlighted == true)
        {
            all_label_information.left_side_refused_label[i].target_deleted = true;
            all_label_information.id_deleted_label.push_back(all_label_information.left_side_refused_label[i].id);
            all_label_information.left_side_refused_label[i] = ClearRefusedLabel(all_label_information.left_side_refused_label[i]);
            break;
        }
    }
    
    all_label_information = ClearAllCells (all_label_information, "clear_all");
        
    return all_label_information;
}

ALL_LABEL_INFORMATION HandlePressedButton (QString pressed_label, ALL_LABEL_INFORMATION all_label_information)
{
    if (pressed_label == "label_30"  ) // accepted
    {
        for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
        {
            if (all_label_information.left_side_new_label[i].label_highlighted == true)
            {
                all_label_information = MoveTargetFromNewToAcceptedTargets (all_label_information.left_side_new_label[i], all_label_information);
                break;
            }
        }
        
        for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
        {
            if (all_label_information.left_side_refused_label[i].label_highlighted == true)
            {
                all_label_information = MoveTargetFromRefusedToAcceptedTargets (all_label_information.left_side_refused_label[i], all_label_information);
                break;
            }
        }
    }
    else if (pressed_label == "label_37") // refused
    {
        for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
        {
            if (all_label_information.left_side_new_label[i].label_highlighted == true)
            {
                all_label_information = MoveTargetFromNewToRefusedTargets (all_label_information.left_side_new_label[i], all_label_information);
                break;
            }
        }
        
        for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
        {
            if (all_label_information.left_side_accepted_label[i].label_highlighted == true)
            {
                all_label_information = MoveTargetFromAcceptedToRefusedTargets (all_label_information.left_side_accepted_label[i], all_label_information);
                break;
            }
        }
    }
    else if (pressed_label == "label_16") //delete
    {
        all_label_information = MoveTargetFromEveryLabelToDelete (all_label_information);
    }
    
    return all_label_information;
}
