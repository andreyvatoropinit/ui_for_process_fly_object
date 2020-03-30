#include "7_viewer_draw_label_only.h"

void RefreshLabel (Ui::MainWindow* ui)
{
    // six new labels
    ui->label_24->clear();
    ui->label_14->clear();
    ui->label_13->clear();
    ui->label_15->clear();
    ui->label_24->setFrameShape(QFrame::StyledPanel);
    ui->label_24->setLineWidth(1);
    
    ui->label_25->clear();
    ui->label_17->clear();
    ui->label_18->clear();
    ui->label_19->clear();
    ui->label_25->setFrameShape(QFrame::StyledPanel);
    ui->label_25->setLineWidth(1);
    
    ui->label_26->clear();
    ui->label_23->clear();
    ui->label_20->clear();
    ui->label_21->clear();
    ui->label_26->setFrameShape(QFrame::StyledPanel);
    ui->label_26->setLineWidth(1);
    
    ui->label_51->clear();
    ui->label_50->clear();
    ui->label_93->clear();
    ui->label_87->clear();
    ui->label_51->setFrameShape(QFrame::StyledPanel);
    ui->label_51->setLineWidth(1);
    
    ui->label_47->clear();
    ui->label_52->clear();
    ui->label_92->clear();
    ui->label_59->clear();
    ui->label_47->setFrameShape(QFrame::StyledPanel);
    ui->label_47->setLineWidth(1);
    
    ui->label_48->clear();
    ui->label_46->clear();
    ui->label_64->clear();
    ui->label_59->clear();
    ui->label_48->setFrameShape(QFrame::StyledPanel);
    ui->label_48->setLineWidth(1);
    
    // six accepeted labels
    ui->label_31->clear();
    ui->label_27->clear();
    ui->label_34->clear();
    ui->label_28->clear();
    ui->label_31->setFrameShape(QFrame::StyledPanel);
    ui->label_31->setLineWidth(1);
    
    ui->label_29->clear();
    ui->label_33->clear();
    ui->label_32->clear();
    ui->label_35->clear();
    ui->label_29->setFrameShape(QFrame::StyledPanel);
    ui->label_29->setLineWidth(1);
    
    ui->label_98->clear();
    ui->label_94->clear();
    ui->label_99->clear();
    ui->label_97->clear();
    ui->label_98->setFrameShape(QFrame::StyledPanel);
    ui->label_98->setLineWidth(1);
    
    ui->label_102->clear();
    ui->label_100->clear();
    ui->label_102->clear();
    ui->label_101->clear();
    ui->label_102->setFrameShape(QFrame::StyledPanel);
    ui->label_102->setLineWidth(1);
    
    // six refused labels
    ui->label_40->clear();
    ui->label_36->clear();
    ui->label_43->clear();
    ui->label_41->clear();
    ui->label_40->setFrameShape(QFrame::StyledPanel);
    ui->label_40->setLineWidth(1);
    
    ui->label_42->clear();
    ui->label_39->clear();
    ui->label_48->clear();
    ui->label_44->clear();
    ui->label_42->setFrameShape(QFrame::StyledPanel);
    ui->label_42->setLineWidth(1);
    
    ui->label_106->clear();
    ui->label_104->clear();
    ui->label_105->clear();
    ui->label_107->clear();
    ui->label_106->setFrameShape(QFrame::StyledPanel);
    ui->label_106->setLineWidth(1);
    
    ui->label_110->clear();
    ui->label_108->clear();
    ui->label_109->clear();
    ui->label_111->clear();
    ui->label_110->setFrameShape(QFrame::StyledPanel);
    ui->label_110->setLineWidth(1);

}

void RefreshUPlittleCameras (Ui::MainWindow* ui)
{
    ui->label_10->clear();
    ui->label_12->clear();
    ui->label_45->clear();
    ui->label->   clear();
    ui->label_53->clear();
    ui->label_54->clear();
    ui->label_22->clear();
    ui->label_56->clear();
    ui->label_57->clear();
    ui->label_58->clear();
    ui->label_60->clear();
    ui->label_61->clear();
    ui->label_62->clear();
    ui->label_63->clear();
    ui->label_65->clear();
    ui->label_66->clear();
    ui->label_67->clear();
    ui->label_68->clear();
    ui->label_69->clear();
    ui->label_70->clear();
    ui->label_71->clear();
    ui->label_72->clear();
    ui->label_73->clear();
    ui->label_74->clear();
    ui->label_75->clear();
    ui->label_76->clear();
    ui->label_77->clear();
    ui->label_78->clear();
    ui->label_79->clear();
    ui->label_80->clear();
    ui->label_81->clear();
    ui->label_82->clear();
    ui->label_83->clear();
    ui->label_84->clear();
    ui->label_85->clear();
    ui->label_86->clear();
}


