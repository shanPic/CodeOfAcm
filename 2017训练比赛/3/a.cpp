#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
int r[MAXN];
int w[MAXN];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    sort(r,r+n);
    sort(w,w+m);
    if(r[n-1]>=w[0]){
        cout<<-1<<endl;
        return 0;
    }
    else{
        int ans=r[n-1];
        if(ans>=2*r[0]){
            cout<<ans<<endl;
            return 0;
        }
        else{
            ans=2*r[0];
            if(ans<w[0]){
                cout<<ans<<endl;
                return 0;
            }
            else{
                cout<<-1<<endl;
                return 0;
            }
        }
    }
}
