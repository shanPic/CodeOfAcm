#include<bits/stdc++.h>
using namespace std;
int vis[7];
int main()
{
    int n;
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        vis[tmp]++;
    }
    if(vis[0]==0) {
        cout<<"-1"<<endl;
        return 0;
    }
    else{
        int round=vis[5]/9*9;
        if(round==0){
            cout<<0<<endl;
            return 0;
        }
        for(int i=0;i<round;i++){
            cout<<5;
        }
        for(int i=0;i<vis[0];i++){
            cout<<0;
        }
        cout<<endl;
    }
}
