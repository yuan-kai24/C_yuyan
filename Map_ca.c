#include "My_Style.h"

extern int X,Y;
void MapInit()
{
	register int i,j,k;
	SetPosstions(LEF+25,0);
	printf("������"); 
	/*�������ṹ*/
	SetPosstions(LEF,1);
	for(i = 0;i < 56;i++)printf("Z");
	for(i = 0;i < 3;i++)
	{
		SetPosstions(LEF,i+2);printf("N");
		SetPosstions(LEF+55,i+2);printf("N");
	}
	SetPosstions(LEF+1,2);
	SetColors(14,0);
	printf("��������"); 
	SetPosstions(LEF+22,4);
	SetColors(15,0);
	printf("״̬��");
	SetColors(10,0);
	printf("Normal"); 
	SetColors(7,0);
	SetPosstions(LEF,5);
	for(i = 0;i < 56;i++)printf("Z");
	
	MapChoose();
	
	/*����ѡ�����ṹ*/
	for(i = 0;i < 9;i++)
	{
		SetPosstions(LEF,6+i);printf("N");
		for(k = 13;k < 55;k+=14)
		{
			SetPosstions(LEF+k,6+i);printf("|");
		}//�� 
		SetPosstions(LEF,6+i);printf("N");
		if(i%2 == 1)
		{
			for(j = 0;j < 54;j++)printf("-");
		}//�� 
		SetPosstions(LEF+55,6+i);printf("N");
	}
	
	SetPosstions(LEF,15);
	for(i = 0;i < 56;i++)printf("Z");
	SetPosstions(LEF+17,16);
	printf("<�ݲ�֧�ִ�λ������>"); 	
} 

Map_zf maps[5][4] = {
	{{"    ^     "},{"    ( )    "},{"     %     "},{"     +     "}},
	{{"    7     "},{"     8     "},{"     9     "},{"     -     "}},
	{{"    4     "},{"     5     "},{"     6     "},{"     *     "}},
	{{"    1     "},{"     2     "},{"     3     "},{"     /     "}},
	{{"    C     "},{"     0     "},{"     .     "},{"     =     "}}
};//��ͼ���� 

void MapChoose()
{
	
	int i,j,k = 1,q = 6;
	for(i = 0;i < 5;i++,q+=2)
	{
		for(j = 0;j < 4;j++,k+=14)
		{
			SetColors(11,0);
			if(Y == i && X == j)SetColors(9,8);	
			if(j == 0)SetPosstions(LEF+2,q); else SetPosstions(LEF+k,q);
			printf("%s",maps[i][j].as);		
		}
		k = 1;
	}
	SetColors(7,0);
	//SetPosstions(LEF+2,3);printf("(%d,%d)",X,Y);
}