void DrawLabel24 (Ui::MainWindow* ui, LEFT_SIDE_NEW_LABEL left_side_new_label)
{
    int w = ui->label_24->width();     int h = ui->label_24->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_new_status_rhubus_question {};   target_new_status_rhubus_question.  load ("target_new_status_rhubus_question.svg")  ;

    int w_little = ui->label_13->width();     int h_little = ui->label_13->height();
    
    if (left_side_new_label._class == class_airplane)
            ui->label_24->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_helicopter)
            ui->label_24->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_new_label._class == class_drone)
            ui->label_24->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_other)
            ui->label_24->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_new_label.label_highlighted == true)
    {
        ui->label_24->setFrameShape(QFrame::Box);
        ui->label_24->setLineWidth(1);
    }
    else if (left_side_new_label.label_highlighted == false)
    {
        ui->label_24->setFrameShape(QFrame::StyledPanel);
        ui->label_24->setLineWidth(1);
    }

    QStringList azimuth_list = QString::number(left_side_new_label.azimut).split(".");

    QString azimuth_int_view = azimuth_list.first();

    QString stroka = "cl-" +        QString::number(left_side_new_label._class) + "  "
                          + "az-" + azimuth_int_view + "  "
                          + "ds-" + QString::number(left_side_new_label.dist)   + "  "
                          + "id-" + QString::number(left_side_new_label.id)     + "  "          
                          + "um-" + QString::number(left_side_new_label.ugol_mesta);            

    ui->label_15->setText(stroka);
    ui->label_13->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_14->setPixmap(target_new_status_rhubus_question.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel25 (Ui::MainWindow* ui, LEFT_SIDE_NEW_LABEL left_side_new_label)
{
    int w = ui->label_25->width();     int h = ui->label_25->height();
    int w_little = ui->label_19->width();   int h_little = ui->label_19->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_new_status_rhubus_question {};   target_new_status_rhubus_question.  load ("target_new_status_rhubus_question.svg")  ;

    if (left_side_new_label._class == class_airplane)
            ui->label_25->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_helicopter)
            ui->label_25->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_new_label._class == class_drone)
            ui->label_25->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_other)
            ui->label_25->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_new_label.label_highlighted == true)
    {
        ui->label_25->setFrameShape(QFrame::Box);
        ui->label_25->setLineWidth(1);
    }
    else if (left_side_new_label.label_highlighted == false)
    {
        ui->label_25->setFrameShape(QFrame::StyledPanel);
        ui->label_25->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_new_label._class) + "  "
                          + "az-" + QString::number(left_side_new_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_new_label.dist)   + "  "
                          + "id-" + QString::number(left_side_new_label.id)     + "  "          
                          + "um-" + QString::number(left_side_new_label.ugol_mesta);    
                          
    ui->label_18->setText(stroka);  
                          
    ui->label_19->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_17->setPixmap(target_new_status_rhubus_question.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel26 (Ui::MainWindow* ui, LEFT_SIDE_NEW_LABEL left_side_new_label)
{
    int w = ui->label_26->width();     int h = ui->label_26->height();
    int w_little = ui->label_19->width();   int h_little = ui->label_19->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_new_status_rhubus_question {};   target_new_status_rhubus_question.  load ("target_new_status_rhubus_question.svg")  ;

    if (left_side_new_label._class == class_airplane)
            ui->label_26->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_helicopter)
            ui->label_26->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_new_label._class == class_drone)
            ui->label_26->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_other)
            ui->label_26->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_new_label.label_highlighted == true)
    {
        ui->label_26->setFrameShape(QFrame::Box);
        ui->label_26->setLineWidth(1);
    }
    else if (left_side_new_label.label_highlighted == false)
    {
        ui->label_26->setFrameShape(QFrame::StyledPanel);
        ui->label_26->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_new_label._class) + "  "
                          + "az-" + QString::number(left_side_new_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_new_label.dist)   + "  "
                          + "id-" + QString::number(left_side_new_label.id)     + "  "          
                          + "um-" + QString::number(left_side_new_label.ugol_mesta);      
                          
    ui->label_23->setText(stroka); 
                          
    ui->label_20->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_21->setPixmap(target_new_status_rhubus_question.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel51 (Ui::MainWindow* ui, LEFT_SIDE_NEW_LABEL left_side_new_label)
{
    int w = ui->label_51->width();     int h = ui->label_51->height();
    int w_little = ui->label_19->width();   int h_little = ui->label_19->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_new_status_rhubus_question {};   target_new_status_rhubus_question.  load ("target_new_status_rhubus_question.svg")  ;

    if (left_side_new_label._class == class_airplane)
            ui->label_51->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_helicopter)
            ui->label_51->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_new_label._class == class_drone)
            ui->label_51->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_new_label._class == class_other)
            ui->label_51->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_new_label.label_highlighted == true)
    {
        ui->label_51->setFrameShape(QFrame::Box);
        ui->label_51->setLineWidth(1);
    }
    else if (left_side_new_label.label_highlighted == false)
    {
        ui->label_51->setFrameShape(QFrame::StyledPanel);
        ui->label_51->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_new_label._class) + "  "
                          + "az-" + QString::number(left_side_new_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_new_label.dist)   + "  "
                          + "id-" + QString::number(left_side_new_label.id)     + "  "          
                          + "um-" + QString::number(left_side_new_label.ugol_mesta);   
                              
    ui->label_50->setText(stroka);    
                          
    ui->label_93->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_87->setPixmap(target_new_status_rhubus_question.scaled(w_little,h_little,Qt::KeepAspectRatio));
}




