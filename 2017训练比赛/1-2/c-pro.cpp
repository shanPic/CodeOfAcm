/*
二分答案
设答案为x，则x一定会满足
x*n-sum>=x
sum为需要的普通玩家比赛总数
每个人参与x场比赛，比赛总数为x*n，减去sum
即为最多有多少场比赛有主持人
找到满足这个条件的最小的数即可
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0,x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    int l=0,r=sum;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*n-sum>x){
            //l=mid+1;
            r=mid-1;
        }
        else //r=mid-1;
            l=mid+1;
    }
    cout<<r<<endl;
}
