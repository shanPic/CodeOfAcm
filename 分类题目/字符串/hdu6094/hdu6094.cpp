/*
* @FileName: D:\代码与算法\acm题目\字符串\hdu6094\hdu6094.cpp
* @Author: Pic
* @Created Time: 2017/9/11 21:41:18
*/
#include <bits/stdc++.h>
using namespace std;
/*
 * 后缀数组的DA算法实现
*suffix array
*倍增算法 O(n*logn)
*待排序数组长度为n,放在0~n-1中，在最后面补一个0
*da(str ,n+1,sa,rank,height, , );//注意是n+1;
*例如：
*n = 8;
*num[] = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
*rank[] = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]为有效值， rank[n]必定为0无效
值 *
sa[] = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值， sa[0]必定为n是无效值
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值
*
*/
const int MAXN = 200010;
int t1[MAXN], t2[MAXN], c[MAXN]; //求SA数组需要的中间变量，不需要赋值
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0， r[n-1]=0
//函数结束以后结果放在sa数组中
bool cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int str[], int sa[], int Rank[], int height[], int n, int m)
{
	n++;
	int i, j, p, *x = t1, *y = t2;
//第一轮基数排序，如果s的最大值很大，可改为快速排序
	for (i = 0; i < m; i++)c[i] = 0;
	for (i = 0; i < n; i++)c[x[i] = str[i]]++;
	for (i = 1; i < m; i++)c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--)sa[--c[x[i]]] = i;
	for (j = 1; j <= n; j <<= 1)
	{
		p = 0;
//直接利用sa数组排序第二关键字
		for (i = n - j; i < n; i++)y[p++] = i; //后面的j个数第二关键字为空的最小
		for (i = 0; i < n; i++)if (sa[i] >= j)y[p++] = sa[i] - j;
//这样数组y保存的就是按照第二关键字排序的结果
//基数排序第一关键字
		for (i = 0; i < m; i++)c[i] = 0;
		for (i = 0; i < n; i++)c[x[y[i]]]++;
		for (i = 1; i < m; i++)c[i] += c[i - 1];
		for (i = n - 1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
//根据sa和x数组计算新的x数组
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for (i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		if (p >= n)break;
		m = p;//下次基数排序的最大值
	}
	int k = 0;
	n--;
	for (i = 0; i <= n; i++)Rank[sa[i]] = i;
	for (i = 0; i < n; i++)
	{
		if (k)k--;
		j = sa[Rank[i] - 1];
		while (str[i + k] == str[j + k])k++;
		height[Rank[i]] = k;
	}
}
int Rank[MAXN], height[MAXN];
int RMQ[MAXN];
char str[MAXN];
int r[MAXN];
int sa[MAXN];
int d[MAXN][50];
void rmq_init(int* A, int n){  
    for (int i = 0; i < n; ++i) d[i][0] = A[i];  
    for (int j = 1; (1<<j) <= n; ++j)  
        for (int i = 0; i + (1<<j) - 1 < n ; ++i)  
            d[i][j] = min(d[i][j-1], d[i + (1<< (j-1))][j-1]);  
}  
  
int ASK(int l,int r){  
    int k = 0;  
    while((1<<(k+1)) <= r-l + 1) ++k;  
    return min(d[l][k], d[r-(1<<k) + 1][k]);  
}  
int len;
int lcp(int l,int r){  
    if (l == r) return len - sa[r]; /// l == r的话 是一个串， 返回本身的长度即可。  
    return ASK(l + 1, r); ///否则在rmq查询。  
}  

int main()
{
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int k; 
		scanf("%d",&k);
		scanf("%s",str);
		len = strlen(str);
		for (int i = 0; i < len; i++) r[i] = str[i];
		r[len] = 0;
		da(r, sa, Rank, height, len, 180);
		rmq_init(height,len+1);
		int ans=0;
		for(int i=1;i+k-1<=len;i++){
			ans+=lcp(i,i+k-1);
			if(i-1>0) ans-=lcp(i-1,i+k-1);
			if(i+k<=len) ans-=lcp(i,i+k);
			if(i-1>0&&i+k<=len) ans+=lcp(i-1,i+k);
		}
		printf("%d\n",ans);
	}
	return 0;
}
