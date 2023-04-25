#include "choose_level_scene.h"
#include "ui_choose_level_scene.h"



choose_level_scene::choose_level_scene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_level_scene)
{
    ui->setupUi(this);

    QMediaPlayer* back_player = new QMediaPlayer(this);
    QAudioOutput* media_audioOutput = new QAudioOutput(this);
    back_player->setAudioOutput(media_audioOutput);
    back_player->setSource(QUrl("qrc:/res/BackButtonSound.wav"));

    QMediaPlayer* choose_player = new QMediaPlayer(this);
    QAudioOutput* media_audioOutput1 = new QAudioOutput(this);
    choose_player->setAudioOutput(media_audioOutput1);
    choose_player->setSource(QUrl("qrc:/res/TapButtonSound.wav"));

    this->setFixedSize(320,588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡");

    QMenuBar* menu = new QMenuBar(this);
    menu->setFixedSize(this->width(),22);
//    QStyle* style = new QStyle();
//    menu->setStyle();
    QMenu* file_menu = menu->addMenu("文件");
    QAction* quit_action = file_menu->addAction("退出");
    connect(quit_action,&QAction::triggered,this,&QWidget::close);

//    MyPushButton2* turn_back_btn = new MyPushButton2();
//    turn_back_btn->setParent(this);
    MyPushButton2*  turn_back_btn = new MyPushButton2(this,":/res/BackButton.png",":/res/BackButtonSelected.png");
    turn_back_btn->move(this->width()-turn_back_btn->width(),this->height()-turn_back_btn->height());

//    connect(turn_back_btn,&QPushButton::clicked,this,[=]()
//    {
//        QTimer::singleShot(100,this,[=]()
//        {

//            turn_back_btn->setIcon(QIcon(turn_back_btn->Press_Image_Path));
// //            turn_back_btn->setIconSize()
//        });
//        QTimer::singleShot(1000,this,[=](){
//        this->hide();
//        emit hide1();
//        });
//    });
    connect(turn_back_btn,&QPushButton::released,this,[=]()
    {
        back_player->play();

        QTimer::singleShot(200,this,[=]()
        {
            this->hide();
            emit show_last_scene();
        });

    });

    Play_Scene* play_scene = NULL;

    for (int i = 0; i < 20; i++)
    {
//        static std::shared_ptr<QPushButton>level_num = std::make_shared<QPushButton>(this);
        MyPushButton* level_num_btn = new MyPushButton(this,":/res/LevelIcon.png");
        level_num_btn->move(30+i%4*70,130+i/4*70);

        QLabel* label = new QLabel(this);
        label->move(30+i%4*70,130+i/4*70);
        label->setFixedSize(level_num_btn->width(),level_num_btn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

        connect(level_num_btn,&QPushButton::clicked,this,[=]()mutable
        {
            choose_player->play();

            QTimer* timer = new QTimer(this);
            timer->setSingleShot(true);
            timer->start(500);
            level_num_btn->animation3();
            level_num_btn->animation4();

            QString str = QString("您选择了第%1关").arg(i+1);
            qDebug() << str;

            connect(timer,&QTimer::timeout,this,[=]()mutable
            {
                play_scene = new Play_Scene(this,i+1);
                this->hide();

                play_scene->setGeometry(this->geometry());
                play_scene->show();

                connect(play_scene,&Play_Scene::show_last_scene,this,/*&QWidget::show*/[=]()mutable
                {
                    this->setGeometry(play_scene->geometry());
                    this->show();
                    delete(play_scene);
                    play_scene = nullptr;
                });
            });
        });

        //    connect(start_btn,&QPushButton::clicked,this,[=]()
        //    {
        //        QTimer* timer = new QTimer(this);
        //        timer->setSingleShot(true);
        //        timer->start(500);
        //        std::cout << QString("点击了打开按钮").toLocal8Bit().data() << std::endl;
        //        start_btn->animation1();
        //        start_btn->animation2();

        //        connect(timer,&QTimer::timeout,this,[=]()
        //        {
        //            this->hide();
        //            scene->show();
        //        });


    }




}




void choose_level_scene::paintEvent(QPaintEvent* paint_event)
{
    QPixmap pixmap;
    pixmap.load(":/res/OtherSceneBg.png");

    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);


    QPixmap pixmap2;
    pixmap2.load(":/res/Title.png");
    painter.drawPixmap( ( this->width()-pixmap2.width() ) * 0.5,10,pixmap2);

}

choose_level_scene::~choose_level_scene()
{
    delete ui;
}
