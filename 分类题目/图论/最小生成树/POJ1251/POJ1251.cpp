#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=28;
int mefi[MAXN];
int n;
typedef struct
{
    int x;
    int y;
    int val;
} node;
vector<node> G;
int findn(int i)
{
    while(mefi[i]!=i){
        i=mefi[i];
    }
    return i;
}
void merg(int a,int b)
{
    int x=findn(a);
    int y=findn(b);
    mefi[x]=y;
}
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int main()
{
    //freopen("data.in","r",stdin);
    int res;
    char tem;
    int id;
    node tnode;
    while(cin>>n&&n!=0){
        res=0;
        G.clear();
        for(int i=1;i<n;i++){
            cin>>tem;
            id=tem-'A'+1;
            tnode.x=id;
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                cin>>tem;
                tnode.y=tem-'A'+1;
                cin>>tnode.val;
                G.push_back(tnode);
            }
        }
        sort(G.begin(),G.end(),cmp);
        for(int i=1;i<=n;i++){
            mefi[i]=i;
        }
        for(vector<node>::iterator ite=G.begin();ite!=G.end();ite++){
            if(findn(ite->x)!=findn(ite->y)){
                merg(ite->x,ite->y);
                res+=(ite->val);
            }
        }
        cout<<res<<endl;
    }
}
