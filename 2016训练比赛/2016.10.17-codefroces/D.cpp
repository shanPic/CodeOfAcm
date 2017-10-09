#include<bits/stdc++.h>
using namespace std;
vector<string> a;
int n,m;
bool judge()
{
    for(auto ite=(a.begin()+1);ite!=a.end();ite++){
        if(*ite<*(ite-1))
             return 0;
    }
    return 1;
}
void swi()
{
    for(auto ite=a.begin();ite!=a.end();ite++){
        for(auto itstr=(*ite).begin();itstr!=(*ite).end();itstr++)
            if(*itstr==(m+'0'))
                (*itstr)='1';
            else (*itstr)++;
    }
}
int main()
{
    freopen("data.in","r",stdin);
    int tem;
    string ch;
    while(cin>>n>>m){
        a.clear();
        for(int i=0;i<n;i++){
            cin>>tem;
            string str="";
            for(int i=0;i<tem;i++){
                cin>>ch;
                //str[i]=ch;
                str.append(ch);
            }
            a.push_back(str);
        }
        bool flag=0;
        int i;
        for(i=0;i<n;i++){
            if(judge()){
                flag=1;
                break;
            }
            swi();
        }
        if(flag)
            cout<<i<<endl;
        else cout<<-1<<endl;
    }
}
