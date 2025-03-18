#include "MainWindow.h"
#include "config.h"
#include "server.h"
#include <qpainter.h>
#include <QPainterPath>
#include <QMouseEvent>
#include <QtGlobal>
void MainWindow::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置窗口标题
    setWindowTitle(GAME_TITLE);
    //icon set
    setWindowIcon(QIcon(GAME_ICON));

    QTime time;
    time= QTime::currentTime();

}

void MainWindow::resetposition()//位置初始化
{
    m_hero.m_X = GAME_WIDTH * 0.5 - m_hero.m_Plane.width()*0.5;
    m_hero.m_Y = GAME_HEIGHT- m_hero.m_Plane.height();

    hero2.m_X = GAME_WIDTH * 0.5 - hero2.m_Plane.width()*0.5;
    hero2.m_Y = GAME_HEIGHT- hero2.m_Plane.height();

    m_enemy.m_X = GAME_WIDTH * 0.5 - m_enemy.m_Enemy.width()*0.5;
    m_enemy.m_Y = 0;
};

int plane1=0,plane2=0,mode=0;
int hero=1;
int press=1;//开始游戏提醒
int winflag=0;
void MainWindow::restartset()
{
    resetposition();
    m_Timer.setInterval(10000000);
    m_Timer.start();//定时器更新时间设为无限长
    press=1;//开始游戏提醒

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initScene();
    menu.show();

    auto connectstart=[&]()
    {
        link.show();
    };

//    auto fight=[&]()
//    {

//        initScene();//初始化场景
//        link.show();
//        plane1=1,plane2=1,mode=1;
//        restartset();

//    };

    auto two=[&]()
    {

        initScene();
        link.show();
        plane1=1,plane2=1,mode=0;
        restartset();
        menu.hide();
    };

    auto one=[&]()
    {

        initScene();
        this->show();
        plane1=1,plane2=0,mode=0;
        restartset();
        menu.hide();
    };

    //主机初始化
    auto start=[&]()
    {
        server=new Server();
        server->Connect(link.severport);
        initScene();
        this->show();

        restartset();
        //监听定时器
        connect(&m_Timer, &QTimer::timeout, this, &MainWindow::GameLoop1);
        hero = 1;
    };

    //客户端初始化
    auto join=[&]()
    {
        client=new Client();
        client->Connect(link.IP,link.PORT);
        initScene();
        this->show();
        restartset();
//        //启动定时器
//        m_Timer.start(1000/30);
        //监听定时器
        connect(&m_Timer, &QTimer::timeout, this, &MainWindow::GameLoop2);
        hero=0;
    };
    //开始菜单返回信号
    //connect(&menu,&startmenu::fight,this,fight);//检测到"starmenu"里的"fight"信号后执行fight()函数
    connect(&menu,&startmenu::towplayer,this,two);
    connect(&menu,&startmenu::oneplayer,this,one);
    //连接菜单返回信号
    connect(&link,&connectmenu::severconnect,this,start);
    connect(&link,&connectmenu::clientconnect,this,join);
}

MainWindow::~MainWindow()
{
}

int timer_flag = 1;

void MainWindow::playGame()
{
    //启动定时器
    m_Timer.stop();
    m_Timer.setInterval(1000/30);
    m_Timer.start();
    //boss定时器
    boss_Timer.setInterval(30);
    boss_Timer.start();

    //监听定时器
    if(timer_flag)
    {
        connect(&m_Timer, &QTimer::timeout, this, &MainWindow::do1);
        connect(&boss_Timer, &QTimer::timeout, this, &MainWindow::bossstep);
        timer_flag = 0;
    }

}

int count=1 , wayflag;
int shootcount = 60 , shootmode;

