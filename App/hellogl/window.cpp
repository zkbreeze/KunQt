//
//  window.cpp
//
//
//  Created by Kun Zhao on 2014-10-17 11:54:07.
//
//

#include <GL/glew.h>
#include <GLUT/glut.h>
#include <QtWidgets>
#include <QGLWidget>

#include "window.h"
#include <kvs/qt/Screen>
#include <kvs/HydrogenVolumeData>
#include <kvs/StructuredVolumeObject>
#include <kvs/RayCastingRenderer>

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QTextEdit>
#include <QString>
#include <QListWidget>
#include <kvs/TransferFunction>

#include "kunscreen.h"

//! [0]
Window::Window( kvs::qt::Application* app )
{
    // Initial object and renderer
    kvs::StructuredVolumeObject* object = new kvs::HydrogenVolumeData( kvs::Vec3ui( 64, 64, 64 ) );
    object->setName( "Object" );
    kvs::glsl::RayCastingRenderer* renderer = new kvs::glsl::RayCastingRenderer();
    renderer->setName( "renderer" );

    // Text Window
    QTextEdit* text = new QTextEdit;
    text->setMinimumSize( 200, 100 );
    text->setCursorWidth( 0 );
    QString str = "This is Kun Box \n";
    str += "This is very easy";
    text->setText( str );

    // Main rendering window
    m_screen = new kun::kunScreen( app );
    m_screen->registerObject( object, renderer );
    m_screen->setMinimumSize( 512, 512 );
    m_screen->setBackgroundColor( kvs::RGBColor( 255, 255, 255 ) );

    // Transfer function editor 1D
    m_editor_1d = new kun::TransferFunctionEditor1D( m_screen );
    m_editor_1d->setVolumeObject( object );
    kvs::TransferFunction tfunc( 256 );
    m_editor_1d->setTransferFunction( tfunc );
    m_screen->setTransferFunctionEditor1D( m_editor_1d );

    // Sliders
    xSlider = createSlider();
    ySlider = createSlider();
    zSlider = createSlider();
    xSlider->setValue( 255 );
    ySlider->setValue( 255 );
    zSlider->setValue( 255 );
    QLabel* sliderRed = new QLabel( "BG_R" );
    QLabel* sliderGreen = new QLabel( "BG_G" );
    QLabel* sliderBlue = new QLabel( "BG_B" );
    QObject::connect(xSlider, SIGNAL(valueChanged(int)), m_screen, SLOT(setBackgroundColorRed(int)) );
    QObject::connect(ySlider, SIGNAL(valueChanged(int)), m_screen, SLOT(setBackgroundColorGreen(int)));
    QObject::connect(zSlider, SIGNAL(valueChanged(int)), m_screen, SLOT(setBackgroundColorBlue(int)));

    // Buttons
    QPushButton* button1 = new QPushButton( "Open" );
    QPushButton* button2 = new QPushButton( "Background" );
    QPushButton* button3 = new QPushButton( "TF" );
    QObject::connect( button1, SIGNAL( clicked() ), m_screen, SLOT( openKVSMLFile() ) );
    QObject::connect( button2, SIGNAL( clicked() ), m_screen, SLOT( chooseBackgroundColor() ) );
    // QObject::connect( button3, SIGNAL( clicked() ), qApp, SLOT(quit()) );
    QObject::connect( button3, SIGNAL( clicked() ), this, SLOT( show1DTFEditor() ) );

    // Label
    QLabel* label = new QLabel( "Created by Kun. All rights reserved");
    label->setFont( QFont("Times", 12, QFont::Bold) );

    // Layout
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget( button1 );
    buttonLayout->addWidget( button2 );
    buttonLayout->addWidget( button3 );

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget( m_screen, 0, 0 );
    mainLayout->addLayout( buttonLayout, 1, 0 );
    mainLayout->addWidget( xSlider, 0, 1, 2, 1 );
    mainLayout->addWidget( ySlider, 0, 2, 2, 1 );
    mainLayout->addWidget( zSlider, 0, 3, 2, 1 );
    mainLayout->addWidget( label, 2, 0, 1, 1 );
    mainLayout->addWidget( sliderRed, 2, 1, 1, 1 );
    mainLayout->addWidget( sliderGreen, 2, 2, 1, 1 );
    mainLayout->addWidget( sliderBlue, 2, 3, 1, 1 );
    mainLayout->addWidget( text, 3, 0, 3, 1 );
    setLayout(mainLayout);

    m_screen->show();

    setWindowTitle(tr("Kun Window"));
}

QSlider *Window::createSlider()
{
    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setRange( 0, 255 );
    slider->setSingleStep( 1 );
    slider->setPageStep( 15 );
    slider->setTickInterval( 15 );
    slider->setTickPosition(QSlider::TicksRight);
    return slider;
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == kvs::Key::O )
        m_screen->openKVSMLFile();
    else
        QWidget::keyPressEvent(event);
}

void Window::show1DTFEditor()
{
    static bool is1DTFEditorShown = false;

    if( !is1DTFEditorShown )
    {
        m_editor_1d->show();
        is1DTFEditorShown = true;
    }
    else
    {
        m_editor_1d->hide();
        is1DTFEditorShown = false;
    }
}
