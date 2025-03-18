#include "heroplane.h"
#include "config.h"
#include "herobullet.h"

HeroPlane::HeroPlane()
{
    //初始化加载飞机图片资源
    m_Plane.load(HERO_PATH);

    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - m_Plane.width()*0.5;
    m_Y = GAME_HEIGHT - m_Plane.height();

    //初始化矩形框 碰撞箱
    m_Rect.setWidth(10);
    m_Rect.setHeight(10);
    m_Rect.moveTo(m_X+m_Plane.width()*0.5-m_Rect.width()*0.5,m_Y+m_Plane.height()*0.5-m_Rect.height()*0.5);

    //发射间隔记录
    m_recorder = 0;
}
void HeroPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void HeroPlane::shoot()
{
    m_recorder+=10;
    if(m_recorder < HERO_BULLET_CD)
    {
        return;
    }
    m_recorder = 0;
    for(int i = 0 ; i < HERO_BULLET_NUM ; i++)
    {
        if(m_bullets[i].m_free)
        {
            m_bullets[i].m_free = false;
            m_bullets[i].m_X = m_X + m_Plane.width()/2 - m_bullets[i].m_Rect.width()/2;
            m_bullets[i].m_Y = m_Y;
            break;
        }
    }
}
