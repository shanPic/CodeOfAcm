#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("data.in","r",stdin);
    int t;
    int n,k;
    scanf("%d",&t);
    long long flag=1;
    long long res=0;
    long long s=0;
    while(t--){
        scanf("%d%d",&n,&k);
        flag=1,res=0,s=0;
        while(n>k){
            if(n&1){
                if(s!=0){
                    res+=(flag-s);
                    s=0;
                    n++;
                }
                else{
                    //res+=flag;
                    s=flag;
                    n--;
                    //n++;
                }
            }
            flag*=2;
            n/=2;
        }
        if(s!=0) res+=(flag-s);
        printf("%d\n",res);
    }
}
