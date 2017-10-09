#include <bits/stdc++.h>
using namespace std;
int deal(string &a)
{
    int i,fu=1;
    if(a[0]=='-')
    {
        a.erase(a.begin());
        fu=-1;
    }
    if(a[0]=='0'&&a[1]!='.')
        a.erase(a.begin());
    if(a.find('.')!=string::npos)
        for(i=a.size()-1; a[i]=='0'; i--)
            a.erase(a.begin()+i);
    if(a[i]=='.')
        a.erase(a.begin()+i);
    if(a[0]=='0')
        fu=1;
    return fu;
}

int main()
{
    int i,a1,b1;
    string a,b;
    while(cin>>a>>b)
    {
        a1=deal(a);
        b1=deal(b);
        if(a==b&&a1==b1)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
