#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;

ll u[maxn],v[maxn];

int main(){
    int n,t,x;
    while(cin>>n){
        if(n==0){
			cout<<1<<endl;
			continue;
		}
		ll maxh=0;
		for(int i=0;i<n;i++){
			scanf("%lld%lld",u+i,v+i);
			maxh=max(maxh,u[i]);
		}
		maxh++;
		ll ans=0;
		for(int i=0;i<n;i++)
		  ans+=v[i]*(maxh-u[i]);
		cout<<ans<<endl;
		
    }
    return 0;
}