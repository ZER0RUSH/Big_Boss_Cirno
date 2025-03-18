#include "startmenu.h"
#include "ui_startmenu.h"
#include "mainwindow.h"

startmenu::startmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startmenu)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(GAME_ICON));
}

startmenu::~startmenu()
{
    delete ui;
}



void startmenu::on_oneplayer_clicked()//单人模式
{
    emit oneplayer();//发送oneplayer信号给mainwindow，以下同理
}


void startmenu::on_twopalyer_clicked()/*双人模式*/
{
    emit towplayer();
}



//void startmenu::on_fight_clicked()/*对战模式*/
//{
//    emit fight();
//}


void startmenu::on_exit_clicked()
{
    exit(0);
}

