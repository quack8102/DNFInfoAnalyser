
// Qt 升级到5.x版本后
// QAbstractEventDispatcher 中函数发生变动
// 导致libqxt库中的qxtGlobalShortcut挂掉
// 参考qxtGlobalShortcut写了一个全局热键类
// 用法与qxtGlobalShortcut一致
// 在 Win8.1 + Qt5.11 下能正常使用
// by 迷路君 2014.03.27

#pragma once
#include <QApplication>
#include <windows.h>
#include <MyGlobalShortCut/MyWinEventFilter.h>
#include <QKeySequence>
#include <QHash>

class MyGlobalShortCut : public QObject
{
    Q_OBJECT
public:


    MyGlobalShortCut(QString key,QObject* app);
    ~MyGlobalShortCut();
    void activateShortcut();
    bool registerHotKey();
    bool unregisterHotKey();
    QHash<QPair<quint32, quint32>, MyGlobalShortCut*> shortcuts;
private:
    QApplication *m_app;
    MyWinEventFilter *m_filter;
    QKeySequence m_key;
    Qt::Key key;
    Qt::KeyboardModifiers mods;
    static quint32 nativeKeycode(Qt::Key keycode);
    static quint32 nativeModifiers(Qt::KeyboardModifiers modifiers);
signals:
    void activated();

};
