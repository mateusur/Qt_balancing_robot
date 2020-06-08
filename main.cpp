#include <QApplication>

#include "interfacewindow.h"
#include "connectwindow.h"

int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");

    QApplication app(argc, argv);

    interfaceWindow = new InterfaceWindow;
    connectWindow = new ConnectWindow;

    connectWindow->show();

    return app.exec();
}
