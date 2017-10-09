#include<bits/stdc++.h>
using namespace std;
struct pro
{
    vector<int> nowsou;
    vector<int> resou;
};
typedef pro proc;
vector<proc> a;
vector<int> sou;
int main()
{
    int p,r,t;
    int tem;
    proc ptem;
    while(cin>>p>>r>>t){
        for(int i=0;i<r;i++){
            cin>>tem;
            sou.push_back(tem);
        }
        for(int i=0;i<p;i++){
            ptem.nowsou.clear();
            ptem.resou.clear();
            for(int j=0;j<r;j++){
                cin>>tem;
                ptem.nowsou.push_back(0);
                ptem.resou.push_back(tem);
            }
        }
        for(int i=0;i<r;i++){

        }
    }
}
