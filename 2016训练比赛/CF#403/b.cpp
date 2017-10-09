#include<bits/stdc++.h>
using namespace std;
const double INF=1e-7;
struct node
{
    int v;
    int x;
};
    int n,x,v;
node a[60010];
inline double solve(int i)
{
    double res=-1;
    for(int i=0;i<n;i++){
        res=max(res,fabs(a[i].x-i)*1.0/a[i].v);
    }
    return res;
}
inline double solve2(double i)
{
    double res=-1;
    for(int i=0;i<n;i++){
        res=max(res,(a[i].x*1.0-i)*1.0/a[i].v);
    }
}
int main()
{
    int mi=0x3f3f3f3f,ma=-1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x;
        mi=min(mi,a[i].x);
        ma=max(ma,a[i].x);
    }
    for(int i=0;i<n;i++){
        cin>>a[i].v;
    }
    double res=0x3f3f3f3f;
    double tmp;
    int mid;
    for(int i=mi;i<=ma;i++){
        tmp=solve(i);
        if(tmp<res){
            mid=i;
        }
    }
    double ptr=mid-1;
    while(ptr!=mid+1){
        res=min(res,solve2(ptr));
        ptr+=INF;
    }
    cout<<fixed<<setprecision(12)<<res<<endl;
}
