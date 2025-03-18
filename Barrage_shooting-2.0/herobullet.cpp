#include "herobullet.h"
#include "config.h"

HeroBullet::HeroBullet()
{
    //初始化加载子弹图片资源
    m_Bullet.load(HERO_BULLET_PATH);
    //初始化矩形框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    //子弹方向
    m_speed = -50;
    //修正子弹过早显示bug
    m_X = -100;
    m_Y = -100;
    //子弹状态
    m_free = true;
}
void HeroBullet::move()
{
    m_Y = m_Y + m_speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_Y < 0)
    {
        m_free = true;
    }
}
