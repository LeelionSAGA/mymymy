 #include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include<iostream>


int a,b;
int round = 1;
int form;
int s;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    le = 0;
    ri = 0;
    start();


}

Widget::~Widget()
{
    delete ui;
}

void Widget:: start()
{
    this->setFixedSize(1050,900);
    qbt1.setParent(this);
    qbt2.setParent(this);
    qbt3.setParent(this);
    qbt4.setParent(this);
    qbt1.setText("双人对战");
    qbt2.setText("四人对战");
    qbt3.setText("六人对战");
    qbt1.setGeometry(900,100,100,50);
    qbt2.setGeometry(900,150,100,50);
    qbt3.setGeometry(900,200,100,50);
    qbt4.setGeometry(900,500,50,50);
    qbt4.setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    connect(&qbt1,&QPushButton::clicked,this,&Widget::two);
    connect(&qbt2,&QPushButton::clicked,this,&Widget::four);
    connect(&qbt3,&QPushButton::clicked,this,&Widget::six);

    int i=0,j=0;

    for(i=0;i<18;i++)
    {
        for(j=0;j<18;j++)
        {
            bt[i][j].q=0;
            bt[i][j].color = 0;
            bt[i][j].j = 0;
        }
    }
    for(i=0;i<18;i++)
    {
        for(j=0;j<18;j++)
        {
            bt[i][j].x =( (i+4) + 0.5 * (j+4))*40 - 320 ;
            bt[i][j].x0 = i;
            bt[i][j].y = (  1.732 * (j+4)) * 20 ;
            bt[i][j].y0 = j;
            connect(&bt[i][j],&mybutton::mysig,this,&Widget::myslot2);
        }
    }

    for(i=0;i<18;i++)
    {
        for(j=0;j<18;j++)
        {
            bt[i][j].setParent(this);
            bt[i][j].setGeometry( bt[i][j].x,bt[i][j].y,30,30);
            bt[i][j].setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
            if( i>3 && i<13 && j>3 && j<13 )
            {
                bt[i][j].q = 1;
            }
        }
    }
    for(i=0;i<18;i++)
    {
        for(j=0;j<18;j++)
        {

            if( i>3 && i<8 && j>3 && j<8 && (i+j)<12)
            {
                bt[i][j].q = 1;
                bt[i][j].side = 1;
            }
            else if( i>7 && i<13 && j>7 && j<13 && (i+j)>20)
            {
                bt[i][j].q = 1;
                bt[i][j].side = 2;
            }
            else if( i>=0 && i<=3 && j>=9 && j<=12 && (i+j)>=12)
            {
                bt[i][j].q = 1;
                bt[i][j].side = 3;
            }
            else if( i>=9 && i<=12 && j>=0 && j<=3 && (i+j)>=12)
            {
                bt[i][j].q = 1;
                bt[i][j].side = 5;
            }
            else if( i>=4 && i<=7 && j>=13 && j<=16 && (i+j)<=20)
            {
                bt[i][j].q = 1;
                bt[i][j].side = 6;
            }
            else if( i>=13 && i<=16 && j>=4 && j<=7 && (i+j)<=20)
            {
                bt[i][j].q = 1;
                bt[i][j].side = 4;
            }

        }
    }

    for(i=0;i<18;i++)
    {
        for(j=0;j<18;j++)
        {
            if(bt[i][j].q==0)
            {
                bt[i][j].hide();
            }
        }
    }
}

void Widget:: two()
{
    form = 2;
    round = 1;
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<18;j++)
        {

            if( i>3 && i<8 && j>3 && j<8 && (i+j)<12)
            {

                bt[i][j].color=1;
                bt[i][j].j=1;

            }
            else if( i>7 && i<13 && j>7 && j<13 && (i+j)>20)
            {
                bt[i][j].color=2;
                bt[i][j].j=1;
            }
            else if( i>=0 && i<=3 && j>=9 && j<=12 && (i+j)>=12)
            {

                bt[i][j].color=0;
                bt[i][j].j=0;
            }
            else if( i>=9 && i<=12 && j>=0 && j<=3 && (i+j)>=12)
            {

                bt[i][j].color=0;
                bt[i][j].j=0;
            }
            else if( i>=4 && i<=7 && j>=13 && j<=16 && (i+j)<=20)
            {

                bt[i][j].color=0;
                bt[i][j].j=0;
            }
            else if( i>=13 && i<=16 && j>=4 && j<=7 && (i+j)<=20)
            {

                bt[i][j].color=0;
                bt[i][j].j=0;
            }
            else
             {
                 bt[i][j].color=0;
                 bt[i][j].j=0;
             }

        }
    }

    refresh();

}

