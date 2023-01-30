#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 1000
#define ERROR 0
#define OK 1

typedef int Status;
typedef char String[MAXSIZE+1];

Status StrAssign(String T,char *chars);
Status StrLength(String T);

int main()
{
    String s;
    StrAssign(s,(char*)"abcdefg");
    for(int i=0;i<=StrLength(s);i++){
        cout<<s[i]<<endl;
    }
    cout<<StrLength(s)<<endl;
}

Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

Status StrLength(String T)
{
    return T[0];
}