void MainWindow::bossstep()
{
    if(hero==1)
    {
        if(shootcount == 60)
        {
            shootmode = generator.bounded(1,4);
            shootcount = 0;
        }

    }
    else
    {
        shootmode = client->getShootMode();
        shootcount = 0;
    }
    shootcount++;
    if(count==1)
    {
        wayflag=generator.bounded(-2,2);
    }
    //boss轨迹随机
    if(wayflag==1)
    {
        bosstrial_X= generator.bounded(0,5);
        bosstrial_Y= generator.bounded(0,5);
    }
    if(wayflag==-1)
    {
        bosstrial_X= generator.bounded(-5,0);
        bosstrial_Y= generator.bounded(-5,0);
    }
    count++;
    if(count==20)count=1;
    if(winflag!=1)
    {
        if(hero && shootmode != 3)
        {
            m_enemy.m_X+=bosstrial_X;
            m_enemy.m_Y+=bosstrial_Y;
        }
        m_enemy.m_Rect.moveTo(m_enemy.m_X,m_enemy.m_Y);
        m_enemy.m_recorder++;
    }
    //boss边界检测
    if(m_enemy.m_X <= 0)
    {
        m_enemy.m_X = 0;
        wayflag=1;
        count=5;
    }
    if(m_enemy.m_X >= GAME_WIDTH - m_enemy.m_Rect.width())
    {
        m_enemy.m_X = GAME_WIDTH - m_enemy.m_Rect.width();
        wayflag=-1;
        count=5;
    }
    if(m_enemy.m_Y <= 0)
    {
        m_enemy.m_Y = 0;

    }
    if(m_enemy.m_Y >= GAME_HEIGHT*0.4 - m_enemy.m_Rect.height())
    {
        m_enemy.m_Y = GAME_HEIGHT*0.4 - m_enemy.m_Rect.height();

    }
    switch (shootmode)
    {
        case 1:
            m_enemy.bullet_curtain_triangular();
            break;
        case 2:
            m_enemy.bullet_curtain_round();
            break;
        case 3:
            m_enemy.bullet_curtain_spiral();
            break;
    }
}
void MainWindow::gameover_win()
{
    winflag=1;
    m_enemy.m_Enemy.load(":/res/QNL_lose.png");

}
void MainWindow::gameover_lose()
{
    winflag=2;
    m_hero.m_Plane.load(":/res/lm_lose.png");
    hero2.m_Plane.load(":/res/mls_lose.png");

}
void MainWindow::do1()
{
    //更新游戏中元素的坐标
    updatePosition();
    //重新绘制图片
    collisionDetection();
    if(hero)
    {
        if(server->getShootFlag() && plane2)
            hero2.shoot();
    }
    else
    {
        if(client->getShootFlag())
            m_hero.shoot();
    }


    if(boss_HP<=0)
        gameover_win();
    if(player_HP<=0)
        gameover_lose();
}
//碰撞箱检测
void MainWindow::collisionDetection()
{


        //遍历所有 非空闲的子弹
            for(int j = 0 ; j < HERO_BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }
            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
                if(m_enemy.m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_hero.m_bullets[j].m_free = true;
                qDebug("boss hitted");
                boss_HP--;
            }
        }

            for(int j = 0 ; j < HERO_BULLET_NUM;j++)
        {
            if(hero2.m_bullets[j].m_free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }
            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_enemy.m_Rect.intersects(hero2.m_bullets[j].m_Rect))
            {
                hero2.m_bullets[j].m_free = true;
                qDebug("boss hitted");
                boss_HP--;
            }
        }

        for(int j = 0 ; j < ENEMY_BULLET_NUM;j++)
        {
            if(m_enemy.m_bullets[j].m_free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }
            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_hero.m_Rect.intersects(m_enemy.m_bullets[j].m_Rect))
            {
                m_enemy.m_bullets[j].m_free = true;
                qDebug("plane hitted");
                player_HP--;
            }

           }
//else{
//        for(int j = 0 ; j < ENEMY_BULLET_NUM;j++)
//        {
//            if(m_enemy.m_bullets[j].m_free)
//            {
//                //空闲子弹 跳转下一次循环
//                continue;
//            }
//            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
//            if(hero2.m_Rect.intersects(m_enemy.m_bullets[j].m_Rect))
//            {
//                hero2.m_bullets[j].m_free = true;
//                qDebug("plane hitted");
//                player_HP--;
//            }
//        }
//}
}

//heroplane
void MainWindow::GameLoop1()
{

    server->sendData(m_hero.m_X,m_hero.m_Y,m_hero.shootflag,m_enemy.m_X,m_enemy.m_Y,shootmode);
    hero2.setPosition(server->getX(),server->getY());
    m_hero.shootflag = 0;
}

//hero2
void MainWindow::GameLoop2()
{

    client->sendData(hero2.m_X,hero2.m_Y,hero2.shootflag,1,1,1);
    m_hero.setPosition(client->getX(),client->getY());
    m_enemy.m_X = client->getBossX();
    m_enemy.m_Y = client->getBossY();
    hero2.shootflag = 0;
}

void MainWindow::updatePosition()
{

        //更新地图坐标
        m_map.mapPosition();
        for(int i = 0 ; i < HERO_BULLET_NUM ; i++ )
        {
            if(!m_hero.m_bullets[i].m_free)
            {
                m_hero.m_bullets[i].move();
            }
        }

        for(int i = 0 ; i < HERO_BULLET_NUM ; i++ )
        {
            if(!hero2.m_bullets[i].m_free)
            {
                hero2.m_bullets[i].move();
            }
        }

        for(int i = 0 ; i < ENEMY_BULLET_NUM ; i++ )
        {
            if(!m_enemy.m_bullets[i].m_free)
            {
                m_enemy.m_bullets[i].move();
            }
        }
        collisionDetection();
        update();

}

