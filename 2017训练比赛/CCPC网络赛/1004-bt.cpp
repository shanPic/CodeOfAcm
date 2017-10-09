/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1004-bt.cpp
* @Author: Pic
* @Date:   2017-08-19 16:30:09
* @Last Modified time: 2017-08-22 12:18:55
*/
#include <bits/stdc++.h>
using namespace std;
/*
* next[]的含义： x[i-next[i]...i-1]=x[0...next[i]-1]
* next[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值（就是x的自身匹配）
*/
long long sum=0;
const long long mod=1e9+7;
const long long MAXN=2e6+30;
char x[MAXN],y[MAXN];
int nxt[MAXN];
void kmp_pre(char x[],int m)
{
    long long i, j;
    j = nxt[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])j = nxt[j];
        nxt[++i] = ++j;
    }
}
/*
* kmpNext[]的意思： next'[i]=next[next[...[next[i]]]] (直到next'[i]<0或者
x[next'[i]]!=x[i])
* 这样的预处理可以快一些
*/
void KMP_Count( char x[],int m,  char y[],int n)
{    //x是模式串， y是主串
    long long i, j;
    kmp_pre(x,m);
    i = j = 0;
    while (i < n)
    {
        while (-1 != j && y[i] != x[j]) {
            sum = (sum+((1+j)*j/2)%mod)%mod;
            j = nxt[j];
        }
        i++; j++;
        //sum=(sum+j)%mod;
        if (j >= m)
        {
            sum = (sum+((1+j)*j/2)%mod)%mod;
            j = nxt[j];
        }
    }
    while(j>=1){
    	sum = (sum+((1+j)*j/2)%mod)%mod;
    	j=nxt[j];
    }
}
int main()
{    
   // clock_t startTime,endTime;  
    //startTime = clock();
    //freopen("data.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",y,x);
        int len1=strlen(y);
        int len2=strlen(x);
        reverse(x,x+len2);
        reverse(y,y+len1);
        sum=0;
        KMP_Count(x,len2,y,len1);
        printf("%I64d\n",sum);
    }
    //endTime = clock();  
    //cout << "Totle Time : " <<(double)(endTime - startTime)<< "ms" << endl;
    return 0;
}