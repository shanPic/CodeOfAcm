#include<bits/stdc++.h>
using namespace std;
const int MAXN = 630;
int mm[MAXN][MAXN];
int vis[MAXN][MAXN];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
char dc[4]={'E','W','S','N'};
struct point
{
	int x, y;
	point(int xx,int yy){
		x=xx;y=yy;
	}
	point(){};
	void print(){
	    cout<<x<<"\t"<<y<<endl;
	}
};
point rock[MAXN * 600];
int m, n;
bool ok(point &p)
{
    if ( p.x < m && p.x >= 0 && p.y < n && p.y >= 0 && vis[p.x][p.y]==0 && mm[p.x][p.y]!=1 )
    {
        return 1;
    }
    else return 0;
}
int DFS(point p)
{
    //cout<<"DFS"<<endl;
    int step=0;
	int res=0,tres;
	for (int i = 0; i < 4; i++) {
		point tmp(p.x + dir[i][0], p.y + dir[i][1]);
		if (ok(tmp)) {
			step=0;
			while (ok(tmp)) {
				step++;
				vis[tmp.x][tmp.y] = 1;
				tmp.x += dir[i][0], tmp.y += dir[i][1];
			}
			//if(mm[tmp.x][tmp.y]!=1)
				tmp.x -= dir[i][0], tmp.y -= dir[i][1];
			tres = step + DFS(tmp);
			while(!(tmp.x==p.x&&tmp.y==p.y)){
                vis[tmp.x][tmp.y]=0;
                tmp.x-=dir[i][0],tmp.y-=dir[i][1];
            }
			if (tres > res) {
				res = tres;
			}
		}
	}
//	if(mm[p.x][p.y]!=1)
//        return res+1;
//    else
        return res;
}
int resd, ans = -1;
point resp;
int tmp;
int search(point &p)
{
    point tt;
    for (int j = 0; j < 4; j++)
    {
        tt=p;
        tt.x+=dir[j][0];
        tt.y+=dir[j][1];
        if(tt.x>=0&&tt.x<m&&tt.y>=0&&tt.y<n)
        {
            memset(vis,0,sizeof(vis));
            vis[p.x][p.y]=1;
            tmp = DFS(tt);
            if(mm[tt.x][tt.y]!=1) tmp++;
            if (tmp > ans)
            {
                resp = tt;
                resd = j;
                ans = tmp;
            }
        }
    }
//    memset(vis,0,sizeof(vis));
//    vis[p.x][p.y]=1;
//    int res=DFS(p);
//    if(mm[p.x][p.y]!=1) res++;
//    return res;
}
int main()
{
    freopen("data.in","r",stdin);
	int r;
	int T=0;
	while (~scanf("%d%d", &m, &n)) {
        resd=0,ans=0,resp=point(0,0);
		memset(mm, 0, sizeof(mm));
		if (m == 0 && n == 0) {
			break;
		}
		scanf("%d", &r);
		int x, y;
		for (int i = 0; i < r; i++) {
			scanf("%d%d", &x, &y);
			mm[x][y] = 1;
			rock[i].x = x, rock[i].y = y;
		}
		for (int i = 0; i < r; i++) {
			search(rock[i]);
		}
		point t;
		t.x=-1,t.y=0;search(t);
		t.x=m,t.y=0;search(t);
		t.x=0,t.y=n;search(t);
		t.x=m,t.y=n-1;search(t);
		printf("Case %d: %d %d %d %c\n",++T,ans,resp.x,resp.y,dc[resd]);
	}
}
