#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("data.in","r",stdin);
    int h,m,s;
    int a;
    double ori;
    double ss;
    int tots;
    while(~scanf("%d:%d:%d",&h,&m,&s)){
        tots=h*3600+m*60+s;
        scanf("%d",&a);
        ori=fabs(((s*1.0/60+m)*1.0/2+h*30.0)-(s*1.0/10+m*6.0));
        ss=ori/(11.0/120.0);
        tots=tots+(int)ori;
        s=tots%60;
        m=tots/60%60;
        h=tots/3600;
        printf("%02d:%02d:%02d\n",h,m,s);
    }
}
