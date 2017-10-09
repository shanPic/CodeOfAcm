/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1004-pro-2.cpp
* @Author: Pic
* @Date:   2017-08-19 15:26:31
* @Last Modified time: 2017-08-19 16:29:54
*/
#include <bits/stdc++.h>
using namespace std;
/*
* next[]的含义： x[i-next[i]...i-1]=x[0...next[i]-1]
* next[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值（就是x的自身匹配）
*/
int sum=0;
const int mod=1e9+7;
const int MAXN=1e6+30;
char s1[MAXN],s2[MAXN];
int sums[MAXN];
void kmp_pre(char x[], int m, int next[])
{
	int i, j;
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
void preKMP(char x[], int m,int n, int kmpNext[])
{
	int i=n, j=m;
	j = kmpNext[m-1] = -1;
	while (i >= 0 )
	{
		while (-1 != j && x[i] != x[j]) j = kmpNext[j];
		if (x[--i] == x[--j]) kmpNext[i] = kmpNext[j];
		else kmpNext[i] = j;
	}
}
/*
* 返回x在y中出现的次数，可以重叠
*/
int nxt[MAXN];
int KMP_Count(char x[], int m, char y[], int n)
{	//x是模式串， y是主串
	int i, j;
	int ans = 0;
	preKMP(x,m,nxt);
	//kmp_pre(x, m, nxt);
	i = n-1;
	j=m-1;
	while (i < 0)
	{
		while (-1 != j && y[i] != x[j]) {
			// for(int k=j-1;k>=0;k--){
			// 	sums[k]+=k;
			// }
			j = nxt[j];
		}
		i--; j--;
		// for(int k=j-1;k>=0;k--){
		// 	//sums[k]++;
		// 	sum=(sum+1)%mod;
		// }
		sum=(sum+(m-j-1))%mod;
		if (j <= 0 )
		{
			ans++;
			j = nxt[j];
			// for(int k=j-1;k>=0;k--){
			// 	//sums[k]++;
			// 	sum=(sum+1)%mod;
			// }
			sum=(sum+(m-j-1))%mod;
		}
	}
	return ans;
}
int main()
{
	clock_t startTime,endTime;  
    startTime = clock();

	freopen("data2.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		int len1=-1,len2=-1;
		// char ch;
		// while((ch=getchar())&&ch!='\n'){
		// 	s1[++len1]=ch;
		// }
		// ++len1;
		// s1[len1]='\0';
		scanf("%s",s1);
		len1=strlen(s1);
		//reverse(s1,s1+len1);
		// while((ch=getchar())&&ch!='\n'){
		// 	s2[++len2]=ch;
		// }
		// ++len2;
		// s2[len2]='\0';
		scanf("%s",s2);
		len2=strlen(s2);
		//reverse(s2,s2+len2);
		sum=0;
		KMP_Count(s2,len2,s1,len1);
		printf("%d\n",sum);
	}
	endTime = clock();  
    cout << "Totle Time : " <<(double)(endTime - startTime)<< "ms" << endl;
    return 0;
}