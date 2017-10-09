#include<bits/stdc++.h>
using namespace std;
struct node
{
    int pos;
    int sta;
};
bool ok(int i)
{
    if(i>=0&&i<=15)
        return 1;
    else return 0;
}
int flip(int sta,int i)
{
    int tem=sta;
    tem=sta^(1<<i);
    if(ok(i+1))
        tem=tem^(1<<(i+1));
    if(ok(i-1))
        tem=tem^(1<<(i-1));
    if(ok(i+4))
        tem=tem^(1<<(i+4));
    if(ok(i-4))
        tem=tem^(i<<(i-4));
    return tem;
}
int main()
{
    freopen("data.in","r",stdin);
    char tem1;
    int sta;
    int flag;
    queue<node> a;
    sta=0;
    for(int i=0;i<16;i++){
        cin>>tem1;
        if(tem1=='b'){
            sta=sta^(1<<i);
        }
    }
    cout<<sta<<endl;
    struct node tnode;
    struct node tem;
    tnode.pos=0;tnode.sta=sta;
    a.push(tnode);
    flag=1;
    while(!a.empty()){
        //cout<<11111111<<endl;
        tnode=a.front();
        a.pop();
        if(tnode.sta==0||tnode.sta==65535){
            cout<<333333<<endl;
            break;
        }
        if(tnode.pos>16){
            flag=0;
            cout<<2222222222<<endl;
            break;
        }
        for(int i=0;i<16;i++){
            if(i!=tnode.sta){
            tem.pos=tnode.pos+1;
            tem.sta=flip(tnode.sta,i);
            a.push(tem);
            }
        }
    }
    if(flag){
    cout<<tnode.pos<<endl;
    }
    else cout<<"impo"<<endl;


}



