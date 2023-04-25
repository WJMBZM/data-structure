#include "mycoin_button.h"
#include "ui_mycoin_button.h"

#include "play_scene.h"

//MyCoin_Button::MyCoin_Button(QWidget *parent) :
//    QPushButton(parent),
//    ui(new Ui::MyCoin_Button)
//{
//    ui->setupUi(this);

//}

MyCoin_Button::MyCoin_Button(QWidget *parent,QString img_str) :
    QPushButton(parent),img_str(img_str),Is_win(false),
    ui(new Ui::MyCoin_Button)
{
    ui->setupUi(this);

    QPixmap pixmap;
//    pixmap.load(":/res/Coin0001.png");
    pixmap.load(img_str);
    this->setFixedSize(pixmap.width(),pixmap.height());
//    this->move(57,200);
    this->setIcon(pixmap);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

    //    this->installEventFilter(this);
//    connect()



}

void MyCoin_Button::coin_clicked_flip()noexcept
{
//    static int map_min = 1;
//    static int map_max = 8;
    map_min = 1;
    map_max = 8;
    if(this->flip_flag==1)
    {
//        static QTimer* flip_gold_timer = new QTimer;
        flip_gold_timer = new QTimer;
        flip_gold_timer->setParent(this);
        flip_gold_timer->start(30);
        IsAnimation = true;
        flip_flag = 0;
        connect(flip_gold_timer,&QTimer::timeout,this,[&]()mutable
        {
           QString img_path = QString(":/res/Coin000%1.png").arg(map_min++);
           QPixmap pixmap;
           pixmap.load(img_path);
           pixmap.save(img_path);
           this->setIcon(pixmap);
//           this->setIcon(QIcon(img_path));
           if( map_min>map_max)
           {
               flip_gold_timer->stop();
               IsAnimation = false;
               map_min = 1 ;
               delete(flip_gold_timer);
               flip_gold_timer = nullptr;
           }
        });

    }
//    if(this->flip_flag==0)
    else
    {
//        static QTimer* flip_silver_timer = new QTimer(this);
        flip_silver_timer = new QTimer(this);
        flip_silver_timer->start(30);
        IsAnimation = true;
        flip_flag = 1;
        connect(flip_silver_timer,&QTimer::timeout,this,[&]()mutable
        {
           QString img_path = QString(":/res/Coin000%1.png").arg(map_max--);
           QPixmap pixmap;
           pixmap.load(img_path);
           pixmap.save(img_path);
           this->setIcon(pixmap);
           if( map_max <map_min)
           {
               flip_silver_timer->stop();
               IsAnimation = false;
               map_max = 8 ;
               delete(flip_silver_timer);
               flip_silver_timer = nullptr;
           }
        });

    }
//    this->installEventFilter(this);



}

//bool MyCoin_Button::Event(QEvent* event)
//{
//    if(IsAnimation == true &&
//            ( event->type() == QEvent::MouseButtonPress || event->type() == QMouseEvent::MouseButtonRelease ))
//    {
//        return true;
//    }
//    return QPushButton::event(event);

//}

void MyCoin_Button::mousePressEvent(QMouseEvent* event)
{
    if(IsAnimation == true || this->Is_win)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(event);
    }

}


MyCoin_Button::~MyCoin_Button()
{
    delete ui;
}
