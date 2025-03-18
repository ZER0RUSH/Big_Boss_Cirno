#include "enemy.h"
#include "config.h"
#include<cmath>

Enemy::Enemy()
{
    //加载图片资源
    m_Enemy.load(ENEMY_PATH);
    //初始化坐标
    m_X = GAME_WIDTH * 0.5 - m_Enemy.width()*0.5;
    m_Y = 0;
    //初始化矩形框
    m_Rect.setWidth(m_Enemy.width());
    m_Rect.setHeight(m_Enemy.height());
    m_Rect.moveTo(m_X,m_Y);
    m_recorder = 0;
    spiral = 0;
}

void Enemy::bullet_curtain_round()
{
    if(m_recorder < ENEMY_BULLET_CD)
    {
        return;
    }
    m_recorder = 0;
    double angel = 0;
    for(int i = 0 ; i < ENEMY_BULLET_NUM ; i++)
    {
        if(m_bullets[i].m_free)
        {
            m_bullets[i].m_free = false;
            m_bullets[i].m_X = m_X + m_Rect.width()/2;
            m_bullets[i].m_Y = m_Y + m_Rect.height()/2;
            m_bullets[i].m_speed_X = (int)(10 * cos(angel));
            m_bullets[i].m_speed_Y = (int)(10 * sin(angel));
            angel += 3;
            if(angel == 360) break;
        }
    }
}

void Enemy::bullet_curtain_triangular()
{
    if(m_recorder < ENEMY_BULLET_CD)
        return;
    m_recorder=0;
    int speedx = -10 , speedy = 10;
    int flagx = 2;
    for(int i = 0 ; i < ENEMY_BULLET_NUM ; i++)
    {
        if(m_bullets[i].m_free)
        {
            m_bullets[i].m_free = false;
            m_bullets[i].m_X = m_X + m_Rect.width()/2;
            m_bullets[i].m_Y = m_Y + m_Rect.height()/2;
            speedx = speedx + flagx;
            m_bullets[i].m_speed_X = speedx;
            m_bullets[i].m_speed_Y = speedy;
            if(speedx == 10) break;
        }
    }
}

void Enemy::bullet_curtain_spiral()
{
    if(m_recorder < 1)
        return;
    m_recorder = 0;
    if(spiral >= 60)
    {
        spiral -= 60;
    }
    double angel = spiral;
    for(int i = 0 ; i < ENEMY_BULLET_NUM ; i++)
    {
        if(m_bullets[i].m_free)
        {
            m_bullets[i].m_free = false;
            m_bullets[i].m_X = m_X + m_Rect.width()/2;
            m_bullets[i].m_Y = m_Y + m_Rect.height()/2;
            m_bullets[i].m_speed_X = (int)(15 * cos(angel));
            m_bullets[i].m_speed_Y = (int)(15 * sin(angel));
            angel += 60;
            if(angel >= 360) break;
        }
    }
    spiral += 1;
}
