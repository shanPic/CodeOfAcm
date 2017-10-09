#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int M=100010;
int sum[M];
unsigned long long N,T;
priority_queue<int> a;
unsigned long long cost(int k,priority_queue<int> qu)
{
//    int cost=0;
//    int i;
//    for(i=k-1;i<N;i+=(k-1)){
//        cost+=sum[i];
//    }
//    if(i>N-1&&i<N+k-2)
//        cost+=sum[N-1];
//    return cost;
    int sum;
    while(qu.empty()){
        for(int i=0;i<k;i++)

    }
}
int main()
{
    std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    unsigned long long t0;
    cin>>t0;
    while(t0--){
        cin>>N>>T;
        int tem;
        for(int i=0;i<N;i++){
            cin>>tem;
            a.push(tem);
        }
        sort(a,a+N);
        sum[0]=a[0];
        for(int i=1;i<N;i++){
            sum[i]=sum[i-1]+a[i];
        }
        int i;
        for(i=2;i<=N;i++){
            if(cost(i,a)<=T)
                break;
        }
        cout<<i<<endl;
    }
}
