#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int x;
    int sk,st;
    while(t--){
        scanf("%d",&n);
        sk=st=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(x==1) sk++;
            else if(x==2) st++;
        }
        if(st==sk) printf("Draw\n");

        else if(st>sk) printf("Tohru\n");
        else printf("Kobayashi\n");
    }
}
