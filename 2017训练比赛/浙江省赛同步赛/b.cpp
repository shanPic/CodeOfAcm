#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
int a[MAXN];
int main()
{
    //freopen("data.in","r",stdin);
    int t,n;
    scanf("%d",&t);
    int num;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(n<10||n>13)
        {
            printf("No\n");
            continue;
        }
        bool flag=1;
        sort(a,a+n);
        if(a[0]!=1){
            printf("No\n");
            continue;
        }
        else{
            num=0;
            int i=0;
            while(a[i]==1){
                num++;
                i++;
            }
            if(num<2){
                printf("No\n");
                continue;
            }
            for(;i<n;i++){
                if(a[i]-a[i-1]>2&&i!=n-1){
                    flag=0;
                    break;
                }
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }
}
