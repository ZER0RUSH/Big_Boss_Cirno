#include "map.h"
#include "config.h"
Map::Map()
{
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);
    win_picture.load(WIN_PATH);
    lose_picture.load(LOSE_PATH);
    background.load(BACKGROUND_PATH);
    press.load(PRESS_PATH);
    //设置地图其实y轴坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;
    //设置地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}
void Map::mapPosition()
{
    //处理第一张图片滚动
    m_map1_posY += MAP_SCROLL_SPEED;
    if(m_map1_posY >= 0)
    {
        m_map1_posY =-GAME_HEIGHT;
    }
        //处理第二张图片滚动
            m_map2_posY += MAP_SCROLL_SPEED;
    if(m_map2_posY >= GAME_HEIGHT )
    {
        m_map2_posY =0;
    }
}
