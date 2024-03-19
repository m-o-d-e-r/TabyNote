#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("Fusion");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    MainWindow w;
    w.show();

    return app.exec();
}
