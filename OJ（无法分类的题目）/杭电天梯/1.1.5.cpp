#include<iostream>
using namespace std;
int main()
{
    int N,m,sum,tem;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>m;
        sum=0;
        for(int i=0;i<m;i++){
            cin>>tem;
            sum+=tem;
        }
        cout<<sum<<endl;
    }
}
