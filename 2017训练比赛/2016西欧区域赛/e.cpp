/*
* @FileName: D:\代码与算法\2017训练比赛\2016西欧区域赛\e.cpp
* @Author: Pic
* @Created Time: 2017/10/6 15:59:02
*/
#include <bits/stdc++.h>
using namespace std ;
 
typedef long long LL ;
 
#define clr( a , x ) memset ( a , x , sizeof a )
typedef pair<int,int>pi;
int n;
int a[20000];
void solve () {
    vector<pi>V;
    for(int i=1;i<=n;i++)scanf("%d",a+i),V.push_back(pi(a[i],i));
    sort(V.begin(),V.end(),greater<pi>());
    int sum=0;
    for(int i=1;i<V.size();i++)sum+=V[i].first;
    if(sum<V[0].first)puts("impossible");
    else{
        for(int i=0;i<n;i++)printf("%d%c",V[i].second,i==n-1?'\n':' ');
    }
}
 
int main () {
    while ( ~scanf ( "%d" , &n ) ) solve () ;
}
