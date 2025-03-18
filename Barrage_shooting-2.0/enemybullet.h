#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <QPixmap>

class EnemyBullet
{
public:
    EnemyBullet();

    void move();

public:
    //子弹资源 对象
    QPixmap m_Bullet;
    //子弹坐标
    int m_X;
    int m_Y;
    //子弹速度以及方向
    int m_speed_X;
    int m_speed_Y;
    //子弹的矩形边框
    QRect m_Rect;
    //子弹状态
    bool m_free;
};

#endif // ENEMYBULLET_H
