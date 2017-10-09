#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+30;
bool vis[MAXN];
int a[MAXN];
int b[MAXN];
int n;
int res[MAXN];
inline int f(int s,int x)
{
    //for(int i=0;i<n;i++)
    for(int i=0;i<n;i++){
        if(b[i]==x) return i;
    }
}
void b(int l,int r)
{
    if(l==r-1){

    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n;i++){

        }
    }
}
