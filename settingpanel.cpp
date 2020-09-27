#include "settingpanel.h"
#include "ui_settingpanel.h"
#include "settingdata.h"
#include <QMessageBox>
#include <QDebug>

SettingPanel::SettingPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPanel) {
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    ui->hotkeyEdit->installEventFilter(this);
    ui->hotkeyEdit->setReadOnly(true);
    disconnect(SettingData::shortcut, SIGNAL(activated()), 0, 0);
    delete SettingData::shortcut;
    refresh();
}

SettingPanel::~SettingPanel() {
    delete ui;
}

void SettingPanel::refresh() {
    ui->hotkeyCKB->setChecked(SettingData::isHotkey);

    ui->hotkeyEdit->setEnabled(ui->hotkeyCKB->isChecked());

    ui->hotkeyEdit->setText(SettingData::hotkeyStr);

    ui->autosaveCKB->setChecked(SettingData::isAutoSave);

    ui->heroCKB->setChecked(SettingData::isHero);

    ui->ampSpinBox->setValue(SettingData::ampLV);

    ui->erRefoSpinBox->setValue(SettingData::earring_refoLV);

    ui->refineSpinBox->setValue(SettingData::refineLV);

    ui->reformSpinBox->setValue(SettingData::reformLV);

    ui->wpRefoSpinBox->setValue(SettingData::weapon_refoLV);

    ui->bufferCKB->setChecked(SettingData::isBuffer);

    ui->buffAtkSpinBox->setEnabled(ui->bufferCKB->isChecked());

    ui->buffAttrSpinBox->setEnabled(ui->bufferCKB->isChecked());

    ui->buffAtkSpinBox->setValue(SettingData::bufferAtk);

    ui->buffAttrSpinBox->setValue(SettingData::bufferAttr);

    ui->antiELESpinBox->setValue(SettingData::antiELE);

    ui->guardELESpinBox->setValue(SettingData::guardELE);

    ui->sysBufferComboBox->clear();
    ui->sysBufferComboBox->addItem(tr("无"));
    ui->sysBufferComboBox->addItem(tr("95版本"));
    ui->sysBufferComboBox->addItem(tr("100版本"));
    ui->sysBufferComboBox->setCurrentIndex(SettingData::sysBufferIdx);

    ui->comboBox->clear();

    for (int i = 0; i < SettingData::vec.size(); ++i) {
        ui->comboBox->addItem(SettingData::vec.at(i).name);
    }

    auto setLayout = [ = ](const AttrData ad) {
        if (ad.indungeon) ui->isInLbl->setText(tr("进图生效"));
        else ui->isInLbl->setText(tr("站街生效"));
        ui->STRSpinBox->setValue(ad.STR);
        ui->INTSpinBox->setValue(ad.INT);
        ui->PATKSpinBox->setValue(ad.P_ATK);
        ui->MATKSpinBox->setValue(ad.M_ATK);
        ui->IATKSpinBox->setValue(ad.I_ATK);
        ui->ELESpinBox->setValue(ad.ELE);
        ui->activeLSpinBox->setValue(ad.activeL);
        ui->activeRSpinBox->setValue(ad.activeR);
        ui->activeCSpinBox->setValue(ad.activeC);
        ui->passiveLSpinBox->setValue(ad.passiveL);
        ui->passiveRSpinBox->setValue(ad.passiveR);
        ui->passiveCSpinBox->setValue(ad.passiveC);
    };

    setLayout(SettingData::vec.at(ui->comboBox->currentIndex()));

    connect(ui->comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated), [ = ](int index) {
        setLayout(SettingData::vec.at(index));
    });
}

void SettingPanel::closeEvent(QCloseEvent *event) {
    SettingData::shortcut = new MyGlobalShortCut(SettingData::hotkeyStr, SettingData::mw);
    connect(SettingData::shortcut, SIGNAL(activated()), SettingData::mw, SLOT(hotkeyActivated()));
    emit windowClosed();
}

bool SettingPanel::eventFilter(QObject *obj, QEvent *event) {
    if (qobject_cast<QLineEdit *>(obj) == ui->hotkeyEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *e = static_cast<QKeyEvent *>(event);
        int uKey = e->key();
        Qt::Key key = static_cast<Qt::Key>(uKey);
        if (key == Qt::Key_unknown) {
            //nothing {unknown key}
        }

        if (key == Qt::Key_Control || key == Qt::Key_Shift || key == Qt::Key_Alt ) {
            return true;
        }

        //获取修饰键(Ctrl,Alt,Shift)的状态
        Qt::KeyboardModifiers modifiers = e->modifiers();
        //判断某个修饰键是否被按下
        if (modifiers & Qt::ShiftModifier)
            uKey += Qt::SHIFT;
        if (modifiers & Qt::ControlModifier)
            uKey += Qt::CTRL;
        if (modifiers & Qt::AltModifier)
            uKey += Qt::ALT;

        //popup information
        ui->hotkeyEdit->setText(QKeySequence(uKey).toString(QKeySequence::NativeText));
        return true;
    } else {
        return false;
        //return QMainWindow::eventFilter(obj, event);
    }
}

