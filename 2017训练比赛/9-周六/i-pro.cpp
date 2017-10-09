#include<bits/stdc++.h>
using namespace std;
const int MAXN=4000000+30;
char str[MAXN];
inline void f(int n)
{
    int tmp=0;
    if(n==0) printf("00");
    else
    while(n){
        tmp=0;
        for(int i=0;i<7;i++){
            tmp=tmp|((1&(n&1))<<i);
            n=n>>1;
        }
        if(n){
            tmp=tmp|(1<<7);
        }
        printf("%02X",tmp);
    }
}
char mo[18]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    scanf("%d\n",&t);
    int x;
    while(t--){
        cin.getline(str,MAXN);
        f(strlen(str));
        int n=strlen(str);
        for(int i=0;i<n;i++){
            putchar(mo[str[i]/16]);
            putchar(mo[str[i]%16]);
        }
        printf("\n");
        //cout<<endl;
    }
}
