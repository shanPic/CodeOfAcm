/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1004.cpp
* @Author: Pic
* @Date:   2017-08-19 13:30:27
* @Last Modified time: 2017-08-19 14:51:37
*/
#include <bits/stdc++.h>
using namespace std;
/*
* next[]的含义： x[i-next[i]...i-1]=x[0...next[i]-1]
* next[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值（就是x的自身匹配）
*/
const int mod=1e9+7;
const int MAXN=1e6+30;
queue<int> q;
char s1[MAXN],s2[MAXN];
int KMP(char ch,int len)
{
	int ans=0;
	for(int i=0;i<len;i++){
		if(ch==s1[i]){
			ans++;
			q.push(i);
		}
	}
	return ans;
}
int size=0;
int cal(int x)
{
	//int size=q.size();
	int si=size;
	int ans=0;
	for(int i=0;i<size;i++){
		int pos=q.front();q.pop();
		if(pos>0&&s1[pos-1]==s2[x]){
			ans++;
			q.push(pos-1);
		}
		else{
			si--;
		}
	}
	size=si;
	return ans;
}
void init()	
{
	while(!q.empty()) q.pop();
}
int main()
{
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	 getchar();
	while(t--){
		init();
		int len1=-1,len2=-1;
		char ch;
		// scanf("%s",s1);
		// getchar();
		// scanf("%s",s2);
		//getchar();
		//cout<<getchar()<<endl;
		while((ch=getchar())&&ch!='\n'){
			s1[++len1]=ch;
		}
		++len1;
		//s1[len1]='\0';
		while((ch=getchar())&&ch!='\n'){
			s2[++len2]=ch;
		}
		++len2;
		//s2[len2]='\0';
		//cout<<s1<<"\t"<<s2<<endl;
		int sum=KMP(s2[len2-1],len1);
		size=sum;
		if(sum==len1){
			for(int i=2;i<=len2;i++){
				sum=(sum+((len1-i+1)*i)%mod)%mod;
			}
		}
		else{
			for(int i=len2-2;i>=0;i--){
				sum=(sum+(cal(i)%mod)*((len2-i)%mod)%mod)%mod;
			}
		}
		printf("%d\n",sum);
	}
}