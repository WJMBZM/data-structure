#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void after_class();
//    {
//        emit tc->hungry();
//    }
    void after_class(QString);
//    void after_class(const char* cs);
    void after_class1();


private:
    Ui::Widget *ui;

    Teacher * tc;
    Student * st;


};
#endif // WIDGET_H
