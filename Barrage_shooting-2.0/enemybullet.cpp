#include "enemybullet.h"
#include "config.h"

EnemyBullet::EnemyBullet()
{
    //初始化加载子弹图片资源
    m_Bullet.load(ENEMY_BULLET_PATH);
    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - m_Bullet.width()*0.5;
    m_Y = GAME_HEIGHT - m_Bullet.height();
    //初始化矩形框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
    //修正子弹过早显示bug
    m_X = -100;
    m_Y = -100;
    //子弹状态
    m_free = true;
}
void EnemyBullet::move()
{
    m_X = m_X + m_speed_X;
    m_Y = m_Y + m_speed_Y;
    m_Rect.moveTo(m_X,m_Y);
    if(m_X <= 0 || m_X >= GAME_WIDTH || m_Y <= 0 || m_Y >= GAME_HEIGHT)
    {
        m_free = true;
    }
}
