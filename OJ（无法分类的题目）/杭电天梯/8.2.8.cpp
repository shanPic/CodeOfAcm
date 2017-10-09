#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int n;
	int res;
	int a,b;
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			res=(res^(a%(b+1)));
		}
		if(res==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}