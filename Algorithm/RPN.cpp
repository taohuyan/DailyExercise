/*
 * @Author: huyantao 
 * @Date: 2023-01-10 18:39:13 
 * @Last Modified by:   huyantao 
 * @Last Modified time: 2023-01-10 18:39:13 
 */
#include<bits/stdc++.h>
#define defaultsize 10
#define increasesize 5
using namespace std;
typedef struct{
	char *base;
	char *top;
	int stacksize;//ջ�Ĵ洢���� 
}OPRTstack;
typedef struct{
	double *base;
	double *top;
	int stacksize;
}NUMstack;
int createStack(OPRTstack*s)
{
	s->base=(char*)malloc(sizeof(char)*defaultsize);
	if(!s->base)return 0;
	s->top=s->base;
	s->stacksize=10;
	return 1;
}
int pop(OPRTstack *s,char *e)
{
	if(s->top==s->base)return 0;
	s->top--;
	*e=*(s->top);
	return 1;
}
int push(OPRTstack*s,char e)
{
	if(s->top-s->base>=s->stacksize)
	{
		s->base=(char*)realloc(s->base,sizeof(char)*(s->stacksize+increasesize));
		if(!s->base)return 0;
		s->top=s->base+s->stacksize;
		s->stacksize+=increasesize;

	}
	*(s->top)=e;
	s->top++;
}
int isEmpty(OPRTstack *s)
{
	if(s->top==s->base)return 1;
	else return 0;
}
char GetTop(OPRTstack *s)
{
	if(!isEmpty(s))
	{
		char*temp=s->top;
		temp--;
		return *(temp);
	}
	else return '!';//��������Ļ���ջ���治�ܴ洢��������� 
}
void showStack(OPRTstack*s)
{
	if(isEmpty(s))return ;
	for(int i=0;i<s->top-s->base;i++)
	{
		printf("%c ",s->base[i]);
	}
	printf("  ");
}
//����������ܶ࣬��ʵ����ĺ������������ļ���һģһ����ֻ�Ǵ��ݵĲ�����ͬ����

int createStack(NUMstack*s)
{
	s->base=(double*)malloc(sizeof(double)*defaultsize);
	if(!s->base)return 0;
	s->top=s->base;
	s->stacksize=10;
	return 1;
}
int pop(NUMstack *s,double *e)
{
	if(s->top==s->base)return 0;
	s->top--;
	*e=*(s->top);
	return 1;
}
int push(NUMstack*s,double e)
{
	if(s->top-s->base>=s->stacksize)
	{
		s->base=(double*)realloc(s->base,sizeof(double)*(s->stacksize+increasesize));
		if(!s->base)return 0;
		s->top=s->base+s->stacksize;
		s->stacksize+=increasesize;

	}
	*(s->top)=e;
	s->top++;
}
int isEmpty(NUMstack *s)
{
	if(s->top==s->base)return 1;
	else return 0;
}
double GetTop(NUMstack *s)
{
	if(!isEmpty(s))
	{
		double *temp=s->top;
		temp--;
		return *(temp);
	}
	else return -1;//��������Ļ���ջ���治�ܴ洢��������� 
}
void showStack(NUMstack*s)
{
	if(isEmpty(s))return ;
	for(int i=0;i<s->top-s->base;i++)
	{
		printf("%f ",s->base[i]);
	}
	printf("  ");
}



int isOPRT(char c)//�ж�c�ǲ�������� 
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='#')return 1;
	else return 0;
}
char compare(char a,char b)
{
	if(a=='+')
	{
		if(b=='*'||b=='/'||b=='(') return '<';
		else return '>';
	}
	else if(a=='-')
	{
		if(b=='*'||b=='/'||b=='(') return '<';
		else return '>';
	}
	else if(a=='*')
	{
		if(b=='(')return '<';
		else return '>';
	}
	else if(a=='/')
	{
		if(b=='(')return '<';
		else return '>';
	}
	else if(a=='(')
	{
		if(b==')')return '=';
		else if(b=='#') return '!';
		else return '<';
	}
	else if(a==')')
	{
		if(b=='(')return '!';
		else return '>';
		
	}
	else if(a=='#')
	{
		if(b==')')return '!';
		if(b=='#')return '=';
		else return '<';
	}
}
double calculate(double left,double right, char operators)
{
	switch(operators)
	{
		case '+':
			return left+right;
			
		case '-':
			return 1.0*left-right;
			
		case '*':
			return left*right;
			
		case '/':
			return 1.0*left/right;
	}
}


int main()
{
	OPRTstack oprt;//�����ջ 
	NUMstack  num;//��������ջ 
	NUMstack temp;//�����������ڹ����������������� 
	int build=0;//��������λ���ɵ����� 
	double index;//ĳ����λ�ϵ����� 
	int complex=1;//10���ݴ� 
	char operators;//�������ʽ�е���������� 
	double left,right;//�������ʽ�������������� 
	createStack(&num);
	createStack(&oprt);
	createStack(&temp);
	printf("����������ʽ����#����\n"); 
	push(&oprt,'#');
	char c=getchar();
	int error=0;//syntax error ��ʶ�� 
	while(c!='#'||GetTop(&oprt)!='#')
	{
		while(!isOPRT(c))//����������� 
		{
			push(&temp,c-'0');
			c=getchar();
		}
		while(!isEmpty(&temp))//����ȡ���������ַ����뻺������������������������ 
		{
			pop(&temp,&index);
			build+=(index*complex);
			complex*=10 ;
			
		}
		complex=1;
		if(build)push(&num,double(build));//������������ѹ��ջnum 
		printf("\n�����ջ��");
		showStack(&oprt);
		printf("������ջ��");
		showStack(&num);//ÿ��ѹջ��ջ����Ҫ��ӡ��Ϣ 
		build=0;
		
		if(isOPRT(c))//������������ 
		{
			switch(compare(GetTop(&oprt),c)){
				case '<':
					push(&oprt,c);
					c=getchar();
					printf("\n�����ջ��");
					showStack(&oprt);
					printf("������ջ��");
					showStack(&num); 
					break;
					
				case '=':
					pop(&oprt,&operators);
					c=getchar();
					printf("\n�����ջ��");
					showStack(&oprt);
					printf("������ջ��");
					showStack(&num);
					break;
					
				case '>':
					pop(&oprt,&operators);
					pop(&num,&right);
					pop(&num,&left);
					push(&num,calculate(left,right,operators));//��numջ���������������֣����������ջ��Ԫ�ؽ��м��� 
					printf("\n�����ջ��");
					showStack(&oprt);
					printf("������ջ��");
					showStack(&num);
					break;
					
				case '!':
					printf("Syntax Error!");
					error=1;
					break;
			}
				
					
			
		}
		if(error)break;
	}
	if(!error)printf("���Ϊ��%f",GetTop(&num));
	return 0;
}
