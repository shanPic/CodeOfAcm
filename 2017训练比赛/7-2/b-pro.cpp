#include<bits/stdc++.h>
using namespace std;

int n,stamp,dfn[1005],low[1005];
int cnt,ansx[10005],ansy[10005];//记录桥的结果
vector<int> vec[1005];
int rank[1005];

void addAns(int x,int y)
{
//    if(x>y)
//        swap(x,y);
//    ansx[cnt]=x, ansy[cnt]=y;
    cnt++;
}

void tarjan(int index,int fa)
{
    int tmp;
    dfn[index]=low[index]=++stamp;
    for(int i=0; i<vec[index].size(); i++)
    {
        tmp=vec[index][i];
        if(!dfn[tmp])
        {
            tarjan(tmp,index);
            low[index]=min(low[index],low[tmp]);
            if(low[tmp]>dfn[index]&&(vec[tmp].size()>1)&&vec[index].size()>1)
                addAns(index,tmp);
        }
        else if(dfn[tmp]<dfn[index] && tmp!=fa)
        {
            low[index]=min(low[index],dfn[tmp]);
        }
    }
}

int main()
{
    //freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    if(m<n-1)
    {
        cout<<0<<endl;
    }
    else  {
        tarjan(1,0);
        //cout<<cnt<<endl;
        cout<<(m-cnt)*(m-cnt-1)/2<<endl;
    }
}
