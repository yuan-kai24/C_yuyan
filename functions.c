#include "My_Style.h"

int X = 0,Y = 4;
int bra = 0;//括号判断变量 
extern bdy;//结果清屏变量
char conum[55] = "<NULL>";

void KeyCon(char key)
{				   	  
        if(key == 72)Y--;//上 
        if(key == 77)X++;//右 
        if(key == 80)Y++;//下 
        if(key == 75)X--;//左 
        if(X > 3)X = 0;
        if(X < 0)X = 3;
        //极限判断 
        if(Y > 4)Y = 0;
        if(Y < 0)Y = 4;
}

void KeyPut(int X,int Y,char key,int * dz)
{
	if(key == 8 && *dz > 0)
        {
        	if(conum[*dz-1] == ')')bra = 1;
        	if(conum[*dz-1] == '(')bra = 0;
        	//括号判定 
        	SetPosstions(LEF+2+(--(*dz)),3);
        	printf(" ");//退格覆盖 
        }//退格与限制最小退格长度 
        
		if(*dz < 52)
		{
			
			if(key >= '0' && key <= '9' || key == '.')
        	{
        		if(bdy)
       			{
        			InClaer(dz);
        		}//得出结果后再按键盘清屏
				conum[*dz] = key;
				if(*dz == 0 && conum[*dz] == '.' || conum[*dz-1] == '(' && conum[*dz] == '.')
        		{
        			printf("%c",(conum[*dz]='0'));
        			conum[++(*dz)]='.';
        		}//开始直接或括号后直接输入小数点时补0 
        		SetPosstions(LEF+2+(*dz)++,3);
        		putch(key);
        		
        		
        	}//打印显示，光标跟随 ，限制最大输入长度 
        	
        	
		
        	if(key == '+' || key == '-' || key == '*' || key == '/' || key == '%' || key == '^' || key == '(' || key == ')')
        	{
        			if(bdy)
       				{
        				InClaer(dz);
        			}//得出结果后再按键盘清屏
        			
        			if(key == '(')bra = 1;
        			if(key == ')')bra = 0;//括号判断 
        			
        			conum[*dz] = key;
        			SetPosstions(LEF+2+(*dz)++,3);
      	  			putch(key);
        		
       		}//运算符判断 
    	}
    	if(key == '=')
    	{
    		conum[*dz] = '\0'; //结束字符串 
    		Clears(LEF+2,3,+1);
    		SetPosstions(LEF+2,3);
    		Results(*dz,conum);
			(*dz)=0; //置零，方便后续操作 
    	}
} //输入判断 


