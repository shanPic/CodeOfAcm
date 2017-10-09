/*
* @FileName: D:\代码与算法\2017训练比赛\9.24南宁网络赛\j.cpp
* @Author: Pic
* @Created Time: 2017/9/24 12:46:56
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
	char str[10];
	int step;
};
int vis[60000000];
char str1[10],str2[10];
int res=0;
int len;
//map<char*,int> mp;
void cp(char *str1,char *str2)//str2到str1
{
	for(int i=0;i<len;i++){
		str1[i]=str2[i];
	}
}
bool cmp(char *str1,char *str2)
{
	for(int i=0;i<len;i++){
		if(str1[i]!=str2[i]){
			return 0;
		}
	}
	return 1;
}
int cal(char *str)
{
	int sum=0,c=1;
	for(int i=len-1;i>=0;i--){
		sum+=((str[i]-'0')*c);
		c*=7;
	}
	return sum;
}
void bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node a;
	cp(a.str,str1);a.step=0;
	vis[cal(str1)]=1;
	//mp[cal(str1)]=1;
	q.push(a);
	while(!q.empty()){
		a=q.front();q.pop();
		if(cmp(a.str,str2)){
			res=a.step;
			break;
		}
		else{
			char tmp[13];
			node b; b.step=a.step+1;
			cp(tmp,a.str);
			for(int i=1;i<len;i++){
				swap(tmp[0],tmp[i]);
				if(vis[cal(tmp)]){
				//if(mp.find(cal(tmp))!=mp.end())
					swap(tmp[0],tmp[i]);
					continue;
				}
				else{
					cp(b.str,tmp);
					q.push(b);
					//mp[b.str]=1;
					vis[cal(tmp)]=1;
					swap(tmp[0],tmp[i]);	
				}
			}
		}
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	//int n;
	scanf("%d",&len);
	for(int i=0;i<5;i++){
		scanf("%s %s",str1,str2);
		//cout<<str1<<"\t"<<str2<<endl;
		//len=strlen(str1);
		res=0;
		bfs();
		printf("%d\n",res);
	}
	//cout<<cal("987654321")<<endl;
	return 0;
}
