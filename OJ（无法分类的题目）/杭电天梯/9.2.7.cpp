#include<bits/stdc++.h>
using namespace std;
const int MAXN = 333;
int num[MAXN][MAXN], dis[MAXN][MAXN];
int N;
void init()
{
	//memset(m,0x3f,sizeof(m));
	//memset(num, 0, sizeof(num)); //!
	memset(num,0,sizeof(num));
	//memset(num, 0x3f, sizeof(dis));
	for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            if(i==j)
                dis[i][i]=0;
            else dis[i][j]=0x3f3f3f3f;
	}
}
void floyd()
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					num[i][j] = num[i][k] + num[k][j];//;
				}
				else if (dis[i][j] == dis[i][k] + dis[k][j] && num[i][j] < num[i][k] + num[k][j] ) {//
					num[i][j] = num[i][k] + num[k][j] ;//
				}
			}
		}
	}
}
int solve(int b1, int e1, int b2, int e2)
{
	int res = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dis[b1][i] + dis[i][j] + dis[j][e1] == dis[b1][e1] && dis[b2][i] + dis[i][j] + dis[j][e2] == dis[b2][e2]) {
				res = max(res, num[i][j]);
			}
		}
	}
	//cout<<res<<endl;
	return res;
}
int main()
{
	//freopen("data.in", "r", stdin);
	int M;
	int x, y, v;
	while (cin >> N >> M) {
		if (!N && !M) break;
		init();
		for (int i = 0; i < M; i++) {
            //cout<<1111111<<endl;
			cin >> x >> y >> v;
						if(dis[x][y]>v)
			dis[x][y] = dis[y][x] = v;
			num[x][y] = num[y][x] = 1;
		}
		floyd();
		int x2, y2;
		cin >> x >> y >> x2 >> y2;
		cout << solve(x, y, x2, y2)+1 << endl;
	}

}
