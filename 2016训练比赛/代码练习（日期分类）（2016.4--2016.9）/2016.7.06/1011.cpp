    #include<cstdio>
    #include<cstring>
    const int N=105, INF=9999999;
    int d[N], w[N][N],vis[N],n,m;

    void Dijkstra(int src){
        for(int i=1; i<=n; ++i)
            d[i] = INF;
        d[src] = 0;
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; ++i){
            int u=-1;
            for(int j=1; j<=n; ++j)if(!vis[j]){
                if(u==-1 || d[j]<d[u]) u=j;
            }
            vis[u] = 1;
            for(int j=1; j<=n; ++j)if(!vis[j]){
                int tmp = d[u] + w[u][j];
                if(tmp<d[j]) d[j] = tmp;
            }
        }
    }
    int main(){
        int a,b,c;
        while(~scanf("%d%d",&n,&m)&&n+m){
            for(int i=1; i<=n; ++i){
                w[i][i] = INF;
                for(int j=i+1; j<=n; ++j)
                    w[i][j] = w[j][i] = INF;
            }
            for(int i=0; i<m; ++i){
                scanf("%d%d%d",&a,&b,&c);
                w[a][b] = w[b][a] = c;
            }
            Dijkstra(1);
            printf("%d\n", d[n]);
        }
        return 0;
    }

