#ifndef CONFIG_H
#define CONFIG_H

/********** 游戏配置数据 **********/
#define GAME_WIDTH 512 //宽度
#define GAME_HEIGHT 768 //高度
#define GAME_TITLE "红魔馆" //标题
#define GAME_ICON ":/res/dreamy_country.ico"

/********** 地图配置数据 **********/
#define MAP_PATH ":/res/line.png" //地图图片路径
#define BACKGROUND_PATH ":/res/dream_world.png"//背景图片
#define PRESS_PATH ":/res/press.png"//提示文字
#define WIN_PATH ":/res/win.png"
#define LOSE_PATH ":/res/lose.png"
#define MAP_SCROLL_SPEED 2 //地图滚动速度
#define GAME_RATE 10

/********** 玩家配置数据 **********/
#define HERO2_PATH ":/res/mls.png"
#define HERO_PATH ":/res/lm.png"
#define PLAYER_HP 20

/********** 敌人配置数据 **********/
#define ENEMY_PATH ":/res/QNL.png"
#define ENEMY_HP 90
/********** 子弹配置数据 **********/
#define HERO_BULLET_PATH ":/res/hero_bullet.png"
#define ENEMY_BULLET_PATH ":/res/enemy_bullet.png"
#define HERO_BULLET_NUM 10
#define ENEMY_BULLET_NUM 10000

/********** 冷却配置数据 **********/
#define HERO_BULLET_CD 10
#define HERO2_BULLET_CD 10
#define ENEMY_BULLET_CD 10


#endif // CONFIG_H
