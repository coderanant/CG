
#include<iostream>
#include<graphics.h>
using namespace std;
void Circle(int x, int y, int xc, int yc)
{
putpixel(x+xc,y+yc,RED);
putpixel(-x+xc,y+yc,RED);
putpixel(x+xc, -y+yc,RED);
putpixel(-x+xc, -y+yc, RED);
putpixel(y+xc, x+yc, RED);
putpixel(y+xc, -x+yc, RED);
putpixel(-y+xc, x+yc, RED);
putpixel(-y+xc, -x+yc, RED);
}
int main()
{
int gd = DETECT, gm;
int r, xc, yc, pk, x, y;
initgraph(&gd, &gm, "");
cout<<"Enter the co-ordinates of the centre : ";
cin>>xc>>yc;
cout<<"Enter the radius of circle : ";
cin>>r;
pk = 3 - 2*r;
x=0;
y = r;
Circle(x,y,xc,yc);while(x < y)
{
if(pk <= 0)
{
pk = pk + (4*x) + 6;
Circle(++x,y,xc,yc);
}
else {
pk = pk + (4*(x-y)) + 10;
Circle(++x,--y,xc,yc);
}
}
getch();
closegraph();
}
