#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,x;cin>>t;
    while(t--){
        cin>>n;
        bool ok=0;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x>1)
                ok=1;
            ans^=x;
        }
        if(ok&&ans||!ok&&n%2==0)
            puts("Yamato_Saikou!");
        else
            puts("Meidikeji_Shijiediyi!");
    }
    return 0;
}