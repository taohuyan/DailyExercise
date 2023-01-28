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
	int stacksize;//栈的存储容量 
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
	else return '!';//这样定义的话，栈里面不能存储！这个数据 
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
//看起来代码很多，其实下面的函数定义和上面的几乎一模一样，只是传递的参数不同而已

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
	else return -1;//这样定义的话，栈里面不能存储！这个数据 
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



int isOPRT(char c)//判断c是不是运算符 
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
	OPRTstack oprt;//运算符栈 
	NUMstack  num;//运算数字栈 
	NUMstack temp;//缓冲区，用于构建完整的运算数字 
	int build=0;//由若干数位构成的数字 
	double index;//某个数位上的数字 
	int complex=1;//10的幂次 
	char operators;//基本表达式中的四则运算符 
	double left,right;//基本表达式中左右运算数字 
	createStack(&num);
	createStack(&oprt);
	createStack(&temp);
	printf("键入运算表达式，以#结束\n"); 
	push(&oprt,'#');
	char c=getchar();
	int error=0;//syntax error 标识符 
	while(c!='#'||GetTop(&oprt)!='#')
	{
		while(!isOPRT(c))//读入的是数字 
		{
			push(&temp,c-'0');
			c=getchar();
		}
		while(!isEmpty(&temp))//将读取到的数字字符存入缓冲区，构建完整的运算数字 
		{
			pop(&temp,&index);
			build+=(index*complex);
			complex*=10 ;
			
		}
		complex=1;
		if(build)push(&num,double(build));//将此运算数字压入栈num 
		printf("\n运算符栈：");
		showStack(&oprt);
		printf("运算数栈：");
		showStack(&num);//每次压栈弹栈都需要打印信息 
		build=0;
		
		if(isOPRT(c))//读入的是运算符 
		{
			switch(compare(GetTop(&oprt),c)){
				case '<':
					push(&oprt,c);
					c=getchar();
					printf("\n运算符栈：");
					showStack(&oprt);
					printf("运算数栈：");
					showStack(&num); 
					break;
					
				case '=':
					pop(&oprt,&operators);
					c=getchar();
					printf("\n运算符栈：");
					showStack(&oprt);
					printf("运算数栈：");
					showStack(&num);
					break;
					
				case '>':
					pop(&oprt,&operators);
					pop(&num,&right);
					pop(&num,&left);
					push(&num,calculate(left,right,operators));//从num栈弹出两个运算数字，利用运算符栈顶元素进行计算 
					printf("\n运算符栈：");
					showStack(&oprt);
					printf("运算数栈：");
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
	if(!error)printf("结果为：%f",GetTop(&num));
	return 0;
}
