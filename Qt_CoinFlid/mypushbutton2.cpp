#include "mypushbutton2.h"
#include "ui_mypushbutton2.h"

MyPushButton2::MyPushButton2(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::MyPushButton2)
{
    ui->setupUi(this);

    QPixmap pixmap;
    pixmap.load(":/res/BackButtonSelected.png");

    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

}

MyPushButton2::MyPushButton2(QWidget *parent /*= nullptr*/,QString Normal_Image, QString Press_Image):
    QPushButton(parent),Normal_Image_Path(Normal_Image),Press_Image_Path(Press_Image),
    ui(new Ui::MyPushButton2)
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

bool MyPushButton2::event(QEvent* event)
{
    if(event->type() == QMouseEvent::MouseButtonPress )
    {
        this->setIcon(QIcon(this->Press_Image_Path));
    }

    if(event->type() == QMouseEvent::MouseButtonRelease)
    {
        this->setIcon(QIcon(this->Normal_Image_Path));
  //        return true;
  //        this->hide();
  //        emit this->hide1();
    }
    return QPushButton::event(event);
}



MyPushButton2::~MyPushButton2()
{
    delete ui;
}
