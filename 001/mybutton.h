#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include<QDebug>



class mybutton : public QPushButton
{
    Q_OBJECT

signals:
    void mysig(int x,int y);
public:
    explicit mybutton(QWidget *parent = nullptr);
    int x0,y0;
    int x;
    int y;
    int color;
    int q;
    int j;
    int side; //阵营，决定该谁跳
    void myslot1();


};

#endif // MYBUTTON_H
