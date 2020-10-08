#include "messagewindow.h"
#include "ui_messagewindow.h"
#include "settingdata.h"

MessageWindow::MessageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWindow) {
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    //setWindowOpacity(0.8);

    ui->label->setOpenExternalLinks(true);
}

MessageWindow::~MessageWindow() {
    delete ui;
}

void MessageWindow::setMessage(const QString &str) {
    ui->label->setText(str);
}

void MessageWindow::on_pushButton_clicked() {
    close();
}

void MessageWindow::closeEvent(QCloseEvent *event) {
    SettingData::messageWindow = NULL;
}
