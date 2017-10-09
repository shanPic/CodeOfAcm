#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[5];
    int k,d;
    while(cin>>num[1]>>num[2]>>num[3]>>num[4]){
        int sum=0;
        for(int i=1;i<=4;i++)
        {
            //cout<<num[i]<<endl;
            sum+=num[i];
        }
        //cout<<sum<<endl;
        cin>>k>>d;
        int target=0;
        for(int i=4;i>k;i--){
            target+=num[i];
        }
        target+=d;
        int mod;
        int res=0;
        int b1=0,b2=0;
        int dis=0;
        for(int x=1;x<=6;x++){
            for(int y=1;y<=6;y++){
                b1=0;
                mod=(x+y)%4;
                for(int i=4;i>mod;i--){
                    b1+=num[i];
                }
                b1+=min(x,y);
                b1++;
                dis=target-b1;
                if(dis<0){
                    dis+=sum;
                }
                if(dis<=24&&(dis%8==0)) {
                    //cout<<x<<"\t"<<y<<endl;
                    res++;
                    if(x==y) res++;
                    //cout<<111111<<endl;
                }
            }
        }
        cout<<res/2<<endl;
    }
}
