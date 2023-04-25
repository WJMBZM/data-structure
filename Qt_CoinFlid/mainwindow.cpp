#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSoundEffect>
#include <QAudioDevice>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

//extern MyPushButton2* turn_back_btn;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QMediaPlayer *m_player = nullptr;
//    QAudioOutput *m_audioOutput = nullptr;
//    QVideoWidget *m_videoWidget = nullptr;

//    m_player = new QMediaPlayer(this);
//    m_audioOutput = new QAudioOutput(this);
//    m_videoWidget = new QVideoWidget(this);
//    m_videoWidget->resize(500, 260);
//    m_player->setAudioOutput(m_audioOutput);
//    m_player->setVideoOutput(m_videoWidget);


//  //    QAudioDevice play_device;
//  //    play_device.mode(QAudioDevice::Output);
//    QSoundEffect* sound = new QSoundEffect(this);
//  //    QAudioDevice* Audio_Device = new QAudioDevice();
//    sound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));
//  //    sound->setSource(QUrl("qrc:/res/Dans la maison.mp3"));
//    QAudioOutput* audioOutput = new QAudioOutput(this);
//    sound->setAudioDevice();
//    sound->play();

    //****************************看MP4播放器就看这里***************************************
//    QMediaPlayer *media_player = nullptr;
//    QAudioOutput *media_audioOutput = nullptr;
//    QVideoWidget *media_videoWidget = nullptr;
//    media_player = new QMediaPlayer(this);
//    media_audioOutput = new QAudioOutput(this);
//    media_videoWidget = new QVideoWidget(this);
//    media_videoWidget->resize(0, 0);
//    media_player->setAudioOutput(media_audioOutput);
//    media_player->setVideoOutput(media_videoWidget);
//    //        media_player->setSource(QUrl::fromLocalFile(":/res/Dans la maison.mp3"));
//    media_player->setSource(QUrl("qrc:/res/Dans la maison.mp3"));
//    //"qrc:/res/Dans la maison.mp3"
//    //"D:/QT++/blackhorse/Qt_CoinFlid/Qt_CoinFlid/res/Dans la maison.mp3"
//    media_player->play();


    //****************************看MP3播放器就看这里***************************************
//    QMediaPlayer *media_player1 = nullptr;
//    QAudioOutput *media_audioOutput1 = nullptr;
    QMediaPlayer* start_player1 = new QMediaPlayer(this);
    QAudioOutput* media_audioOutput1 = new QAudioOutput(this);
    start_player1->setAudioOutput(media_audioOutput1);
    start_player1->setSource(QUrl("qrc:/res/TapButtonSound.wav"));//qrc:/res/TapButtonSound.wav
    start_player1->setLoops(2);

//    media_player1->play();



//        QMediaPlayer* player = new QMediaPlayer(this);
//        QAudioOutput* audioOutput = new QAudioOutput(this);
//        QVideoWidget* videoWidget = new QVideoWidget(this);
//        videoWidget->resize(500, 260);
//        player->setAudioOutput(audioOutput);
//        player->setVideoOutput(videoWidget);
//        player->setSource(QUrl("D:/QT++/blackhorse/Qt_CoinFlid/Qt_CoinFlid/res/Dans la maison.mp3"));
//        player->play();

//        player = new QMediaPlayer(this);
//        audioOutput = new QAudioOutput(this);
//        videoWidget = new QVideoWidget(this);
//        videoWidget->resize(500, 260);
//        player->setAudioOutput(audioOutput);
//        player->setVideoOutput(videoWidget);
//        player->setSource(QUrl(":/video.mp4"));
//        player->play();


//    QTimer* timer = new QTimer(this);
//    timer->singleShot(10000,timer,[=]()
//    {
//        media_player->stop();
//    });



//    QToolBar* toolbar = new QToolBar(this);
//    this->addToolBar(Qt::LeftToolBarArea,toolbar);
    this->setFixedSize(320,588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币游戏");

//    QMenu* file_menu = ui->menubar->addAction("文件");
    QMenu * FileMenu = this->menuBar()->addMenu("文件");
    QAction* open = FileMenu->addAction("打开");
    QAction* Action_quit = FileMenu->addAction("退出");

    connect(Action_quit,&QAction::triggered,this,&QWidget::close);

    MyPushButton* start_btn = new MyPushButton(this,":/res/MenuSceneStartButton.png");
    start_btn->move(this->width()*0.5 - start_btn->width()*0.5,this->height()*0.7);

    choose_level_scene* scene = new choose_level_scene(this);

    connect(start_btn,&QPushButton::clicked,this,[=]()
    {
        start_player1->play();



        QTimer* timer = new QTimer(this);
        timer->setSingleShot(true);
        timer->start(500);
        std::cout << QString("点击了打开按钮").toLocal8Bit().data() << std::endl;
        start_btn->animation1();
        start_btn->animation2();

        connect(timer,&QTimer::timeout,this,[=]()
        {
            this->hide();
            scene->setGeometry(this->geometry());
            scene->show();

        });


    });
    connect(scene,/*&QWidget::hide*/ &choose_level_scene::show_last_scene,this,/*&QWidget::show*/[=]()
    {
        this->setGeometry(scene->geometry());
        this->show();
    });

//    connect(scene->turn_back_btn,&QPushButton::clicked,this,[=]()
//    {
//        this->show();
//    });


}

void MainWindow::paintEvent(QPaintEvent* paint_event)
{
    QPixmap pixmap;
    pixmap.load(":/res/PlayLevelSceneBg.png");
    QPainter painter(this);

    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

    QPixmap pixmap2;
    pixmap2.load(":/res/Title.png");
    pixmap2 = pixmap2.scaled(pixmap2.width() * 0.5 , pixmap2.height() * 0.5 );
    painter.drawPixmap(10,30,pixmap2);


}

//bool MainWindow::Event(QEvent* event)
//{
//    if(event->type() == QMouseEvent::MouseButtonPress )
//    {
//  //        start_btn->move(this->width()*0.5 - start_btn->width()*0.5,this->height()*0.7);

//    }
//}

//bool MainWindow::eventFilter(QObject* obj,QEvent* event)
//{
//    if(obj->)


//}


MainWindow::~MainWindow()
{
    delete ui;
}

