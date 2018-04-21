#include "My_Style.h"

void SetPosstions(x,y)
{
	HANDLE winHandle;//句柄
    COORD pos = {x,y}; 
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得标准输出设备
    SetConsoleCursorPosition(winHandle,pos);
}//定位 

void SetColors(foreColor,BackColor)
{
	HANDLE winHandle;   
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(winHandle,foreColor + BackColor*0x10);
}//文字的前景色与背景色 

void Clears(x,y,rowCount)
{
	int i,j;
	SetPosstions(x,y);
    for(i = 0;i < rowCount;i++)
    {
        SetPosstions(x,y+i);
        for(j = 0;j < 52;j++)
        {
            printf(" ");
        }
    }
}//清屏（定位空格覆盖实现） 
