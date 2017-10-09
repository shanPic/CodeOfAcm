/*
* @FileName: D:\代码与算法\2017训练比赛\9.21北京网络赛练习赛\f.cpp
* @Author: Pic
* @Created Time: 2017/9/21 21:18:50
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=6e4+30;
long long a[maxn],b[maxn];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
   	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		long long sum=0,sum2=0;
		for(int i=0;i<n;i++){
			scanf("%I64d",&a[i]);
		}	
		for(int i=0;i<n;i++){
			scanf("%I64d",&b[i]);
			sum+=b[i];
			sum2+=b[i]*b[i];
		}
		long long res=0x80808080,tmp=0;
		for(int i=0;i<n;i++){
			tmp=n*a[i]*a[i]-2*a[i]*sum+2*a[i]*b[i]+sum2-(b[i]*b[i]);
			if(tmp<res){
				res=tmp;
			}
		}
		printf("%I64d\n",res);
	}	
	return 0;
}
