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
    int top;    //����ջ��ָ��
    /*��ʼ��˳��ջ*/
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
    cout<<"������ջԪ�ظ���"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"��"<<i<<"����ջԪ��"<<endl;
        cin>>ans1;
        Push(&S,ans1);
    }
    cout<<"˳��ջ�ĳ���Ϊ��"<<endl;
    cout<<Get_Length(&S)<<endl;
    cout<<"���˳��ջ��"<<endl;
    PrintSqStack(&S);
    for(int i=0;i<n;i++){
        Pop(&S,&ans2);
    }
}

//���˳��ջS�ĳ���
int Get_Length(SqStack **S)
{
    if((*S)->top==-1||(*S)->top>=MAXSIZE-1){
        cout<<"ERROR"<<endl;
        return -1;
    }
    return (*S)->top+1; 
}

//����Ԫ��eΪ�µ�ջ��Ԫ��
void Push(SqStack **S,SElemType e)
{
    if((*S)->top==MAXSIZE-1){
        cout<<"ERROR"<<endl;
        return;
    }
    (*S)->top++;
    (*S)->data[(*S)->top]=e;
    cout<<"Ԫ��"<<e<<"��ջ�ɹ�"<<endl;
}

//��ջ���գ���ɾ��S��ջ��Ԫ�أ�����eֵ���ء�
void Pop(SqStack **S,SElemType *e)
{
    if((*S)->top==-1)
    {
        cout<<"ERROR"<<endl;
        return;
    }
    *e=(*S)->data[(*S)->top];
    (*S)->top--;
    cout<<"Ԫ��"<<*e<<"��ջ�ɹ�"<<endl;
}

//���˳��ջ��Ԫ��
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