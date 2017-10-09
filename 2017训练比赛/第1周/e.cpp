#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+3;
int m[MAXN];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //freopen("data.in","r",stdin);
    int a,b;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    cin>>a>>b;
    sort(m,m+n);
    int len=unique(m,m+n)-m;
    int res=0;
    int now=-1;
    while(a>b){
        //now=a-1;
        now=a-1;
        for(int i=0;i<len;i++){
            if(a-a%m[i]<b){
                m[i--]=m[--len];
            }
            else{
//                now=max(now,a%m[i]);
//                now=max(now,1);
                now=min(now,a-a%m[i]);
            }
        }
        //a-=now;
        a=now;
        res++;
    }
    cout<<res<<endl;
}
