#include<bits/stdc++.h>
using namespace std;
const int MAXN=100030;
long long a[MAXN];
int main()
{
    int n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        //cout<<(a[n-1]-a[0])*2<<endl;
        printf("%lld\n",(a[n-1]-a[0])*2);
    }
}
