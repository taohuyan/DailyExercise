/*
 * @Author: huyantao 
 * @Date: 2023-01-08 18:25:44 
 * @Last Modified by: huyantao
 * @Last Modified time: 2023-01-09 16:52:23
 */

#include<bits/stdc++.h>
#define MAXSIZE 1001
using namespace std;

typedef int SElemtype;
typedef struct SqDoubleSqStack 
{
    SElemtype date[MAXSIZE];
    int top1;
    int top2;
    SqDoubleSqStack():
        top1(-1),top2(MAXSIZE-1){

        }
}SqDStack;

void Push(SqDoubleSqStack **S,SElemtype e,SElemtype Num_SqDStack);
void Pop(SqDoubleSqStack **S,SElemtype *e,SElemtype Num_SqDStack);

int main()
{
    return 0;
}   

/*插入元素为e的栈顶元素*/
void Push(SqDoubleSqStack **S,SElemtype e,SElemtype Num_SqDStack)
{
    if((*S)->top1+1==(*S)->top2){   //栈已满，不能再Push新元素
        cout<<"ERROR"<<endl;
        return;
    }
    if(Num_SqDStack==1){
        (*S)->date[++(*S)->top1]=e;
    }
    else if(Num_SqDStack==2)
    {
        (*S)->date[--(*S)->top2]=e;
    }
    cout<<"Push--"<<e<<"--OK"<<endl;
}

//若栈不空，则删除S的栈顶元素，并用e值返回。
void Pop(SqDoubleSqStack **S,SElemtype *e,SElemtype Num_SqDStack)
{
    if(Num_SqDStack==1){
        if((*S)->top1==-1){
            cout<<"ERROR"<<endl;
            return;
        }
        *e=(*S)->date[(*S)->top1--];
    }
    else if(Num_SqDStack==2){
        if((*S)->top2==MAXSIZE-1){
            cout<<"ERROR"<<endl;
            return;
        }
        *e=(*S)->date[(*S)->top2++];
    }
    cout<<"Pop--"<<*e<<"--OK"<<endl;
}