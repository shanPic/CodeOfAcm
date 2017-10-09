#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
bool vis[MAXN];
int main()
{
    //freopen("data.in","r",stdin);
    int n,x,but;
    cin>>n;
    but=n;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        cin>>x;
        vis[x]=1;
        if(x==but){
            for(;;x--){
                if(vis[x]){
                    cout<<x<<" ";
                    vis[x]=0;
                    but--;
                }
                else break;
            }
        }
        cout<<endl;
    }
}
