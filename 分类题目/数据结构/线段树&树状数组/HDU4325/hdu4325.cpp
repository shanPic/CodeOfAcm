#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<map>
using namespace std;
const int M=100100;
int tree[M];
int q[M];
int N=0;
map<int,int> ls;
struct node
{
    int le;
    int ri;
}a[M];
int lowbits(int x)
{
    return x&(-x);
}
void update(int i,int val)
{
    for(;i<=N;i+=lowbits(i)){
        tree[i]+=val;
    }
}
int getsum(int i)
{
    int sum=0;
    for(;i>0;i-=lowbits(i)){
        sum+=tree[i];
    }
    return sum;
}
void init()
{
    memset(tree,0,sizeof(tree));
    ls.clear();
}
int main()
{
    freopen("data.in","r",stdin);
    int m,n;
    int t;
    int l,r;
    int tem;
    int casn=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<casn++<<":"<<endl;
        init();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>l>>r;
            if(ls.find(l)==ls.end()) ls.insert(make_pair(l,1));
            if(ls.find(r)==ls.end()) ls.insert(make_pair(r,1));
            a[i].le=l;a[i].ri=r;
        }
        for(int i=0;i<m;i++){
            cin>>l;
            if(ls.find(l)==ls.end()) ls.insert(make_pair(l,1));
            q[i]=l;
        }
        int i=1;
        for(map<int,int>::iterator ite=ls.begin();ite!=ls.end();ite++){
            ite->second=i++;
        }
        N=i-1;
        for(int i=0;i<n;i++){
            update(ls[a[i].le],1);
            update(ls[a[i].ri]+1,-1);
        }
        for(int i=0;i<m;i++){
            cout<<getsum(ls[q[i]])<<endl;
        }
    }
}
