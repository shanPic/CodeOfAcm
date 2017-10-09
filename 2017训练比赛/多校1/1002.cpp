/*
* @FileName: D:\代码与算法\2017训练比赛\多校1\1002.cpp
* @Author: Pic
* @Date:   2017-07-25 21:17:34
* @Last Modified time: 2017-07-25 22:28:09
*/

#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
struct node
{
	int name,cnt;
};
node a[28];
int vis[28];
int vis1[28];
long long c[28];
int tot;
void init()
{
	for(int i=0;i<26;i++){
		a[i].name=i;
		a[i].cnt=0;
	}
	memset(vis,0,sizeof(vis));
	memset(c,0,sizeof(c));
	memset(vis1,0,sizeof(vis1));
	tot=0;
}
string str[100000+30];
void chuli(string &str)
{
	int i=str.size();
	i--;
	int step=1;
	for(;i>=0;i--){
		a[str[i]-'a'].cnt+=step;
		if(!vis1[str[i]-'a']) {
			vis1[str[i]-'a']=1;
			tot++;
		}
		step++;
	}
	if(str.size()>1)
		vis[str[0]-'a']=1;

}
bool cmp(node a,node b)
{
	return a.cnt>b.cnt;
}
long long res;
void chuli2(string &str)
{
	int i=str.size();
	i--;
	long long step=1;
	for(;i>=0;i--){
		res=((res%mod)+(c[str[i]-'a']*(step%mod))%mod)%mod;
		step=((step%mod)*(long long)26)%mod;
	}
}
int main(){
	//freopen("data.in","r",stdin);
	int n;
	int t=0;
	while(~scanf("%d",&n)){
		init();
		for(int i=0;i<n;i++){
			cin>>str[i];
			chuli(str[i]);
		}
		//cout<<tot<<endl;
		sort(a,a+26,cmp);
		int flag=-1;
		if(tot>=26){
			for(int i=25;i>=0;i--){
				if(a[i].cnt>0&&vis[a[i].name]==0){
					flag=i;
					c[a[i].name]=0;
					break;
				}
			}
		}
		int cost=25;
		for(int i=0;i<26;i++){
			if(i!=flag){
				c[a[i].name]=cost;
				cost--;
				//cout<<cost<<"\t";
			}
		}
		//cout<<endl;
		res=0;
		for(int i=0;i<n;i++){
			chuli2(str[i]);
		}
		printf("Case #%d: %lld\n",++t,res);
	}
    return 0;
}