void Inputs(int X,int Y,char key,int * dz)
{		
		if(key == 13)
        {
        	if(bdy)
       			{
        			InClaer(dz);
        		}//得出结果后再按键盘清屏
			if(X >= 0 && X <= 3 && Y >= 0 && Y <= 4 && *dz < 52)
			{
				SetPosstions(LEF+2+(*dz),3);
				if(X == 1 && Y == 4)printf("%c",conum[(*dz)++] = '0');
				if(X == 2 && Y == 4)
				{
					conum[*dz] = '.';
					if(*dz == 0 && conum[*dz] == '.' || conum[*dz-1] == '(' && conum[*dz] == '.')
        			{
        				printf("%c",(conum[*dz]='0'));
        				conum[++(*dz)]='.';
        			}//开始直接或括号后直接输入小数点时补0  
        			printf("%c",conum[(*dz)++]);
					
				}
				if(X == 0 && Y == 3)printf("%c",conum[(*dz)++] = '1');
				if(X == 1 && Y == 3)printf("%c",conum[(*dz)++] = '2');
				if(X == 2 && Y == 3)printf("%c",conum[(*dz)++] = '3');
				if(X == 0 && Y == 2)printf("%c",conum[(*dz)++] = '4');
				if(X == 1 && Y == 2)printf("%c",conum[(*dz)++] = '5');
				if(X == 2 && Y == 2)printf("%c",conum[(*dz)++] = '6');
				if(X == 0 && Y == 1)printf("%c",conum[(*dz)++] = '7');
				if(X == 1 && Y == 1)printf("%c",conum[(*dz)++] = '8');
				if(X == 2 && Y == 1)printf("%c",conum[(*dz)++] = '9');
				//数字区 
				
				//运算符区
				 if(X == 0 && Y == 0)printf("%c",conum[(*dz)++] = '^');
				 if(X == 1 && Y == 0)
				 {
				 	if(bra == 0)
				 	{
				 		printf("%c",conum[(*dz)++] = '(');
				 		bra = 1;
				 	}else
				 	{
				 		printf("%c",conum[(*dz)++] = ')');
				 		bra = 0;
				 	}	
				 }//括号操作 
				 if(X == 2 && Y == 0)printf("%c",conum[(*dz)++] = '%');
				 if(X == 3 && Y == 0)printf("%c",conum[(*dz)++] = '+');
				 if(X == 3 && Y == 1)printf("%c",conum[(*dz)++] = '-');
				 if(X == 3 && Y == 2)printf("%c",conum[(*dz)++] = '*');
				 if(X == 3 && Y == 3)printf("%c",conum[(*dz)++] = '/');
				 
			}
			if(X == 3 && Y == 4)
			{
				conum[*dz] = '\0'; //结束字符串 
    			Clears(LEF+2,3,+1);
    			SetPosstions(LEF+2,3);
    			Results(*dz,conum);
				(*dz)=0; //置零，方便后续操作 
			} 
			if(X == 0 && Y == 4)
			{
				InClaer(dz);
			}//清屏 
			
		} 
}//回车判断 

void InClaer(int *dz)
{
	Clears(LEF+2,3,(*dz=0)+1);
	bra = 0;
	bdy = 0;
	*dz = 0; 
	strcpy(conum,"<NULL>");
	SetPosstions(LEF+22,4);
	SetColors(15,0);
	printf("状态：");
	SetColors(10,0);
	printf("Normal                 "); 
	SetColors(7,0);
}

/*
*写到崩溃，不想说话。。。。。。 
*这些代码告诉我，不要想着装逼。。。谨以此话，献给未来的自己 
*/ 
int Unlaw(int dz,char num[])
{
	int i,j = 0;
	int deci = 0;//小数点判断 
	if(dz == 0)return 0;
	for(i = 0;i < dz;i++)
	{
		if(num[i] == '(')
		{
			bra++;//预防出现）+1+（2+3这种类型运算
			if(num[i+1] == '*' || num[i+1] == '/')j = 1;//预防出现（*或（/这类运算 
		}
		//不能为（/12）或（*12）或（12+/-）这种类型 
		if(num[i] == ')')	
		{
			if(bra <= 0)j=1; 
			bra--;
			if(num[i-1] == '+' || num[i-1] == '-')j = 1;
		}
	}
	if(bra != 0)j = 1;//利用bra判断正反括号是否对等 
	
	for(i = 0;i < dz;i++)
	{	
		if(num[i] == '(')
        		{
        			if(num[i+1] == ')' || num[i-1] >= '0' && num[i-1] <= '9')j=1;
        		}
				if(num[i] == ')')
				{
					if(num[i+1] == '(' || num[i+1] >= '0' && num[i+1] <= '9')j=1;
				}//括号规则  ：括号之间必须要有运算符链接 
		
		if(num[i] == '+' || num[i] == '-' || num[i] == '*' || num[i] == '/' || num[i] == '%' || num[i] == '^')
		{
			deci = 0;//每次加上运算符后重置小数点判断 
			if(num[i-1] == '(' && num[i+1] == ')')j = 1;//判断括号里不能只有一个为运算符的参数 
			if(num[i+1] == '+' || num[i+1] == '-' || num[i+1] == '*' || num[i+1] == '/' || num[i+1] == '%' || num[i+1] == '^')j=1;
			//判断运算符不能连续 
			if(i == 0 || i == dz-1)j=1;//首尾不能添加运算符 
		} //运算符的一些规则 
		if(num[i] >= '0' && num[i] <= '9' || num[i] == '.')
		{
			if(num[i] == '.')deci += 1;
			if(deci == 2)j = 1;
		}//小数点非法操作判断 
		if(j)
		{
			strcpy(conum,"<NULL>");
			SetPosstions(LEF+28,4);
			SetColors(12,0);
			printf("Operator call error");//返回状态 
			SetColors(7,0);
			SetPosstions(LEF+2,3);
			return 0;
		}//捕获异常，如果非法输入，则j就会变为1，结束此函数并返回0 
	}
	
	return 1;
}//非法操作检测 