void DrawLabel31 (Ui::MainWindow* ui,  LEFT_SIDE_ACCEPTED_LABEL left_side_accepted_label)
{
    int w = ui->label_31->width();     int h = ui->label_31->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_approve_status_rhombus_plus {};  target_approve_status_rhombus_plus. load ("target_approve_status_rhombus_plus.svg") ;

    int w_little = ui->label_34->width();     int h_little = ui->label_34->height();

    if (left_side_accepted_label._class == class_airplane)
            ui->label_31->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_helicopter)
            ui->label_31->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_accepted_label._class == class_drone)
            ui->label_31->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_other)
            ui->label_31->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_accepted_label.label_highlighted == true)
    {
        ui->label_31->setFrameShape(QFrame::Box);
        ui->label_31->setLineWidth(1);
    }
    else if (left_side_accepted_label.label_highlighted == false)
    {
        ui->label_31->setFrameShape(QFrame::StyledPanel);
        ui->label_31->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_accepted_label._class) + "  "
                          + "az-" + QString::number(left_side_accepted_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_accepted_label.dist)   + "  "
                          + "id-" + QString::number(left_side_accepted_label.id)     + "  "          
                          + "um-" + QString::number(left_side_accepted_label.ugol_mesta);  
                          
    ui->label_27->setText(stroka); 
                              
    ui->label_34->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_28->setPixmap(target_approve_status_rhombus_plus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel29 (Ui::MainWindow* ui,  LEFT_SIDE_ACCEPTED_LABEL left_side_accepted_label)
{
    int w = ui->label_29->width();     int h = ui->label_29->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_approve_status_rhombus_plus {};  target_approve_status_rhombus_plus. load ("target_approve_status_rhombus_plus.svg") ;

    int w_little = ui->label_32->width();     int h_little = ui->label_32->height();

    if (left_side_accepted_label._class == class_airplane)
            ui->label_29->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_helicopter)
            ui->label_29->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_accepted_label._class == class_drone)
            ui->label_29->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_other)
            ui->label_29->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_accepted_label.label_highlighted == true)
    {
        ui->label_29->setFrameShape(QFrame::Box);
        ui->label_29->setLineWidth(1);
    }
    else if (left_side_accepted_label.label_highlighted == false)
    {
        ui->label_29->setFrameShape(QFrame::StyledPanel);
        ui->label_29->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_accepted_label._class) + "  "
                          + "az-" + QString::number(left_side_accepted_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_accepted_label.dist)   + "  "
                          + "id-" + QString::number(left_side_accepted_label.id)     + "  "          
                          + "um-" + QString::number(left_side_accepted_label.ugol_mesta);  
     
    ui->label_33->setText(stroka);  
                          
    ui->label_32->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_35->setPixmap(target_approve_status_rhombus_plus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel98 (Ui::MainWindow* ui,  LEFT_SIDE_ACCEPTED_LABEL left_side_accepted_label)
{
    int w = ui->label_98->width();     int h = ui->label_98->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_approve_status_rhombus_plus {};  target_approve_status_rhombus_plus. load ("target_approve_status_rhombus_plus.svg") ;

    int w_little = ui->label_99->width();     int h_little = ui->label_99->height();

    if (left_side_accepted_label._class == class_airplane)
            ui->label_98->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_helicopter)
            ui->label_98->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_accepted_label._class == class_drone)
            ui->label_98->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_other)
            ui->label_98->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
  
    if (left_side_accepted_label.label_highlighted == true)
    {
        ui->label_98->setFrameShape(QFrame::Box);
        ui->label_98->setLineWidth(1);
    }
    else if (left_side_accepted_label.label_highlighted == false)
    {
        ui->label_98->setFrameShape(QFrame::StyledPanel);
        ui->label_98->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_accepted_label._class) + "  "
                          + "az-" + QString::number(left_side_accepted_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_accepted_label.dist)   + "  "
                          + "id-" + QString::number(left_side_accepted_label.id)     + "  "          
                          + "um-" + QString::number(left_side_accepted_label.ugol_mesta);  
                          
    ui->label_94->setText(stroka);  
                          
    ui->label_99->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));
    ui->label_97->setPixmap(target_approve_status_rhombus_plus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel102 (Ui::MainWindow* ui, LEFT_SIDE_ACCEPTED_LABEL left_side_accepted_label)
{
    int w = ui->label_102->width();     int h = ui->label_102->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_approve_status_rhombus_plus {};  target_approve_status_rhombus_plus. load ("target_approve_status_rhombus_plus.svg") ;

    int w_little = ui->label_103->width();     int h_little = ui->label_103->height();

    if (left_side_accepted_label._class == class_airplane)
            ui->label_102->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_helicopter)
            ui->label_102->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_accepted_label._class == class_drone)
            ui->label_102->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_accepted_label._class == class_other)
            ui->label_102->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
  
  
    if (left_side_accepted_label.label_highlighted == true)
    {
        ui->label_102->setFrameShape(QFrame::Box);
        ui->label_102->setLineWidth(1);
    }
    else if (left_side_accepted_label.label_highlighted == false)
    {
        ui->label_102->setFrameShape(QFrame::StyledPanel);
        ui->label_102->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_accepted_label._class) + "  "
                          + "az-" + QString::number(left_side_accepted_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_accepted_label.dist)   + "  "
                          + "id-" + QString::number(left_side_accepted_label.id)     + "  "          
                          + "um-" + QString::number(left_side_accepted_label.ugol_mesta); 
                             
    ui->label_100->setText(stroka);   

    ui->label_103->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));

    ui->label_101->setPixmap(target_approve_status_rhombus_plus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}




