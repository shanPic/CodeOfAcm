#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c25=0,c50=0;
    int n;
    cin>>n;
    int x;
    int flag=1;
    for(int i=0;i<n;i++){
        cin>>x;
        if(flag){
            if(x==25) c25++;
            else if(x==50){
                if(c25>=1){
                    c25--;
                    c50++;
                }
                else{
                    flag=0;
                }
            }
            else if(x==100){
                if(c25>=1&&c50>=1){
                    c25--;
                    c50--;
                }
                else if(c25>=3){
                    c25-=3;
                }
                else{
                    flag=0;
                }
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
