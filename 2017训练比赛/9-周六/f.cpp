#include<bits/stdc++.h>
using namespace std;
const int MAXN=200;
const int INF=0x3f3f3f3f;
int m[MAXN][MAXN];
int d[MAXN][MAXN];
int cnt=0;
int res=0;
void floyd(int n,int r)
{
    //cout<<2222222<<endl;
    int num=0;
    while(1){
       // cout<<11111<<endl;
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!m[i][j]){
                    //cout<<333333<<endl;
                    num=0;
                    for(int k=0;k<n;k++){
                        if(m[i][k]&&m[j][k]){
                            num++;
                        }
                    }
                    if(num>=r){
                        //cout<<4444<<endl;
                        cnt++;
                        m[i][j]=m[j][i]=1;
                    }
                }
            }
        }
        res+=cnt;
        if(cnt==0){
            break;
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
    //freopen("data.in","r",stdin);
    int t,n,mm,k;
    int u,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&mm,&k);
        memset(m,0,sizeof(m));
        for(int i=0;i<mm;i++){
            scanf("%d%d",&u,&v);
            m[u][v]=m[v][u]=1;
        }
        //print(n); cout<<endl;
        res=0;
        floyd(n,k);
        printf("%d\n",res);
    }
}
