#include<bits/stdc++.h>
using namespace std;
int main()
{
	int res;
	int tmp;
	int t,n;
	bool flag;
	while(cin>>n){
		res=0;
		flag=0;
		for(int i=0;i<n;i++){
			cin>>tmp;
			res=(res^tmp);
			if(tmp>1) flag=1;
		}
		if((res&&flag==1)||(flag==0&&res==0)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}