#include<iostream>
using namespace std;
int main()
{
    long long m,n,res;
    while(cin>>m>>n){
        res=0;
        for(int i=1;i<=2016;i++){
            for(int j=1;j<=2016;j++){
                if((i*j)%2016==0){
                    if(m>=i&&n>=j)
                    res+=((m-i)/2016+1)*((n-j)/2016+1);
                    else ;
                }
            }
        }
        cout<<res<<endl;
    }
}
