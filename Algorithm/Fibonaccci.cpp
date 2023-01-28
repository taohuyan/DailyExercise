/*
 * @Author: huyantao 
 * @Date: 2023-01-09 16:50:43 
 * @Last Modified by: huyantao
 * @Last Modified time: 2023-01-09 16:51:10
 */

#include<bits/stdc++.h>

using namespace std;

int Fbi(int i);

int main()
{
    cout<<"递归实现斐波那契数列："<<endl;
    for(int i=0;i<40;i++){
        cout<<Fbi(i)<<" ";
    }
    cout<<endl;
}

int Fbi(int i)
{
    if(i<2)
        return i == 0 ? 0 : 1;
    return Fbi(i-1)+Fbi(i-2);
}