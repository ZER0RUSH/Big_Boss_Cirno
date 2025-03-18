#include "connectmenu.h"
#include "ui_connectmenu.h"

connectmenu::connectmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectmenu)
{
    ui->setupUi(this);
}

connectmenu::~connectmenu()
{
    delete ui;
}


void connectmenu::on_sever_clicked()//主机按钮进程
{
    severport=ui->severport->text().toInt();
    emit severconnect();//发送severconnect信号给mainwindow，以下同理
    this->hide();
}


void connectmenu::on_pushButton_2_clicked()//客户端按钮进程
{
    IP=ui->IP->text();
    PORT=ui->PORT->text();
    this->hide();
    emit clientconnect();
}

