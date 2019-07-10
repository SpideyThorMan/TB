#include <iostream>
#include <windows.h>
#include <conio.h>

#include<dos.h>

#include <time.h>
using namespace std;

void main()
{
    clrscr();
    _setcursortype(_NOCURSOR);
    for(int x=0;x<70;x++)
    {
        printf("%c",219)
        delay(60);
    }
     _setcursortype(_NOCURSOR);
     window(6,23,55,25);
     printf("completed");
     getch();
}
