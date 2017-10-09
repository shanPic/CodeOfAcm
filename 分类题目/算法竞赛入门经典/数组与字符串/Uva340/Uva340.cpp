#include<bits/stdc++.h>
using namespace std;
int str[1100];
int nu[10];
int nu2[10];
int str2[1100];
int a,b;
int n;
void init()
{
    memset(nu,0,sizeof(nu));
    memset(nu2,0,sizeof(nu2));
    a=b=n=0;
}
bool shuru()
{
    bool flag=0;
    for(int i=0;i<n;i++){
        cin>>str2[i];
        if(str2[i]!=0)
            flag=1;
    }
    return flag;
}
int main()
{
    int casen=0;
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    init();
    while(cin>>n&&n!=0){
        printf("Game %d:\n",++casen);
        for(int i=0;i<n;i++){
            cin>>str[i];
            nu[str[i]]=nu[str[i]]+1;
        }
        while(shuru()){//
            a=b=0;
            memset(nu2,0,sizeof(nu2));
            for(int i=0;i<n;i++){
                nu2[str2[i]]=nu2[str2[i]]+1;
            }
            for(int i=0;i<10;i++){
                b+=(min(nu[i],nu2[i]));
            }
            for(int i=0;i<n;i++){
                if(str2[i]==str[i])
                    a++;
            }
            printf("    (%d,%d)\n",a,b-a);
        }
        init();
    }
}
