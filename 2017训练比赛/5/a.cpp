#include<bits/stdc++.h>
using namespace std;
const int MAXN=200030;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int res=1;
    int dis=a[1]-a[0];
    int tmp;
    for(int i=2;i<n;i++){
        tmp=a[i]-a[i-1];
        if(tmp<dis){
            res=1;
            dis=a[i]-a[i-1];
        }
        else if(tmp==dis){
            res++;
        }
    }
    printf("%d %d\n",dis,res);
}
