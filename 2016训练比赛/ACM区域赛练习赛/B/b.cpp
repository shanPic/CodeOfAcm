#include<bits/stdc++.h>
using namespace std;
double a[510];
double f(double r1,double r2)
{
    return (r1+r2+r2*r2)/(r1-r2);
}
double jisuan(double x,double y)
{
    double tem=f(x,y);
//    cout<<(tem*tem-y*y)/tem*x<<"   111111"<<endl;
    return tem2=(tem*tem-y*y)/tem*x;
//    if(tem2<=x)
//        return x;
//    else return tem2;
}
int main()
{
    freopen("data.in","r",stdin);
    int n;
    double res;
    while(cin>>n){
        res=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            double an=max(a[i],a[i+1]);
            double bn=min(a[i],a[i+1]);
            if(a[i]==a[i+1]){
                res+=(a[i]+a[i]);
            }
            else {
            res+=jisuan(an,bn);
            }
        }
        res+=(a[0]+a[n-1]);
        cout<<setprecision(8)<<res<<endl;
    }
}
