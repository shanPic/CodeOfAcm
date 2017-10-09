#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[100100];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    int mi=INF;
    bool flag=0;
    for(int i=1;i<n;i++){
        if(a[i]>mi){
            flag=1;
            break;
        }
        if((a[i-1]-a[i])<mi){
            mi=a[i-1]-a[i];
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
