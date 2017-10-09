#include<bits/stdc++.h>
using namespace std;
const int MAXN=201000;
unsigned int data[MAXN];
unsigned int sum;
unsigned int res;
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    while(cin>>n){
        sum=0;
        for(int i=0;i<n;i++){
            cin>>data[i];
            sum+=data[i];
        }
        //cout<<sum<<endl;
        res=0;
        for(int i=0;i<n;i++){
            unsigned int tem=sum;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(data[j]<data[i]) tem-=data[j];
                else tem-=((data[j])%(data[i]));
            }
            res=max(tem,res);
        }
        cout<<res<<endl;
    }
}
