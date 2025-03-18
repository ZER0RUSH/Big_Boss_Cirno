#ifndef CONNECTMENU_H
#define CONNECTMENU_H

#include <QDialog>

namespace Ui {
class connectmenu;
}

class connectmenu : public QDialog
{
    Q_OBJECT

public:
    explicit connectmenu(QWidget *parent = nullptr);
    ~connectmenu();
    int severport;
    QString IP;
    QString PORT;


private slots:
    void on_sever_clicked();

    void on_pushButton_2_clicked();
signals:
    void severconnect();
    void clientconnect();

private:
    Ui::connectmenu *ui;

};

#endif // CONNECTMENU_H
