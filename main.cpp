#include "mainwindow.h"
#include <QApplication>
#include <MyGlobalShortCut/MyGlobalShortCut.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    MainWindow w;
    MyGlobalShortCut *shortcut = new MyGlobalShortCut("F2", &w);
    QObject::connect(shortcut, SIGNAL(activated()), &w, SLOT(hotkeyActivated()));
    //w.show();
    return a.exec();
}
