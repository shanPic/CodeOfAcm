#include<bits/stdc++.h>
using namespace std;
const int days[13]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string m[8]={"sunday","monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main()
{
    //freopen("data.in","r",stdin);
    map<int,string> xq;
    map<string,int> xq2;
    for(int i=0;i<=7;i++){
        xq.insert(make_pair(i,m[i]));
        xq2.insert(make_pair(m[i],i));
    }
    string a,b;
    bool flag=1;
    while(cin>>a>>b){
        flag=0;
        for(int i=1;i<=11;i++){
            if(xq[(xq2[a]+(days[i]%7))%7]==b){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
