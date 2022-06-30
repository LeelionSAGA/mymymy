#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <mybutton.h>
#include <QPushButton>
#include<QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT





public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    mybutton bt[18][18];
    QPushButton qbt1;
    QPushButton qbt2;
    QPushButton qbt3;
    QPushButton qbt4;
    void two();
    void four();
    void six();
    void start();
    void refresh();
    void myslot2(int x,int y);
    void jump(int m,int n);
    int le,ri;
    bool check(int x0,int y0);
    int vic(mybutton bt[18][18]);

private:
    Ui::Widget *ui;
signals:

};
#endif // WIDGET_H
