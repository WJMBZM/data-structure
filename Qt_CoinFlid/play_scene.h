#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H



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
#include <QStyle>

#include <QMap>
#include <QVector>

#include <QSoundEffect>
#include <QAudioDevice>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

#include "mycoin_button.h"
#include "mypushbutton2.h"
#include "dataconfig.h"

class MyCoin_Button;

#include <QMainWindow>

namespace Ui {
class Play_Scene;
}

class Play_Scene : public QMainWindow
{
    Q_OBJECT

public:
//    explicit Play_Scene(QWidget *parent = nullptr);
    ~Play_Scene();

    explicit Play_Scene(QWidget *parent = nullptr,int num=0);

    int num;
    void paintEvent(QPaintEvent*);

    static bool IsWin(QMap< QString  , MyCoin_Button* >);

//    MyCoin_Button* array_MyCoin_btn[4][4]; //也可以用 按钮指针 二维数组来代替 QMap 实现功能

    bool win_flag;


signals:
    void show_last_scene();
//    void Is_win();

private:
    Ui::Play_Scene *ui;
};

#endif // PLAY_SCENE_H