void Widget:: four()
{
    form = 4;
    round = 1;
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<18;j++)
        {

            if( i>3 && i<8 && j>3 && j<8 && (i+j)<12)
            {

                bt[i][j].color=1;
                bt[i][j].j=1;

            }
            else if( i>7 && i<13 && j>7 && j<13 && (i+j)>20)
            {
                bt[i][j].color=2;
                bt[i][j].j=1;
            }
            else if( i>=0 && i<=3 && j>=9 && j<=12 && (i+j)>=12)
            {

                bt[i][j].color=3;
                bt[i][j].j=1;
            }
            else if( i>=13 && i<=16 && j>=4 && j<=7 && (i+j)<=20)
            {

                bt[i][j].color=6;
                bt[i][j].j=1;
            }
            else if( i>=9 && i<=12 && j>=0 && j<=3 && (i+j)>=12)
            {

                bt[i][j].color=0;
                bt[i][j].j=0;
            }
            else if( i>=4 && i<=7 && j>=13 && j<=16 && (i+j)<=20)
            {

                bt[i][j].color=0;
                bt[i][j].j=0;
            }
            else
             {
                 bt[i][j].color=0;
                 bt[i][j].j=0;
             }
        }
    }

    refresh();
    }

void Widget:: six()
{
    form = 6;
    round = 1;
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<18;j++)
        {
                        if( i>3 && i<8 && j>3 && j<8 && (i+j)<12)
                        {

                            bt[i][j].color=1;
                            bt[i][j].j=1;
                        }
                        else if( i>7 && i<13 && j>7 && j<13 && (i+j)>20)
                        {

                            bt[i][j].color=2;
                            bt[i][j].j=1;
                        }
                        else if( i>=0 && i<=3 && j>=9 && j<=12 && (i+j)>=12)
                        {

                            bt[i][j].color=3;
                            bt[i][j].j=1;
                        }
                        else if( i>=9 && i<=12 && j>=0 && j<=3 && (i+j)>=12)
                        {

                            bt[i][j].color=4;
                            bt[i][j].j=1;
                        }
                        else if( i>=4 && i<=7 && j>=13 && j<=16 && (i+j)<=20)
                        {

                            bt[i][j].color=5;
                            bt[i][j].j=1;
                        }
                        else if( i>=13 && i<=16 && j>=4 && j<=7 && (i+j)<=20)
                        {

                            bt[i][j].color=6;
                            bt[i][j].j=1;
                        }
                       else
                        {
                            bt[i][j].color=0;
                            bt[i][j].j=0;
                        }


        }
    }

    refresh();
}

