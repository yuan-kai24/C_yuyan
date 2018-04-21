#define GAMELIB_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#define LEF 12	//内容推移 


/*
*开发人员：yk 
*策划日期：2017年12月20日 11:52:23 
*最后修改日期：2017年12月26日 11:43:21 
*最后修改人员： yk 
*版本：测试版（1.0.-1） 
*状态：（  /笑哭  ）一脸懵bi~~~ 
*/

/*
*控制台命令区 
*/
void SetPosstions(int ,int);//设置位置（绝对定位） 
void SetColors(int,int);//设置文字前景背景 
void Clears(int,int,int); //按坐标与行数进行清屏

/*
*地图设置区 
*/ 
void MapInit();//地图初始化
void MapChoose();//当前所选项
typedef struct map_jp {
	char as[20];
}Map_zf;//所有选择项 


/*
*运算区 
*/
char * Sums(double,double);//加
char * Subs(double,double);//减
char * mults(double,double);//乘
char * Divs(double,double);//除
char * Delis(double,double);//取模
char * Powrs(double,double);//幂运算 
void Results(int,char []);//结果 
char * OpePri(char []);//运算过程 
char * Prios(int,int,char []);//运算优先级 (begins,ends)
char * CharShorten(int,int,char [],char []);//字符串缩短 


/*
*功能区 
*字符数值转换 
*操作检测 
*非法操作检测 
*/ 
void KeyPut(int,int,char,int *);//键盘输入字符录入 
void Inputs(int,int,char,int *);//键盘回车字符录入 
double Tra_ch_db(char []);//字符串转换为double
char * Tra_db_ch(double);//double转换为字符串 
void KeyCon(char);//键盘选择控制
int Unlaw(int,char []);//非法检测  返回0为假 1为真 
void InClaer(int *);//输入框清屏 


