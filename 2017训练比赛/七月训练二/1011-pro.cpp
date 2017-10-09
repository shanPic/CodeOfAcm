/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1011-pro.cpp
* @Author: Pic
* @Date:   2017-07-17 23:14:02
* @Last Modified time: 2017-07-18 02:16:35
*/

#include <cstdio>
using namespace std;
int mod[4]={0,5,3,1};
int num[7];
int main(){
    freopen("data.in","r",stdin);
    while(1){
        bool flag=0;
        for(int i=1;i<=6;i++){
            scanf("%d",&num[i]);
            if(num[i]) flag=1;
        }
        if(!flag) break;
        int res=0,s1=0,s2=0;
        int sum1=0;
        for(int i=3;i<=6;i++){
            //res+=num[i];
            if(i==3){
                res+=(num[i]+3)/4;
                s2=mod[num[i]%4];
                if(s2>num[2]){
                	s2-=num[2],num[2]=0;
                }
                else{
                	num[2]-=s2,s2=0;
                }
                //sum1+=s1;
                sum1+=s2*4;
            }
            else if(i==4){
                res+=num[i];
                s2=num[i]*5;
                if(s2>num[2]){
                	s2-=num[2],num[2]=0;
                }
                else{
                	num[2]-=s2,s2=0;
                }
                sum1+=s2*4;
                //sum1+=s1;
            }
            else if(i==5){
                res+=num[i];
                s1=num[i]*11;
                if(num[1]){
                    if(num[1]>=s1){
                        num[1]-=s1;s1=0;
                    }
                    else{
                        s1-=num[1],num[1]=0;
                    }
                }
                //sum1+=s1;
            }
            else if(i==6){
                res+=num[i];
            }
        }
    //    cout<<res<<endl;
        if(num[2]){
            res+=num[2]/9;
            if(num[2]%9) res++;
            num[2]=num[2]%9;
            s2=(9-num[2]%9)*4;
        }
        if(num[1]){
            num[1]=num[1]-sum1-s2;
	        if(num[1]>0){
	            res+=num[1]/36;
	            if(num[1]%36) res++;
	        }
        }
        printf("%d\n",res);
    }
    return 0;
}