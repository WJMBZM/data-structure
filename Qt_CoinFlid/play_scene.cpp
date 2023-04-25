#include "play_scene.h"
#include "ui_play_scene.h"

//Play_Scene::Play_Scene(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::Play_Scene)
//{
//    ui->setupUi(this);
//}

Play_Scene::Play_Scene(QWidget *parent, int num) :
    QMainWindow(parent),num(num),
    ui(new Ui::Play_Scene)
{
    ui->setupUi(this);

    QMediaPlayer* back_player = new QMediaPlayer(this);
    QAudioOutput* media_audioOutput = new QAudioOutput(this);
    back_player->setAudioOutput(media_audioOutput);
    back_player->setSource(QUrl("qrc:/res/BackButtonSound.wav"));

    QMediaPlayer* play_player = new QMediaPlayer(this);
    QAudioOutput* play_media_audioOutput = new QAudioOutput(this);
    play_player->setAudioOutput(play_media_audioOutput);
    play_player->setSource(QUrl("qrc:/res/ConFlipSound.wav"));

    QMediaPlayer* win_player = new QMediaPlayer(this);
    QAudioOutput* win_media_audioOutput = new QAudioOutput(this);
    win_player->setAudioOutput(win_media_audioOutput);
    win_player->setSource(QUrl("qrc:/res/LevelWinSound.wav"));

    QString str = QString("您选择了第%1关").arg(num);
    qDebug() << str;

    setWindowTitle("翻金币游戏场景");
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setFixedSize(320,588);

    QMenuBar* menu_bar = new QMenuBar(this);
    menu_bar->setFixedSize(this->width(),22);
    QMenu* file_menu = menu_bar->addMenu("文件");
    QAction* action_quit = file_menu->addAction("退出");
    connect(action_quit,&QAction::triggered,this,&QWidget::close);

    MyPushButton2* turn_back_btn = new MyPushButton2(this,":/res/BackButton.png",":/res/BackButtonSelected.png");
    turn_back_btn->move(this->width()-turn_back_btn->width(),this->height()-turn_back_btn->height());
    connect(turn_back_btn,&MyPushButton2::released,this,[=]()
    {
        back_player->play();

        QTimer::singleShot(200,this,[=]()
        {
//            this->hide();
            emit show_last_scene();
        });
    });

    QLabel* label = new QLabel(this);
//    label->setParent(this);
    label->move(30,this->height()-50);
    label->resize(120,50);
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(20);
    font.setBold(true);

    label->setFont(font);
//    int c = label->colorCount();
    label->setText(QString("Level:%1").arg(num));

    dataConfig data_config;

    int data_array[4][4];

//    using btn_array = int *[];
//    using btn_arrats = int
//    QMap<QVector<QVector<int>> /*btn_array*/, MyCoin_Button* >MyCoin_button_map;
//    QVector<QVector<int>>MyCoin_btn_key_y /*= new QVector<QVector<int>>()*/;
//    QVector<int>MyCoin_btn_key_x;

    QMap< QString  , MyCoin_Button* >MyCoin_button_map;

    for (int i = 0; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            QLabel* label = new QLabel(this);
            label->setPixmap(QPixmap(":/res/BoardNode(1).png"));
//            label->resize(50,50);
            label->setGeometry(0,0,50,50);
            label->move(57+50*i,200+50*j);
            label->setAttribute(Qt::WA_TransparentForMouseEvents);

            data_array[i][j]=data_config.mData[num][i][j];

//            QString coin_color_gold(":/res/Coin0001.png");
//            QString coin_color_silver(":/res/Coin0008.png");
            QString coin_color;
            if(data_array[i][j] ==1)
            {
                coin_color = ":/res/Coin0001.png";

            }
            else
            {
                coin_color = ":/res/Coin0008.png";
            }

            MyCoin_Button* MyCoin_btn = new MyCoin_Button(this,/*":/res/Coin0001.png"*/ coin_color);
            MyCoin_btn->move(59+50*i,202+50*j);
//            MyCoin_btn->installEventFilter(this);

            MyCoin_btn->position_row = i;
            MyCoin_btn->position_column = j;
            MyCoin_btn->flip_flag = data_array[MyCoin_btn->position_row][MyCoin_btn->position_column];
//            MyCoin_btn->data_array[i][j]=data_array[i][j];

//            MyCoin_btn_key_x.push_back(MyCoin_btn->position_x);
//            MyCoin_button_map.insert( MyCoin_btn_key_y ,MyCoin_btn);
//            qDebug() << MyCoin_button_map[ MyCoin_btn_key_y ]->position_x;
//            qDebug() << MyCoin_button_map[ MyCoin_btn_key_y ]->position_y;
            QString str_MyCoin_btn_num = QString("%1-%2").arg(MyCoin_btn->position_row).arg(MyCoin_btn->position_column);
            MyCoin_button_map.insert(str_MyCoin_btn_num,MyCoin_btn);

            connect(MyCoin_btn,&QPushButton::clicked,[=]()
            {
//               MyCoin_btn->coin_clicked_flip();
                play_player->play();
//               data_array[][]=



            });



        }
//        MyCoin_btn_key_y.push_back(MyCoin_btn_key_x);


    }

    QLabel* animation_label = new QLabel;
    animation_label->setParent(this);
    QPixmap pixmap;
    pixmap.load(":/res/LevelCompletedDialogBg.png");