void DrawLabel40 (Ui::MainWindow* ui,  LEFT_SIDE_REFUSED_LABEL left_side_refused_label)
{
    int w = ui->label_40->width();     int h = ui->label_40->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_decline_status_rhombus_minus {}; target_decline_status_rhombus_minus.load ("target_decline_status_rhombus_minus.svg");

    int w_little = ui->label_43->width();     int h_little = ui->label_43->height();

    if (left_side_refused_label._class == class_airplane)
            ui->label_40->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_helicopter)
            ui->label_40->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_refused_label._class == class_drone)
            ui->label_40->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_other)
            ui->label_40->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_refused_label.label_highlighted == true)
    {
        ui->label_40->setFrameShape(QFrame::Box);
        ui->label_40->setLineWidth(1);
    }
    else if (left_side_refused_label.label_highlighted == false)
    {
        ui->label_40->setFrameShape(QFrame::StyledPanel);
        ui->label_40->setLineWidth(1);
    }

    QString stroka = "cl-" +        QString::number(left_side_refused_label._class) + "  "
                          + "az-" + QString::number(left_side_refused_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_refused_label.dist)   + "  "
                          + "id-" + QString::number(left_side_refused_label.id)     + "  "          
                          + "um-" + QString::number(left_side_refused_label.ugol_mesta);
                          
    ui->label_36->setText(stroka);    

    ui->label_43->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));

    ui->label_41->setPixmap(target_decline_status_rhombus_minus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel42 (Ui::MainWindow* ui,  LEFT_SIDE_REFUSED_LABEL left_side_refused_label)
{
    int w = ui->label_42->width();     int h = ui->label_42->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_decline_status_rhombus_minus {}; target_decline_status_rhombus_minus.load ("target_decline_status_rhombus_minus.svg");

    int w_little = ui->label_38->width();     int h_little = ui->label_38->height();

    if (left_side_refused_label._class == class_airplane)
            ui->label_42->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_helicopter)
            ui->label_42->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_refused_label._class == class_drone)
            ui->label_42->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_other)
            ui->label_42->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_refused_label.label_highlighted == true)
    {
        ui->label_42->setFrameShape(QFrame::Box);
        ui->label_42->setLineWidth(1);
    }
    else if (left_side_refused_label.label_highlighted == false)
    {
        ui->label_42->setFrameShape(QFrame::StyledPanel);
        ui->label_42->setLineWidth(1);
    }
 
    QString stroka = "cl-" +        QString::number(left_side_refused_label._class) + "  "
                          + "az-" + QString::number(left_side_refused_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_refused_label.dist)   + "  "
                          + "id-" + QString::number(left_side_refused_label.id)     + "  "          
                          + "um-" + QString::number(left_side_refused_label.ugol_mesta);
                          
    ui->label_39->setText(stroka);    
                          
    ui->label_38->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));

    ui->label_44->setPixmap(target_decline_status_rhombus_minus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel106 (Ui::MainWindow* ui, LEFT_SIDE_REFUSED_LABEL left_side_refused_label)
{
    int w = ui->label_106->width();     int h = ui->label_106->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_decline_status_rhombus_minus {}; target_decline_status_rhombus_minus.load ("target_decline_status_rhombus_minus.svg");

    int w_little = ui->label_105->width();     int h_little = ui->label_105->height();

    if (left_side_refused_label._class == class_airplane)
            ui->label_106->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_helicopter)
            ui->label_106->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_refused_label._class == class_drone)
            ui->label_106->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_other)
            ui->label_106->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_refused_label.label_highlighted == true)
    {
        ui->label_106->setFrameShape(QFrame::Box);
        ui->label_106->setLineWidth(1);
    }
    else if (left_side_refused_label.label_highlighted == false)
    {
        ui->label_106->setFrameShape(QFrame::StyledPanel);
        ui->label_106->setLineWidth(1);
    }
 
    QString stroka = "cl-" +        QString::number(left_side_refused_label._class) + "  "
                          + "az-" + QString::number(left_side_refused_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_refused_label.dist)   + "  "
                          + "id-" + QString::number(left_side_refused_label.id)     + "  "          
                          + "um-" + QString::number(left_side_refused_label.ugol_mesta);  
                          
    ui->label_104->setText(stroka);  
                          
    ui->label_105->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));

    ui->label_107->setPixmap(target_decline_status_rhombus_minus.scaled(w_little,h_little,Qt::KeepAspectRatio));
}

