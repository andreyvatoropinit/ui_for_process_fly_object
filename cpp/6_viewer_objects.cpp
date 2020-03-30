#include <7_viewer_draw_label_only.h>
#include <6_viewer_objects.h>

// функция рисования целей в пространстве новых ячеек
void DrawLeftSideNewTargets (Ui::MainWindow* ui, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
         if (all_label_information.left_side_new_label[i].label_picture  == "label_24" &&
             all_label_information.left_side_new_label[i].label_busy     == true       &&
             all_label_information.left_side_new_label[i].target_deleted == false )
            DrawLabel24 (ui, all_label_information.left_side_new_label[i]);
      
         if (all_label_information.left_side_new_label[i].label_picture  == "label_25" &&
             all_label_information.left_side_new_label[i].label_busy     == true       &&
             all_label_information.left_side_new_label[i].target_deleted == false )
            DrawLabel25 (ui, all_label_information.left_side_new_label[i]);

         if (all_label_information.left_side_new_label[i].label_picture == "label_26" &&
             all_label_information.left_side_new_label[i].label_busy == true &&
             all_label_information.left_side_new_label[i].target_deleted == false )
            DrawLabel26 (ui,  all_label_information.left_side_new_label[i]);

         if (all_label_information.left_side_new_label[i].label_picture == "label_51" &&
             all_label_information.left_side_new_label[i].label_busy == true &&
             all_label_information.left_side_new_label[i].target_deleted == false )
            DrawLabel51 (ui,  all_label_information.left_side_new_label[i]);

         if (all_label_information.left_side_new_label[i].label_picture == "label_47" &&
             all_label_information.left_side_new_label[i].label_busy == true && 
             all_label_information.left_side_new_label[i].target_deleted == false );
            //DrawLabel47 (ui, all_label_information);

         if (all_label_information.left_side_new_label[i].label_picture == "label_48" &&
             all_label_information.left_side_new_label[i].label_busy == true && 
             all_label_information.left_side_new_label[i].target_deleted == false );
            //DrawLabel48 (ui, all_label_information);*/
    }

}

// функция рисования подтвержденных целей в пространстве подтвержденных целей
void DrawLeftSideAcceptedTargets (Ui::MainWindow* ui, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
         if (all_label_information.left_side_accepted_label[i].label_picture == "label_31" &&
             all_label_information.left_side_accepted_label[i].label_busy == true &&
             all_label_information.left_side_accepted_label[i].target_deleted == false )
            DrawLabel31 (ui, all_label_information.left_side_accepted_label[i]);
      
         if (all_label_information.left_side_accepted_label[i].label_picture == "label_29" &&
             all_label_information.left_side_accepted_label[i].label_busy == true &&
             all_label_information.left_side_accepted_label[i].target_deleted == false )
            DrawLabel29 (ui, all_label_information.left_side_accepted_label[i]);

         if (all_label_information.left_side_accepted_label[i].label_picture == "label_98" &&
             all_label_information.left_side_accepted_label[i].label_busy == true && 
             all_label_information.left_side_accepted_label[i].target_deleted == false )
            DrawLabel98 (ui,  all_label_information.left_side_accepted_label[i]);

         if (all_label_information.left_side_accepted_label[i].label_picture == "label_102" &&
             all_label_information.left_side_accepted_label[i].label_busy == true && 
             all_label_information.left_side_accepted_label[i].target_deleted == false )
            DrawLabel102 (ui,  all_label_information.left_side_accepted_label[i]);

    }
}

// функция рисования отказанных целей в пространсве отказанных целей
void DrawLeftSideRefusedTargets (Ui::MainWindow* ui, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
         if (all_label_information.left_side_refused_label[i].label_picture == "label_40" &&
             all_label_information.left_side_refused_label[i].label_busy == true && 
             all_label_information.left_side_refused_label[i].target_deleted == false )
            DrawLabel40 (ui, all_label_information.left_side_refused_label[i]);
      
         if (all_label_information.left_side_refused_label[i].label_picture == "label_42" &&
             all_label_information.left_side_refused_label[i].label_busy == true && 
             all_label_information.left_side_refused_label[i].target_deleted == false )
            DrawLabel42 (ui, all_label_information.left_side_refused_label[i]);

         if (all_label_information.left_side_refused_label[i].label_picture == "label_106" &&
             all_label_information.left_side_refused_label[i].label_busy == true && 
             all_label_information.left_side_refused_label[i].target_deleted == false )
            DrawLabel106 (ui,  all_label_information.left_side_refused_label[i]);

         if (all_label_information.left_side_refused_label[i].label_picture == "label_110" &&
             all_label_information.left_side_refused_label[i].label_busy == true && 
             all_label_information.left_side_refused_label[i].target_deleted == false )
            DrawLabel110 (ui,  all_label_information.left_side_refused_label[i]);
    } 

}

