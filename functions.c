#include "My_Style.h"

int X = 0,Y = 4;
int bra = 0;//�����жϱ��� 
extern bdy;//�����������
char conum[55] = "<NULL>";

void KeyCon(char key)
{				   	  
        if(key == 72)Y--;//�� 
        if(key == 77)X++;//�� 
        if(key == 80)Y++;//�� 
        if(key == 75)X--;//�� 
        if(X > 3)X = 0;
        if(X < 0)X = 3;
        //�����ж� 
        if(Y > 4)Y = 0;
        if(Y < 0)Y = 4;
}

void KeyPut(int X,int Y,char key,int * dz)
{
	if(key == 8 && *dz > 0)
        {
        	if(conum[*dz-1] == ')')bra = 1;
        	if(conum[*dz-1] == '(')bra = 0;
        	//�����ж� 
        	SetPosstions(LEF+2+(--(*dz)),3);
        	printf(" ");//�˸񸲸� 
        }//�˸���������С�˸񳤶� 
        
		if(*dz < 52)
		{
			
			if(key >= '0' && key <= '9' || key == '.')
        	{
        		if(bdy)
       			{
        			InClaer(dz);
        		}//�ó�������ٰ���������
				conum[*dz] = key;
				if(*dz == 0 && conum[*dz] == '.' || conum[*dz-1] == '(' && conum[*dz] == '.')
        		{
        			printf("%c",(conum[*dz]='0'));
        			conum[++(*dz)]='.';
        		}//��ʼֱ�ӻ����ź�ֱ������С����ʱ��0 
        		SetPosstions(LEF+2+(*dz)++,3);
        		putch(key);
        		
        		
        	}//��ӡ��ʾ�������� ������������볤�� 
        	
        	
		
        	if(key == '+' || key == '-' || key == '*' || key == '/' || key == '%' || key == '^' || key == '(' || key == ')')
        	{
        			if(bdy)
       				{
        				InClaer(dz);
        			}//�ó�������ٰ���������
        			
        			if(key == '(')bra = 1;
        			if(key == ')')bra = 0;//�����ж� 
        			
        			conum[*dz] = key;
        			SetPosstions(LEF+2+(*dz)++,3);
      	  			putch(key);
        		
       		}//������ж� 
    	}
    	if(key == '=')
    	{
    		conum[*dz] = '\0'; //�����ַ��� 
    		Clears(LEF+2,3,+1);
    		SetPosstions(LEF+2,3);
    		Results(*dz,conum);
			(*dz)=0; //���㣬����������� 
    	}
} //�����ж� 


void Inputs(int X,int Y,char key,int * dz)
{		
		if(key == 13)
        {
        	if(bdy)
       			{
        			InClaer(dz);
        		}//�ó�������ٰ���������
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
        			}//��ʼֱ�ӻ����ź�ֱ������С����ʱ��0  
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
				//������ 
				
				//�������
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
				 }//���Ų��� 
				 if(X == 2 && Y == 0)printf("%c",conum[(*dz)++] = '%');
				 if(X == 3 && Y == 0)printf("%c",conum[(*dz)++] = '+');
				 if(X == 3 && Y == 1)printf("%c",conum[(*dz)++] = '-');
				 if(X == 3 && Y == 2)printf("%c",conum[(*dz)++] = '*');
				 if(X == 3 && Y == 3)printf("%c",conum[(*dz)++] = '/');
				 
			}
			if(X == 3 && Y == 4)
			{
				conum[*dz] = '\0'; //�����ַ��� 
    			Clears(LEF+2,3,+1);
    			SetPosstions(LEF+2,3);
    			Results(*dz,conum);
				(*dz)=0; //���㣬����������� 
			} 
			if(X == 0 && Y == 4)
			{
				InClaer(dz);
			}//���� 
			
		} 
}//�س��ж� 

void InClaer(int *dz)
{
	Clears(LEF+2,3,(*dz=0)+1);
	bra = 0;
	bdy = 0;
	*dz = 0; 
	strcpy(conum,"<NULL>");
	SetPosstions(LEF+22,4);
	SetColors(15,0);
	printf("״̬��");
	SetColors(10,0);
	printf("Normal                 "); 
	SetColors(7,0);
}

