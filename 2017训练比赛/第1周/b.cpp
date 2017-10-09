#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+3;
int vis[MAXN];
int main()
{
    memset(vis,-1,sizeof(vis));
    int n,x;
    cin>>n;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x!=i) vis[i]=x;
        else res++;
    }
    //cout<<res<<endl;
    int flag=0;
    for(int i=0;i<n;i++){
        if(vis[i]!=-1){
            if(vis[vis[i]]!=-1){
                flag=1;
            }
            if(vis[vis[i]]==i){
                flag=2;
                break;
            }
        }
    }
    //cout<<flag<<endl;
//    for(int i=0;i<n;i++){
//        cout<<vis[i]<<"\t";
//    }
    //cout<<endl;
    cout<<res+flag<<endl;
}
