//
//  kunscreen.cpp
//
//
//  Created by Kun Zhao on 2014-10-16 15:44:59.
//
//

#include "kunscreen.h"
#include <kvs/RGBColor>
#include <kvs/Background>
#include <QString>
#include <QFileDialog>
#include <kvs/StructuredVolumeObject>
#include <kvs/StructuredVolumeImporter>
#include <kvs/UnstructuredVolumeObject>
#include <kvs/UnstructuredVolumeImporter>
#include <kvs/PointObject>
#include <kvs/PointImporter>
#include <kvs/RayCastingRenderer>
#include <kvs/StochasticTetrahedraRenderer>
#include <kvs/PointRenderer>
#include <kvs/ObjectManager>
#include <kvs/RendererManager>
#include <kvs/XMLDocument>
#include <Core/FileFormat/KVSML/KVSMLTag.h>

#include <QColorDialog>
#include <QColor>

namespace kun
{

void kunScreen::setBackgroundColorRed( int red )
{
    m_red = red;
    m_green = this->scene()->background()->color().g();
    m_blue = this->scene()->background()->color().b();

    this->setBackgroundColor( kvs::RGBColor( m_red, m_green, m_blue ) );
    this->redraw();
}

void kunScreen::setBackgroundColorGreen( int green )
{
    m_red = this->scene()->background()->color().r();
    m_green = green;
    m_blue = this->scene()->background()->color().b();

    this->setBackgroundColor( kvs::RGBColor( m_red, m_green, m_blue ) );
    this->redraw();
}

void kunScreen::setBackgroundColorBlue( int blue )
{
    m_red = this->scene()->background()->color().r();
    m_green = this->scene()->background()->color().g();
    m_blue = blue;

    this->setBackgroundColor( kvs::RGBColor( m_red, m_green, m_blue ) );
    this->redraw();
}

void kunScreen::openKVSMLFile()
{
    QString qFilename =  QFileDialog::getOpenFileName(this, tr("Open Volume Data"), "~/", tr("KVSML Files (*.kvsml)"));
    if( !qFilename.isEmpty() )
    {
        std::string filename = qFilename.toStdString();
        std::string objectName = "Object";
        std::string rendererName = "renderer";
        std::string DataType = this->checkDataType( filename );

        kvs::ObjectBase* object = NULL;
        kvs::RendererBase* renderer = NULL;
        if( DataType == "StructuredVolumeObject" )
        {
            object = new kvs::StructuredVolumeImporter( filename );
            renderer = new kvs::glsl::RayCastingRenderer();
            std::cout << "Input the Structured Volume Object." << std::endl;
        }
        if( DataType == "UnstructuredVolumeObject" )
        {
            object = new kvs::UnstructuredVolumeImporter( filename );
            renderer = new kvs::StochasticTetrahedraRenderer();
            std::cout << "Input the Unstructured Volume Object (only support tetrahedra data)." << std::endl;
        }
        if( DataType == "Point" )
        {
            object = new kvs::PointImporter( filename );
            renderer = new kvs::PointRenderer();
            std::cout << "Input the Point Object." << std::endl;
        }

        object->setName( objectName );
        renderer->setName( rendererName );

        this->scene()->replaceObject( objectName, object );
        this->scene()->replaceRenderer( rendererName, renderer );
        this->scene()->reset();

        this->redraw();
    }
}

void kunScreen::chooseBackgroundColor()
{
    int red = this->scene()->background()->color().r();
    int green = this->scene()->background()->color().g();
    int blue = this->scene()->background()->color().b();
    QColor color_origin( red, green, blue );
    QColor color = QColorDialog::getColor( color_origin, this, tr("Choose Background Color") );
    this->setBackgroundColor( kvs::RGBColor( color.red(), color.green(), color.blue() ) );
    this->redraw();
}

std::string kunScreen::checkDataType( std::string filename )
{
    kvs::XMLDocument xml( filename );
    kvs::kvsml::KVSMLTag kvsml_tag;
    kvsml_tag.read( &xml );
    return kvsml_tag.node()->FirstChild()->FirstChild()->Value();
}

} // end of namespace kun
