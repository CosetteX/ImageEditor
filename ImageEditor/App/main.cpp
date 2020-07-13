#include "View/mainwindow.h"
#include "app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    App app;
    app.Run();

    return a.exec();
}
