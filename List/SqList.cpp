/*
 * @Author: huyantao
 * @Date: 2023-01-03 18:38:34
 * @Last Modified by:   huyantao
 * @Last Modified time: 2023-01-03 18:38:34
 */

#include<bits/stdc++.h>

using namespace std;
#define SIZE 20
typedef int ElemType;
typedef struct
{
    int* head; //��̬����
    int size;  //�ռ��С
    int length;//���鳤��
}SqList;

SqList InitSqList();
int InsertSqList(SqList* L, int position, ElemType e);
void ShowSqList(SqList L);
void GetDate(SqList L, ElemType e);
void test();

int main()
{
    test();
    return 0;
}

//��ʼ������
SqList InitSqList() {
    SqList L;
    L.head = (int*)malloc(SIZE * sizeof(int));

    if (!(L.head)) {
        cout << "��ʼ��ʧ��" << endl;
        exit(0);
    }
    L.size = SIZE;
    L.length = 0;
    return L;
}

//�������
int InsertSqList(SqList* L, int position, ElemType e) {
    if (L->length >= SIZE)
        return 0;
    if (position<1 || position>L->length + 1)
        return 1;
    if (position <= L->length) {
        for (int i = L->length - 1; i >= position - 1; i--) {
            L->head[i + 1] = L->head[i];
        }
    }
    L->head[position - 1] = e;
    L->length++;

    return 2;
}

//ɾ������
int DeleteSqList(SqList* L, int postion) {
    if (L->length < 1)
        return 0;
    if (postion<1 || postion>L->length + 1)
        return 1;
    if (postion <= L->length) {
        for (int i = postion - 1; i < L->length; i++) {
            L->head[i] = L->head[i + 1];
        }
    }
    L->head[L->length - 1] == 0;
    L->length--;

    return 2;
}

//���Ҳ���
int GetPostion(SqList* L, ElemType e) {
    if (L->length < 1) {
        cout << "˳���Ϊ��" << endl;
        return -1;
    }
    for (int i = 0; i < L->length; i++) {
        if (L->head[i] == e)
            return i + 1;
    }
    return -2;
}

int GetDate(SqList* L, ElemType postion) {
    if (L->length < 1)
        cout << "˳���Ϊ��" << endl;
    return L->head[postion - 1];
}

//��ʾ����
void ShowSqList(SqList L) {
    if (L.length < 1) {
        cout << "˳���Ϊ��" << endl;
    }
    else {
        cout << "˳���ĳ��ȣ�" << L.length << endl;
        cout << "˳�����������£�" << endl;
        for (int i = 0; i < L.length; i++) {
            cout << L.head[i] << " ";
        }
        cout << endl;
    }
}

//��������
void test() {
    int s_ans, d_ans, G_ans1;
    SqList L = InitSqList();
    for (int i = 1; i <= 10; i++) {
        s_ans = InsertSqList(&L, i, i);
        if (s_ans == 0)
            cout << "˳�������" << endl;
        else if (s_ans == 1) {
            cout << "����λ��Խ��" << endl;
        }
        else if (s_ans == 2) {
            cout << i << "----" << "����ɹ�" << endl;
        }
    }
    ShowSqList(L);

    int D_postion = 5;
    d_ans = DeleteSqList(&L, D_postion);
    if (d_ans == 0)
        cout << "˳���Ϊ��" << endl;
    else if (d_ans == 1) {
        cout << "ɾ��λ��Խ��" << endl;
    }
    else if (d_ans == 2) {
        cout << "��" << D_postion << "λ����" << "----" << "ɾ���ɹ�" << endl;
    }
    ShowSqList(L);

    int G_postion = 6;
    cout << "���ҵ�" << G_postion << "λ������" << endl;
    cout << "����Ϊ��" << GetDate(&L, G_postion) << endl;

    int G_Date = 8;
    cout << "����ֵΪ" << G_Date << "��λ��" << endl;
    G_ans1 = GetPostion(&L, G_Date);
    if (G_ans1 == -1) {
        cout << "˳���Ϊ��" << endl;
    }
    else if (G_ans1 == -2) {
        cout << "���ݲ�����" << endl;
    }
    else {
        cout << "λ��Ϊ��" << G_ans1 << endl;
    }
}