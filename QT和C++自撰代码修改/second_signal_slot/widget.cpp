#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <QPushButton>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton * mybtn = new QPushButton("点击关闭并下课",this);
    connect(mybtn,&QPushButton::clicked,this,&Widget::close);
    mybtn->resize(100,100);
    mybtn->move(250,250);
    this->resize(600,600);


    setWindowTitle("下课吃饭");


    this->tc = new Teacher();

    this->st = new Student();

    void (Teacher:: *hungry1)() = &Teacher::hungry;
    void (Teacher:: *hungry2)(const QString&) = &Teacher::hungry;
//    void (Teacher:: *hungry2)(QString) = &Teacher::hungry;
    void (Student:: *treat1)() = &Student::treat;
//    void (Student:: *treat2)(QString) = &Student::treat;
    void (Student:: *treat2)(const QString&) = &Student::treat;
    //这里的函数指针赋值我是挺服气的
    //函数指针赋值，这里的地址居然能这么用的
    //取址符会根据前边的函数指针类型，来给对应的类内部函数声明


    //connect(tc , &Teacher::hungry ,st , &Student::treat);
    connect(tc,hungry1,st,treat1);

    after_class();


    connect(tc,hungry2,st,treat2);

    after_class("宫保鸡丁");

//    static QString Qs = "请老师吃饭";
//    qPrintable()
    QPushButton * mybtn2 = new QPushButton;
    mybtn2->setParent(this);
    mybtn2->resize(100,100);
    mybtn2->setText("请老师吃什么");
//    void (Widget::*after_class1)(QString) = &Widget::after_class; //"请老师吃饭"
//    connect(mybtn2,&QPushButton::clicked,this,&Widget::after_class1);
    connect(mybtn2,SIGNAL( QPushButton::clicked()),this,SLOT( Widget::after_class("请老师吃饭")));

    QPushButton * mybtn3 = new QPushButton;
    mybtn3->setParent(this);
    mybtn3->resize(100,50);
    mybtn3->setText("请老师吃什么2");
    mybtn3->move(500,0);
    connect(mybtn3,&QPushButton::clicked,this,&Widget::after_class1);

}

void Widget::after_class()
{
    emit tc->hungry();
}



void Widget::after_class(QString s)
{
    emit tc->hungry(s);
}

//void Widget::after_class1()
//{
//    emit tc->hungry((QString) "老师connect函数无法传参啊，还吃啥，吃麻婆豆腐吧");
//}

//void Widget::after_class1()
//{
//    emit tc->hungry((const QString) "老师connect函数无法传参啊，还吃啥，吃麻婆豆腐吧");
//}
void Widget::after_class1()
{
    emit tc->hungry((/*const*/ QString&&) "老师connect函数无法传参啊，还吃啥，吃麻婆豆腐吧");
}


//void Widget::after_class(const char *cs)
//{
//    emit tc->hungry(cs);
//}

Widget::~Widget()
{
    delete ui;
}



