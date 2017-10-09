#include<bits/stdc++.h>
using namespace std;
const int MAXN = 533;
#define clr(a) memset(a,0,sizeof(a));
map<string,int> name;
vector<vector<int>> boys, girls;
vector<int> boysok[MAXN], girlsok[MAXN];
int N;
int cou;
void init()
{
	//clr(boysok); clr(girlsok);
	boysok.clear();girlsok.clear();
	name.clear(); boys.clear();
	name.clear();
	cou = 1;
}
int getname()
{
	string s;
	cin >> s;
	if (name.find(s) == name.end()) {
		name[s] = cou++;
		return cou-1;
	}
	else{
		return name[s];
	}
}
int cmp(int man1,int man2,int woman)
{
	int flag1=0,flag2=0;
	for(auto ite=girls[woman].begin();ite!=girls[woman].end();ite++){
		if(*ite==man1){
			if(flag2) return 0;
			else flag1=1;
		}
		if(*ite==man2) {
			if(flag1) return 1;
			else flag2=1;
		}
	}
}
int main()
{
	string str;
	while (cin >> N) {
		init();
		for(int i=0;i<N;i++){
			int man=getname();
			boysok[man]=0;
			for(int j=0;j<N;j++){
				boys[man].push_back(getname());
			}
		}
		for(int i=0;i<N;i++){
			int wom=getname();
			girlsok[wom]=0;
			for(int j=0;j<N;j++){
				girls[wom].push_back(getname());
			}
		}
	}
	while(1)
	{
		bool f=0;
		for(auto ii=boysok.begin();ii!=boysok.end();ii++){
			int i=ii-boysok.begin();
			if(!boysok){
				f=1;
				bool flag=0;
				for(auto ite=boys[i].begin();ite!=boys[i].end();ite++){
					if(!girlsok[*ite]){
						flag=*ite;break;
					}
					else{
						if(cmp(i,girlsok[*ite],*ite)){
							boysok[girlsok[*ite]]=0;
							flag=*ite;break;
						}
					}
				}
				if(flag) boysok[i]=flag;
			}
		}
		if(!f) break;
	}
	auto ite=name.begin();
	for(int i=1;i<=N;i++){
		cout<<(low_bound(i))->first<<" ";
		cout<<(low_bound())
	}
}