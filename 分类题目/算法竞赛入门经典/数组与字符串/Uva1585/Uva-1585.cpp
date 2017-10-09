#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int t;
    cin>>t;
    char ch;
    int sum;
    int add;
    getchar();
    while(t--){
        sum=add=0;
        while((ch=getchar())!='\n'){
            if(ch=='O'){
                add++;
                sum+=add;
            }
            else add=0;
        }
        cout<<sum<<endl;
    }
}
