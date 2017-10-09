#include<bits/stdc++.h>
using namespace std;
const int M=505;
int a[M];
int b[M];
set<int> res;
int gcd(int a,int b)
{
    if(b!=0)
        return gcd(b,a%b);
    else return a;
}
int main()
{
    //freopen("data.in","r",stdin);
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    int t,n,tem;cin>>t;
    while(t--){
        res.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res.insert(gcd(a[i],a[j]));
            }
        }
        for(set<int>::iterator ite=res.begin();ite!=res.end();ite++)
            cout<<*ite<<" ";
        cout<<endl;
    }

}
