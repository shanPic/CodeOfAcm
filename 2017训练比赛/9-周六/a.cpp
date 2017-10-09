
#include<bits/stdc++.h>
using namespace std;
const int MAXN=200;
const int INF=0x3f3f3f3f;
int m[MAXN][MAXN];
int d[MAXN][MAXN];
void floyd(int n,int r)
{
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((m[k][i]&&m[k][j])||(d[k][i]>=r&&d[k][j]>=r)){
                    d[i][j]++;
                    d[j][i]++;
                }
            }
        }
    }
}
void print(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[j][i]==INF) cout<<"X"<<"\t";
            else cout<<m[j][i]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    freopen("data.in","r",stdin);
    int t,n,mm,k;
    int u,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&mm,&k);
        memset(m,0,sizeof(m));
        //memset(d,0,sizeof(d));
        for(int i=0;i<mm;i++){
            scanf("%d%d",&u,&v);
            m[u][v]=m[v][u]=1;
        }
        //print(n); cout<<endl;
        floyd(n,k);
        //print(n);
        int res=0;
//        for(int i=0;i<n;i++){
//            for(int j=i+1;j<n;j++){
//                if(d[i][j]>k){
//                    res++;
//                }
//            }
//        }
        printf("%d\n",cnt);
    }
}
