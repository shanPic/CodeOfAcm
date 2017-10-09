#include<bits/stdc++.h>
using namespace std;
int c[10];
int f(int i)
{
    int vc=v%c[i];
    int len=v/c[i];
}
int main()
{
    int v;
    while(cin>>v){
        int res=0,res=-1;
        for(int i=1;i<10;i++){
            cin>>c[i];
            if(c[i]>v) c[i]=0;
        }
        int res2;
        for(int i=1;i<10;i++){
            if(ok[i]){
                res2=f(i);
                if(res2>res){

                }
            }
        }
    }
}
