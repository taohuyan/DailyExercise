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
    ElemType date;      //数据域
    struct Node* next;  //指针域
    Node(int x) :        //析构函数
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
    cout << "输入链表的长度：" << endl;
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

//尾插法
void LinkListTail(LinkList* Head, int n)
{
    LinkList p;
    int num;
    *Head = new Node(n);
    p = *Head;
    for (int i = 1; i <= n; i++) {
        cout << "输入第" << i << "个数据的值" << endl;
        cin >> num;
        LinkList q = new Node(num);
        p->next = q;
        p = p->next;
    }
}

//头插法
void LinkListHead(LinkList* Head, int n)
{
    int num;
    *Head = new Node(n);
    for (int i = 1; i <= n; i++) {
        cout << "输入第" << i << "个数据的值" << endl;
        cin >> num;
        LinkList q = new Node(num);
        q->next = (*Head)->next;

        (*Head)->next = q;
    }
}

//在postion处插入e
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
    cout << "插入成功" << endl;
    LinkList s = *L;
    s->date = s->date + 1;
}

//删除postion处的数据
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
    cout << "删除成功" << endl;
}

//clear整个链表
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
    cout << "清空链表成功" << endl;
}

//输出链表数据
void PrintLinkList(LinkList Head)
{
    LinkList p = Head;
    cout << "链表的长度：" << p->date << endl;
    p = p->next;
    cout << "链表数据如下：" << endl;
    while (p != NULL) {
        cout << p->date << " ";
        p = p->next;
    }
    cout << endl;
}


/*双向链表
typedef struct DulNode
{
    ElemType date;
    struct DulNode *prior;
    struct SulNode *next;
}DulNode, *DuLinkList;
*/

/*     p->next->prior=p=p->prior->next     */