QT       += core gui
QT       += network
QT += multimediawidgets
QT += multimedia multimediawidgets
QT += core


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += TEST_MODE

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



HEADERS += \
    h/1_udp_read_from_lan.h \
    h/4_controller.h \
    h/5_model.h \
    h/5_model_labels_on_ui.h \
    h/5_model_targets_on_ui.h \
    h/6_viewer_objects.h \
    h/7_viewer_draw_label_only.h \
    h/7_viewer_get_hndl_show_video.h \
    h/9_mainwindow.h \
    mavlink/include/checksum.h \
    mavlink/include/mavlink_conversions.h \
    mavlink/include/mavlink_get_info.h \
    mavlink/include/mavlink_helpers.h \
    mavlink/include/mavlink_sha256.h \
    mavlink/include/mavlink_types.h \
    mavlink/include/message.hpp \
    mavlink/include/microservice/mavlink.h \
    mavlink/include/microservice/mavlink_msg_microservice_command.h \
    mavlink/include/microservice/mavlink_msg_microservice_command.hpp \
    mavlink/include/microservice/mavlink_msg_microservice_heartbeat_data.h \
    mavlink/include/microservice/mavlink_msg_microservice_heartbeat_data.hpp \
    mavlink/include/microservice/mavlink_msg_microservice_request_data.h \
    mavlink/include/microservice/mavlink_msg_microservice_request_data.hpp \
    mavlink/include/microservice/microservice.h \
    mavlink/include/microservice/microservice.hpp \
    mavlink/include/microservice/testsuite.h \
    mavlink/include/microservice/version.h \
    mavlink/include/msgmap.hpp \
    mavlink/include/protocol.h \
    mavlink/include/target_analyzer/mavlink.h \
    mavlink/include/target_analyzer/mavlink_msg_analyzer_target_data.h \
    mavlink/include/target_analyzer/mavlink_msg_analyzer_target_data.hpp \
    mavlink/include/target_analyzer/target_analyzer.h \
    mavlink/include/target_analyzer/target_analyzer.hpp \
    mavlink/include/target_analyzer/testsuite.h \
    mavlink/include/target_analyzer/version.h \


INCLUDEPATH += mavlink/include/
INCLUDEPATH += mavlink/include/microservice
INCLUDEPATH += mavlink/include/target_analyzer
INCLUDEPATH += h/

FORMS += \
    mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv4

LIBS += -L"/usr/local/lib/"

LIBS += \
   -lopencv_core \
   -lopencv_features2d \
   -lopencv_highgui \
   -lopencv_imgcodecs \
   -lopencv_imgproc \
   -lopencv_video \
   -lopencv_videoio \
   -lopencv_videostab

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
    cpp/1_udp_read_from_lan.cpp \
    cpp/4_controller.cpp \
    cpp/5_model.cpp \
    cpp/5_model_labels_on_ui.cpp \
    cpp/5_model_targets_on_ui.cpp \
    cpp/6_viewer_objects.cpp \
    cpp/7_viewer_draw_label_only.cpp \
    cpp/7_viewer_get_hndl_show_video.cpp \
    cpp/9_main.cpp \
    cpp/9_mainwindow.cpp
