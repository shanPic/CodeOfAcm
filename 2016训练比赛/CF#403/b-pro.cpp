/*
当然也可以三分，这里采用另一种二分时间的方法
耗费某一个时间时，求出最南边可以到达的点及最北端可以到达的点
当有交点时，说明都可以到达
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=60000+100;
const double EPS=1e-6;
int x[MAXN],v[MAXN];
int main()
{
   // freopen("data.in","r",stdin);
    int n;
    cin>>n;
    int xss=0x3f3f3f3f,xnn=-1;
    for(int i=0;i<n;i++){
        cin>>x[i];
        xss=min(xss,x[i]);
        xnn=max(xnn,x[i]);
    }
    int vmin=0x3f3f3f3f,vmax=-1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        vmin=min(vmin,v[i]);
        vmax=max(vmax,v[i]);
    }
    double l=0,r=(xnn-xss)*1.0/2/vmin+1;//初始化l与r缩小搜索范围，也可不初始化，直接给r一个大数即可
    double res=0;
    double mid;
    double tmp;
    while(fabs(r-l)>=EPS){
        mid=(l+r)/2.0;
        //cout<<fixed<<setprecision(6)<<mid<<endl;
        double xn=0x3f3f3f3f,xs=-1;
        for(int i=0;i<n;i++){
                xs=max(xs,x[i]*1.0-v[i]*mid);
                xn=min(xn,x[i]*1.0+v[i]*mid);
        }
        if(xn>xs){
           r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<fixed<<setprecision(12)<<mid<<endl;

}
