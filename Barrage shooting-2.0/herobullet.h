#ifndef HEROBULLET_H
#define HEROBULLET_H
#include <QPixmap>

class HeroBullet
{
public:
    HeroBullet();

    void move();

public:
    //子弹资源 对象
    QPixmap m_Bullet;
    //子弹坐标
    int m_X;
    int m_Y;
    //子弹方向
    int m_speed;
    //子弹的矩形边框
    QRect m_Rect;
    //子弹状态
    bool m_free;
};

#endif // HEROBULLET_H