/*
*д������������˵�������������� 
*��Щ��������ң���Ҫ����װ�ơ��������Դ˻����׸�δ�����Լ� 
*/ 
int Unlaw(int dz,char num[])
{
	int i,j = 0;
	int deci = 0;//С�����ж� 
	if(dz == 0)return 0;
	for(i = 0;i < dz;i++)
	{
		if(num[i] == '(')
		{
			bra++;//Ԥ�����֣�+1+��2+3������������
			if(num[i+1] == '*' || num[i+1] == '/')j = 1;//Ԥ�����֣�*��/�������� 
		}
		//����Ϊ��/12����*12����12+/-���������� 
		if(num[i] == ')')	
		{
			if(bra <= 0)j=1; 
			bra--;
			if(num[i-1] == '+' || num[i-1] == '-')j = 1;
		}
	}
	if(bra != 0)j = 1;//����bra�ж����������Ƿ�Ե� 
	
	for(i = 0;i < dz;i++)
	{	
		if(num[i] == '(')
        		{
        			if(num[i+1] == ')' || num[i-1] >= '0' && num[i-1] <= '9')j=1;
        		}
				if(num[i] == ')')
				{
					if(num[i+1] == '(' || num[i+1] >= '0' && num[i+1] <= '9')j=1;
				}//���Ź���  ������֮�����Ҫ����������� 
		
		if(num[i] == '+' || num[i] == '-' || num[i] == '*' || num[i] == '/' || num[i] == '%' || num[i] == '^')
		{
			deci = 0;//ÿ�μ��������������С�����ж� 
			if(num[i-1] == '(' && num[i+1] == ')')j = 1;//�ж������ﲻ��ֻ��һ��Ϊ������Ĳ��� 
			if(num[i+1] == '+' || num[i+1] == '-' || num[i+1] == '*' || num[i+1] == '/' || num[i+1] == '%' || num[i+1] == '^')j=1;
			//�ж�������������� 
			if(i == 0 || i == dz-1)j=1;//��β������������ 
		} //�������һЩ���� 
		if(num[i] >= '0' && num[i] <= '9' || num[i] == '.')
		{
			if(num[i] == '.')deci += 1;
			if(deci == 2)j = 1;
		}//С����Ƿ������ж� 
		if(j)
		{
			strcpy(conum,"<NULL>");
			SetPosstions(LEF+28,4);
			SetColors(12,0);
			printf("Operator call error");//����״̬ 
			SetColors(7,0);
			SetPosstions(LEF+2,3);
			return 0;
		}//�����쳣������Ƿ����룬��j�ͻ��Ϊ1�������˺���������0 
	}
	
	return 1;
}//�Ƿ�������� 

/*
*����C���Եİ��������� 
*/ 

double Tra_ch_db(char dnum[])
{
	
	double res,//������ 
		   car = 1,//��λ 
		   plmi = 1;//��������ֵ 
	int i = 0,j = 0;//�����±����Ƿ���С���� 

	if(dnum[i] == '-')plmi = -1;//�����ж� 
	
	dnum = strrev(dnum);//�����ַ���
	
	while(dnum[i] != '\0')
	{
		if(dnum[i] == '.')j=1;//�Ƿ���С����
		i++;
	} //��ѯ�Ƿ���С���� 
	i=0;
	
	while(dnum[i] != '.' && j)
	{
		res += (dnum[i]-48)*car;
		car *= 10;
		i++;
	}//��ȡС����ǰ��ֵ 
	res /= car;//��С�� 
	
	if(j)i += (car=1); 
	
	while(dnum[i] != '\0' && dnum[i] != '-')
	{
		res += (dnum[i]-48)*car;
		car *=10;
		i++;
	}//��ȡС������ֵ 
	
	return res*plmi; 
} //�ַ���תdouble������ 


/*
*δ�޸�BUG��
*����С��ʱ��һ�������ݻᱻ���������۸� 
* ����12345.12345ʱ������12345.123449����������ܶ�
*������������ 
*ָ�뷵��ֵ�쳣 
*/ 
char * Tra_db_ch(double num)
{
	char * ptr_num = NULL;//���շ��ص�ַ 
	//ptr_num = (char *)malloc(sizeof(char)*50);
	char cwnum[50];//�洢ת��ֵ
	char decq[50],dech[50];//�洢С����ǰ����ֵ 
	int cnum = (int)num;//�������� 
	int i = 0,j = 0,s = 0,k = 0; //�����±� 
	if(num < 0)
	{
		strcpy(cwnum,"-");
		s = 1;
		num *= -1;
	}//�ж��Ƿ�Ϊ���� 
	double deciw = num-(int)num;//��ȡС�������� 
	int deci = 0;
	
	/*
	*BUG�����￪ʼ
	*���˼�룺������������ 
	*/
	//printf("dou����%d\t",sizeof(double));
	if(deciw != 0)
	{
		deci = (deciw*1e10);
	};//С�������� 
	//printf("С����%d  ",deci);
	
	while(deci != 0)
	{
		k = 1;
		dech[i] = (char)((deci%10)+48);
		deci /= 10;
		i++;
	}//С�����洢 
	dech[i] = '\0';//�����ַ���¼�� 
	strrev(dech); //����
	i=0;
	
	do{
		decq[i] = (char)((cnum%10)+48);
		cnum /= 10;
		i++;
	} while(cnum != 0);//ȡ�������֣�do-whileԭ����ҲҪ���� 
	decq[i] = '\0';
	strrev(decq);
	
	/*
	*�ַ���ƴ�Ӳ���
	*s�����Ƿ�Ϊ����
	*k�����Ƿ���С�� 
	*/ 
	if(s)strcat(cwnum,decq);
	else strcpy(cwnum,decq);
	if(k)
	{
		strcat(cwnum,".");
		strcat(cwnum,dech);	
	}
	
	ptr_num = cwnum;

	return ptr_num; //��������� 
} //double��ת�ַ��� 


