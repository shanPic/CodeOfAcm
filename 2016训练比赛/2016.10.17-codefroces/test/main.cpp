#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int tj[MAXN];
vector<int> a[500010];
int t,c;
void add(int l,int r)
{
    tj[l]++;
    tj[r++]--;
}
int solve()
{
    for(int i=1; i<t; i++) {
        int len=min(a[i].size(),a[i-1].size());
        int j=0;
        while(a[i][j]==a[i-1][j]&&j<len) {
            j++;
        }
        if(j==len&&a[i].size()<a[i-1].size()){
            return -1;
        }
        else{
            if(j==len){
                add(0,c);
            }
            else if(a[i][j]>a[i-1][j]){
                add(0,c-a[i-1][j]);
            }
            else {
                add(c-a[i-1][j]+1,c-a[i][j]);
            }
        }
    }
    int res=0;
    for(int i=0;i<=c;i++){
        res+=tj[i];
//        cout<<res<<endl;
        if(res==(t-1)){
            return i;
        }
    }
    return -1;
}
int main()
{
    freopen("data.in","r",stdin);
    int tem;
    while(cin>>t>>c){
        for(int k=0;k<t;k++){
            a[k].clear();
        }
        for(int k=0;k<=c;k++){
            tj[k]=0;
        }
        for(int i=0;i<t;i++){
            int n;
            cin>>n;
            for(int j=0;j<n;j++){
                //cout<<11111<<endl;
                cin>>tem;
                a[i].push_back(tem);
            }
        }
        cout<<solve()<<endl;
    }
}
