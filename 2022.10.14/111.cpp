#include <iostream>
#include<iomanip>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct
{//运算符栈
    char *base;
	char *top;
	int stacksize;
}SqStack1;
Status InitStack1(SqStack1 &S)
{//运算符栈初始化
	S.base = new char[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
Status Push1(SqStack1 &S, char e)
{//运算符栈入栈
	if(S.top - S.base == S.stacksize) return ERROR;
    *S.top++=e;
    return OK;
}
Status Pop1(SqStack1 &S)
{//运算符栈出栈
    char e;
	if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
char GetTop1(SqStack1 S)
{//运算符栈取栈顶元素
	if(S.top != S.base)
        return *(S.top - 1);
}
typedef struct
{//操作数栈
	double *base;
	double *top;
	int  stacksize;
}SqStack2;
Status InitStack2(SqStack2 &S)
{//操作数栈初始化
	S.base = new double[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
Status Push2(SqStack2 &S,double e)
{//操作数栈入栈
	if(S.top - S.base == S.stacksize) return ERROR;
    *S.top++=e;
    return OK;
}
Status Pop2(SqStack2 &S)
{//操作数栈出栈
    double e;
	if(S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}
double GetTop2(SqStack2 S)
{//操作数栈取栈顶元素
	if(S.top != S.base)
        return *(S.top - 1);
}
double Calculate(double a,char op,double b)
{//计算表达式“a op b”的值
    if(op=='+')
		return b+a;
	else if(op=='-')
		return b-a;
	else if(op=='*')
		return b*a;
	else if(op=='/')
		return b/a;
}

char Precede(char a,char b)
{//比较运算符a和b的优先级
	if((a == '(' && b == ')') || (b == '(' && a == ')'))
		return '=';
	else if(a == '('|| a=='='||b=='('|| (a=='+'||a=='-') && (b=='*'||b=='/'))
		return '<'; 
	else
		return '>';
}


double EvaluateExpression(SqStack1 OPTR,SqStack2 OPND,char s[])
{//算术表达式求值的算符优先算法
 //设OPTR和OPND分别为运算符栈和操作数栈
 //表达式求值算法调用Precede函数和Calculate函数 
	//while(s[0]!='=')
	//{
        //InitStack1(OPTR);//运算符栈
        //InitStack2(OPND);//数栈

		//Push1(OPTR,'=');


		int i,x=0,e=0,flag=0;
		for(i=0;s[i]!='\0';i++)
		{
			if('0'<=s[i]&&s[i]<='9')
			{
				flag=1;
				x=x*10+(s[i]-'0');	
				if(e!=0)
					e=e*10;
			}
			else if(s[i]=='.')
				e=1;
			else		
			{
				if(flag!=0)
				{
					double number=x;	
					if(e!=0)
						number=number/e;
					Push2(OPND,number);		
					x=e=flag=0;
				}
				while(1)
				{
					if(Precede(GetTop1(OPTR),s[i])=='<')			
					{
						Push1(OPTR,s[i]);		
						break;
					}
					else if(Precede(GetTop1(OPTR),s[i])=='>')	
					{
						double a=GetTop2(OPND);
						Pop2(OPND);
						double b=GetTop2(OPND);
						Pop2(OPND);
						char oper=GetTop1(OPTR);
						Pop1(OPTR);
						Push2(OPND,Calculate(a,oper,b));
					}
					else
					{
						Pop1(OPTR);				
						break;
					}
				}
			}
		}
        return GetTop2(OPND);	
	//}
	return 0;
}
