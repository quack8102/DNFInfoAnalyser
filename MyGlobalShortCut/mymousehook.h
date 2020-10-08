#ifndef MYMOUSEHOOK_H
#define MYMOUSEHOOK_H
#include <QObject>
#include <functional>
#ifdef Q_OS_WIN
#include "Windows.h"

class MyMouseHook {
  public:
    MyMouseHook();
    void installHook();
    void unInstallHook();
    static std::function<void()> fun;
};
#endif
#endif // MYMOUSEHOOK_H
