#include "My_Style.h"

int bdy = 0;

void Results(int dz,char conum[])
{
	char res[55] = "<NULL>";
	bdy = 1;//��¼�Ƿ�������� 
	if(Unlaw(dz,conum))
	{
		strcpy(res,OpePri(conum));
		printf("%s",res); 
		strcpy(res,"<NULL>");
	}else{
		printf("%s",res);
		return;
	}                    
}//�����ӡ 

char * Sums(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1+num2);
	return ptr_num;
}//��
 
char * Subs(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1-num2);
	return ptr_num;
}//�� 

char * mults(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1*num2);
	return ptr_num;
}//�� 

char * Divs(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(num1/num2);
	return ptr_num;
}//�� 

char * Delis(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch((int)num1%(int)num2);
	return ptr_num;
}//ȡģ 

char * Powrs(double num1,double num2)
{
	char * ptr_num = NULL; 
	ptr_num = Tra_db_ch(pow(num1,num2));
	return ptr_num;
}//������ 

/*
*����ǰ��������ƣ������Ӧ������������ 
*˼·
*ɨ���Ƿ�Ϊ������ 
*�����ݸ���һ�ÿ������һ��˫Ŀ�����ʽ�ӣ��������̵�û�������(�����������)
*�ҳ���Ҫ��������ģ��ȴ������ţ�Ȼ���������ݣ���˳����㣩���˳����Ӽ�
*�����ַ�����+- ++ --�����
*��������*-N  /-N  ^-N  %-N  ���� 
 ----------------------------------------------------------------------------- 
*ת���ҳ�����������Ϊdouble�ͣ�ͨ��������жϵ������㺯��
*���㺯��������Ϻ�ת���ַ�������
*����������ַ����滻ԭ����λ��
*����ʽ��ͨ���ݹ�����ж����� 
*/  
char * OpePri(char num[])
{
	int i,j,k,//ѭ������ 
			ysfpd = 0,
			boolnum = 0,//����Ƿ�Ϊ������ 
			kh1 = 0,kh2;//������� 
	char *ptr_ac = NULL;//����洢 
	
	/*
	*�ϲ��������� 
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
			num[i] = num[i+1];//��ǰ���� 
		}
	}//�ϲ������ 
	
	
	for(i = 0;i < strlen(num);i++)
	{
		if(!(num[i] >= '0' && num[i] <= '9'))boolnum = 1;//�Ƿ��������� 
		if(num[0] == '-')boolnum = 0;//-----�������� 
		if(num[i] = '(')kh1 = i;//Ѱ������ 
	}//ɨ���Ƿ�Ϊ�����֣�˳��Ѱ���Ƿ������ţ�
	
	if(kh1 != 0)
	{
		for(i = kh1;i < strlen(num);i++)
		{
			if(num[i] = ')')
			{
				kh2 = i;
				break;
			}
		}//�����һ�������ſ�ʼѰ�� 
				
	}//Ѱ�ҷ����� 		
	 
	if(/*boolnum*/0)
	{
		if(kh1)
		{
			
		}//���Ŵ��� ����ѯ�������м���������� 
		return OpePri("������������ַ���");//
	}else
	{
		ptr_ac = num;
		return ptr_ac = "�����";
	}//��������ʽ�ӵ����� 
	
}//������� 

char * Prios(int begins,int ends,char nums[])
{

	return; 
} //�������ȼ� 

char * CharShorten(int begins,int ends,char num1[],char num2[])
{

	return; 
}//�ַ������� 
 

