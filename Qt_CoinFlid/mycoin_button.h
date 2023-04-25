#ifndef MYCOIN_BUTTON_H
#define MYCOIN_BUTTON_H

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





#include <QWidget>



namespace Ui {
class MyCoin_Button;
}

class MyCoin_Button : public QPushButton
{
    Q_OBJECT

public:
//    explicit MyCoin_Button(QWidget *parent = nullptr);
    ~MyCoin_Button();

    explicit MyCoin_Button(QWidget *parent = nullptr,QString img_str = "");

    QString img_str;

    int position_row;
    int position_column;
    bool flip_flag;

    void coin_clicked_flip()noexcept;
    QTimer* flip_gold_timer ; /*= new QTimer(this);*/
    QTimer* flip_silver_timer ; /*= new QTimer(this);*/
    int map_min;
    int map_max;

    bool IsAnimation = false;

    void mousePressEvent(QMouseEvent*);
//    bool Event(QEvent*);

//    int data_array[4][4];
    bool Is_win ;

private:
    Ui::MyCoin_Button *ui;
};

#endif // MYCOIN_BUTTON_H
