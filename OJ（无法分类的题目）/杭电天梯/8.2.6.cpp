#include<bits/stdc++.h>
using namespace std;
int main()
{
	int res;
	int tmp;
	int t,n;
	bool flag;
	cin>>t;
	while(t--){
		res=0;
		flag=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>tmp;
			res=(res^tmp);
			if(tmp>1) flag=1;
		}
		if((res&&flag==1)||(flag==0&&res==0)) cout<<"John"<<endl;
		else cout<<"Brother"<<endl;
	}
}