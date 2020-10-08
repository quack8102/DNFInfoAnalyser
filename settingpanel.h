#ifndef SETTINGPANEL_H
#define SETTINGPANEL_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class SettingPanel;
}

class SettingPanel : public QWidget {
    Q_OBJECT

  public:
    explicit SettingPanel(QWidget *parent = nullptr);
    ~SettingPanel();

  private:
    Ui::SettingPanel *ui;
    void refresh();

  protected:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

  signals:
    void settingPanelClosed();
  private slots:
    void on_saveBtn_clicked();
    void on_exitBtn_clicked();
    void on_modifyBtn_clicked();
    void on_bufferCKB_stateChanged(int arg1);
    void on_recoverBtn_clicked();
    void on_hotkeyCMB_currentIndexChanged(int index);
};

#endif // SETTINGPANEL_H
