/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\d.cpp
* @Author: Pic
* @Date:   2017-07-16 15:01:09
* @Last Modified time: 2017-07-16 17:19:21
*/

#include <iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
int hs[10];
int n1,n2,n;
int num1,num2;
int res;
int num[13];
//bool vis[10];
int mod[10][8];
//{1,10,100,1000,10000,100000,1000000,10000000};
void dfs2(int step,int num)
{
	if(step==n2){
		res=min(res,abs(num1-num));
		return;
	}
	else{
		if(step==n2-1){
			bool flag=0;
			for(int i=1;i<10;i++){
				if(hs[i]){
					flag=1;
					hs[i]=0;
					//num2+=mod[i][step];
					dfs2(step+1,num+mod[i][step]);
					//num2-=mod[i][step];
					hs[i]=1;
				}
			}
			if(!flag){
				if(num2==0&&hs[0]){
					//hs[0]=0;
					dfs2(step+1,0);
					//hs[0]=1;
				}
				return ;
			}
		}
		else{
			for (int i = 0; i < 10; i++) {
				if (hs[i]) {
					hs[i] = 0;
					//num2 += mod[i][step];
					dfs2(step + 1,num+mod[i][step]);
					//num2 -= mod[i][step];
					hs[i] = 1;
				}
			}
		}
		return;
	}
}
void dfs1(int step,int num)
{
	if(step==n1){
		num1=num;
		dfs2(0,0);
		return ;
	}
	else{
		bool flag=0;
		if(step==n1-1){
			for(int i=1;i<10;i++){
				if(hs[i]){
					flag=1;
					hs[i]=0;
					//num1+=mod[i][step];
					dfs1(step+1,num+mod[i][step]);
					//num1-=mod[i][step];
					hs[i]=1;
				}
			}
			if(!flag){
				if(num1==0&&hs[0]){
					dfs1(step+1,0);
				}
				return;
			}
		}
		else{
			for (int i = 0; i < 10; i++) {
				if (hs[i]) {
					hs[i] = 0;
					//num1 += mod[i][step];
					dfs1(step + 1,num+mod[i][step]);
					//num1 -= mod[i][step];
					hs[i] = 1;
				}
			}
		}
		return ;

	}
}
int main(){
	//freopen("data.in","r",stdin);
	int t;
	//char str[30];
	scanf("%d",&t);
	//getchar();
	while(t--){
		int x;n=0;
		while(~scanf("%d",&x)){
			//hs[x]=1;
			num[n++]=x;
			//ch=getchar();
			if(getchar()=='\n') break;
		}
		if(n==2){
			printf("%d\n",abs(num[0]-num[1]));
			continue;
		}
		while(num[0]==0){
			next_permutation(num,num+n);
		}
		res=0x3f3f3f3f;
		n1=n/2;
		do{
			num1=num2=0;
			int i=0;
			for(i=0;i<n1;i++){
				num1=num1*10+num[i];
			}
			if (num[i] != 0) {
				for (; i < n; i++) {
					num2=num2*10+num[i];
				}
				res = min(res, abs(num1 - num2));
			}
		}while(next_permutation(num,num+n));
		printf("%d\n",res);
	}
    return 0;
}
