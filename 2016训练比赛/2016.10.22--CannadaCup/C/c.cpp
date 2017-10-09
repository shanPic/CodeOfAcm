#include<bits/stdc++.h>
using namespace std;
const double sqrt5=2.23607;
void dayin(string &str,int a,int b)
{
//    int f=0;
//    for(int i=(14+a+(b-a-1)/2);i<27&&i>=0;i++){
//        cout<<str[i];
//        f++;
//    }
//    for(int i=0;i<a;i++){
//        cout<<str[i];
//        f++;
//    }
//    for(int i=)
    char s[3][14];
    int tem=13-(b-a-1)/2;
    s[1][tem]=str[a];
    int j=1;
    for(int i=(tem+1);i<=13;i++){
        s[1][i]=str[a+j];
        j++;
    }
    for(int i=13;i>=tem;i--){
        if(a+j==b){
            i++;
            continue;
        }
        s[2][i]=str[j];
        j++;
    }


}
int main()
{
    string str;
    char ch;
    int flag;
    int a,b;
    map<char,int> m;
    for(int i=0;i<26;i++){
        m.insert('A'+i);
    }
    while(cin>>str){
        flag=1;
        for(auto ite=m.begin();ite!=m.end();ite++){
            ite->second=0;
        }
        stringstream a(str);
        for(int i=0;i<27;i++){
            a>>ch;
            if(m[ch]!=0&&i==(i-1)){
                flag=0;
                a=m[ch];
                b=i;
            }
            m[ch]=i;
        }
        if(flag){
            dayin(str,a,b);
        }
        else cout<<"Impossible"<<endl;
    }
}