void SettingPanel::on_hotkeyCKB_stateChanged(int arg1) {
    ui->hotkeyEdit->setEnabled(ui->hotkeyCKB->isChecked());
}

void SettingPanel::on_saveBtn_clicked() {
    SettingData::isHotkey = ui->hotkeyCKB->isChecked();

    SettingData::hotkeyStr = ui->hotkeyEdit->text();

    SettingData::isAutoSave = ui->autosaveCKB->isChecked();

    SettingData::isHero = ui->heroCKB->isChecked();

    SettingData::ampLV = ui->ampSpinBox->value();

    SettingData::earring_refoLV = ui->erRefoSpinBox->value();

    SettingData::refineLV = ui->refineSpinBox->value();

    SettingData::reformLV = ui->reformSpinBox->value();

    SettingData::weapon_refoLV = ui->wpRefoSpinBox->value();

    SettingData::isBuffer = ui->bufferCKB->isChecked();

    SettingData::bufferAtk = ui->buffAtkSpinBox->value();

    SettingData::bufferAttr = ui->buffAttrSpinBox->value();

    SettingData::antiELE = ui->antiELESpinBox->value();

    SettingData::guardELE = ui->guardELESpinBox->value();

    SettingData::sysBufferIdx = ui->sysBufferComboBox->currentIndex();

    SettingData::savefile();
}

void SettingPanel::on_exitBtn_clicked() {
    this->close();
}

void SettingPanel::on_modifyBtn_clicked() {
    int idx = ui->comboBox->currentIndex();
    SettingData::vec[idx].STR = ui->STRSpinBox->value();
    SettingData::vec[idx].INT = ui->INTSpinBox->value();
    SettingData::vec[idx].P_ATK = ui->PATKSpinBox->value();
    SettingData::vec[idx].M_ATK = ui->MATKSpinBox->value();
    SettingData::vec[idx].I_ATK = ui->IATKSpinBox->value();
    SettingData::vec[idx].ELE = ui->ELESpinBox->value();
    SettingData::vec[idx].activeL = ui->activeLSpinBox->value();
    SettingData::vec[idx].activeR = ui->activeRSpinBox->value();
    SettingData::vec[idx].activeC = ui->activeCSpinBox->value();
    SettingData::vec[idx].passiveL = ui->passiveLSpinBox->value();
    SettingData::vec[idx].passiveR = ui->passiveRSpinBox->value();
    SettingData::vec[idx].passiveC = ui->passiveCSpinBox->value();
    QMessageBox::information(NULL, "DNF面板自动分析", "当前打造已修改，但设置文件尚未保存");
}

void SettingPanel::on_bufferCKB_stateChanged(int arg1) {
    ui->buffAtkSpinBox->setEnabled(ui->bufferCKB->isChecked());
    ui->buffAttrSpinBox->setEnabled(ui->bufferCKB->isChecked());
}

void SettingPanel::on_recoverBtn_clicked() {
    QMessageBox::StandardButton result = QMessageBox::information(NULL, "还原默认值", "你确定要把设置还原为默认值吗？", QMessageBox::Yes | QMessageBox::No);
    switch (result) {
    case QMessageBox::Yes: {
        QFile out("./setting.ini");
        if (!out.open(QIODevice::WriteOnly | QIODevice::Text)) {
            //qDebug() << "Can't open the file!" << endl;
            QMessageBox::critical(NULL, "错误", "设置文件打开失败");
        } else {
            QTextStream outstream(&out);
            QFile in("://resources/default.ini");
            if (!in.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::critical(NULL, "错误", "资源文件解包失败");
            } else {
                QTextStream instream(&in);
                forever {
                    QString line = instream.readLine();
                    if (line.isEmpty()) break;
                    outstream << line << endl;
                }
                in.close();
            }
            out.close();
            SettingData::readfile();
            refresh();
            QMessageBox::information(NULL, "DNF面板自动分析", "设置已还原为默认值");
        }
    }
    break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}