void DrawLabel110 (Ui::MainWindow* ui, LEFT_SIDE_REFUSED_LABEL left_side_refused_label)
{
    int w = ui->label_110->width();     int h = ui->label_110->height();

    QPixmap airplane{}; airplane.load("airplane.png"); QPixmap drone{}; drone.load("drone.png");  QPixmap helicopter{}; helicopter.load("helicopter.png");
    QPixmap target_visible_status_ball_green {};    target_visible_status_ball_green.   load ("target_visible_status_ball_green.svg")   ;
    QPixmap target_invisble_status_ball_orange {};  target_invisble_status_ball_orange. load ("target_invisble_status_ball_orange.svg") ;
    QPixmap target_decline_status_rhombus_minus {}; target_decline_status_rhombus_minus.load ("target_decline_status_rhombus_minus.svg");

    int w_little = ui->label_109->width();     int h_little = ui->label_109->height();

    if (left_side_refused_label._class == class_airplane)
            ui->label_110->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_helicopter)
            ui->label_110->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
    
    if (left_side_refused_label._class == class_drone)
            ui->label_110->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));
            
    if (left_side_refused_label._class == class_other)
            ui->label_110->setPixmap(airplane.scaled(w,h,Qt::KeepAspectRatio));

    if (left_side_refused_label.label_highlighted == true)
    {
        ui->label_110->setFrameShape(QFrame::Box);
        ui->label_110->setLineWidth(1);
    }
    else if (left_side_refused_label.label_highlighted == false)
    {
        ui->label_110->setFrameShape(QFrame::StyledPanel);
        ui->label_110->setLineWidth(1);
    }
 
    QString stroka = "cl-" +        QString::number(left_side_refused_label._class) + "  "
                          + "az-" + QString::number(left_side_refused_label.azimut) + "  "
                          + "ds-" + QString::number(left_side_refused_label.dist)   + "  "
                          + "id-" + QString::number(left_side_refused_label.id)     + "  "          
                          + "um-" + QString::number(left_side_refused_label.ugol_mesta);  
                          
    ui->label_108->setText(stroka);  
                          
    ui->label_109->setPixmap(target_visible_status_ball_green.scaled(w_little,h_little,Qt::KeepAspectRatio));

    ui->label_111->setPixmap(target_decline_status_rhombus_minus.scaled(w_little,h_little,Qt::KeepAspectRatio));

}
