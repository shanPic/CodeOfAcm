#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s(ll a)
{
    ll res=0;
    while(a){
        res+=a%10;
        a=a/10;
    }
    return res;
}
int main()
{
    freopen("data.out","w",stdout);
    ll a;
    int n=1;
    double res=s(1*2)/s(1);
    while(res<100&&n<=999999999){
        n++;
        cout<<n<<"\t"<<(res=(s(2*n)*1.0)/(s(n)*1.0))<<endl;
    }
//    int flag=0;
//    for(int i=0;i<101;i++){
//        for(int j=0;j<101;j++){
//            flag=0;
//            for(int k=1;k<399999;k++){
//                if(i*s(k)==j*s(k*2)){
//                    cout<<i<<"\t"<<j<<"\t"<<k<<endl;
//                    flag=1;
//                    break;
//                }
//            }
//            if(!flag) cout<<i<<"\t"<<j<<"\t"<<0<<endl;
//        }
//    }
}
