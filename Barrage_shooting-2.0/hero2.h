#ifndef HERO2_H
#define HERO2_H

#include <QPixmap>
#include <herobullet.h>
#include <config.h>

class HeroPlane2
{
public:
    HeroPlane2();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x, int y);
public:
    //飞机资源 对象
    QPixmap m_Plane;
    //飞机坐标
    int m_X;
    int m_Y;
    int shootflag=0;
    //飞机的矩形边框
    QRect m_Rect;
    //发射间隔记录
    int m_recorder;
    //飞机所属子弹
    HeroBullet m_bullets[HERO_BULLET_NUM];
};




#endif // HERO2_H
