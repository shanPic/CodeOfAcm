#include<bits/stdc++.h>
using namespace std;
const int M=100010;
int sum[M];
int a[M];
int N,T;
//priority_queue<int> a;
bool cost(int k)
{
//    int cost=0;
//    int i;
//    for( i=k-1;i<N;i+=(k-1)){
//        cost+=sum[i];
//    }
//    if(i>N-1&&i<N+k-2)
//        cost+=sum[N-1];
//    return cost;
    int cost=0;
    int i;
    for(i=k-1;i<N;i+=(k-1)){
        cost+=sum[i];
    }
    if(i>N-1&&i<N+k-2)
        cost+=sum[N-1];
    return cost;
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	freopen("data.in","r",stdin);
    int t0;
    int k;
    cin>>t0;
    while(t0--){
        cin>>N>>T;
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        sort(a,a+N);
        sum[0]=a[0];
        for(int i=1;i<N;i++){
            sum[i]=sum[i-1]+a[i];
        }
        int i;
        cout<<cost(2)<<endl;
        for(i=2;i<N;i++){
            if(cost(i)<T)
                break;
        }
        cout<<i<<endl;
    }

}
