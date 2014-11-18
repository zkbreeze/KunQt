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
#include <kvs/RendererBase>
#include <kvs/RendererManager>
#include <kvs/RayCastingRenderer>

#include <QColorDialog>
#include <QColor>
#include <kvs/OrthoSlice>
#include <kvs/PolygonObject>
#include <kvs/transferFunction>
#include <kvs/PolygonRenderer>

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
		std::string objectName = "object";
		std::string rendererName = "renderer";
		std::string DataType = this->checkDataType( filename );

		kvs::StructuredVolumeObject* object = NULL;
		kvs::RendererBase* renderer = NULL;
		if( DataType == "StructuredVolumeObject" )
		{
			object = new kvs::StructuredVolumeImporter( filename );
			renderer = new kvs::glsl::RayCastingRenderer();
			std::cout << "Input the Structured Volume Object." << std::endl;
		}
		// if( DataType == "UnstructuredVolumeObject" )
		// {
		// 	object = new kvs::UnstructuredVolumeImporter( filename );
		// 	renderer = new kvs::StochasticTetrahedraRenderer();
		// 	std::cout << "Input the Unstructured Volume Object (only support tetrahedra data)." << std::endl;
		// }
		// if( DataType == "Point" )
		// {
		// 	object = new kvs::PointImporter( filename );
		// 	renderer = new kvs::PointRenderer();
		// 	std::cout << "Input the Point Object." << std::endl;
		// }

		object->setName( objectName );
		renderer->setName( rendererName );

		this->setBaseVolume( object );
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

void kunScreen::drawSliceX( int x )
{
	kvs::OrthoSlice::AlignedAxis a = kvs::OrthoSlice::XAxis;
	float range = m_volume->maxObjectCoord().x() - m_volume->minObjectCoord().x();
	float location = ( x / 255.0 ) * range + m_volume->minObjectCoord().x();
	kvs::PolygonObject* object = new kvs::OrthoSlice( m_volume, location, a, m_editor_1d->transferFunction() );

	kvs::PolygonRenderer* renderer = new kvs::PolygonRenderer();

	std::string objectName = "slice_x";
	std::string rendererName = "renderer";

	object->setName( objectName );
	renderer->setName( rendererName );

	if( this->scene()->hasObject( "volume" ) ) this->scene()->replaceObject( "volume", object, false );
	else if( !this->scene()->hasObject( objectName ) ) this->registerObject( object );
	else if( this->scene()->hasObject( objectName ) ) this->scene()->replaceObject( objectName, object, false );
	object->setXform( this->scene()->objectManager()->object( "line" )->xform() );

	this->scene()->replaceRenderer( rendererName, renderer, true );
	this->redraw();
}

void kunScreen::drawSliceY( int y )
{
	kvs::OrthoSlice::AlignedAxis a = kvs::OrthoSlice::YAxis;
	float range = m_volume->maxObjectCoord().y() - m_volume->minObjectCoord().y();
	float location = ( y / 255.0 ) * range + m_volume->minObjectCoord().y();
	kvs::PolygonObject* object = new kvs::OrthoSlice( m_volume, location, a, m_editor_1d->transferFunction() );

	kvs::PolygonRenderer* renderer = new kvs::PolygonRenderer();

	std::string objectName = "slice_y";
	std::string rendererName = "renderer";

	object->setName( objectName );
	renderer->setName( rendererName );

	if( this->scene()->hasObject( "volume" ) ) this->scene()->replaceObject( "volume", object, false );
	else if( !this->scene()->hasObject( objectName ) ) this->registerObject( object );
	else if( this->scene()->hasObject( objectName ) ) this->scene()->replaceObject( objectName, object, false );
	object->setXform( this->scene()->objectManager()->object( "line" )->xform() );

	this->scene()->replaceRenderer( rendererName, renderer, true );
	this->redraw();
}

void kunScreen::drawSliceZ( int z )
{
	kvs::OrthoSlice::AlignedAxis a = kvs::OrthoSlice::ZAxis;
	float range = m_volume->maxObjectCoord().z() - m_volume->minObjectCoord().z();
	float location = ( z / 255.0 ) * range + m_volume->minObjectCoord().z();
	kvs::PolygonObject* object = new kvs::OrthoSlice( m_volume, location, a, m_editor_1d->transferFunction() );

	kvs::PolygonRenderer* renderer = new kvs::PolygonRenderer();

	std::string objectName = "slice_z";
	std::string rendererName = "renderer";

	object->setName( objectName );
	renderer->setName( rendererName );

	if( this->scene()->hasObject( "volume" ) ) this->scene()->replaceObject( "volume", object, false );
	else if( !this->scene()->hasObject( objectName ) ) this->registerObject( object );
	else if( this->scene()->hasObject( objectName ) ) this->scene()->replaceObject( objectName, object, false );
	object->setXform( this->scene()->objectManager()->object( "line" )->xform() );

	this->scene()->replaceRenderer( rendererName, renderer, true );
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