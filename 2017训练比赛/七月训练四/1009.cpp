/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1009.cpp
* @Author: Pic
* @Date:   2017-08-02 20:10:20
* @Last Modified time: 2017-08-02 21:37:19
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int M=6;
const int N=5;
int mp[N+3][M+3];
int flip[N+3][M+3];
int res[N+3][M+3];
int resC[N+3][M+3];
int cntC=0x3f3f3f3f;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
void init()
{
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			flip[i][j]=mp[i][j];
		}
	}
	cntC=0x3f3f3f3f;
}
void f(int x,int y)
{
	int nowx,nowy;
	flip[x][y]=(flip[x][y]^1);
	for(int i=0;i<4;i++){
		nowx=x+dir[i][0];
		nowy=y+dir[i][1];
		flip[nowx][nowy]=(flip[nowx][nowy]^1);
	}
}
bool ok()
{
	//for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(flip[5][j]) return 0;
		}
	//}
	return 1;
}
int main(){
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				scanf("%d",&mp[i][j]);
			}
		}
		//int cnt=0;
		int n=0;
		for(int i=0;i<(1<<6);i++){
			int cnt=0;
			init();
			int now=i;
			for(int j=M;j>=1;j--){
				res[1][j]=0;
				if(now&1){
					res[1][j]=1;
					f(1,j);
					cnt++;
				}
				now=(now>>1);
			}
			for(int j=2;j<=N;j++){
				for(int k=1;k<=M;k++){
					res[j][k]=0;
					if(flip[j-1][k]==1){
						res[j][k]=1;
						f(j,k);
						cnt++;
					}
				}
			}
			if(ok()){
				//n++;
				cout<<11111<<endl;
				cout<<i<<endl;
				if(cnt<cntC){
					for(int i=1;i<=N;i++){
						for(int j=1;j<=M;j++){
							resC[i][j]=res[i][j];
						}
					}
				}
			}
		}
		//cout<<cnt<<endl;
		//cout<<n<<endl;
		printf("PUZZLE #%d\n",++cas);
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				printf("%d ",resC[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}