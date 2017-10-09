#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
const int INF=0x3f3f3f3f;
int m[MAXN][MAXN];
int cost[MAXN];
int dist[MAXN][MAXN];
int path[MAXN][MAXN];
void floyd()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(m[i][j]!=-1){
				dist[i][j]=m[i][j];
				path[i][j]=j;
			}
			else {
				dist[i][j]=INF;
				path[i][j]=-1;
			}
		}

	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		if(dist[i][j]>dist[i][k]+dist[k][j]+cost[k]){
			dist[i][j]=dis[i][k]+dist[k][j]+cost[k];
			path[i][j]=path[i][k];
		}
		else if(dist[i][j]==dist[i][k]+dist[k][j]+cost[k]&& path[i][j]>path[i][k]{

		}
	}
}
int main()
{

}