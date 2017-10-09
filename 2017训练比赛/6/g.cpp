#include<bits/stdc++.h>
using namespace std;
const int MAXN=1300;
map<int,int> h;
int a[MAXN];
int main()
{
    //freopen("data.in","r",stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n,m;
    int tmp;
    int t=0;
    while(cin>>n>>m){
        h.clear();
        int maxn=-1;
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=m)
                maxn=max(maxn,a[i]);
        }
        sort(a,a+n);
        //cout<<111111<<endl;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                h[a[i]+a[j]]=1;
            }
        }
        //cout<<222222<<endl;
        maxn=min(maxn*4,m);
        //cout<<maxn<<endl;
        //cout<<h[4]<<endl<<h[4]<<endl;
        int res=0;
        bool flag=0;
        for(int i=maxn;i>0;i--){
            for(int j=1;j<=i/2;j++){
                if(h[j]&&h[i-j]){
                    res=i;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        cout<<"Case "<<++t<<": ";
        cout<<res<<endl<<endl;
    }
}
