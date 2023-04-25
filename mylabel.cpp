#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent)
{

}

void MyLabel::enterEvent(QEnterEvent* )
{
    qDebug()<<"鼠标进入了该区域";
}

void MyLabel::leaveEvent(QEvent* )
{
    qDebug()<<"鼠标离开了该区域";
}

void MyLabel::mouseMoveEvent(QMouseEvent* ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
    qDebug()<<"移动了鼠标";
    }
}

void MyLabel::mousePressEvent(QMouseEvent* ev)
{
    QString str = QString("按下了鼠标 x=%1 , y=%2 , %3 , %4").arg(ev->x()).arg((ev->y())).arg(ev->globalX()).arg(ev->globalY());

    qDebug()<< str ;
}

void MyLabel::mouseReleaseEvent(QMouseEvent* ev)
{
    if(ev->button()==Qt::LeftButton)
    {
    qDebug()<<"释放了鼠标";
    }

}

bool MyLabel::event(QEvent* event)
{

//    if(event->type() == QMouseEvent::Enter)
//    {
//        qDebug() << "鼠标进入了该区域";
//    }
//    if(event->type() == QEvent::Leave)
//    {
//        qDebug() << "鼠标退出了该区域";
//    }
//    if(event->type() == QEvent::MouseMove)
//    {
//        qDebug() << "鼠标移动了";
//    }
//    if(event->type() == QEvent::MouseButtonRelease)
//    {
//        qDebug() << "鼠标松开了";
//    }

    if(event->type()==QEvent::MouseButtonPress) //QMouseEvent
    {
        qDebug() << " QEvent中 按下了鼠标";
        return true;//此处的返回 true 代表用户自行处理该项事件，不向下分发  //如果不设置该项，则事件会继续向下分发
    }
    return QLabel::event(event);
}





