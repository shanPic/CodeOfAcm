#include<stdio.h>
#include<string.h>
const int MAXN=15;
int mm[MAXN][MAXN];
int n,m;
long long tot=0;
int vis2[MAXN];
int total;
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
    //cin>>t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&mm[i][j]);
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
        long long tt=1;
        for(int i=2;i<=n;i++){
            tt*=i;
        }
        long long tmp;
        while(__gcd(tt,tot)!=1){
            tmp=__gcd(tt,tot);
            tt/=tmp;
            tot/=tmp;
        }
        //cout<<tt<<"/"<<tot<<endl;
        printf("%lld/%lld\n",tt,tot);
    }
}
