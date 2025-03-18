#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>
#include <enemybullet.h>
#include<config.h>

class Enemy
{
public:
    Enemy();

    void move();

    void bullet_curtain_round();

    void bullet_curtain_triangular();

    void bullet_curtain_spiral();
public:
    //敌人资源
    QPixmap m_Enemy;
    //敌人坐标
    int m_X;
    int m_Y;
    //敌人矩形
    QRect m_Rect;
    //弹幕
    EnemyBullet m_bullets[ENEMY_BULLET_NUM];
    //CD
    int m_recorder;
    //螺旋
    int spiral;
};

#endif // ENEMY_H
