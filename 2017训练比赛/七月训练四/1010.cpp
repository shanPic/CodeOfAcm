/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1010.cpp
* @Author: Pic
* @Date:   2017-08-03 09:24:54
* @Last Modified time: 2017-08-03 10:41:54
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;
const int MAXN=320000+30;
struct node
{
    int dir;
    double pos;
    char name[280];
};
node a[MAXN];
int mp[MAXN];
bool cmp(int i,int j)
{
    return a[i].pos<a[j].pos;
}
//http://blog.sina.com.cn/s/blog_6a079c260100mraf.html
int main()
{
    //freopen("data.in","r",stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    int n;
    while(cin>>n&&n){
        double l,v;
        char ch;
        double reslen=-1*1.0;
        int resid=0;
        //cin>>l>>v;
        scanf("%lf%lf",&l,&v);
        getchar();
        for(int i=0;i<n;i++){
            //cin>>ch>>a[i].pos>>a[i].name;
        	scanf("%c%lf%s",&ch,&a[i].pos,&a[i].name);
        	getchar();
            if(ch=='p'||ch=='P'){
                a[i].dir=1;
                if((l-a[i].pos)>reslen){
                    reslen=l-a[i].pos;
                    resid=i;
                }
            }
            else if(ch=='n'||ch=='N'){
                a[i].dir=0;
                if(a[i].pos>reslen){
                    reslen=a[i].pos;
                    resid=i;
                }
            }
        }
        int flag=(a[resid].dir^1);
        for(int i=0;i<n;i++) mp[i]=i;
        sort(mp,mp+n,cmp);
        int tmp=0;
        int i=0;
        while(mp[i]!=resid) i++;
        resid=i;
        if(flag==0){
            for(;i<n;i++){
                if(a[mp[i]].dir==flag){
                    tmp++;
                }
            }
            resid=resid+tmp;
        }
        else{
            for(;i>=0;i--){
                if(a[mp[i]].dir==flag){
                    tmp++;
                }
            }
            resid-=tmp;
        }
        //printf("%13.2lf %s\n",reslen/v,a[mp[resid]].name);
        cout<<setw(13)<<fixed<<setprecision(2)<<(int)(reslen/v*100.0)/100.0<<" "<<a[mp[resid]].name<<endl;
    }
}