void ClearObjectOnRigthSide (Ui::MainWindow* ui, ALL_LABEL_INFORMATION all_label_information)
{
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].label_highlighted == true)
            return;
    }  
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_highlighted == true)
            return;
    }
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_highlighted == true)
            return;
    }
    
    ui->label_95->clear();         
    ui->label_88->clear();
    ui->label_89->clear();
    ui->label_90->clear();
    ui->label_91->clear();
    ui->comboBox->setCurrentIndex(0);
}

// функция отображения выделенной цели в правой части
void DrawObjectOnRigthSide (Ui::MainWindow* ui, ALL_LABEL_INFORMATION all_label_information)
{
    ClearObjectOnRigthSide (ui, all_label_information);

    QPixmap target_new_status_rhubus_question {};   target_new_status_rhubus_question.  load ("target_new_status_rhubus_question.svg")  ;
    QPixmap target_approve_status_rhombus_plus {};  target_approve_status_rhombus_plus. load ("target_approve_status_rhombus_plus.svg") ;
    QPixmap target_decline_status_rhombus_minus {}; target_decline_status_rhombus_minus.load ("target_decline_status_rhombus_minus.svg");
        
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].label_highlighted == true)
        {
            ui->label_95->setText(QString::number(all_label_information.left_side_new_label[i].id));          
            ui->label_88->setText(QString::number(all_label_information.left_side_new_label[i].azimut));
            ui->label_89->setText(QString::number(all_label_information.left_side_new_label[i].ugol_mesta));
            ui->label_90->setText(QString::number(all_label_information.left_side_new_label[i].dist));  
            ui->label_91->setPixmap(target_new_status_rhubus_question);
            ui->comboBox->setCurrentIndex(all_label_information.left_side_new_label[i]._class);                                                                   
        }
    }  
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_highlighted == true)
        {
            ui->label_95->setText(QString::number(all_label_information.left_side_accepted_label[i].id));          
            ui->label_88->setText(QString::number(all_label_information.left_side_accepted_label[i].azimut));
            ui->label_89->setText(QString::number(all_label_information.left_side_accepted_label[i].ugol_mesta));
            ui->label_90->setText(QString::number(all_label_information.left_side_accepted_label[i].dist));
            ui->comboBox->setCurrentIndex(all_label_information.left_side_accepted_label[i]._class);   
            ui->label_91->setPixmap(target_approve_status_rhombus_plus);
        }
    }
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_highlighted == true)
        {
            ui->label_95->setText(QString::number(all_label_information.left_side_refused_label[i].id));           
            ui->label_88->setText(QString::number(all_label_information.left_side_refused_label[i].azimut));
            ui->label_89->setText(QString::number(all_label_information.left_side_refused_label[i].ugol_mesta));
            ui->label_90->setText(QString::number(all_label_information.left_side_refused_label[i].dist));    
            ui->comboBox->setCurrentIndex(all_label_information.left_side_refused_label[i]._class);           
            ui->label_91->setPixmap(target_decline_status_rhombus_minus);
        }
    }
}