//    animation_label->setGeometry(0,0,pixmap.width(),pixmap.height());
    animation_label->setFixedSize(pixmap.width(),pixmap.height());
    animation_label->setPixmap(pixmap);
    animation_label->move(( this->width() - pixmap.width() ) * 0.5 ,-pixmap.height());

    for(int row = 0; row < 4 ; row++)
    {

        for(int column = 0 ; column < 4 ; column++)
        {
            connect(MyCoin_button_map[QString("%1-%2").arg(row).arg(column)],&QPushButton::clicked,this,
                    [=]()
            {

                MyCoin_Button* MyCoin_btn2 = MyCoin_button_map[QString("%1-%2").arg(row).arg(column)];

//                qDebug() << MyCoin_btn2->data_array[row][column];

                MyCoin_btn2->coin_clicked_flip();
                if(MyCoin_btn2->position_column>0)
                {
                    QString str = QString("%1-%2").arg(MyCoin_btn2->position_row).arg(MyCoin_btn2->position_column-1);
                    MyCoin_button_map[str]->coin_clicked_flip();
                }
                if(MyCoin_btn2->position_column<3)
                {
                    QString str = QString("%1-%2").arg(MyCoin_btn2->position_row).arg(MyCoin_btn2->position_column+1);
                    MyCoin_button_map[str]->coin_clicked_flip();
                }
                if(MyCoin_btn2->position_row>0)
                {
                    QString str = QString("%1-%2").arg(MyCoin_btn2->position_row-1).arg(MyCoin_btn2->position_column);
                    MyCoin_button_map[str]->coin_clicked_flip();
                }
                if(MyCoin_btn2->position_row<3)
                {
                    QString str = QString("%1-%2").arg(MyCoin_btn2->position_row+1).arg(MyCoin_btn2->position_column);
                    MyCoin_button_map[str]->coin_clicked_flip();
                }
                win_flag = this->IsWin(MyCoin_button_map);
                if(win_flag)
                {
                    win_player->play();

                    QMessageBox::information(this,"你获得了胜利!","恭喜！您获得了胜利!");
//                    emit this->Is_win();
                    QPropertyAnimation* animation = new QPropertyAnimation(animation_label,"geometry");
                    animation->setStartValue( QVariant( QRect( ( ( this->width() - pixmap.width() ) * 0.5 ),-pixmap.height()
                                                        ,pixmap.width() , pixmap.height() ) ));
                    animation->setEndValue( QVariant( QRect( ( ( this->width() - pixmap.width() ) * 0.5 ),pixmap.height()+200
                                                             ,pixmap.width() , pixmap.height() ) ) );
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    animation->setDuration(1000);
                    animation->start();



                    for(int row1 = 0; row1 < 4 ; row1++)
                    {

                        for(int column1 = 0 ; column1 < 4 ; column1++)
                        {
                            MyCoin_button_map[QString("%1-%2").arg(row1).arg(column1)]->Is_win = true;
                        }
                    }

                }



            });



        }
    }

//    qDebug() << MyCoin_button_map[MyCoin_btn_key_y]->position_x ;




}

void Play_Scene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

    QPixmap pixmap2;
    pixmap2.load(":/res/Title.png");
    pixmap2 = pixmap2.scaled(pixmap2.width()*0.5,pixmap2.height()*0.5);
    painter.drawPixmap(/*( this->width()-pixmap2.width() )*0.5,10*/10,30,pixmap2.width(),pixmap2.height(),pixmap2);


}

bool Play_Scene::IsWin(QMap<QString, MyCoin_Button*> MyCoin_button_map)
{
    for(int row = 0 ; row < 4 ;row++)
    {
        for(int column = 0 ; column < 4 ; column++)
        {
            if(MyCoin_button_map[QString("%1-%2").arg(row).arg(column)]->flip_flag == 0)
            {
                return false;
            }
        }
    }
    return true;
}

Play_Scene::~Play_Scene()
{
    delete ui;
}
