#include <iostream>  
#include <algorithm>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <vector>  
#include <queue>  
#include <cstring>  
using namespace std;  
const int N = 1050;  
const int inf = 0x3f3f3f3f;  
#define Del(a,b) memset(a,b,sizeof(a))  
const int INF = 0x3f3f3f3f;
struct Node  
{  
    int from,to,cap,flow,cost;  
};  
vector<int> v[N];  
vector<Node> e;  
void addedge(int from,int to,int cap,int cost)  
{  
    e.push_back((Node){from,to,cap,0,cost});  
    e.push_back((Node){to,from,0,0,-cost});  
    int len = e.size()-1;  
    v[to].push_back(len);  
    v[from].push_back(len-1);  
}  
int vis[N],dis[N];  
int father[N],pos[N];  
bool BellManford(int s,int t,int& flow,int& cost)  
{  
    Del(dis,inf);  
    Del(vis,0);  
    queue<int> q;  
    q.push(s);  
    vis[s]=1;  
    father[s]=-1;  
    dis[s] = 0;  
    pos[s] = inf;  
    while(!q.empty())  
    {  
        int f = q.front();  
        q.pop();  
        vis[f] = 0;  
        for(int i=0; i<v[f].size(); i++)  
        {  
            Node& tmp = e[v[f][i]];  
            if(father[tmp.to]!=u&&tmp.cap>tmp.flow && dis[tmp.to] > dis[f] + tmp.cost)  
            {  
                dis[tmp.to] = dis[f] + tmp.cost;  
                father[tmp.to] = v[f][i];  
                pos[tmp.to] = min(pos[f],tmp.cap - tmp.flow);  
                if(vis[tmp.to] == 0)  
                {  
                    vis[tmp.to]=1;  
                    q.push(tmp.to);  
                }  
            }  
        }  
    }  
    if(dis[t] == inf)  
        return false;  
    flow += pos[t];  
    cost += dis[t]*pos[t];  
    for(int u = t; u!=s ; u = e[father[u]].from)  
    {  
        e[father[u]].flow += pos[t];  
        e[father[u]^1].flow -= pos[t];  
    }  
    return true;  
}  
int Mincost(int s,int t)  
{  
    int flow = 0, cost = 0;  
    while(BellManford(s,t,flow,cost)){}  
    return cost;  
}  
void init(int x)  
{  
    for(int i=0; i<=x; i++)  
        v[i].clear();  
    e.clear();  
}  
char mp[13][13];
inline bool ok(int x,int y)
{
	if(x>=8||x<0||y>=8||y<0) return 0;
	if(mp[x][y]=='O') return 0;
	return 1;
}
 int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
 	int t;
	scanf("%d",&t);
	while(t--){
		getchar();
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				scanf("%c",&mp[i][j]);
			}
			getchar();
		}

		int s=64*2;
		int t=s+1;
		init(t+1);
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(mp[i][j]!='O'){
					addedge(i*8+j,i*8+j+64,1,-1);
					if(mp[i][j]=='K'){
						addedge(s,i*8+j,INF,0);
					}
				//	else 
						addedge(i*8+j+64,t,INF,0);

					if(ok(i,j+1)){
						addedge(i*8+j+64,i*8+j+1,1,0);
						addedge(i*8+j+1+64,i*8+j,1,0);
					}
					if(ok(i+1,j)){
						addedge(i*8+j+64,(i+1)*8+j,1,0);
						addedge((i+1)*8+j+64,i*8+j,1,0);
					}
					if(ok(i+1,j+1)){
						addedge(i*8+j+64,(i+1)*8+j+1,1,0);
						addedge((i+1)*8+j+1+64,i*8+j,1,0);
					}
				}
			}
		}
	//	sap(s,t,t+1);
		int res=0;
		cout<<1111<<endl;
		res=Mincost(s,t);
		printf("%d\n",-res);

	}
	return 0;
} 
