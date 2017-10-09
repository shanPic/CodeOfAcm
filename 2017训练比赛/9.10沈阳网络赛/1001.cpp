/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\1001.cpp
* @Author: Pic
* @Date:   2017-09-10 12:50:43
* @Last Modified time: 2017-09-10 17:02:08
*/
#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <stack>  
#include <queue>  
#include <map>  
#include <set>  
#include <vector>  
#include <math.h>  
#include <bitset>  
#include <algorithm>  
#include <climits>  
using namespace std;  
  
#define LS 2*i  
#define RS 2*i+1  
#define UP(i,x,y) for(i=x;i<=y;i++)  
#define DOWN(i,x,y) for(i=x;i>=y;i--)  
#define MEM(a,x) memset(a,x,sizeof(a))  
#define W(a) while(a)  
#define gcd(a,b) __gcd(a,b)  
#define LL long long  
#define N 20005  
#define MOD 1000000007  
#define INF 0x3f3f3f3f  
#define EXP 1e-8  
const int maxn=3*1e6;
int wa[N],wb[N],wsf[N],wv[N],sa[N];  
int ran[N],height[N],a[N];  
char s[N];
char str1[N],str2[N];  
//sa:字典序中排第i位的起始位置在str中第sa[i]  
//rank:就是str第i个位置的后缀是在字典序排第几  
//height：字典序排i和i-1的后缀的最长公共前缀  
int cmp(int *r,int a,int b,int k)  
{  
    return r[a]==r[b]&&r[a+k]==r[b+k];  
}  
void getsa(char *r,int *sa,int n,int m)//n要包含末尾添加的0  
{  
    int i,j,p,*x=wa,*y=wb,*t;  
    for(i=0; i<m; i++)  wsf[i]=0;  
    for(i=0; i<n; i++)  wsf[x[i]=r[i]]++;  
    for(i=1; i<m; i++)  wsf[i]+=wsf[i-1];  
    for(i=n-1; i>=0; i--)  sa[--wsf[x[i]]]=i;  
    p=1;  
    j=1;  
    for(; p<n; j*=2,m=p)  
    {  
        for(p=0,i=n-j; i<n; i++)  y[p++]=i;  
        for(i=0; i<n; i++)  if(sa[i]>=j)  y[p++]=sa[i]-j;  
        for(i=0; i<n; i++)  wv[i]=x[y[i]];  
        for(i=0; i<m; i++)  wsf[i]=0;  
        for(i=0; i<n; i++)  wsf[wv[i]]++;  
        for(i=1; i<m; i++)  wsf[i]+=wsf[i-1];  
        for(i=n-1; i>=0; i--)  sa[--wsf[wv[i]]]=y[i];  
        t=x;  
        x=y;  
        y=t;  
        x[sa[0]]=0;  
        for(p=1,i=1; i<n; i++)  
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)? p-1:p++;  
    }  
}  
void getheight(char *r,int n)//n不保存最后的0  
{  
    int i,j,k=0;  
    for(i=1; i<=n; i++)  ran[sa[i]]=i;  
    for(i=0; i<n; i++)  
    {  
        if(k)  
            k--;  
        else  
            k=0;  
        j=sa[ran[i]-1];  
        while(r[i+k]==r[j+k])  
            k++;  
        height[ran[i]]=k;  
    }  
}  
int ans,n,m;  
int fun(int k)  
{  
	int num=0;
	for(int i=2;i<=n;i++){
		if(height[i]<k){
			num++;
		}
	}
	return num;
}  

    
int main() {
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		//cout<<1111<<endl;
		scanf("%d",&m); 
		scanf("%s",s);
		n=strlen(s);
        s[n] = 0;  
        getsa(s,sa,n+1,127);  
        getheight(s,n);  
        int ans=0;
		for(int i=1;i<=n;i++){
			//cout<<111<<endl;
			// if(fun(i)){
			// 	ans++;
			// }
			ans+=fun(i);
		}
        printf("%d\n",ans);  
	}


	return 0;
}