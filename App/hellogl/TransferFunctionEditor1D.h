//
//  TransferFunctionEditor1D.h
//
//
//  Created by Kun Zhao on 2014-10-22 17:24:43.
//
//

#ifndef KUN__TRANSFERFUNCTIONEDITOR1D_H_INCLUDE
#define KUN__TRANSFERFUNCTIONEDITOR1D_H_INCLUDE
 
#include <kvs/qt/Screen>
#include <kvs/glut/TransferFunctionEditor>

namespace kun
{

class TransferFunctionEditor1D : public kvs::glut::TransferFunctionEditor
{
public:
	TransferFunctionEditor1D( kvs::qt::Screen* screen );
	void apply();
};

	
} // end of namespace kun

 
#endif // KUN__TRANSFERFUNCTIONEDITOR1D_H_INCLUDE