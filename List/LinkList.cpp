/*
 * @Author: huyantao
 * @Date: 2023-01-04 21:55:23
 * @Last Modified by: huyantao
 * @Last Modified time: 2023-01-07 18:41:46
 */

#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct Node
{
    ElemType date;      //������
    struct Node* next;  //ָ����
    Node(int x) :        //��������
        date(x), next(NULL) {

    }
}Node;
typedef struct Node* LinkList;

void LinkListHead(LinkList* Head, int n);
void LinkListTail(LinkList* Head, int n);
void InsertLinkList(LinkList* L, int postion, ElemType e);
void DelectLinkList(LinkList* L, int postion);
void ClearLinkList(LinkList* L);
void PrintLinkList(LinkList L);

int main() {
    LinkList Head;
    int H_Length;
    cout << "��������ĳ��ȣ�" << endl;
    cin >> H_Length;
    //    LinkListHead(&Head,H_Length);
    LinkListTail(&Head, H_Length);
    PrintLinkList(Head);
    InsertLinkList(&Head, 5, 5);
    PrintLinkList(Head);
    DelectLinkList(&Head, 5);
    PrintLinkList(Head);
    ClearLinkList(&Head);
}

//β�巨
void LinkListTail(LinkList* Head, int n)
{
    LinkList p;
    int num;
    *Head = new Node(n);
    p = *Head;
    for (int i = 1; i <= n; i++) {
        cout << "�����" << i << "�����ݵ�ֵ" << endl;
        cin >> num;
        LinkList q = new Node(num);
        p->next = q;
        p = p->next;
    }
}

//ͷ�巨
void LinkListHead(LinkList* Head, int n)
{
    int num;
    *Head = new Node(n);
    for (int i = 1; i <= n; i++) {
        cout << "�����" << i << "�����ݵ�ֵ" << endl;
        cin >> num;
        LinkList q = new Node(num);
        q->next = (*Head)->next;

        (*Head)->next = q;
    }
}

//��postion������e
void InsertLinkList(LinkList* L, int postion, ElemType e)
{
    LinkList p;
    p = *L;
    int j = 1;
    while (p && j < postion) {
        p = p->next;
        ++j;
    }
    if (!p || j > postion) {
        cout << "ERROR" << endl;
        return;
    }
    LinkList q = new Node(e);
    q->next = p->next;
    p->next = q;
    cout << "����ɹ�" << endl;
    LinkList s = *L;
    s->date = s->date + 1;
}

//ɾ��postion��������
void DelectLinkList(LinkList* L, int postion)
{
    LinkList p;
    p = *L;
    int j = 1;
    while (p->next && j < postion) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j < postion) {
        cout << "ERROR" << endl;
        return;
    }
    LinkList q = p->next;
    p->next = q->next;
    free(q);
    LinkList s = *L;
    s->date = s->date - 1;
    cout << "ɾ���ɹ�" << endl;
}

//clear��������
void ClearLinkList(LinkList* L)
{
    LinkList p, q;
    p = *L;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    cout << "�������ɹ�" << endl;
}

//�����������
void PrintLinkList(LinkList Head)
{
    LinkList p = Head;
    cout << "����ĳ��ȣ�" << p->date << endl;
    p = p->next;
    cout << "�����������£�" << endl;
    while (p != NULL) {
        cout << p->date << " ";
        p = p->next;
    }
    cout << endl;
}


/*˫������
typedef struct DulNode
{
    ElemType date;
    struct DulNode *prior;
    struct SulNode *next;
}DulNode, *DuLinkList;
*/

/*     p->next->prior=p=p->prior->next     */