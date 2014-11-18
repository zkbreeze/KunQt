//
//  kunscreen.h
//
//
//  Created by Kun Zhao on 2014-10-16 15:41:50.
//
//
	
#ifndef KUN__KUNSCREEN_H_INCLUDE
#define KUN__KUNSCREEN_H_INCLUDE
 
#include <kvs/qt/Application>
#include <kvs/qt/Screen>
#include "TransferFunctionEditor1D.h"
#include <kvs/StructuredVolumeObject>

namespace kun
{

class kunScreen : public kvs::qt::Screen
{
	Q_OBJECT;

	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;

	kun::TransferFunctionEditor1D* m_editor_1d;
	kvs::StructuredVolumeObject* m_volume;

public:

	kunScreen();
	kunScreen( kvs::qt::Application* app ): kvs::qt::Screen( app ){};
	~kunScreen(){};

	void setTransferFunctionEditor1D( kun::TransferFunctionEditor1D* editor ){ m_editor_1d = editor; }
	void setBaseVolume( kvs::StructuredVolumeObject* volume ) { m_volume = volume; }

public slots:
	void setBackgroundColorRed( int red );
	void setBackgroundColorGreen( int green );
	void setBackgroundColorBlue( int blue );
	void openKVSMLFile();
	void chooseBackgroundColor();
	void drawSliceX( int x );
	void drawSliceY( int y );
	void drawSliceZ( int z );

private:
	std::string checkDataType( std::string filename );

};

} // end of namespace kun

 
#endif // KUN__KUNSCREEN_H_INCLUDE