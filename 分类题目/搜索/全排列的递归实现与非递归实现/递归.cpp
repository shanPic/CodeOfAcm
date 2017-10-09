#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void Perm(string s,int k,int m)
{
    if(k==m)
    {
        int static a=1;
        cout<<a++<<"\t"<<s<<endl;
    }
    else{
        for(int i=k;i<=m;i++){
            swap(s[i],s[k]);
            Perm(s,k+1,m);
            swap(s[i],s[k]);
        }
    }
}
int main()
{
    string s="ABC";
    Perm(s,0,s.size()-1);
}
