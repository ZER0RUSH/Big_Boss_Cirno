#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QDebug>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client();
    bool Connect(QString ip,QString port);
    void sendData(int x_self,int y_self,int ShootFlag,int BossX,int BossY,int ShootMode);
    int getX();
    int getY();
    int getShootFlag();
    int getBossX();
    int getBossY();
    int getShootMode();
private slots:
    void receiveData();

private:
    QTcpSocket socket;
    int x,y,ShootFlag; //对方数据
    int BossX,BossY;
    int ShootMode;
};

#endif // CLIENT_H
