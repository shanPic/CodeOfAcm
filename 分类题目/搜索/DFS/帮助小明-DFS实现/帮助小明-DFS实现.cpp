#include<bits/stdc++.h>
using namespace std;
int val[20],weight[20];
int res;
int n,m;
void dfs(int nowwei,int nowval,int nowpos)
{
    if(nowpos==n){
        if(nowval>res)
            res=nowval;
    }
    else{
        if(nowwei>=weight[nowpos])
            dfs(nowwei-weight[nowpos],nowval+val[nowpos],nowpos+1);
        dfs(nowwei,nowval,nowpos+1);
    }
}
int main()
{
    freopen("date.in","r",stdin);
    while(cin>>n>>m&&(n!=0||m!=0)){
        for(int i=0;i<n;i++){
            cin>>weight[i]>>val[i];
        }
        res=0;
        dfs(m,0,0);
        cout<<res<<endl;
    }
}
