#include<bits/stdc++.h>
using namespace std;
int val[20],weight[20];
int res;
int n,m;
struct sta
{
  int pos;
  int sumval;
  int sumweight;
  int YorN;
};
int main()
{
    queue<sta> a;
    struct sta tem,tem2;
    tem.pos=0;
    tem.sumval=0;
    tem.sumweight=0;
    tem.YorN=0;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    while(cin>>n>>m&&(n!=0||m!=0)){
        for(int i=0;i<n;i++){
            cin>>weight[i]>>val[i];
        }
        res=0;
        a.push(tem);
        tem.sumval=val[0];
        tem.sumweight=weight[0];
        tem.YorN=1;
        a.push(tem);
        res=0;
        while(!a.empty())
        {
            //cout<<111<<endl;
            tem2=a.front();
            cout<<tem2.pos<<"\t"<<tem2.YorN<<"\t"<<tem2.sumval<<"\t"<<tem2.sumweight<<endl;
            a.pop();
            if(!(tem2.sumweight>m)) {
                //cout<<2222<<endl;
                if(tem2.pos>=n-1) {
                    //cout<<33333<<endl;
                    if(tem2.sumval>res) {
                        res=tem2.sumval;
                    }
                } else {
                    //cout<<4444<<endl;
                    struct sta tem3;
                    tem3=tem2;
                    tem3.pos=tem3.pos+1;
                    tem3.sumval+=val[tem3.pos];
                    tem.sumweight+=weight[tem3.pos];
                    tem.YorN=1;
                    a.push(tem3);
                    tem3.sumval-=val[tem3.pos];
                    tem.sumweight-=weight[tem.pos];
                    a.push(tem3);
                }
            }
            else if(tem2.sumweight==m){
                if(tem2.sumval>res)
                    res=tem2.sumval;
            }
            cout<<endl;
        }
        cout<<res<<endl;
    }
}
