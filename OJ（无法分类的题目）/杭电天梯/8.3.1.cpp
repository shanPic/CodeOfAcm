#include<bits/stdc++.h>
using namespace std;
	int n,k;
struct  node
{
    int m[12][12];
    node(){
        memset(m,0,sizeof(m));
    }
};
int mod=9973;
node multi(node &a,node &b)
{
    node tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++){
                sum+=(a.m[i][k]%mod)*(b.m[k][j]%mod);
            }
            tmp.m[i][j]=sum%mod;
        }
    }
    return tmp;
}
void e_mat(node &a)
{
    for(int i=0;i<n;i++){
        a.m[i][i]=1;
    }
}
node quick_mul(node &a,int n)
{
    node tmp=a;
    //e_mat(tmp);
    node res;
    e_mat(res);
    if(n&1){
        res=a;
    }
    n=n>>1;
    while(n!=0){
        tmp=multi(tmp,tmp);
        if(n&1){
            res=multi(res,tmp);
        }
        n=n>>1;
    }
    return res;
}
int main()
{
    freopen("data.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		node t,res;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cin>>t.m[i][j];
		}
		res=quick_mul(t,k);
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=res.m[i][i];
			ans%=mod;
		}
		cout<<ans%mod<<endl;
	}
}
