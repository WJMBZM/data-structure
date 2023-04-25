#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<assert.h>
#include<float.h>
#include<ctype.h>
#include<stddef.h>
#include<errno.h>
#include<malloc.h>
#include<stddef.h>


#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<algorithm>
#include<cctype>

#include <iostream>
#include <iterator>
#include <initializer_list>
#include <stdexcept>

#include <thread>
#include <deque>
#include <numeric>
#include <utility>

#include <fstream>
#include <sstream>

#include <array>
#include <memory>
#include <functional>

#include <qmenubar.h>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QDebug>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <qstring.h>
#include <QFontDialog>
#include <QMovie>
#include <QToolButton>
#include <QAbstractButton>
// #include <onDoubleClicked>
#include <QMouseEvent>
#include <QTimer>
#include <QLabel>
#include <QEnterEvent>
#include <QTimerEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QStringConverter>
#include <QTextCodec>
#include <QFileInfo>
#include <QPropertyAnimation>


#include <QWidget>

namespace Ui {
class MyPushButton;
}

class MyPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MyPushButton(QWidget *parent = nullptr);
    ~MyPushButton();

    MyPushButton(QWidget *parent = nullptr,QString Normal_Image = "", QString Press_Image = "");

    QString Normal_Image_Path;
    QString Press_Image_Path;

    void animation1();
    void animation2();
    void animation3();
    void animation4();

//    bool event(QEvent* event);

private:
    Ui::MyPushButton *ui;
};

#endif // MYPUSHBUTTON_H
