#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#define INF 0x7ffffff
#define MAXN 3000000
#define M 1000000007
using namespace std;
unsigned long long a[MAXN+100];
int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("data.in", "r", stdin);
    //#endif
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(0);
    a[0]=1;a[1]=1;a[2]=1;a[3]=3;
    for(unsigned long long i=4;i<200010;i++){
        a[i]=((a[i-1]%M*(i-1))%M+(i-2))%M;
    }
    int t;
    cin>>t;
    int n;
    while(t--){
    	cin>>n;
    	cout<<a[n]<<endl;
    }

}
