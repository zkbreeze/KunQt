//
//  kunscreen.h
//
//
//  Created by Kun Zhao on 2014-10-16 15:41:50.
//
//

#ifndef KUN__KUNSCREEN_H_INCLUDE
#define KUN__KUNSCREEN_H_INCLUDE

#include <kvs/qt/Screen>

namespace kun
{

class kunScreen : public kvs::qt::Screen
{
    Q_OBJECT;

    unsigned char m_red;
    unsigned char m_green;
    unsigned char m_blue;

public:

    kunScreen(){};
    ~kunScreen(){};

public slots:
    void setBackgroundColorRed( int red );
    void setBackgroundColorGreen( int green );
    void setBackgroundColorBlue( int blue );
    void openKVSMLFile();
    void chooseBackgroundColor();

private:
    std::string checkDataType( std::string filename );
};

} // end of namespace kun


#endif // KUN__KUNSCREEN_H_INCLUDE
