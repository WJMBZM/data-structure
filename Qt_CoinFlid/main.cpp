#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//D:\QT\6.4.2\mingw_64\bin\windeployqt
//windeployqt Qt_CoinFlid.exe  //游戏打包，以及可以用 NSIS 打包成安装包
    MainWindow w;
    w.show();

    return a.exec();
}
