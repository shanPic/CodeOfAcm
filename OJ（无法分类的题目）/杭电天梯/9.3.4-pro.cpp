#include<bits/stdc++.h>
using namespace std;
const int MAXN=630;
int m,n;
int mm[MAXN][MAXN];
int vis[MAXN][MAXN];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
char dc[4]={'E','W','S','N'};
struct point
{
	int x,y;
};
bool ok(point p)
{
	if(p.x<0||p.x>=m||p.y<0||p.y>=n||vis[p.x][p.y]||mm[p.x][p.y]){
		return 0;
	}
	else return 1;
}
int DFS(point p,int d)//p表示起始点（包括），d表示方向
{
    if(ok(p)==0) return 0;
	int step=0;
	point tt=p,tmp;
	while(ok(tt)){
		vis[tt.x][tt.y]=1;
		step++;
		tt.x+=dir[d][0],tt.y+=dir[d][1];
	}
	tt.x-=dir[d][0],tt.y-=dir[d][1];
	int tans=step,res=0;
	for(int i=0;i<4;i++){
		if(i!=d){
			tmp=tt;tans=step;
			tmp.x+=dir[i][0],tmp.y+=dir[i][1];
			if(ok(tmp)){
				tans=tans+DFS(tmp,i);
				if(tans>res){
					res=tans;
				}
			}
		}
	}
	return res;
}
point socks[MAXN*MAXN];
int main()
{
    freopen("data.in","r",stdin);
	while(~scanf("%d%d",&m,&n)){
        if(n==0&&m==0) break;
		int r;
		scanf("%d",&r);
		point tmp;
		for(int i=0;i<r;i++){
			scanf("%d%d",&tmp.x,&tmp.y);
			socks[i]=tmp;
			mm[tmp.x][tmp.y]=1;
		}
		int res=-1,resd;
		point resp;
		point tt;
		int tres;
        for(int i=0;i<r;i++){
            tmp=socks[i];
            for(int j=0;j<4;j++){
                tmp.x+=dir[i][0],tmp.y+=dir[i][1];
                for(int k=0;k<4;k++){
                    memset(vis,0,sizeof(vis));
                    tres=DFS(tmp,k);
                    if(tres>res){
                        res=tres; resp=tmp; resd=k;
                    }
                }
            }
        }
        printf("%d %d %d %c\n",res,resp.x,resp.y,dc[resd]);
	}
}
