#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1 = startTimer(1000);
    id2 = startTimer(2000);


    static std::shared_ptr<QTimer>timer = std::make_shared<QTimer>(this);
//    QTimer* timer = new QTimer(this);
//    std::shared_ptr<QTimer>timer = new QTimer(this);
    (timer)->setSingleShot(false);
    (timer)->start(500);
//    timer = std::static_pointer_cast<QTimer*>(timer);

//    QTimer* timer1 = timer;
//    QTimer* timer2 = qobject_cast<QTimer*>(timer);

//    QTimer* timer2 = &(*timer); //该处可行
    connect(&(*timer) ,&QTimer::timeout,this,[=]()
    {
        static int i = 1;
        ui->label_5->setText(QString::number(i++));
    });

    connect(ui->btn_pause,&QPushButton::clicked,&(* timer),[]()
    {
        timer->setSingleShot(true);
    });
    connect(ui->btn_continue,&QPushButton::clicked,&(* timer),[]()
    {
        timer->setSingleShot(false);
        timer->start(500);
    });

    //*******************************************重要：事件筛选器需要实现安装*************************************************
    ui->label->installEventFilter(this);
    ui->label_2->installEventFilter(this);



}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject* obj,QEvent* event)
{
    if( (event->type() == QMouseEvent::MouseButtonPress) && ( (static_cast<QMouseEvent*> (event) )->button() == Qt::LeftButton )
             )
    {
        qDebug() << "eventFilter 过滤器中 按下了鼠标";
        return true;
    }

    return QWidget::eventFilter(obj,event);

}

//bool MyLabel::eventFilter(QObject* obj,QEvent* event)
//{
//    if( (event->type() == QMouseEvent::MouseButtonPress) && ( (static_cast<QMouseEvent*> (event) )->button() == Qt::LeftButton )
//            )
//    {
//        qDebug() << "eventFilter 过滤器中 按下了鼠标";
//        return true;
//    }

//    return QLabel::eventFilter(obj,event);

//}




void Widget::timerEvent(QTimerEvent* timer_ev)
{
  //    ui->label_3->addAction("1");

    if(timer_ev->timerId() == id1)
    {
        static int i1 = 1;
        ui->label_3->setText(QString::number(i1++));

    }
    if(timer_ev->timerId() == id2)
    {
        static int i2 = 1;
        ui->label_4->setText(QString::number(i2++));
    }

}








