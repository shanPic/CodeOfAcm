#include<iostream>
using namespace std;
int main()
{
    int N,m,sum,tem;
    cin>>N;
    cin>>m;
    sum=0;
    while(m--){
            cin>>tem;
            sum+=tem;
        }
        cout<<sum<<endl;
    for(int i=1;i<N;i++){
        cin>>m;
        sum=0;
        while(m--){
            cin>>tem;
            sum+=tem;
        }
        cout<<endl<<sum<<endl;
    }
}
