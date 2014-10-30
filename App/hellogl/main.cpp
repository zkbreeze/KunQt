//
//  main.cpp
//
//
//  Created by Kun Zhao on 2014-10-17 11:54:35.
//
//

#include <kvs/qt/Application>
#include <QDesktopWidget>

#include "window.h"

int main(int argc, char *argv[])
{
    kvs::qt::Application app(argc, argv);
    Window window( &app );
    window.show();

    return app.run();
}
