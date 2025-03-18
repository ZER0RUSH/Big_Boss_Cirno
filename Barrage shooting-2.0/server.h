#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void Connect(int port);
    void sendData(int x_self,int y_self,int ShootFlag,int BossX,int BossY,int ShootMode);
    int getX();
    int getY();
    int getShootFlag();
    int getBossX();
    int getBossY();
    int getShootMode();
private:
    QTcpSocket socket;
    int x,y,ShootFlag; //对方数据
    int BossX,BossY;
    int ShootMode;
    bool isConnected=0;

private slots:
    void incomingConnection(qintptr handle);
    void receiveData();
signals:
    void dataReceived();
    void getMessage();
};

#endif // SERVER_H
