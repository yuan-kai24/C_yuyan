#include "My_Style.h"

void SetPosstions(x,y)
{
	HANDLE winHandle;//���
    COORD pos = {x,y}; 
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ñ�׼����豸
    SetConsoleCursorPosition(winHandle,pos);
}//��λ 

void SetColors(foreColor,BackColor)
{
	HANDLE winHandle;   
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(winHandle,foreColor + BackColor*0x10);
}//���ֵ�ǰ��ɫ�뱳��ɫ 

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
}//��������λ�ո񸲸�ʵ�֣� 
