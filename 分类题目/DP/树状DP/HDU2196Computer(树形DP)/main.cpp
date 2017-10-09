#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
using namespace std;
const int M=10010;
int n;
int dp[M][2];
int deep[M][2];
struct node
{
    int son;
    int val;
};
vector<node> tree[M];
int h[M],s[M];
void dfs1(int nu)//第一遍DFS的作用是寻找每一个点至底部的最长路径长度与次长路径长度
{
    if(tree[nu].empty()){
        //dp[nu][0]=dp[nu][1]=
        return;
    }
    int len=tree[nu].size();
    for(int i=0;i<len;i++){
        dfs1(tree[nu][i].son);
        int tem=deep[tree[nu][i].son][0]+tree[nu][i].val;
        if(tem>deep[nu][0]){
            deep[nu][1]=deep[nu][0];
            deep[nu][0]=tem;
        }
        else if(tem>deep[nu][1]){
            deep[nu][1]=tem;//记录每一个节点向下最长与次长的路程
        }
        //dp[nu][0]=max(dp[nu][0],tem);
    }
}
void dfs2(int nu)//第二遍DFS的作用是DP
{
    if(tree[nu].empty())
        return;
    int len=tree[nu].size();
    for(int i=0;i<len;i++){
        int tem=tree[nu][i].son;
        if(tree[nu][i].val+deep[tem][0]==deep[nu][0]){
//            if(tree[nu][i].val+dp[nu][1]>=deep[tem][0]){
//                dp[tem][0]=tree[nu][i].val+dp[nu];
//            }
//            else{
//                dp[tem]=tree[nu][i].val+dp[nu];
//            }
            dp[tem][0]=max(tree[nu][i].val+dp[nu][1],deep[tem][0]);
            dp[tem][1]=max(tree[nu][i].val+dp[nu][1],deep[tem][1]);
        }
        else {
//            if(tree[nu][i]+dp[nu][0]>=dp[tem][0]){
//                dp[tem][1]=dp[tem][0];
//                dp[tem][0]=tree[nu][i]+dp[nu][0];
//            }
            dp[tem][0]=max(tree[nu][i].val+dp[nu][0],deep[tem][0]);
            dp[tem][1]=max(tree[nu][i].val+dp[nu][0],deep[tem][1]);
        }
        dfs2(tem);
    }
}
int main()
{

    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    while(cin>>n){
        for(int i=0;i<=n;i++){
            tree[i].clear();
        }
        //memset(h,-1,sizeof(h));
        memset(deep,0,sizeof(deep));
        memset(dp,0,sizeof(dp));
        struct node tem;int temf;
        for(int i=2;i<=n;i++){
            tem.son=i;
            scanf("%d%d",&temf,&tem.val);
            tree[temf].push_back(tem);
        }
        dfs1(1);
//        for(int i=0;i<=n;i++){
//            cout<<deep[i][0]<<"\t"<<deep[i][1]<<endl;
//        }
        dp[1][0]=deep[1][0];
        dp[1][1]=deep[1][1];
        dfs2(1);
//        cout<<"----------"<<endl;
//        for(int i=0;i<=n;i++){
//            cout<<dp[i][0]<<"\t"<<dp[i][1]<<endl;
//        }
        //cout<<111111111111<<endl;
        for(int i=1;i<=n;i++){
            cout<<dp[i][0]<<endl;
        }
//        cout<<11111111<<endl;
    }
}
