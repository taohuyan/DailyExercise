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
    SElemType date;         //ջ��Ԫ��
    struct StackNode *next; //����ջ��ջ������
}StackNode,*LinkStackPtr;

typedef struct LinkStack 
{
    LinkStackPtr top;   //ջ
    int count;          //ջ�Ĵ�С
}LinkStack;

void Push(LinkStack *S,SElemType e);
void Pop(LinkStack *S,SElemType *e);

int main(){
    
    return 0;
}

/*����Ԫ��Ϊe��ջ��Ԫ��*/
void Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
    s->date=e;
    s->next=S->top;
    S->count++;
    cout<<"Push--"<<e<<"--OK"<<endl;
}

//��ջ���գ���ɾ��S��ջ��Ԫ�أ�����eֵ���ء�
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