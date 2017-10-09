#include<iostream>
#include<cstdio>
#include <stdlib.h>
using namespace std;
int main()
{
    freopen("date.in","r",stdin);
    double a=0,res=0;
    while(cin>>a){
        res+=a;
    }
    cout<<res<<endl;
    system("pause");
}
