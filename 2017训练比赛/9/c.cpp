#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+30;
int a[MAXN];
void init(int n)
{
    a[0]=2;
    int flag=1;
    for(int i=1;i<n;i++){
        flag++;
        a[i]=a[i-1]+flag;
    }
}
int main()
{
    init(MAXN-3);
    for(int i=0;i<MAXN-3;i++){
        cout<<a[i]<<"\t";
    }
}
