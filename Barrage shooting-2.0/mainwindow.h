#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "hero2.h"
#include "map.h"
#include <QMainWindow>
#include <QResource>
#include <QApplication>
#include <qTimer.h>
#include "heroplane.h"
#include "enemy.h"
#include "startmenu.h"
#include "connectmenu.h"
#include "server.h"
#include "client.h"
#include <QTimerEvent>
#include <QTime>
#include <QtGlobal>
#include <QRandomGenerator>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initScene();
    //启动游戏 用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //地图对象
    //QTimer m_Timer;
    Map m_map;
    QTimer m_Timer;
    QTimer boss_Timer;
    //飞机对象
    HeroPlane m_hero;
    HeroPlane2 hero2;
    //敌人对象
    Enemy m_enemy;
    //碰撞箱检测
    void collisionDetection();
    // 生成随机数种子，可以使用当前时间作为种子
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    // 生成一个0到99之间的随机数
    int bosstrial_X;
    int bosstrial_Y;
    void mouseMoveEvent(QMouseEvent *event);
    void bossstep();
    void keyPressEvent(QKeyEvent *event);
    void resetposition();
    void restartset();

    int player_HP=PLAYER_HP;
    int boss_HP=ENEMY_HP;

    void gameover_win();
    void gameover_lose();

public slots:
    void do1();
    void GameLoop1();
    void GameLoop2();
    //void timerevent(QTimerEvent *event);

private:
    startmenu menu;
    connectmenu link;
    Server *server;
    Client *client;

};

#endif // MAINWINDOW_H
