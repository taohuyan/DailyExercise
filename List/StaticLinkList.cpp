/*
 * @Author: huyantao
 * @Date: 2023-01-07 15:07:38
 * @Last Modified by: huyantao
 * @Last Modified time: 2023-01-07 15:43:47
 */
#include<bits/stdc++.h>
#define MAXSIZE 1001
using namespace std;

typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;        //�α�
}Component, StaticLinkList[MAXSIZE];

void StaticLinkListInit(StaticLinkList space);
int Molloc_SLL(StaticLinkList sapce);
void InsertStaticLinkList(StaticLinkList space, int postion, ElemType e);
int LengthStaticLinkList(StaticLinkList space);
void DelectStaticLinkList(StaticLinkList space, int postion);
void Free_SLL(StaticLinkList space, int k);

//������
int main()
{
    
}

//��ʼ����̬����
void StaticLinkListInit(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
}

//ģ�����ռ�------����
int Molloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

//��������ĳ���
int LengthStaticLinkList(StaticLinkList space)
{
    int j = 0;
    int i = space[MAXSIZE - 1].cur;
    while (i) {
        i = space[i].cur;
        j++;
    }
    return j;
}

//��postion����������e
void InsertStaticLinkList(StaticLinkList space, int postion, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;
    if (postion<1 || postion>LengthStaticLinkList(space) + 1) {
        cout << "ERROR" << endl;
        return;
    }
    j = Molloc_SLL(space);
    if (j) {
        space[j].data = e;
        for (l = 1; l <= postion - 1; l++)
            k = space[k].cur;
        space[j].cur = space[k].cur;
        space[k].cur = j;
        cout << "����ɹ�" << endl;
        return;
    }
    cout << "ERROR" << endl;
    return;
}

//ɾ��postion��������
void DelectStaticLinkList(StaticLinkList space, int postion)
{
    int j, k;
    if (postion<1 || postion>LengthStaticLinkList(space)) {
        cout << "ERROR" << endl;
        return;
    }
    k = MAXSIZE - 1;
    for (j = 1; j <= postion - 1; j++)
        k = space[k].cur;
    j = space[k].cur;
    space[k].cur = space[j].cur;
    Free_SLL(space, j);
}

//���ս��
void Free_SLL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}