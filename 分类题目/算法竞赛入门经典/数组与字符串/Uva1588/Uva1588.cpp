#include<bits/stdc++.h>
using namespace std;
const int M=101;
char a[M],b[M];
int res;
int m,n;
void jisuan(char* ac,char* bc,int mn)
{
    bool flag;
    int minn=min(m,n);
    for(int i=0;i<mn;i++){
        flag=1;
        int fix=min(minn,mn-i);
        for(int j=0;j<fix;j++){
            if(ac[i+j]=='2'&&bc[j]=='2'){
                flag=0;
                break;
            }
        }
        if(flag){
            res=min(res,m+n-fix);
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    while(scanf("%s%s",a,b)==2){
        n=strlen(a);
        m=strlen(b);
        res=m+n;
        jisuan(a,b,n);
        jisuan(b,a,m);
        cout<<res<<endl;
    }
}
