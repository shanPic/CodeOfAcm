/*
* @FileName: D:\代码与算法\2017训练比赛\广西邀请赛\1005.cpp
* @Author: Pic
* @Created Time: 2017/8/31 12:16:17
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+30;
int bitsand[35],bitsor[35];
int num0[35];
int num1[35];
int num[maxn];
void chuli(int bits[],int tg)
{
	int id=0;
	while(tg!=0){
		bits[id]=tg&1;
		tg=tg>>1;
		id++;	
	}
}
int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n,q;
	int xorm=0;
	int andm=1,orm=0;
	while(~scanf("%d%d",&n,&q)){
		andm=1;orm=0;xorm=0;
		memset(num0,0,sizeof(num0));
		memset(num1,0,sizeof(num1));
		memset(bitsand,0,sizeof(bitsand));
		memset(bitsor,0,sizeof(bitsor));
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			int tmp=num[i];
			int id=0;
			int now=0;
			//while(tmp!=0)
			for(int id=0;id<32;id++){
				now=tmp&1;
				if(now==0) num0[id]++;
				else num1[id]++;
				tmp=tmp>>1;
			//	id++;	
			}
			xorm=xorm^num[i];
			orm=orm|num[i];
			andm=andm&num[i];
		}
		chuli(bitsand,andm);
		chuli(bitsor,orm);	
		int p;
		int resand=0,resor=0,resxor=xorm;
		for(int i=0;i<q;i++){
			scanf("%d",&p);
			resand=resor=0;
			int id=0;
			int tmp=num[p];
			while(tmp!=0){
				if(tmp&1){
					if(num1[id]==1){
						
					}
				}
				else{

				}
			}
			
	    }
	}
}
	return 0;
}
