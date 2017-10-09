#include<bits/stdc++.h>
using namespace std;
#define FRE freopen("data.in","r",stdin)
struct node
{
    int x;
    int y;
    int nxt;
}lj[100];
int head[100];
int ne=0;
void addnode(int x,int y)
{
    lj[ne].x=x;
    lj[ne].y=y;
    lj[ne].nxt=head[x];
    head[x]=ne;
    ne++;
}
int main()
{
    FRE;
    for(int i=0;i<15;i++){
        head[i]=-1;
    }
    int a,b;
    while(cin>>a>>b){
        addnode(a,b);
        //addnode(b,a);
    }
    for(int i=0;i<15;i++)
        cout<<head[i]<<"\t";
    cout<<endl;
    for(int i=0;i<15;i++){
        int tem=head[i];
        while(tem>=0){
        cout<<lj[tem].x<<"\t"<<lj[tem].y<<endl;
        tem=lj[tem].nxt;
        }
    }
}
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               ·ð×æ±£ÓÓ         ÓÀÎÞBUG
//
//
//

