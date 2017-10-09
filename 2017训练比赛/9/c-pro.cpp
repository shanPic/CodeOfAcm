#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+30;
int a[MAXN];
int main()
{
    long long n;
    cin>>n;
    long long res=0;
    long long ori=n;
    //if(n%3) res++;
    n=n+(3-n%3);
    //cout<<n<<endl;
    for(;n>=(((n-ori+1)*(n-ori)/2)*3);n+=3){
        res++;
    }
    cout<<res<<endl;
}
