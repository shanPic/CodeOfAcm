#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int d[maxn];

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		memset(d,0,sizeof(d));
		int x,sz=1;
		cin>>x;d[0]=x;
		for(int i=1;i<n;i++){
			cin>>x;int mm;
			for(mm=0;mm<sz;mm++)
			  if(d[mm]<=x)
				break;
		    d[mm]=x;
			if(mm==sz)
				sz++;
		}
		cout<<sz<<endl;

	}
	return 0;
}