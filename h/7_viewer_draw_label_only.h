#ifndef _7_VIEWER_DRAW_LABEL_ONLY_H
#define _7_VIEWER_DRAW_LABEL_ONLY_H

#include "9_mainwindow.h"
#include "ui_mainwindow.h"
#include "5_model_labels_on_ui.h"


// new targets
void DrawLabel24 (Ui::MainWindow*, LEFT_SIDE_NEW_LABEL);

void DrawLabel25 (Ui::MainWindow*, LEFT_SIDE_NEW_LABEL);

void DrawLabel26 (Ui::MainWindow*, LEFT_SIDE_NEW_LABEL);

void DrawLabel51 (Ui::MainWindow*, LEFT_SIDE_NEW_LABEL);

void DrawLabel47 (Ui::MainWindow*, LEFT_SIDE_NEW_LABEL);

void DrawLabel48 (Ui::MainWindow*, LEFT_SIDE_NEW_LABEL);


// accepted targets
void DrawLabel31 (Ui::MainWindow*, LEFT_SIDE_ACCEPTED_LABEL);

void DrawLabel29 (Ui::MainWindow*, LEFT_SIDE_ACCEPTED_LABEL);

void DrawLabel98 (Ui::MainWindow*, LEFT_SIDE_ACCEPTED_LABEL);

void DrawLabel102 (Ui::MainWindow*, LEFT_SIDE_ACCEPTED_LABEL);


// refused targets
void DrawLabel40 (Ui::MainWindow*, LEFT_SIDE_REFUSED_LABEL);

void DrawLabel42 (Ui::MainWindow*, LEFT_SIDE_REFUSED_LABEL);

void DrawLabel106 (Ui::MainWindow*, LEFT_SIDE_REFUSED_LABEL);

void DrawLabel110 (Ui::MainWindow*, LEFT_SIDE_REFUSED_LABEL);

void RefreshLabel (Ui::MainWindow* );

void RefreshUPlittleCameras (Ui::MainWindow*);

static const int class_airplane = 1;
static const int class_helicopter = 2;
static const int class_drone = 3;
static const int class_other = 4;

#endif // _7_VIEWER_DRAW_LABEL_ONLY_H
