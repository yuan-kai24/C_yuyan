#define GAMELIB_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#define LEF 12	//�������� 


/*
*������Ա��yk 
*�߻����ڣ�2017��12��20�� 11:52:23 
*����޸����ڣ�2017��12��26�� 11:43:21 
*����޸���Ա�� yk 
*�汾�����԰棨1.0.-1�� 
*״̬����  /Ц��  ��һ����bi~~~ 
*/

/*
*����̨������ 
*/
void SetPosstions(int ,int);//����λ�ã����Զ�λ�� 
void SetColors(int,int);//��������ǰ������ 
void Clears(int,int,int); //��������������������

/*
*��ͼ������ 
*/ 
void MapInit();//��ͼ��ʼ��
void MapChoose();//��ǰ��ѡ��
typedef struct map_jp {
	char as[20];
}Map_zf;//����ѡ���� 


/*
*������ 
*/
char * Sums(double,double);//��
char * Subs(double,double);//��
char * mults(double,double);//��
char * Divs(double,double);//��
char * Delis(double,double);//ȡģ
char * Powrs(double,double);//������ 
void Results(int,char []);//��� 
char * OpePri(char []);//������� 
char * Prios(int,int,char []);//�������ȼ� (begins,ends)
char * CharShorten(int,int,char [],char []);//�ַ������� 


/*
*������ 
*�ַ���ֵת�� 
*������� 
*�Ƿ�������� 
*/ 
void KeyPut(int,int,char,int *);//���������ַ�¼�� 
void Inputs(int,int,char,int *);//���̻س��ַ�¼�� 
double Tra_ch_db(char []);//�ַ���ת��Ϊdouble
char * Tra_db_ch(double);//doubleת��Ϊ�ַ��� 
void KeyCon(char);//����ѡ�����
int Unlaw(int,char []);//�Ƿ����  ����0Ϊ�� 1Ϊ�� 
void InClaer(int *);//��������� 


