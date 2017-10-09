#include<bits/stdc++.h>
using namespace std;
const int MAXN=100030;
int m[MAXN];//记录图，记录的是点的上一个节点
int chu[MAXN];//记录出度
//int ru[MAXN];//记录入度
//int vis[MAXN];//记录是否可以访问
int hotel[MAXN];
int cnt=0;
int DFS(int i,int deep)
{
    if(m[i]==0||chu[m[i]]==-1){
        return deep;
    }
    else{
        DFS(m[i],deep+1);
    }
}
void print(int i)
{
    if(m[i]==0||chu[m[i]]==-1){
        printf("%d ",i);
        return ;
    }
    else{
        print(m[i]);
        printf("%d ",i);
    }
}
int main()
{
    int n;
    int tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        if(tmp){
            hotel[cnt++]=i;
        }
    }
    int flag;
    for(int i=1;i<=n;i++){
        flag=0;
        scanf("%d",&tmp);
        if(chu[tmp]!=-1&&tmp!=0){
            chu[tmp]++;
            flag=1;
            if(chu[tmp]>1){
                chu[tmp]=-1;
                flag=0;
            }
        }
        if(flag)
            m[i]=tmp;
    }
    int ansid;
    int ans=-1;
    for(int i=0;i<cnt;i++){
        tmp=DFS(hotel[i],1);
        if(tmp>ans){
            ans=tmp;
            ansid=hotel[i];
        }
    }
    printf("%d\n",ans);
    print(ansid);
    printf("\n");
}
