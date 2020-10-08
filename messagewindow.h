#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QWidget>

namespace Ui {
class MessageWindow;
}

class MessageWindow : public QWidget {
    Q_OBJECT

  public:
    explicit MessageWindow(QWidget *parent = nullptr);
    ~MessageWindow();
    void setMessage(const QString &str);

  protected:
    void closeEvent(QCloseEvent *event);

  private slots:
    void on_pushButton_clicked();

  private:
    Ui::MessageWindow *ui;
};

#endif // MESSAGEWINDOW_H
