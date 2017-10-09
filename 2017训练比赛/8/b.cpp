#include<bits/stdc++.h>
using namespace std;
int bitch[13] = {1,1,2,6,24,120,720,5040,40320,362880,39916800,479001600};
const int MAXN=15;
int mm[MAXN][MAXN];
int n,m;
int tot=0;
int vis2[MAXN];
int total;
int maxn;
void search(int cur)
{
    if(cur==n){
        int i;
        for(i=1;i<=n;i++){
            if(vis2[i]==0){
                total+=mm[cur][i];
                break;
            }
        }
        if(total>=m){
            tot++;
        }
        total-=mm[cur][i];
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(vis2[i]==0){
                total+=mm[cur][i];
                if(total>=m){
                    total-=mm[cur][i];
                    tot++;
                    continue;
                }
                if(((m-total)/(n-cur))>maxn){
                    total-=mm[cur][i];
                    continue;
                }
                vis2[i]=1;
                search(cur+1);
                total-=mm[cur][i];
                vis2[i]=0;
            }
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        maxn=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&mm[i][j]);
                maxn=max(maxn,mm[i][j]);
            }
        }
        tot=0;
        memset(vis2,0,sizeof(vis2));
        total=0;
        search(1);
        if(tot==0){
            printf("No solution\n");
            continue;
        }
        int tt=bitch[n];
        int tmp;
        while(__gcd(tt,tot)!=1){
            tmp=__gcd(tt,tot);
            tt/=tmp;
            tot/=tmp;
        }
        printf("%d/%d\n",tt,tot);
    }
}