/*
*来自C语言的爱抚。。。 
*/ 

double Tra_ch_db(char dnum[])
{
	
	double res,//储存结果 
		   car = 1,//进位 
		   plmi = 1;//储存正负值 
	int i = 0,j = 0;//数组下标与是否有小数点 

	if(dnum[i] == '-')plmi = -1;//正负判断 
	
	dnum = strrev(dnum);//逆置字符串
	
	while(dnum[i] != '\0')
	{
		if(dnum[i] == '.')j=1;//是否有小数点
		i++;
	} //查询是否有小数点 
	i=0;
	
	while(dnum[i] != '.' && j)
	{
		res += (dnum[i]-48)*car;
		car *= 10;
		i++;
	}//提取小数点前的值 
	res /= car;//变小数 
	
	if(j)i += (car=1); 
	
	while(dnum[i] != '\0' && dnum[i] != '-')
	{
		res += (dnum[i]-48)*car;
		car *=10;
		i++;
	}//提取小数点后的值 
	
	return res*plmi; 
} //字符串转double型数据 


/*
*未修复BUG：
*运行小数时有一部分数据会被神秘力量篡改 
* 传入12345.12345时返回了12345.123449，类似问题很多
*整数部分正常 
*指针返回值异常 
*/ 
char * Tra_db_ch(double num)
{
	char * ptr_num = NULL;//最终返回地址 
	//ptr_num = (char *)malloc(sizeof(char)*50);
	char cwnum[50];//存储转换值
	char decq[50],dech[50];//存储小数点前后数值 
	int cnum = (int)num;//整数部分 
	int i = 0,j = 0,s = 0,k = 0; //数组下标 
	if(num < 0)
	{
		strcpy(cwnum,"-");
		s = 1;
		num *= -1;
	}//判断是否为负数 
	double deciw = num-(int)num;//获取小数点后的数 
	int deci = 0;
	
	/*
	*BUG从这里开始
	*解决思想：。。。。。。 
	*/
	//printf("dou数：%d\t",sizeof(double));
	if(deciw != 0)
	{
		deci = (deciw*1e10);
	};//小数变整数 
	//printf("小数：%d  ",deci);
	
	while(deci != 0)
	{
		k = 1;
		dech[i] = (char)((deci%10)+48);
		deci /= 10;
		i++;
	}//小数点后存储 
	dech[i] = '\0';//结束字符串录入 
	strrev(dech); //逆置
	i=0;
	
	do{
		decq[i] = (char)((cnum%10)+48);
		cnum /= 10;
		i++;
	} while(cnum != 0);//取整数部分，do-while原因，零也要返回 
	decq[i] = '\0';
	strrev(decq);
	
	/*
	*字符串拼接操作
	*s代表是否为负数
	*k代表是否有小数 
	*/ 
	if(s)strcat(cwnum,decq);
	else strcpy(cwnum,decq);
	if(k)
	{
		strcat(cwnum,".");
		strcat(cwnum,dech);	
	}
	
	ptr_num = cwnum;

	return ptr_num; //用数组接受 
} //double型转字符串 


