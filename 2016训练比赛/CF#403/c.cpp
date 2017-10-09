#include<bits/stdc++.h>
using namespace std;
const int E=2*1e5+100;
//使用邻接表进行存储
struct edge
{
    int x, y, nxt;
} bf[E];
int ne=1;
int head[E];
void addedge(int x, int y)
{
    bf[ne].x = x; bf[ne].y = y;
    bf[ne].nxt = head[x]; head[x] = ne++;
}
int clor[E];
void DFS(int p,int pp,int now)//p,pp分别代表上一节点与上上节点
{
    int x=clor[p],y=clor[pp];
    int ptr=head[now];
    while(ptr!=0){

    }
}
int main()
{
    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        addedge(x,y);
        addedge(y,x);
    }
    DFS(0,0,now);
    for(int i=1;i<=n;i++){
        cout<<clor[i]<<" ";
    }
    cout<<endl;
}
