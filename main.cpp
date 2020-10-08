#include "mainwindow.h"
#include <settingdata.h>
#include <QApplication>
#include <QDebug>
#include <MyGlobalShortCut/MyGlobalShortCut.h>
#include <QFile>
#include <QFileInfo>
#define LOG_FILE_KEEP_NUM 7

QFile *file;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    //#4 joint string
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString logMsg;

    switch (type) {
    case QtDebugMsg:
        logMsg = QString("%1: [Debug]: %2  Function: %3  File: %4  Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtInfoMsg:
        logMsg = QString("%1: [Info]: %2  Function: %3  File: %4  Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtWarningMsg:
        logMsg = QString("%1: [Warning]: %2 Function: %3 File: %4 Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtCriticalMsg:
        logMsg = QString("%1: [Critical]: %2 Function: %3 File: %4 Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtFatalMsg:
        logMsg = QString("%1: [Fatal]: %2 Function: %3 File: %4 Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        abort();
        break;
    default:
        break;
    }

    //#5 log message out to file
    QTextStream ts(file);
    ts << logMsg;
}

int main(int argc, char *argv[]) {
    //#1 create directory that name is log
    QDir dir("log");
    if (!dir.exists()) {
        QDir dir;
        dir.mkdir("log");
    }

    //#2 create log file by current date ==> eg:log20170418.txt
    QString currentDate = QDateTime::currentDateTime().toString("yyyyMMdd");
    QString logName = "log" + currentDate + ".txt";
    QString logFileName = "log/" + logName;

    //#3 Keep a journal for the last one week.
    if (!QFile::exists(logFileName)) {
        QFileInfoList fileList = dir.entryInfoList(QStringList() << "*.txt", QDir::NoFilter, QDir::Time);
        if (fileList.size() >= LOG_FILE_KEEP_NUM) {
            int i = 1;
            foreach (QFileInfo fileInfo, fileList) {
                if (i >= LOG_FILE_KEEP_NUM) {
                    QString fileName = fileInfo.absoluteFilePath();
                    QFile::remove(fileName);
                }
                i++;
            }
        }
    }

    file = new QFile(logFileName);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Append)) {
        file->close();
        return 1;
    }

    qInstallMessageHandler(myMessageOutput);
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    QFont font("simsun");
    font.setPixelSize(14);
    a.setFont(font);
    qInfo() << "DNFInfoAnalyser start up. Trying to load the MainWindow.";
    MainWindow w;
    int res = a.exec();
    //w.show();
    file->close();
    delete file;
    return res;
}
