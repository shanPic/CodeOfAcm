#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
int a[MAXN];
int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    int n;
    cin>>n;
    int m=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m=max(m,a[i]);
    }
    sort(a,a+n);
    int res=gcd(a[n-1],a[n-2]);
    for(int i=n-3;i>=0;i--){
        res=gcd(max(res,a[i]),min(res,a[i]));
        if(res==1) break;
    }
    int total=m/res-n;
    if(total%2) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
