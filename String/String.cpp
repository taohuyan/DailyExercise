#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=1000;
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef char String[MAXSIZE+1];

/* 生成一个其值等于chars的串T */
Status StrAssign(String T,char *chars);

/* 由串S复制得串T */
Status StrCopy(String T,String S);

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status StrEmpty(String T);

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
Status StrCompare(String T,String S);

/* 返回串的元素个数 */
Status StrLength(String T);

/* 初始条件:串S存在。操作结果:将S清为空串 */
Status StrClear(String T);

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status Concat(String T1,String T2,String T3);

/*  输出字符串T */
void StrPrint(String T);

/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
Status SubString(String Sub,String S,int pos,int len);

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
/* 其中,T非空,1≤pos≤StrLength(S)。 */
int Index(String S, String T, int pos);

/*  T为非空串。若主串S中第pos个字符之后存在与T相等的子串， */
/*  则返回第一个这样的子串在S中的位置，否则返回0 */
int Index2(String S, String T, int pos);

/*  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
/*  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE */
Status StrInsert(String S,int pos,String T);

/*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
/*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
Status StrDelete(String S,int pos,int len);

/*  初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） */
/*  操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */
Status Replace(String S,String T,String V);

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

Status StrCopy(String T,String S)
{
    for(int i=0;i<=T[0];i++){
        S[i]=T[i];    
    }
    return OK;
}

Status StrEmpty(String T)
{
    if(T[0]!=0)
        return TRUE;
    else 
        return FALSE;
} 

Status StrCompare(String T,String S)
{
    for(int i=0;i<T[0]&&i<S[0];i++){
        if(T[i]!=S[i])
            return S[0]-T[0];
    }
        return S[0]-T[0];
}

Status StrClear(String T)
{
    if(T[0]!=0)
        T[0]=0; /*  令串长为零 */
    return OK;
}

Status Concat(String T,String S1,String S2)
{
    if(S1[0]+S2[0]<=MAXSIZE)
    {   /* 未截断 */
        T[0]=S1[0]+S2[0];
        for(int i=1;i<S1[0];i++)
            T[i]=S1[i];
        for(int i=1;i<S1[0];i++)
            T[S1[0]+i]=S1[i];
        return TRUE;
    }
    else
    {   /* 截断S2 */
		for(int i=1;i<=S1[0];i++)
			T[i]=S1[i];
		for(int i=1;i<=MAXSIZE-S1[0];i++)
			T[S1[0]+i]=S2[i];
		T[0]=MAXSIZE;
        return FALSE;
    }
}

Status SubString(String Sub,String S,int pos,int len)
{
	int i;
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
		return ERROR;
	for(i=1;i<=len;i++)
		Sub[i]=S[pos+i-1];
	Sub[0]=len;
	return OK;
}


int Index(String S, String T, int pos) 
{
	int i = pos;	/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;				/* j用于子串T中当前位置下标值 */
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (S[i] == T[j]) 	/* 两字母相等则继续 */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* 指针后退重新开始匹配 */
      	{  
         	i = i-j+2;		/* i退回到上次匹配首位的下一位 */
         	j = 1; 			/* j退回到子串T的首位 */
      	}      
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

int Index2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);	/* 得到主串S的长度 */
		m = StrLength(T);	/* 得到子串T的长度 */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString (sub, S, i, m);	/* 取主串中第i个位置长度与T相等的子串给sub */
			if (StrCompare(sub,T) != 0)    /* 如果两串不相等 */
				++i;
			else 				/* 如果两串相等 */
				return i;		/* 则返回i值 */
		}
	}
	return 0;	/* 若无子串与T相等，返回0 */
}

Status StrInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1||pos>S[0]+1)
		return ERROR;
	if(S[0]+T[0]<=MAXSIZE)
	{ /*  完全插入 */
		for(i=S[0];i>=pos;i--)
			S[i+T[0]]=S[i];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  部分插入 */
		for(i=MAXSIZE;i<=pos;i--)
			S[i]=S[i-T[0]];
		for(i=pos;i<pos+T[0];i++)
			S[i]=T[i-pos+1];
		S[0]=MAXSIZE;
		return FALSE;
	}
}

Status StrDelete(String S,int pos,int len)
{ 
	int i;
	if(pos<1||pos>S[0]-len+1||len<0)
		return ERROR;
	for(i=pos+len;i<=S[0];i++)
		S[i-len]=S[i];
	S[0]-=len;
	return OK;
}

Status Replace(String S,String T,String V)
{ 
	int i=1; /*  从串S的第一个字符起查找串T */
	if(StrEmpty(T)) /*  T是空串 */
		return ERROR;
	do
	{
		i=Index(S,T,i); /*  结果i为从上一个i之后找到的子串T的位置 */
		if(i) /*  串S中存在串T */
		{
			StrDelete(S,i,StrLength(T)); /*  删除该串T */
			StrInsert(S,i,V); /*  在原串T的位置插入串V */
			i+=StrLength(V); /*  在插入的串V后面继续查找串T */
		}
	}while(i);
	return OK;
}

/*  输出字符串T */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}