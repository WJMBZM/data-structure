#include "mylabel2.h"

MyLabel2::MyLabel2(QWidget *parent)
    : QLabel(parent)
{


}

bool MyLabel2::event(QEvent* event)
{

    if(event->type() == QMouseEvent::Enter)
    {
        qDebug() << "鼠标进入了该区域";
    }
    if(event->type() == QEvent::Leave)
    {
        qDebug() << "鼠标退出了该区域";
    }
    if(event->type() == QEvent::MouseMove)
    {
        qDebug() << "鼠标移动了";
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        qDebug() << "鼠标松开了";
    }

    if(event->type()==QMouseEvent::MouseButtonPress)
    {
        qDebug() << "按下了鼠标";
        return true;//此处的返回 true 代表用户自行处理该项事件，不向下分发
    }
    return QLabel::event(event);
}


//   不知道为何 这个标签里边无法使用  事件过滤器
//   需要安装时间过滤器
bool MyLabel2::eventFilter(QObject* obj,QEvent* event)
{
    if( (event->type() == QMouseEvent::MouseButtonPress) && ( (static_cast<QMouseEvent*> (event) )->button() == Qt::LeftButton )  )
    {
        qDebug() << "eventFilter 过滤器中 按下了鼠标";
        return true;
    }

    return QLabel::eventFilter(obj,event);

}
