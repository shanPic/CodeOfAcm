/*
* @FileName: D:\代码与算法\POJ\poj1446\poj1446.cpp
* @Author: Pic
* @Date:   2017-08-17 10:15:46
* @Last Modified time: 2017-08-17 10:19:23
*/

//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 2001
#define mod 10007
#define eps 1e-9
//const int inf=0x7fffffff;   //无限大
const int inf=0x3f3f3f3f;
/*

*/
//**************************************************************************************

inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int ma[maxn][maxn];
int vis[maxn];
int match[maxn];
int n,m;
vector<int> e[maxn];
int dfs(int a)
{
    for(int i=0;i<e[a].size();i++)
    {
        if(vis[e[a][i]]==0)
        {
            vis[e[a][i]]=1;
            if(match[e[a][i]]==-1||dfs(match[e[a][i]]))
            {
                match[e[a][i]]=a;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
	freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(match,-1,sizeof(match));
        for(int i=0;i<n;i++)
            e[i].clear();
        m=n;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d: (%d)",&x,&y);
            for(int j=0;j<y;j++)
            {
                int c=read();
                e[x].push_back(c);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i)==1)
                ans++;
        }
        printf("%d\n",n*2-ans);
    }

}