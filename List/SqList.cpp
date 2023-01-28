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
    int* head; //动态数组
    int size;  //空间大小
    int length;//数组长度
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

//初始化操作
SqList InitSqList() {
    SqList L;
    L.head = (int*)malloc(SIZE * sizeof(int));

    if (!(L.head)) {
        cout << "初始化失败" << endl;
        exit(0);
    }
    L.size = SIZE;
    L.length = 0;
    return L;
}

//插入操作
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

//删除操作
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

//查找操作
int GetPostion(SqList* L, ElemType e) {
    if (L->length < 1) {
        cout << "顺序表为空" << endl;
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
        cout << "顺序表为空" << endl;
    return L->head[postion - 1];
}

//显示操作
void ShowSqList(SqList L) {
    if (L.length < 1) {
        cout << "顺序表为空" << endl;
    }
    else {
        cout << "顺序表的长度：" << L.length << endl;
        cout << "顺序表的数据如下：" << endl;
        for (int i = 0; i < L.length; i++) {
            cout << L.head[i] << " ";
        }
        cout << endl;
    }
}

//测试样例
void test() {
    int s_ans, d_ans, G_ans1;
    SqList L = InitSqList();
    for (int i = 1; i <= 10; i++) {
        s_ans = InsertSqList(&L, i, i);
        if (s_ans == 0)
            cout << "顺序表已满" << endl;
        else if (s_ans == 1) {
            cout << "插入位置越界" << endl;
        }
        else if (s_ans == 2) {
            cout << i << "----" << "插入成功" << endl;
        }
    }
    ShowSqList(L);

    int D_postion = 5;
    d_ans = DeleteSqList(&L, D_postion);
    if (d_ans == 0)
        cout << "顺序表为空" << endl;
    else if (d_ans == 1) {
        cout << "删除位置越界" << endl;
    }
    else if (d_ans == 2) {
        cout << "第" << D_postion << "位数据" << "----" << "删除成功" << endl;
    }
    ShowSqList(L);

    int G_postion = 6;
    cout << "查找第" << G_postion << "位的数据" << endl;
    cout << "数据为：" << GetDate(&L, G_postion) << endl;

    int G_Date = 8;
    cout << "查找值为" << G_Date << "的位置" << endl;
    G_ans1 = GetPostion(&L, G_Date);
    if (G_ans1 == -1) {
        cout << "顺序表为空" << endl;
    }
    else if (G_ans1 == -2) {
        cout << "数据不存在" << endl;
    }
    else {
        cout << "位置为：" << G_ans1 << endl;
    }
}