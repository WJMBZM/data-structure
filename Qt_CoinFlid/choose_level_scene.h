#ifndef CHOOSE_LEVEL_SCENE_H
#define CHOOSE_LEVEL_SCENE_H

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

#include <QSoundEffect>
#include <QAudioDevice>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

#include "mypushbutton2.h"
#include "play_scene.h"
#include "mypushbutton.h"

#include <QMainWindow>

namespace Ui {
class choose_level_scene;
}

class choose_level_scene : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose_level_scene(QWidget *parent = nullptr);
    ~choose_level_scene();



    void paintEvent(QPaintEvent*);
//    bool event(QEvent*);

//    MyPushButton2* turn_back_btn;

signals:
    void show_last_scene();

private:
    Ui::choose_level_scene *ui;
};

#endif // CHOOSE_LEVEL_SCENE_H
