#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define XRES 640
#define YRES 480

int
main()
{

_SETVIDEOMODE(_VRES16COLOR);

_setcolor(14);
_rectangle(_GFILLINTERIOR,0,0,(XRES-1),(YRES-1));

getch();
_setvideomode(_DEFAULTMODE);

puts("Ok");
return 0;
}