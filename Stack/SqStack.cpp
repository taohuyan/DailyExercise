/*
 * @Author: huyantao 
 * @Date: 2023-01-08 17:58:58 
 * @Last Modified by: huyantao
 * @Last Modified time: 2023-01-08 18:24:55
 */

#include<bits/stdc++.h>
#define MAXSIZE 1001

using namespace std;
typedef int SElemType;
typedef struct SqStack
{
    SElemType data[MAXSIZE];
    int top;    //用于栈顶指针
    /*初始化顺序栈*/
    SqStack(int x):
        top(x){

        } 
}SqStack;

void Push(SqStack **S,SElemType e);
void Pop(SqStack **S,SElemType *e);
int Get_Length(SqStack **S); 
void PrintSqStack(SqStack **S);

int main()
{
    SqStack *S=new SqStack(-1);
    int n,ans1,ans2;
    cout<<"输入入栈元素个数"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"第"<<i<<"个入栈元素"<<endl;
        cin>>ans1;
        Push(&S,ans1);
    }
    cout<<"顺序栈的长度为："<<endl;
    cout<<Get_Length(&S)<<endl;
    cout<<"输出顺序栈："<<endl;
    PrintSqStack(&S);
    for(int i=0;i<n;i++){
        Pop(&S,&ans2);
    }
}

//获得顺序栈S的长度
int Get_Length(SqStack **S)
{
    if((*S)->top==-1||(*S)->top>=MAXSIZE-1){
        cout<<"ERROR"<<endl;
        return -1;
    }
    return (*S)->top+1; 
}

//插入元素e为新的栈顶元素
void Push(SqStack **S,SElemType e)
{
    if((*S)->top==MAXSIZE-1){
        cout<<"ERROR"<<endl;
        return;
    }
    (*S)->top++;
    (*S)->data[(*S)->top]=e;
    cout<<"元素"<<e<<"入栈成功"<<endl;
}

//若栈不空，则删除S的栈顶元素，并用e值返回。
void Pop(SqStack **S,SElemType *e)
{
    if((*S)->top==-1)
    {
        cout<<"ERROR"<<endl;
        return;
    }
    *e=(*S)->data[(*S)->top];
    (*S)->top--;
    cout<<"元素"<<*e<<"出栈成功"<<endl;
}

//输出顺序栈的元素
void PrintSqStack(SqStack **S)
{
    if((*S)->top==-1){
        cout<<"ERROR"<<endl;
        return;
    }
    for(int i=(*S)->top;i>=0;i--){
        cout<<(*S)->data[i]<<" ";
    }
    cout<<endl;
}