#include "9_mainwindow.h"
#include "4_controller.h"


QString StaticStorageForStoreLastPressedLabel (QString label_pressed, QString input_string)
{
    static QString static_pressed_label {};

    if (input_string == "put_last_pressed_label")
    {
        static_pressed_label = label_pressed;
        return static_pressed_label;
    }
    else if (input_string == "get_last_pressed_label")
    {
        QString pressed_label = static_pressed_label;
        static_pressed_label = "empty";
        return pressed_label;
    }
}

void InterfaceFromLANToController (FRAMES_TARGET_ANALYZER_VIEW one_frame_mavlink_view)
{
    QString last_pressed_label {};
    last_pressed_label = StaticStorageForStoreLastPressedLabel ("empty", "get_last_pressed_label");

    InterfaceFromControllerToModel (one_frame_mavlink_view, last_pressed_label);
}

// сбод данных о имени нажатой label
bool  MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QString label_pressed = "empty";

    if ((event->type() == QEvent::MouseButtonPress))
    {
             if (obj->objectName() == "label_24")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_25")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_26")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_51")  label_pressed = obj->objectName();

        else if (obj->objectName() == "label_31")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_29")  label_pressed = obj->objectName();

        else if (obj->objectName() == "label_40")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_42")  label_pressed = obj->objectName();

        else if (obj->objectName() == "label_30")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_37")  label_pressed = obj->objectName();
        else if (obj->objectName() == "label_16")  label_pressed = obj->objectName();

        else if (obj->objectName() == "label_10")  label_pressed = obj->objectName();

        StaticStorageForStoreLastPressedLabel (label_pressed, "put_last_pressed_label");


    }

   return false;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
     StaticStorageForStoreLastPressedLabel (arg1, "put_last_pressed_label");
}

