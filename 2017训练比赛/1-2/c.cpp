#include<bits/stdc++.h>
using namespace std;
int a[100000+30];
int main()
{
    int n;
    int ma=-1,mi=0x3f3f3f3f;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n-1]+a[1]-(a[n-2]-a[0])<<endl;
}
