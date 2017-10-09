#include<bits/stdc++.h>
using namespace std;
const int MAXN=99999;
int str[1100];
int a[MAXN];
int n;
int main()
{
    //freopen("data.in","r",stdin);
    int buf;
    int flag;
    while(cin>>n){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>str[i];
        }
        for(int i=1;i<=n;i++){
            a[str[i]]=1;
            if(i<=n-1)
                a[str[i]*10+str[i+1]]=1;
            if(i<=n-2)
                a[str[i]*100+str[i+1]*10+str[i+2]]=1;
        }
        int i;
        for(i=0;i<MAXN;i++){
            if(a[i]==0)
                break;
        }
        cout<<i<<endl;
    }
}
