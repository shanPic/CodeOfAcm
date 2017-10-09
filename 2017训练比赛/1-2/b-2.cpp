#include<bits/stdc++.h>
using namespace std;
int v;
int c[10],ok[10];
int main()
{

    freopen("data.in","r",stdin);
    while(cin>>v){
        for(int i=1;i<=9;i++) ok[i]=1;
        int mi=0x3f3f3f3f;
        int cnt=0;
        for(int i=1;i<=9;i++){
            cin>>c[i];
            if(c[i]>v) ok[i]=0;
            else cnt++;
            mi=min(mi,c[i]);
        }
        if(cnt==0){
            cout<<-1<<endl;
            continue;
        }
        int flag=0;
        for(int i=1;i<=9;i++){
            if(ok[i])
            if(c[i]==mi&&i>flag){
                flag=i;
            }
        }
        int res=0;
        int vc=v;
        int cou=1;
        for(int i=0;i<v/c[flag]-1;i++){
            cou*=10;
            res*=10;
            res+=flag;
            vc-=c[flag];
        }
        if(vc>c[flag]){
            int f2;
            for(int i=flag+1;i<=9;i++){
                if(c[i]<=vc&&i>flag) flag=i;
            }
           // cou*=10;
            flag*=cou;
            cou*=10;
            res+=flag;
            vc-=c[flag];
        }
        else {res*=10;res+=flag;}
        if(res) cout<<res<<endl;
        else cout<<-1<<endl;
    }
}
