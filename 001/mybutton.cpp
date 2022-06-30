#include "mybutton.h"


mybutton::mybutton(QWidget *parent) : QPushButton(parent)
{

 connect(this,&mybutton::clicked,this,&mybutton::myslot1);
}

void mybutton::myslot1()
{
 int a ,b ;
 a = this->x0;
 b = this->y0;
 emit mysig(a,b);
}

