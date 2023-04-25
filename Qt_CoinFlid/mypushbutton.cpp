#include "mypushbutton.h"
#include "ui_mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::MyPushButton)
{
    ui->setupUi(this);

}

MyPushButton::MyPushButton(QWidget *parent /*= nullptr*/,QString Normal_Image, QString Press_Image):
    QPushButton(parent),Normal_Image_Path(Normal_Image),Press_Image_Path(Press_Image),
    ui(new Ui::MyPushButton)
{
    ui->setupUi(this);

    QPixmap pixmap;
    bool ret = pixmap.load(Normal_Image_Path);
    if(!ret)
    {
        qDebug() << "加载图片失败";
    }

    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setIcon(pixmap);

    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));


}

//bool MyPushButton::event(QEvent* event)
//{

//    if(event->type() == QMouseEvent::MouseButtonPress)
//    {

//    }
//}

void MyPushButton::animation1()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QVariant(QRect(this->x(),this->y()+10,this->width(),this->height())));

    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();

//    delete(animation);
//    animation = nullptr;

}

void MyPushButton::animation2()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QVariant(QRect(this->x(),this->y(),this->width(),this->height())));

    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();

//    delete(animation);
//    animation = nullptr;

}

void MyPushButton::animation3()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QVariant( QRect(this->x(),this->y(),this->width(),this->height() ) ));
    animation->setEndValue(QVariant( QRect(this->x(),this->y()+5,this->width(),this->height() ) ));

    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::animation4()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QVariant( QRect(this->x(),this->y()+5,this->width(),this->height() ) ));
    animation->setEndValue(QVariant( QRect(this->x(),this->y(),this->width(),this->height() ) ));

    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}




MyPushButton::~MyPushButton()
{
    delete ui;
}
