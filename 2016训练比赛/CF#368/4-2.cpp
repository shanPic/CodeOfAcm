#include<bits/stdc++.h>
using namespace std;
#define MAXN
int n,k,a,b;
int tea[101000];
int main()
{
	cin>>n>>k>>a>>b;
	memset(tea,0,sizeof(tea));
	int tmp=min(a,b);
	int ma=max(a,b);
	for(int i=1;i<2*tmp;i+=2){
		tea[i]=1;
	}
	int maxn=-1;
	while(ma!=0){
		int i;
		for( i=0;(i<2*tmp+2)&&(ma>0);i+=2){
			tea[i]++;
			ma--;
		}
		i-=2;
		if(tea[i]>maxn) maxn=tea[i];
	}
	//cout<<maxn<<endl;
	if(maxn>k){
		cout<<"NO"<<endl;
		return 0;
	}
	if(a>b){
		bool flag=1;
		for(int i=0;i<2*b+1;i++){
			int x=tea[i];
			if(flag){
				for(int j=0;j<x;j++){
					cout<<"G";
				}
				flag=0;
			}
			else {
				for(int j=0;j<x;j++){
					cout<<"B";
				}
				flag=1;
			}
		}
		cout<<endl;
	}
	else{
		bool flag=1;
		for(int i=0;i<2*a;i++){
			int x=tea[i];
			if(flag){
				for(int j=0;j<x;j++){
					cout<<"B";
				}
				flag=0;
			}
			else {
				for(int j=0;j<x;j++){
					cout<<"G";
				}
				flag=1;
			}
		}
		cout<<endl;
	}
	return 0;
}
