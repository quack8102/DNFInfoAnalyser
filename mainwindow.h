#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "userinfowindow.h"
#include "settingpanel.h"
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    void hotkeyActivated();

  private slots:
    void on_refreshButton_clicked();

    void on_grabButton_clicked();

    void on_topButton_clicked();

    void on_openBtn_clicked();

    void actionActivated();

    void childWindowClosed();

  private:
    Ui::MainWindow *ui;
    void addDNF(const HWND &hwnd);
    void refresh();
    void grabDNFWindow(const HWND &hwnd);
    void readImg(cv::Mat &inMat, const QString &path);
    template <typename T>
    void readCSV(QVector<T> &vec, const QString &path);
    void addEquipment(const QString &name);
    void addWeapon(const QString &name);
    void showChildWindow(const cv::Mat &srcImg, bool mode);
    void activeTray(QSystemTrayIcon::ActivationReason reason);
    QImage drawChar(const QString &str, const QImage &triangle);
    QImage drawText(const QString &str);

    QSystemTrayIcon *mainTray;
    QMenu *mainMenu;
    QMenu *windowMenu;
    QAction *grabAction;
    QAction *openAction;
    QAction *setAction;
    QAction *updateAction;
    QAction *exitAction;
    SettingPanel *sp;
};

#endif // MAINWINDOW_H
