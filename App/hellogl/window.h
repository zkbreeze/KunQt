//
//  window.h
//
//
//  Created by Kun Zhao on 2014-10-17 11:54:23.
//
//

#ifndef WINDOW_H
#define WINDOW_H

#include <kvs/qt/Application>
#include <QWidget>
#include <QMainWindow>
#include "kunscreen.h"
#include "TransferFunctionEditor1D.h"

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE
//! [0]
class GLWidget;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window( kvs::qt::Application* app );

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QSlider *createSlider();

    GLWidget *glWidget;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;

    kun::kunScreen* m_screen;
    kun::TransferFunctionEditor1D* m_editor_1d;

public slots:
	void show1DTFEditor();

};
//! [0]

#endif
