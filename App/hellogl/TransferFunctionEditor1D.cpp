//
//  TransferFunctionEditor1D.cpp
//
//
//  Created by Kun Zhao on 2014-10-22 12:20:47.
//
//

#include "TransferFunctionEditor1D.h"
#include <kvs/RendererBase>
#include <kvs/RendererManager>
#include <kvs/RayCastingRenderer>

namespace kun
{

TransferFunctionEditor1D::TransferFunctionEditor1D( kvs::qt::Screen* screen ):
	kvs::glut::TransferFunctionEditor( screen ){}

void TransferFunctionEditor1D::apply()
{
	kvs::RendererBase* r = static_cast<kvs::qt::Screen*>( screen() )->scene()->rendererManager()->renderer();
	kvs::glsl::RayCastingRenderer* renderer = static_cast<kvs::glsl::RayCastingRenderer*>( r );
	renderer->setTransferFunction( transferFunction() );
	screen()->redraw();
}

} // end of namespace kun