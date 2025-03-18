#ifndef STARTMENU_H
#define STARTMENU_H

#include <QDialog>

namespace Ui {
class startmenu;
}

class startmenu : public QDialog
{
    Q_OBJECT

public:
    explicit startmenu(QWidget *parent = nullptr);
    ~startmenu();

private slots:

    void on_oneplayer_clicked();

    void on_twopalyer_clicked();

    //void on_fight_clicked();

    void on_exit_clicked();
signals:
    void fight();
    void oneplayer();
    void towplayer();
private:
    Ui::startmenu *ui;
};

#endif // STARTMENU_H
