#include "My_Style.h"

extern int X,Y;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dz = 0;//���λ��������λ��
	char key;//�����ַ�����ʱ���� 
	SetConsoleTitle("���׼�����1.0.-1�����԰�");//����̨���� 
	MapInit();//��ͼ��ʼ�� 
	while(1)
    {
    	SetPosstions(LEF+2+dz,3);
        key = getch();//¼��  
        KeyPut(X,Y,key,&dz);//����¼�� 
     	Inputs(X,Y,key,&dz);//�س�¼�� 
		KeyCon(key);//����ѡ����� 
        MapChoose();//��ǰѡ�����ӡ��Ĭ������(0,4)�� 	
    }
	return 0;
}

/*
*����main��������˳�� 
*/ 
