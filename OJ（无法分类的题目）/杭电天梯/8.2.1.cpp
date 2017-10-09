#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n,m;
	while(t--){
		cin>>n>>m;
		if(n%(m+1)==0){
			cout<<"second"<<endl;
		}
		else{
			cout<<"first"<<endl;
		}
	}
}