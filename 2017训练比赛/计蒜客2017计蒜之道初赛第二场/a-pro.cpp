#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[5];
    cin>>num[1]>>num[2]>>num[3]>>num[4];
    int sum=0;
    for(int i=1;i<=4;i++){
        sum+=num[i];
    }
    int k,d,target=0;
    cin>>k>>d;
    for(int i=4;i>k;i--){
        target+=num[i];
    }
    target+=d;
    int now,p;
    int res=0;
    int pt=0;
    for(int x=1;x<=6;x++){
        for(int y=1;y<=6;y++){
            pt=0;
            p=0;
            now=(x+y)%4;
            for(int i=4;i>now;i--){
                pt+=num[i];
            }
            pt+=(min(x,y)+1);
            if(pt>target)
            {
                pt-=sum;
                //pt++;
            }
            int flag=1;
            int cnt=0;
            int flag1=-1,flag2=-1;
            while(cnt<24&&cnt<=sum&&(flag1==-1&&flag2==-1)){
                //cout<<111111<<endl;
                if(pt==target)
                {
                    flag1=flag;
                    if(flag2==-1)
                        flag2=flag;
                }
                if(pt==target+1) flag2=flag;
                pt+=2;
                cnt+=2;
                flag+=1;
                flag=flag%4;
            }
            if(flag1==1&&flag2==1){
                //cout<<x<<"\t"<<y<<endl;
                res++;
                if(x==y) res++;
            }
        }
    }
    cout<<res/2<<endl;
}