void Widget::refresh()
{
    if(round==1){
        qbt4.setStyleSheet("background: rgb(255,0,0);"
                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
    }
    if(round==2){
        qbt4.setStyleSheet("background: rgb(0,255,0);"
                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
    }
    if(round==3){
        qbt4.setStyleSheet("background: rgb(0,0,255);"
                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
    }

    if(round==5){
        qbt4.setStyleSheet("background: rgb(255,255,0);"
                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
    }
    if(round==6){
        qbt4.setStyleSheet("background: rgb(255,0,255);"
                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
    }
    if(round==4){
        qbt4.setStyleSheet("background: rgb(0,255,255);"
                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
    }
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<18;j++)
        {
            if(bt[i][j].color!=0)
            {
                if(bt[i][j].color==1)
                {
                    bt[i][j].setStyleSheet("background: rgb(255,0,0);"
                                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
                }
                if(bt[i][j].color==2)
                {
                    bt[i][j].setStyleSheet("background: rgb(0,255,0);"
                                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
                }
                if(bt[i][j].color==3)
                {
                   bt[i][j].setStyleSheet("background: rgb(0,0,255);"
                                          "border:2px groove gray;border-radius:10px;padding:2px 4px;");
                }
                if(bt[i][j].color==4)
                {
                    bt[i][j].setStyleSheet("background: rgb(255,255,0);"
                                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
                }
                if(bt[i][j].color==5)
                {
                    bt[i][j].setStyleSheet("background: rgb(255,0,255);"
                                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
                }
                if(bt[i][j].color==6)
                {
                    bt[i][j].setStyleSheet("background: rgb(0,255,255);"
                                           "border:2px groove gray;border-radius:10px;padding:2px 4px;");
                }
            }
            if(bt[i][j].color==0)
            {
                bt[i][j].setStyleSheet("background: rgba(255,255,255,150);"
                                       "border:2px groove gray;border-radius:10px;padding:2px 4px;");
            }
        }
    }
}

void Widget::myslot2(int x0, int y0)
{
    qDebug()<<"选定按钮x为"<< x0 << endl;
    qDebug()<< "选定按钮y为"<<y0 << endl;
    if(bt[x0][y0].j==1)
    {
        a = x0;
        b = y0;
        le = 1 ;
        ri = 0 ;
    }
    else
    {
        ri = 1 ;
    }
    if(ri==1&&le==1&&bt[a][b].side == round)
    {
    if(check(x0,y0))
    {
        (jump(x0,y0));
    }
    }

}
void Widget::jump(int x0,int y0)
{
    bt[x0][y0].color = bt[a][b].color;
    bt[x0][y0].j = 1;
    bt[x0][y0].side = bt[a][b].side;
    bt[a][b].j = 0;
    bt[a][b].color = 0;
    bt[a][b].side = 0;
    round ++ ;
    if(round > form)
    {
        round = 1;
    }
    ri = 0;
    le = 0;
    a = 0;
    b = 0;
    refresh();
    if( bt[11][12].side==1 && bt[12][12].side==1 && bt[12][11].side==1 && bt[12][10].side==1 && bt[12][9].side==1 && bt[11][11].side==1 && bt[11][10].side==1 && bt[10][12].side==1 && bt[10][11].side==1 && bt[9][12].side==1)
       {
          s = 1;
       }
       if( bt[4][4].side ==2 && bt[4][5].side == 2 && bt[4][6].side == 2 && bt[4][7].side == 2 && bt[5][4].side == 2 && bt[5][5].side == 2 && bt[5][6].side == 2 && bt[6][4].side == 2 && bt[6][5].side == 2 && bt[7][5].side == 2)
       {
          s = 2;
       }
       if( bt[0][12].side == 4 && bt[1][12].side == 4 && bt[2][12].side == 4 && bt[3][12].side == 4 && bt[3][11].side == 4 && bt[3][10].side == 4 && bt[3][9].side == 4 && bt[2][11].side == 4 && bt[2][10].side == 4 && bt[1][11].side == 4 ) s = 4 ;
       if( bt[13][4].side == 3 && bt[13][5].side == 3 && bt[13][6].side == 3 && bt[13][7].side == 3 && bt[14][4].side == 3 && bt[14][5].side == 3 && bt[14][6].side == 3 && bt[15][4].side == 3 && bt[15][5].side == 3 && bt[16][4].side == 3 ) s = 3;
       if( bt[9][3].side == 6 && bt[10][3].side == 6 && bt[10][2].side == 6 && bt[11][3].side == 6 && bt[11][2].side == 6 && bt[11][1].side == 6 && bt[12][3].side == 6 && bt[12][2].side == 6 && bt[12][1].side == 6 && bt[12][0].side == 6) s = 6;
       if( bt[4][13].side == 5 &&  bt[4][14].side == 5 && bt[4][15].side == 5 && bt[4][16].side == 5 && bt[5][13].side == 5 && bt[5][14].side == 5 && bt[5][15].side == 5 && bt[6][13].side == 5 && bt[6][14].side == 5 && bt[7][13].side == 5 ) s = 5;
       if(s!=0)
       {
       if(s = 1) { qDebug() << "玩家1获胜" << endl;}
       if(s = 2) { qDebug() << "玩家2获胜" << endl;}
       if(s = 3) { qDebug() << "玩家3获胜" << endl;}
       if(s = 4) { qDebug() << "玩家4获胜" << endl;}
       if(s = 5) { qDebug() << "玩家5获胜" << endl;}
       if(s = 6) { qDebug() << "玩家6获胜" << endl;}
       }
}
bool Widget::check(int x0,int y0)
{

   if( (x0 - a)*(x0 - a)+(y0 - b) * (y0 - b) <= 8 )
    {
       if ((x0 - a)*(x0 - a)+(y0 - b) * (y0 - b) <= 2)
       {
           if(((x0-a)== 1 && (y0-b) == 1 ) || ((x0-a)== -1 && (y0-b) == -1)){return false;}
           else return true;
       }
       else
       {
           if((x0-a)== 2 && (y0-b) == 0 && bt[(x0+a)/2][y0].j == 1) return true;
           if((x0-a)== -2 && (y0-b) == 0 && bt[(x0+a)/2][y0].j == 1) return true;
           if((x0-a)== 0 && (y0-b) == 2 && bt[x0][(y0+b)/2].j == 1) return true;
           if((x0-a)== 0 && (y0-b) == -2 && bt[x0][(y0+b)/2].j == 1) return true;
           if((x0-a)== -2 && (y0-b) == 2 && bt[(x0+a)/2][(y0+b)/2].j == 1) return true;
           if((x0-a)== 2 && (y0-b) == -2 && bt[(x0+a)/2][(y0+b)/2].j == 1) return true;
           else return false;
       }
    }

    else return false;
}

