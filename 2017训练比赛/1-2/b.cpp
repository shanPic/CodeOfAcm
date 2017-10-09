#include<bits/stdc++.h>
using namespace std;
int c[10];
int ok[10];
int v=0;
int main()
{
    cin>>v;
    for(int i=1;i<=9;i++) ok[i]=1;
    for(int i=1;i<=9;i++){
        cin>>c[i];
        if(c[i]>v) ok[i]=-1;
    }
    int mi=-1;
    for(int i=1;i<=9;i++){
        if(ok[i]!=-1){
            if(v/c[i]>=mi) mi=v/c[i];
            else ok[i]=-1;
        }
    }
    int res=1;
    for(int i=1;i<=9;i++){

    }

}
