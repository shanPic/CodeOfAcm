#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
int main()
{
	freopen("data.in","r",stdin);
	int n,c,r;
	map<string,int> loca;
	int G[MAXN][MAXN];
	string brok[MAXN];
	string str;
	while(cin>>n>>c>>r){
		loca.clear();
		int flag=0;
		cin>>str;
		loca[str]=1;
		for(int i=2;i<=c+1;i++){
			cin>>str;
			brok[flag++]=str;
		}
		string a,b;
		int count=2;
		flag=0;
		strigstring s;
		
		for(int i=0;i<r;i++){
			cin>>a;
			if(loca.find(a)==loca.end()) loca[a]=(count++);
			s.string(a);
			a>>
		}
	}
	return 0;
}