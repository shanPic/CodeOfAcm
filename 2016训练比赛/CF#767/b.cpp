#include<bits/stdc++.h>
using namespace std;
const long long INF=0x3f3f3f3f;
const int MAXN=100010;
struct node
{
    long long arv;
    long long endt;
}a[MAXN];
int main()
{
    freopen("data.in","r",stdin);
    long long ts,tf,t;
    cin>>ts>>tf>>t;
    long long n;
    cin>>n;
    if(n==0){
        cout<<ts<<endl;
        return 0;
    }
    long long tmp;
    long long  tts=ts;
    a[0].arv=a[0].endt=ts;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        a[i].arv=tmp;
        if(tts<tf){
            if(tts>=tmp)
                tts+=t;
            else tts=tmp+t;
            a[i].endt=tts;
        }
        else{
            a[i].endt=INF;
        }
    }
    long long res=0,flag=INF;
    for(int i=1;i<=n;i++){
        if((a[i-1].endt-a[i].arv)<flag&&a[i].endt!=INF){
            flag=a[i-1].endt-a[i].arv;
            res=i;
        }
        if(a[i].endt==INF) break;
    }
    //cout<<flag<<endl;
    //cout<<res<<endl;
    //cout<<a[res-1].endt<<endl;
    if(flag<0){
        cout<<a[res-1].endt<<endl;
    }
    else{
        cout<<a[res].arv-1<<endl;
    }

}
