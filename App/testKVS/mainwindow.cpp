#include <GL/glew.h>
#include <GLUT/glut.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <kvs/qt/Screen>
#include <kvs/HydrogenVolumeData>
#include <kvs/StructuredVolumeObject>
#include <kvs/RayCastingRenderer>

#include "kunscreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    kvs::StructuredVolumeObject* object = new kvs::HydrogenVolumeData( kvs::Vec3ui( 64, 64, 64 ) );
    object->setName( "Object" );
    kvs::glsl::RayCastingRenderer* renderer = new kvs::glsl::RayCastingRenderer();
    renderer->setName( "renderer" );
    ui->widget_2->registerObject( object, renderer );
    ui->widget_2->setMinimumSize( 512, 512 );
    ui->widget_2->setBackgroundColor( kvs::RGBColor( 255, 255, 255 ) );

}

MainWindow::~MainWindow()
{
    delete ui;
}
