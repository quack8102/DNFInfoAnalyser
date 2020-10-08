#include "mymousehook.h"
#include <QDebug>
#include <settingdata.h>
#ifdef Q_OS_WIN
MyMouseHook::MyMouseHook() {}
std::function<void()> MyMouseHook::fun;
static HHOOK mouseHook = nullptr;
LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && SettingData::hotkeyType == 1) { //当nCode等于HC_ACTION时，要求得到处理
        if (wParam == WM_LBUTTONDOWN && SettingData::hotkeyStr == "LeftButton") {
            MyMouseHook::fun();
        } else if (wParam == WM_RBUTTONDOWN && SettingData::hotkeyStr == "RightButton") {
            MyMouseHook::fun();
        } else if (wParam == WM_MBUTTONDOWN && SettingData::hotkeyStr == "MidButton") {
            MyMouseHook::fun();
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam); //否则，如果返回给下一个钩子子程处理
}

void MyMouseHook::unInstallHook() {
    if (mouseHook != nullptr) {
        UnhookWindowsHookEx(mouseHook);
        mouseHook = nullptr;
        //qDebug() << "hook deleted";
    }
}

void MyMouseHook::installHook() {
    mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, nullptr, 0);
    //qDebug() << "hook created";
}
#endif