void PaintLittleCamera (Ui::MainWindow* ui, int CamId, int id)
{
        if (CamId == camera_1)   ui->label_10-> setText(QString::number(id));
        if (CamId == camera_2)   ui->label_12-> setText(QString::number(id));
        if (CamId == camera_3)   ui->label_45-> setText(QString::number(id));
        if (CamId == camera_4)   ui->label->    setText(QString::number(id));
        if (CamId == camera_5)   ui->label_53-> setText(QString::number(id));
        if (CamId == camera_6)   ui->label_54-> setText(QString::number(id));
        if (CamId == camera_7)   ui->label_22-> setText(QString::number(id));
        if (CamId == camera_8)   ui->label_56-> setText(QString::number(id));
        if (CamId == camera_9)   ui->label_57-> setText(QString::number(id));
        if (CamId == camera_10)  ui->label_58-> setText(QString::number(id));
        if (CamId == camera_11)  ui->label_60-> setText(QString::number(id));
        if (CamId == camera_12)  ui->label_61-> setText(QString::number(id));
        if (CamId == camera_13)  ui->label_62-> setText(QString::number(id));
        if (CamId == camera_14)  ui->label_63-> setText(QString::number(id));
        if (CamId == camera_15)  ui->label_65-> setText(QString::number(id));
        if (CamId == camera_16)  ui->label_66-> setText(QString::number(id));
        if (CamId == camera_17)  ui->label_67-> setText(QString::number(id));
        if (CamId == camera_18)  ui->label_68-> setText(QString::number(id));
        if (CamId == camera_19)  ui->label_69-> setText(QString::number(id));
        if (CamId == camera_20)  ui->label_70-> setText(QString::number(id));
        if (CamId == camera_21)  ui->label_71-> setText(QString::number(id));
        if (CamId == camera_22)  ui->label_72-> setText(QString::number(id));
        if (CamId == camera_23)  ui->label_73-> setText(QString::number(id));
        if (CamId == camera_24)  ui->label_74-> setText(QString::number(id));
        if (CamId == camera_25)  ui->label_75-> setText(QString::number(id));
        if (CamId == camera_26)  ui->label_76-> setText(QString::number(id));
        if (CamId == camera_27)  ui->label_77-> setText(QString::number(id));
        if (CamId == camera_28)  ui->label_78-> setText(QString::number(id));
        if (CamId == camera_29)  ui->label_79-> setText(QString::number(id));
        if (CamId == camera_30)  ui->label_80-> setText(QString::number(id));
        if (CamId == camera_31)  ui->label_81-> setText(QString::number(id));
        if (CamId == camera_32)  ui->label_82-> setText(QString::number(id));
        if (CamId == camera_33)  ui->label_83-> setText(QString::number(id));
        if (CamId == camera_34)  ui->label_84-> setText(QString::number(id));
        if (CamId == camera_35)  ui->label_85-> setText(QString::number(id));
        if (CamId == camera_36)  ui->label_86-> setText(QString::number(id));
}

// функция рисования целей в линейке 36 камер
void DrawOneLittleCameraUpSide (Ui::MainWindow* ui, ALL_LABEL_INFORMATION all_label_information)
{
    RefreshUPlittleCameras (ui);
    
    for (int i = 0; i < all_label_information.left_side_new_label.size(); i++)
    {
        if (all_label_information.left_side_new_label[i].label_busy == true)
        {
            PaintLittleCamera (ui, all_label_information.left_side_new_label[i].CamId, all_label_information.left_side_new_label[i].id);
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_accepted_label.size(); i++)
    {
        if (all_label_information.left_side_accepted_label[i].label_busy == true)
        {
            PaintLittleCamera (ui, all_label_information.left_side_accepted_label[i].CamId, all_label_information.left_side_accepted_label[i].id);
        }
    }
    
    for (int i = 0; i < all_label_information.left_side_refused_label.size(); i++)
    {
        if (all_label_information.left_side_refused_label[i].label_busy == true)
        {
            PaintLittleCamera (ui, all_label_information.left_side_refused_label[i].CamId, all_label_information.left_side_refused_label[i].id);
        }
    }

}

ALL_LABEL_INFORMATION PutGetOneFrameToLocalStorage (ALL_LABEL_INFORMATION all_label_inforamtion, QString input_string)
{
    static ALL_LABEL_INFORMATION static_all_label_information {};

    if (input_string == "put_data" )
    {
         static_all_label_information = all_label_inforamtion;
         return static_all_label_information;
    }

    else if (input_string == "get_data")
    {
        return static_all_label_information;
    }
    else
        while (true);
}

// в последствии возможно уйти от QGraphicsScene т.к. нажатие на обьект нам не нужно
void MainWindow::paintEvent(QPaintEvent *event)
{
    // получаем цели для рисования из локального хранилища
    ALL_LABEL_INFORMATION all_label_information {};

    all_label_information = PutGetOneFrameToLocalStorage (all_label_information, "get_data");
    
    if (all_label_information.left_side_new_label.     empty () == true &&
        all_label_information.left_side_accepted_label.empty () == true &&
        all_label_information.left_side_refused_label. empty () == true)
        return;

    if (all_label_information.name_little_camera_pressed == "label_10")
        emit  MainWindow :: InterfaveFromModelToViewerVideo ("label_10");

    RefreshLabel (ui);

    DrawOneLittleCameraUpSide    (ui,  all_label_information);

    DrawLeftSideNewTargets       (ui,  all_label_information);

    DrawLeftSideAcceptedTargets  (ui,  all_label_information);

    DrawLeftSideRefusedTargets   (ui,  all_label_information);

    DrawObjectOnRigthSide        (ui,  all_label_information);
}

// интерфейс из модели во Viewer. необходим для хранения текущего кадра
void InterfaceFromModelToViewer (ALL_LABEL_INFORMATION all_label_information)
{
    PutGetOneFrameToLocalStorage (all_label_information, "put_data" );
}

