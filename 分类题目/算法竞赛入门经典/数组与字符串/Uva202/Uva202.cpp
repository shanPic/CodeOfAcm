#include<bits/stdc++.h>
using namespace std;
int flag;
int cyc;
int tem[10000];
int tem2[10000];
bool ok(int a)
{
    for(int i=0;i<flag;i++){
        if(a==tem2[i]){
            cyc=i;
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a,b;
    int oa;
    while(cin>>a>>b){
        oa=a;
        memset(tem2,0,sizeof(tem2));
        memset(tem,0,sizeof(tem));
        tem[0]=(a/b);
        flag=0;
        cyc=0;
        a=a%b*10;
        while(ok(a)){
            tem2[flag++]=a;
            tem[flag]=a/b;
            a=a%b*10;
        }
        int temnu=1;
        bool flag2=0;
        printf("%d/%d = ",oa,b);
        for(int i=0;i<flag+1;i++){
            if(i==0)
                cout<<tem[i]<<".";
            else if(i==(cyc+1)){
                cout<<"("<<tem[i];
                flag2=1;
            }
            else{
                cout<<tem[i];
                if(flag2) temnu++;
                if(temnu==50){
                    cout<<"...";
                    break;
                }
            }
        }
        cout<<")"<<endl;
        cout<<"   "<<flag-cyc<<" = number of digits in repeating cycle"<<endl<<endl;
    }
}
