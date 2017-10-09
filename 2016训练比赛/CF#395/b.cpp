#include<bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int a[MAXN];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	for(i=1;i<=n/2;i++){
		if(i%2) cout<<a[n-i+1]<<" ";
		else cout<<a[i]<<" ";
	}
	if(n%2){
		for(;i<=n;i++){
			if(i%2) cout<<a[n-i+1]<<" ";
			else cout<<a[i]<<" ";
		}
	}
	else{
		for(;i<=n;i++){
			if(i%2) cout<<a[i]<<" ";
			else cout<<a[n-i+1]<<" ";
		}
	}
	cout<<endl;
	return 0;
}