/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1004-pro-3.cpp
* @Author: Pic
* @Date:   2017-08-19 16:30:09
* @Last Modified time: 2017-08-19 20:20:57
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
char s1[MAXN],s2[MAXN];
void kmp_pre(char x[], long long m, long long next[])
{
    long long i, j;
    j = next[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])j = next[j];
        next[++i] = ++j;
    }
}
/*
* kmpNext[]的意思： next'[i]=next[next[...[next[i]]]] (直到next'[i]<0或者
x[next'[i]]!=x[i])
* 这样的预处理可以快一些
*/
void preKMP(char x[], long long m, long long kmpNext[])
{
    long long i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])j = kmpNext[j];
        if (x[++i] == x[++j])kmpNext[i] = kmpNext[j];
        else kmpNext[i] = j;
    }
}
/*
* 返回x在y中出现的次数，可以重叠
*/
long long nxt[MAXN];
long long KMP_Count(char x[], long long m, char y[], long long n)
{    //x是模式串， y是主串
    long long i, j;
    long long ans = 0;
   // preKMP(x,m,nxt);
    kmp_pre(x,m,nxt);
    i = j = 0;
    while (i < n)
    {
        while (-1 != j && y[i] != x[j]) {
        	//sum=(sum+j)%mod;
            j = nxt[j];
            for(int k=j;k>0;k--){
            	sum=(sum+k)%mod;
            }
            // sum=(sum+j)%mod;
        }
        i++; j++;
        //sum=(sum+j)%mod;
        if (j >= m)
        {
            ans++;
            j = nxt[j];
            	//sum=(sum+j)%mod;
            for(int k=j;k>0;k--){
            	sum=(sum+k)%mod;
            }
        }
    }
    while(j>=1){
    	for(int k=j;j>0;k--){
    		sum=(sum+k)%mod;
    	}
    	j=nxt[j];
    }
    return ans;
}
int main()
{	
   // clock_t startTime,endTime;  
    //startTime = clock();
	freopen("data.in","r",stdin);
	//freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",s1,s2);
		long long len1=strlen(s1);
		long long len2=strlen(s2);
		//if(len1<len2) swap(s1,s2);
		reverse(s1,s1+len1);
        reverse(s2,s2+len2);
        sum=0;
        KMP_Count(s2,len2,s1,len1);
        printf("%I64d\n",sum);
    }
	//endTime = clock();  
    //cout << "Totle Time : " <<(double)(endTime - startTime)<< "ms" << endl;
	return 0;
}