void MainWindow::paintEvent(QPaintEvent *event)      //绘制地图
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,0,m_map.background);
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);

    if(press)painter.drawPixmap(0,0,m_map.press);
    if(winflag==1)painter.drawPixmap(0,0 , m_map.win_picture);
    if(winflag==2)painter.drawPixmap(0,0 , m_map.lose_picture);
    if(mode)
    {
        if(hero)
        {
            painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
            painter.drawPixmap(GAME_WIDTH-hero2.m_X-(hero2.m_Plane.width()),GAME_HEIGHT-hero2.m_Y-(hero2.m_Plane.height()),hero2.m_Plane);
        }
        else
        {
            painter.drawPixmap(hero2.m_X,hero2.m_Y,hero2.m_Plane);
            painter.drawPixmap(GAME_WIDTH-m_hero.m_X-(m_hero.m_Plane.width()),GAME_HEIGHT-m_hero.m_Y-(m_hero.m_Plane.height()),m_hero.m_Plane);
        }
    }
    else
    {
        if(plane1)painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
        //if(plane2)painter.drawPixmap(GAME_WIDTH-hero2.m_X-(hero2.m_Plane.width()),GAME_HEIGHT-hero2.m_Y-(hero2.m_Plane.height()),hero2.m_Plane);
        if(plane2)painter.drawPixmap(hero2.m_X,hero2.m_Y,hero2.m_Plane);
    }
    if(!press&&!mode)
    {
        painter.drawPixmap(m_enemy.m_X , m_enemy.m_Y , m_enemy.m_Enemy);
        for(int i = 0 ; i < ENEMY_BULLET_NUM ; i++ )
        {
            if(!m_enemy.m_bullets[i].m_free)
            {
                painter.drawPixmap(m_enemy.m_bullets[i].m_X , m_enemy.m_bullets[i].m_Y , m_enemy.m_bullets[i].m_Bullet);
            }
        }
    }

    for(int i = 0 ; i < HERO_BULLET_NUM ; i++ )
    {
        if(!m_hero.m_bullets[i].m_free)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X , m_hero.m_bullets[i].m_Y , m_hero.m_bullets[i].m_Bullet);
        }
    }

    for(int i = 0 ; i < HERO_BULLET_NUM ; i++ )
    {
        if(!hero2.m_bullets[i].m_free)
        {
            painter.drawPixmap(hero2.m_bullets[i].m_X , hero2.m_bullets[i].m_Y , hero2.m_bullets[i].m_Bullet);
        }
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)    //鼠标确定飞机位置，以及联机双方位置
{
    if(winflag!=2){
    int xp = event->x() - m_hero.m_Plane.width()*0.5; //鼠标位置 - 飞机矩形的一半
    int yp = event->y() - m_hero.m_Plane.height()*0.5;
    //边界检测
    if(xp <= 0)
    {
        xp = 0;
    }
    if(xp >= GAME_WIDTH - m_hero.m_Plane.width())
    {
        xp = GAME_WIDTH - m_hero.m_Plane.width();
    }
    if(yp <= 0)
    {
        yp = 0;
    }
    if(yp >= GAME_HEIGHT - m_hero.m_Plane.height())
    {
        yp = GAME_HEIGHT - m_hero.m_Plane.height();
    }
    if(plane2==1)
        if(hero)
        {
            m_hero.setPosition(xp,yp);
            m_hero.m_Rect.moveTo(m_hero.m_X+m_hero.m_Plane.width()*0.5-m_hero.m_Rect.width()*0.5,m_hero.m_Y+m_hero.m_Plane.height()*0.5-m_hero.m_Rect.height()*0.5);
        }
        else
        {
            hero2.setPosition(xp,yp);
        }
    else
    {
        m_hero.setPosition(xp,yp);
        m_hero.m_Rect.moveTo(m_hero.m_X+m_hero.m_Plane.width()*0.5-m_hero.m_Rect.width()*0.5,m_hero.m_Y+m_hero.m_Plane.height()*0.5-m_hero.m_Rect.height()*0.5);
    }
    update();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space && press == 0)
    {
        if(winflag!=2)
        {
            if(hero)
            {
                m_hero.shootflag = 1;
                m_hero.shoot();
            }
            else
            {
                hero2.shootflag = 1;
                hero2.shoot();
            }
        }
        m_enemy.bullet_curtain_round();
    }
    if(event->key() == Qt::Key_A)
    {
       press=0;
       playGame();
    }
    update();
}
