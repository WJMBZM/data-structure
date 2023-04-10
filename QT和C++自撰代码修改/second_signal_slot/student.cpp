#include "student.h"
#include <QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{



}


void Student::treat()
{
    qDebug() << "请老师吃饭" ;



}

void Student::treat(const QString& s)
{
    //qDebug() << "请老师吃:" <</* (char*) */s;
    //qDebug() << "请老师吃:" <<(const char*) s.toUtf8();
    qDebug() << "请老师吃:" << s.toUtf8().data();  //toUtf8() 函数 可以将QString转为 QByteArray 在通过 data（）函数转为char*
}

//void Student::treat(QString s)
//{
//    //qDebug() << "请老师吃:" <</* (char*) */s;
//    //qDebug() << "请老师吃:" <<(const char*) s.toUtf8();
//    qDebug() << "请老师吃:" << s.toUtf8().data();  //toUtf8() 函数 可以将QString转为 QByteArray 在通过 data（）函数转为char*
//}










