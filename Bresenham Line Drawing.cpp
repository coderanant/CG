
#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "");
int x1,y1,x2,y2, p;
cout<<"Enter x1 y1: ";
cin>>x1>>y1;
cout<<"Enter x2, y2: ";
cin>>x2>>y2;
putpixel(x1, y1, WHITE);
p = 2*(y2-y1) - (x2-x1);
while (x2>x1)
{
if (p>=0)
{
x1++;
y1++;
putpixel(x1, y1, WHITE);
p = p + 2*(y2-y1) - 2*(x2-x1);
}
else
{
x1++;
putpixel(x1, y1, WHITE);
p = 2*(y2-y1) - (x2-x1);
}
}
getch();
closegraph();
}
