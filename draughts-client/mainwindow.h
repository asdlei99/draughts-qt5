#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QtNetwork>
#include "solver.h"
#include "enterhost.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    QPushButton***button;
    QTcpSocket *readWriteSocket;
    QString ip;
    int port;
    int less;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    solver sol;
    int state;//-1: wait, 0: other, 1: self, 2: end
//    int rev;//0: default, 1: change b and w
    int col;//0: b, 1: w
private:
    Mat show_a,show_b,show_c;
    void send(QString);
    void calc();
public slots:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void setip(QString,int);
    void on_actionInput_host_triggered();
    void restart(int clear=1);
    void recvMessage();
private slots:
    void on_actionGive_up_triggered();
    void on_actionMake_a_draw_triggered();
};

#endif // MAINWINDOW_H
