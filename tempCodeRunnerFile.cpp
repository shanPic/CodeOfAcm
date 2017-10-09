#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int,int> PII;
const double eps=1e-8;
const double pi=acos(-1.0);
const int K=1e6+7;
const int mod=1e9+7;

int now,pre,v[K],pe[K],nt[K],dl[K];
set<int>st;
vector<int>tmp;

int main(void)
{
    //freopen("in.acm","r",stdin);
    int t,n;cin>>t;
    while(t--)
    {
        memset(dl,0,sizeof dl);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   dl[i]=0,scanf("%d",v+i),pe[i]=i-1,nt[i]=i+1,st.insert(i);
        nt[0]=1,pe[n+1]=n,pe[1]=0,nt[n]=n+1;
        v[0]=0,v[n+1]=K;
        while(st.size())
        {
            tmp.clear();
            for(auto &x:st)
            {
                int ntx=nt[x],px=pe[x];
                if(v[px]>v[x])  tmp.PB(px),tmp.PB(x);
                if(v[x]>v[ntx]) tmp.PB(x),tmp.PB(ntx);
            }
            st.clear();
            for(auto &x:tmp)
            if(!dl[x])
            {
                int ntx=nt[x],px=pe[x];
                nt[px]=ntx,pe[ntx]=px;
                st.insert(px);
                dl[x]=1;
            }
        }
        int cnt=0;
        for(int i=nt[0];i!=n+1;i=nt[i])   cnt++;
        printf("%d\n",cnt);
        for(int i=nt[0];i!=n+1;i=nt[i])   printf("%d ",v[i]);
        printf("\n");
    }
    return 0;
}