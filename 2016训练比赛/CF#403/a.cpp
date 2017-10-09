#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+100;
int vis[MAXN];
int n;
int num;
int res=-1,desk=0;
int main()
{
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>num;
        if(vis[num]){
            vis[num]=0;
            desk--;
        }
        else{
            vis[num]=1;
            desk++;
        }
        res=max(desk,res);
    }
    cout<<res<<endl;
}
