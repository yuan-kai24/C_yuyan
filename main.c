#include "My_Style.h"

extern int X,Y;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dz = 0;//光标位置与输入位数
	char key;//输入字符的临时储存
	SetConsoleTitle("简易计算器1.0.-1—测试版");//控制台标题
	MapInit();//地图初始化
	while(1)
    {
    	SetPosstions(LEF+2+dz,3);
        key = getch();//录入
        KeyPut(X,Y,key,&dz);//键盘录入
     	Inputs(X,Y,key,&dz);//回车录入
		KeyCon(key);//键盘选择控制
        MapChoose();//当前选择项打印（默认坐标(0,4)）
    }
	return 0;
}

/*
*还是main函数看着顺眼
*/
