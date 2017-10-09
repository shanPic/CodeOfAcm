#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
int a[MAXN];
vector<int> c;
void init(int n)
{
    c.clear();
    for(int i=1;i<=n;i++){
        c.push_back(i);
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        init(n);
//        cout<<"----------"<<endl;
//        cout<<*(c.begin()+3)<<endl;
//        cout<<"--------"<<endl;
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        int lead=1;
        int t=0;
        vector<int>::iterator ite=c.begin();
        int now;
        while(t<k){
            //cout<<111111<<endl;
            now=(lead+(a[t]%n))%n;
            if(now==0){
                cout<<*(ite+n-1)<<" ";
                c.erase(ite+n-1);
                n--;
                lead=1;
            }
            else{
                cout<<*(ite+now-1)<<" ";
                c.erase(ite+now-1);
                n--;
                lead=now;
            }
            t++;
        }
        cout<<endl;
    }
}
