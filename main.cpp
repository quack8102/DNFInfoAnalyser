#include "mainwindow.h"
#include <QApplication>
#include <MyGlobalShortCut/MyGlobalShortCut.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    QFont font;
    font.setFamily("宋体");
    font.setPixelSize(14);
    a.setFont(font);
    MainWindow w;
    //w.show();
    return a.exec();
}
