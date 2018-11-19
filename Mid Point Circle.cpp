
#include<iostream>
#include<graphics.h>
#define xc x_centre
#define yc y_centre
using namespace std;
void midPointCircleDraw(int x_centre, int y_centre, int r)
{ int x = r, y = 0,a,b,rad;
cout<<"Enter the x, y coordinate and radius: ";
cin>>a>>b>>a;
putpixel(x+xc, y+yc, RED);
if (r > 0)
{
putpixel(x+xc, -y+yc, RED);
putpixel(y+xc, x+yc, RED);
putpixel(-y+xc, x+yc, RED);
}
int P = 1 - r;
while (x > y)
{
y++;
if (P <= 0)
P = P + 2*y + 1;
else
{
x--;
P = P + 2*y - 2*x + 1;
}
if (x < y)
break;
putpixel(x+xc, y+yc, RED);
putpixel(-x+xc, y+yc, RED);
putpixel(x+xc, -y+yc, RED);
putpixel(-x+xc, -y+yc, RED);
if (x != y)
{
putpixel(y+xc, x+yc, RED);
putpixel(-y+xc, x+yc, RED);
putpixel(-y+xc, -x+yc, RED);
putpixel(y+xc, -x+yc, RED);
}
}
}int main()
{
int gd=DETECT, gm;
initgraph(&gd, &gm, "");
midPointCircleDraw(100, 70, 50);
getch();
closegraph();
return 0;
}
