#include "My_Style.h"

int bdy = 0;

void Results(int dz,char conum[])
{
	char res[55] = "<NULL>";
	bdy = 1;//记录是否计算过结果 
	if(Unlaw(dz,conum))
	{
		strcpy(res,OpePri(conum));
		printf("%s",res); 
		strcpy(res,"<NULL>");
	}else{
		printf("%s",res);
		return;
	}                    
}//结果打印 

char * Sums(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1+num2);
	return ptr_num;
}//加
 
char * Subs(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1-num2);
	return ptr_num;
}//减 

char * mults(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1*num2);
	return ptr_num;
}//乘 

char * Divs(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1/num2);
	return ptr_num;
}//除 

char * Delis(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch((int)num1%(int)num2);
	return ptr_num;
}//取模 

char * Powrs(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(pow(num1,num2));
	return ptr_num;
}//幂运算 

/*
*经过前面各种限制，传入的应该是正常数据 
*思路
*扫描是否为纯数字 
*反复递给下一项，每项运算一个双目运算符式子，慢慢缩短到没有运算符(负数结果除外)
*找出需要优先运算的，先处理括号，然后求余与幂（按顺序计算），乘除，加减
*缩短字符串中+- ++ --等情况
*运算过后的*-N  /-N  ^-N  %-N  问题 
 ----------------------------------------------------------------------------- 
*转换找出的两个数字为double型，通过运算符判断调用运算函数
*运算函数计算完毕后转回字符串返回
*运算出来的字符串替换原来的位置
*缩短式子通过递归继续判断运算 
*/  
char * OpePri(char num[])
{
	int i,j,k,//循环变量 
			ysfpd = 0,
			boolnum = 0,//检测是否为纯数字 
			kh1 = 0,kh2;//检测括号 
	char *ptr_ac = NULL;//结果存储 
	
	/*
	*合并符号运算 
	*/ 
	for(i = 0;i < strlen(num);i++)
	{
		if(num[i] == '+' && num[i+1] == '-')ysfpd = 1;
		if(num[i] == '-' && num[i+1] == '-')
		{
			num[i+1] = '+';
			ysfpd = 1;
		}
		if(ysfpd)
		{
			num[i] = num[i+1];//向前覆盖 
		}
	}//合并运算符 
	
	
	for(i = 0;i < strlen(num);i++)
	{
		if(!(num[i] >= '0' && num[i] <= '9'))boolnum = 1;//是否存在运算符 
		if(num[0] == '-')boolnum = 0;//-----负数问题 
		if(num[i] = '(')kh1 = i;//寻找括号 
	}//扫描是否为纯数字（顺便寻找是否有括号）
	
	if(kh1 != 0)
	{
		for(i = kh1;i < strlen(num);i++)
		{
			if(num[i] = ')')
			{
				kh2 = i;
				break;
			}
		}//从最后一个反括号开始寻找 
				
	}//寻找反括号 		
	 
	if(/*boolnum*/0)
	{
		if(kh1)
		{
			
		}//括号处理 （查询括号里有几个运算符） 
		return OpePri("传入运算过的字符串");//
	}else
	{
		ptr_ac = num;
		return ptr_ac = "结果！";
	}//纯数字与式子的运算 
	
}//运算过程 

char * Prios(int begins,int ends,char nums[])
{

	return; 
} //运算优先级 

char * CharShorten(int begins,int ends,char num1[],char num2[])
{

	return; 
}//字符串缩短 
 

