#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<regex>
using namespace std;
const int MAXN=2600;
string s,p;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>s>>p;
        string s1=".*";
        string s2="(a*|b*|c*|d*|e*|f*|g*|h*|i*|j*|k*|l*|m*|n*|o*|p*|q*|r*|s*|t*|u*|v*|w*|x*|y*|z*"
                  "|A*|B*|C*|D*|E*|F*|G*|H*|I*|J*|K*|L*|M*|N*|O*|P*|Q*|R*|S*|T*|U*|V*|W*|X*|Y*|Z*)";
        //string s2="(.)\\1*";
        int len=s2.length();
        auto pos=p.find(s1);
        while(pos!=string::npos)
        {
            p.replace(pos,2,s2);
            pos=p.find(s1,pos+len);
        }
        regex pat(p);
        if(regex_match(s,pat)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}