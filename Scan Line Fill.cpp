#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
class point
{
public:
int x,y;
};
class polygon
{
private:
point p[20];
int inter[20],x,y;
int v,xmin,ymin,xmax,ymax;
public:
int c;
void read();
void calcul();
void display();
void ints(float);
void sort(int);
};
void polygon::read()
{
int i, ver;
cout<<"Enter the no of vertices of polygon:";
cin>>ver;
if(ver>2)
{
for(i=0;i<ver; i++)
{
cout<<"\nEnter the co-ordinate no.- "<<i+1<<" : ";
cout<<"\tx"<<(i+1)<<"=";
cin>>p[i].x;
cout<<"\n\ty"<<(i+1)<<"=";cin>>p[i].y;
}
p[i].x=p[0].x;
p[i].y=p[0].y;
xmin=xmax=p[0].x;
ymin=ymax=p[0].y;
}
else
cout<<"\n Enter valid no. of vertices.";
}
void polygon::calcul()
{
for(int i=0;i<v;i++)
{
if(xmin>p[i].x)
xmin=p[i].x;
if(xmax<p[i].x)
xmax=p[i].x;
if(ymin>p[i].y)
ymin=p[i].y;
if(ymax<p[i].y)
ymax=p[i].y;
}
}
void polygon::display()
{
int ch1;
char ch='y';
float s,s2;
do
{
cout<<"\n\nMENU:";
cout<<"\n\n\t1 . Scan line Fill ";
cout<<"\n\n\t2 . Exit ";
cout<<"\n\nEnter your choice:";
cin>>ch1;
switch(ch1)
{
case 1:
s=ymin+0.01;
delay(100);cleardevice();
while(s<=ymax)
{
ints(s);
sort(s);
s++;
}
break;
case 2:
exit(0);
}
cout<<"Do you want to continue?: ";
cin>>ch;
}while(ch=='y' || ch=='Y');
}
void polygon::ints(float z)
{
int x1,x2,y1,y2,temp;
c=0;
for(int i=0;i<v;i++)
{
x1=p[i].x;
y1=p[i].y;
x2=p[i+1].x;
y2=p[i+1].y;
if(y2<y1)
{
temp=x1;
x1=x2;
x2=temp;
temp=y1;
y1=y2;
y2=temp;
}
if(z<=y2&&z>=y1)
{
if((y1-y2)==0)
x=x1;
else
{
x=((x2-x1)*(z-y1))/(y2-y1);x=x+x1;
}
if(x<=xmax && x>=xmin)
inter[c++]=x;
}
}
}
void polygon::sort(int z)
{
int temp,j,i;
for(i=0;i<v;i++)
{
line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
}
for(i=0; i<c;i+=2)
{
delay(100);
line(inter[i],z,inter[i+1],z);
}
}
int main()
{
initwindow(500, 600);
polygon x;
x.read();
x.calcul();
int cl=0;
setcolor(cl);
x.display();
getch();
closegraph();
return 0;
}
