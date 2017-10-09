#include<bits/stdc++.h>
using namespace std;
const int MAXN=1100;
int n,t;
int a[MAXN],b[MAXN];
bool cmp1(int a,int b){
	return a<b;
}
bool cmp2(int a,int b){
	return a>b;
}
int main()
{
	while(cin>>n>>t){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		sort(a,a+n,cmp1);
		sort(b,b+n,cmp2);
		int res=0;
		for(int i=0;i<n;i++){
            if(a[i]+b[i]>t)
			res+=(a[i]+b[i]-t);
		}
		cout<<res<<endl;
	}
}
