#include<bits/stdc++.h>
using namespace std;
const int MAXN=23;
int n,m;
int main()
{
    cin>>n>>m;
    int x;
    int sum1=0;
    int sum2=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i&1){
            //cout<<111111<<endl;
            sum1+=x;
        }
        else{
            //cout<<222222<<endl;
            sum2+=x;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i&1){
            //cout<<333333<<endl;
            sum2+=x;
        }
        else{
            //cout<<44444<<endl;
            sum1+=x;
        }
    }
    long long res=0;
    //res+=m*sum;
    if(n&1){
        res+=(m/2)*(sum1+sum2);
        res+=(m%2)*sum1;
        cout<<res<<endl;
    }
    else{
        cout<<m*sum1<<endl;
    }

}
