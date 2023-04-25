#ifndef MYLABEL_H
#define MYLABEL_H

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

#include <QWidget>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

//    using QWidget::leaveEvent;
    void enterEvent(QEnterEvent* );
//    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* );

    void mouseMoveEvent(QMouseEvent* );
    void mousePressEvent(QMouseEvent* );
    void mouseReleaseEvent(QMouseEvent* );

    bool event(QEvent*);
//    bool eventFilter(QObject* obj,QEvent* event);



signals:

private:
    using QWidget::leaveEvent;

};

#endif // MYLABEL_H
