/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1011.cpp
* @Author: Pic
* @Date:   2017-07-17 23:14:02
* @Last Modified time: 2017-07-18 00:56:06
*/

#include <cstdio>
using namespace std;

int mod[4]={0,5,3,1};
int num[7];
int main(){
	//freopen("data.in","r",stdin);
	while(1){
		bool flag=0;
		for(int i=1;i<=6;i++){
			scanf("%d",&num[i]);
			if(num[i]) flag=1;
		}
		if(!flag) break;
		int res=0,s1=0,s2=0;
		res+=(num[3]+3)/4+num[4]+num[5]+num[6];
		s2=mod[num[3]%4]+num[4]*5;
		if(num[2]>s2){
			res+=(num[2]-s2+8)/9;
		}
		s1=res*36-num[6]*36-num[5]*25-num[4]*16-num[3]*9-num[2]*4;
        if(num[1]>s1)
            res+=(num[1]-s1+35)/36;
		printf("%d\n",res);
	}
    return 0;
}