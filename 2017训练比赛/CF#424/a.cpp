/*
* @Author: zhans
* @Date:   2017-08-18 08:39:18
* @Last Modified by:   zhans
* @Last Modified time: 2017-08-18 09:42:06
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000+30;
int per[MAXN],key[MAXN],mp[MAXN];
int vis[MAXN];
int n,k,p;
bool cmp(int i,int j)
{
	return abs(p-key[i])<abs(p-key[j]);
}
int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&k,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&per[i]);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&key[i]);
	}
	for(int i=0;i<k;i++) mp[i]=i;
	sort(mp,mp+k,cmp);
	int res=-1;
	for(int i=n-1;i>=0;--i){
		//cout<<"------"<<mp[i]<<endl;
		int flag=i,dis=0x3f3f3f3f;
		for(int j=0;j<n;j++){
			if(!vis[j]&&abs(per[j]-key[mp[i]])<dis){
				flag=j;
				dis=abs(per[j]-key[mp[i]]);
			}
		}
		//cout<<"\t"<<flag<<"\t"<<dis<<endl;
		vis[flag]=1;
		res=max(dis+abs(key[mp[i]]-p),res);
	}
	printf("%d\n",res);
}