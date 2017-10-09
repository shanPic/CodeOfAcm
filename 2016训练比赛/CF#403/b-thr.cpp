#include<bits/stdc++.h>
using namespace std;
int n;
double a[60004],b[60004];
int main()
{
    freopen("data.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lf",&a[i]);
    for(int i=0;i<n;i++) scanf("%lf",&b[i]);
    double lef=0.0,rig=1e9,mid;
    while(rig-lef>=1e-8){
        mid=(lef+rig)/2;
        double lowx=0,higx=1e9;
        for(int i=0;i<n;i++){
            lowx=max(lowx,a[i]-mid*b[i]);//Ð¡x
            higx=min(higx,a[i]+mid*b[i]);//´óx
        }
        if(lowx<=higx) rig=mid;
        else lef=mid;
    }
    printf("%.6lf\n",rig);
    return 0;
}
