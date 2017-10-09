#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b!=0)
        return gcd(b,a%b);
    else return a;
}
int main()
{
    cout<<gcd(5,15)<<endl;
    cout<<gcd(2,3)<<endl;
}
