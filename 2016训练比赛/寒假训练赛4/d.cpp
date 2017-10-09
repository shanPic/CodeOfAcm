#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main()
{
    int n;
    while(cin>>n){
        int x;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++ ){
            cin>>x;
            a[x]++;
        }
        int flag1=0,flag2=0;
        bool flag=0;
        for(int i=1;i<=1000;i++){
            if(a[i]>0&&a[i]%2&&flag2==0){
                flag=1;
                break;
            }
            if(a[i]>0&&a[i]%2==0){
                flag2=1;
            }
            if(a[i]>0&&a[i]%2){
                flag=1;
                break;
            }
        }
        if(flag1%2) flag=1;
        if(flag) cout<<"a ha ! cyk , too young too simple sometimes native !"<<endl;
        else cout<<"en heng UMR , you also have today !"<<endl;
    }
}
