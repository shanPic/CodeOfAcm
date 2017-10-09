#include <bits/stdc++.h>
using namespace std;
const int MAXN=3e5+30;
int a[MAXN];
int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    int n,m;
   while(~ scanf("%d%d",&n,&m)){
    int flag=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==-1||a[i]==0){
            flag=1;
        }
    }
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
    }
    if(flag){
       printf("0\n");
    }
    else{
        if(n>=2&&m>=1){
            printf("1\n1\n");
        }
        else{
            printf("-1\n");
        }
    }
   }
	return 0;
}
