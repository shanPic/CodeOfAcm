#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<set>
#include<iterator>
using namespace std;
int tem[100000];
set<int> a;
int T,N,sum;
void dfs(int now){
	if(now>N){
		for(set<int>::iterator it=a.begin();it!=a.end();it++){
			sum+=(*it);
		}
		return;
	}
	else{
		dfs(now++);
		a.insert(tem[now]);
		dfs(now++);
		a.erase(tem[now]);
	}
}
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		for(int j=0;j<N;j++){
			cin>>tem[j];
		}
		a.clear();
		sum=0;
		dfs(0);
		cout<<sum;
	}
}