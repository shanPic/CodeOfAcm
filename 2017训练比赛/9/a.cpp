#include<bits/stdc++.h>
using namespace std;
const int MAXN=13;
int vis[MAXN];
int main()
{
    int x;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<6;i++){
        cin>>x;
        vis[x]++;
    }
    int flag1=0,flag2=0;
    for(int i=1;i<10;){
        if(vis[i]==2){
            flag2=1;
            i++;
            continue;
        }
        if(vis[i]>=4){
            vis[i]-=4;
            flag1=1;
            continue;
        }
        i++;
    }
    //cout<<flag1<<endl<<flag2<<endl;
    if(flag2&&flag1) cout<<"Elephant"<<endl;
    else if(flag2==0&&flag1) cout<<"Bear"<<endl;
    else cout<<"Alien"<<endl;
}
