#include<bits/stdc++.h>
using namespace std;
const int MAXN=200100;
const int INF=0x3f3f3f;
struct  node
{
	int x,div;
	node(int a=0,int b=0){
		x=a;
		div=b;
	}
}a[MAXN];
node b[MAXN];
int main()
{
    freopen("data.in","r",stdin);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].div;
		}
		int flag=a[0].div;
		node tmp(0,0);
		int cou=0;
		for(int i=0;i<n;){
			tmp.div=flag;
			while(a[i].div==flag&&i<n){
				tmp.x+=a[i].x;
				i++;
			}
			b[cou++]=tmp;
			tmp.x=0;
			if(flag==1){
				flag=2;
			}
			else flag=1;
		}
		int flag2=1;
		flag=b[0].div;
		int xx=0;
		if(flag==2) xx=1899;
		else xx=1899-b[0].x;
		for(int i=0;i<cou;i++){
			if(b[i].div==1&&b[i].x>0&&i!=(cou-1)){
				flag2=0;
				break;
			}
			xx+=b[i].x;
		}
		if(flag2==0) cout<<"Impossible"<<endl;
		else {
			if(b[0].div==1&&b[cou-1].div==2) cout<<1899+b[cou-1].x<<endl;
			else if(b[0].div==1&&b[cou-1].div==1) cout<<"Infinity"<<endl;
			else cout<<xx<<endl;
		}
	}
	return 0;
}
