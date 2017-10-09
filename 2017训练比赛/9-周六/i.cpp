#include<bits/stdc++.h>
using namespace std;
const int MAXN=3000000+30;
char str[MAXN];
void f(int n)
{
    int tmp=0;
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
int main()
{
    freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(str);
        f(strlen(str));
        for(int i=0;i<strlen(str);i++){
            printf("%X",str[i]);
        }
        printf("\n");
    }
}
