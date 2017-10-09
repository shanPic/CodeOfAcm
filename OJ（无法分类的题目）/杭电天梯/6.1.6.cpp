#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#define INF 0x7ffffff
#define MAXN 200010
using namespace std;
const double eps=1e-10;
const double PI=acos(-1);
struct edge
{
    int x,y;
    int v;
};
bool operator >(const edge a,const edge b){
    return a.v>b.v;
}
priority_queue<edge,vector<edge>,greater<edge> > a;
int res;
int m[MAXN];
int n;
int fid(int x)
{
//    cout<<666666<<endl;
    if(m[x]==x){
        return x;
    }
    m[x]=fid(m[x]);
    return m[x];
}
void Kruskal()
{
    res=0;
    int cou=0;
    edge tmp;
    int xx,yy;
    while(cou!=n-1 ){
//        cout<<3333<<endl;
        tmp=a.top();
        a.pop();
//        cout<<5555<<endl;
        xx=fid(tmp.x);//
//        cout<<"---------"<<endl;
//        cout<<tmp.y<<endl;
        yy=fid(tmp.y);//
//        cout<<4444<<endl;
        if(xx==yy){
            continue;
        }
        res+=tmp.v;
        m[xx]=yy;
        cou++;
    }
}

void init()
{
    while(!a.empty() ){
        a.pop();
    }
    for(int i=0;i<=n;i++){
        m[i]=i;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    char cha;
    int ch;
    int m;
    edge tmp;
    int val;
    while(cin>>n&&n!=0){
        init();
        for(int i=0;i<n-1;i++){
//            cout<< 111111<<endl;
            cin>>cha;
            ch=cha-'A';
            cin>>m;
            for(int j=0;j<m;j++){
                cin>>cha;
                cin>>val;
                tmp.x=ch;
                tmp.y=cha-'A';
                tmp.v=val;
                a.push(tmp);
            }
        }
//        cout<<22222<<endl;
        Kruskal();
        cout<<res<<endl;
    }
}
