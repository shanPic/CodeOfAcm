#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[130];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x,y,res=-INF;
    int xl,yl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]-a[j]>res){
                x=a[i],y=a[j];
                xl=i,yl=j;
                res=a[i]-a[j];
            }
            if(a[j]-a[i]>res){
                y=a[i],x=a[j];
                xl=j,yl=i;
                res=a[j]-a[i];
            }
        }
    }
    a[xl]=-INF,a[yl]=-INF;
    sort(a,a+n);
    cout<<x<<" ";
    for(int i=0;i<n;i++){
        if(a[i]!=-INF){
            cout<<a[i]<<" ";
        }
    }
    cout<<y<<endl;
}
