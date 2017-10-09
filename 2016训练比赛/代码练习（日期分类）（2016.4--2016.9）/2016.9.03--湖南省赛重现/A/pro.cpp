#include<iostream>
using namespace std;
const long long C=26545+1;
int sum[2017];
int main()
{
    long long n,m,res=0,tem=0;
    sizeof(sum[0],0,sizeof(sum[0]));
    for(int i=1;i<=2016;i++){
        for(int j=1;j<=2016;j++){
            if((i*j)%2016==0)
                tem++;
        }
        sum[i]=tem;
    }
    while(cin>>n>>m){
        res=0;
        res+=(((n/2016ll)*(m/2016ll))*sum[2016]);
        res+=((m/2016ll)*sum[n%2016]);
        for(int i=1;i<=n%2016ll;i++){
            for(int j=1;j<=m%2016ll;j++)
                if((i*j)%2016ll==0)
                    res++;
        }
        cout<<res<<endl;
    }
}
