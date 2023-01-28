/*
 * @Author: huyantao 
 * @Date: 2023-01-09 16:14:35 
 * @Last Modified by: huyantao
 * @Last Modified time: 2023-01-09 16:48:53
 */

#include<bits/stdc++.h>
#define MAXSIZE 1001
using namespace std;

typedef int SElemType;
typedef struct StackNode
{
    SElemType date;         //栈的元素
    struct StackNode *next; //用于栈与栈的连接
}StackNode,*LinkStackPtr;

typedef struct LinkStack 
{
    LinkStackPtr top;   //栈
    int count;          //栈的大小
}LinkStack;

void Push(LinkStack *S,SElemType e);
void Pop(LinkStack *S,SElemType *e);

int main(){
    
    return 0;
}

/*插入元素为e的栈顶元素*/
void Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->date=e;
    s->next=S->top;
    S->count++;
    cout<<"Push--"<<e<<"--OK"<<endl;
}

//若栈不空，则删除S的栈顶元素，并用e值返回。
void Pop(LinkStack *S,SElemType *e)
{
    LinkStackPtr p;
    if(S->count==0){
        cout<<"ERROR"<<endl;
        return;
    }
    *e=S->top->date;
    p=S->top;
    S->top=S->top->next;
    free(p);
    S->count--;
    cout<<"Pop--"<<*e<<"--OK"<<endl;
}