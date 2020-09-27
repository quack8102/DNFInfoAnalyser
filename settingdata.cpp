#include "settingdata.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

AttrData::AttrData(const QStringList &li) {
    this->name = li.value(0, "");
    this->indungeon = (li.value(1, "0").toInt() == 1);
    this->STR = li.value(2, "0").toInt();
    this->INT = li.value(3, "0").toInt();
    this->P_ATK = li.value(4, "0").toInt();
    this->M_ATK = li.value(5, "0").toInt();
    this->I_ATK = li.value(6, "0").toInt();
    this->ELE = li.value(7, "0").toInt();
    this->passiveL = li.value(8, "0").toInt();
    this->passiveR = li.value(9, "0").toInt();
    this->passiveC = li.value(10, "0").toInt();
    this->activeL = li.value(11, "0").toInt();
    this->activeR = li.value(12, "0").toInt();
    this->activeC = li.value(13, "0").toInt();
}

QString AttrData::toQString() {
    QStringList li;
    li << this->name << (this->indungeon ? "1" : "0") << QString::number(this->STR) << QString::number(this->INT)
       << QString::number(this->P_ATK) << QString::number(this->M_ATK) << QString::number(this->I_ATK) << QString::number(this->ELE)
       << QString::number(this->passiveL) << QString::number(this->passiveR) << QString::number(this->passiveC)
       << QString::number(this->activeL) << QString::number(this->activeR) << QString::number(this->activeC);
    return li.join(",");
}

void AttrData::operator () (Character &model) {
    if (!indungeon) {
        if (model.isPhy) model.attr += STR;
        else model.attr += INT;
        if (model.isInd) model.atk += I_ATK;
        else if (model.isPhy) model.atk += P_ATK;
        else model.atk += M_ATK;
        model.addAllElementOUT(ELE);
        model.addPassiveLevelOUT(passiveL, passiveR, passiveC);
        model.addActiveLevelOUT(activeL, activeR, activeC);
    } else {
        if (model.isInd) model.inatk += I_ATK;
        else if (model.isPhy) model.inatk += P_ATK;
        else model.inatk += M_ATK;
        model.addAllElementIN(ELE);
        model.addPassiveLevelIN(passiveL, passiveR, passiveC);
        model.addActiveLevelIN(activeL, activeR, activeC);
    }
}

QString SettingData::hotkeyStr = "";
bool SettingData::isHotkey = false, SettingData::isAutoSave = false, SettingData::isHero = false, SettingData::isBuffer = false;
int SettingData::ampLV = 0, SettingData::reformLV = 0, SettingData::weapon_refoLV = 0, SettingData::refineLV = 0, SettingData::earring_refoLV = 0;
int SettingData::bufferAttr = 0, SettingData::bufferAtk = 0, SettingData::sysBufferIdx = 0, SettingData::antiELE = 0, SettingData::guardELE = 0;
QVector<AttrData> SettingData::vec;
MyGlobalShortCut *SettingData::shortcut = NULL;
MainWindow *SettingData::mw = NULL;

void SettingData::readfile() {
    vec.clear();
    QFile file("./setting.ini");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //qDebug() << "Can't open the file!" << endl;
        QMessageBox::critical(NULL, "错误", "设置文件读取失败");
    } else {
        QTextStream stream(&file);
        //stream.setCodec("UTF-8");
        QStringList li = stream.readLine().split(",");
        hotkeyStr = li.value(0, "F2");
        isHotkey = (li.value(1, "1").toInt() == 1);
        isAutoSave = (li.value(2, "1").toInt() == 1);
        isHero = (li.value(3, "1").toInt() == 1);
        ampLV = li.value(4, "10").toInt();
        reformLV = li.value(5, "5").toInt();
        weapon_refoLV = li.value(6, "12").toInt();
        refineLV = li.value(7, "8").toInt();
        earring_refoLV = li.value(8, "12").toInt();
        isBuffer = (li.value(9, "1").toInt() == 1);
        bufferAttr = li.value(10, "50000").toInt();
        bufferAtk = li.value(11, "3000").toInt();
        sysBufferIdx = li.value(12, "2").toInt();
        antiELE = li.value(13, "0").toInt();
        guardELE = li.value(14, "15").toInt();
        forever {
            QString line = stream.readLine();
            if (line.isEmpty()) break;
            vec.push_back(AttrData(line.split(",")));
        }
        file.close();
    }
}
void SettingData::savefile() {
    QFile file("./setting.ini");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //qDebug() << "Can't open the file!" << endl;
        QMessageBox::critical(NULL, "错误", "设置文件打开失败");
    } else {
        QTextStream stream(&file);
        //stream.setCodec("UTF-8");
        QStringList li;
        li << hotkeyStr << (isHotkey ? "1" : "0") << (isAutoSave ? "1" : "0") << (isHero ? "1" : "0")
           << QString::number(ampLV) << QString::number(reformLV) << QString::number(weapon_refoLV)
           << QString::number(refineLV) << QString::number(earring_refoLV)
           << (isBuffer ? "1" : "0") << QString::number(bufferAttr) << QString::number(bufferAtk)
           << QString::number(sysBufferIdx) << QString::number(antiELE) << QString::number(guardELE);
        stream << li.join(",") << endl;
        for (AttrData ad : vec) {
            stream << ad.toQString() << endl;
        }
        file.close();
        QMessageBox::information(NULL, "DNF面板自动分析", "设置文件保存成功");
    }
}