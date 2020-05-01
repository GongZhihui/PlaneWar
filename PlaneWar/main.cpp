#include "MainScene.h"
#include <QtWidgets/QApplication>
#include <qresource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QResource::registerResource(a.applicationDirPath() + SKIN_PATH);


    MainScene w;
    w.show();
    return a.exec();
}
