#include<iostream>
using namespace std;
int main()
{
    int n,sum,tem;
    while(cin>>n&&n!=0){
        sum=0;
        for(int i=0;i<n;i++){
            cin>>tem;
            sum+=tem;
        }
        cout<<sum<<endl;
    }
}
