/*
* @FileName: 1006.cpp
* @Author: Pic
* @Date:   2017-05-27 15:56:12
* @Last Modified time: 2017-05-27 22:00:26
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000+30;
int dp[MAXN][MAXN];
int path[MAXN][MAXN];
int cnt=0;
char str1[MAXN],str2[MAXN];
void out(int x,int y)
{
	if(x-1<0||y-1<0||path[x][y]==-1){
		return;
	}
	if(path[x][y]==0){
		out(x-1,y-1);

		printf("%c",str1[x-1]);
		
		return ;
	}
	if(path[x][y]==1){
		out(x-1,y);
		return;
	}
	if(path[x][y]==2){
		out(x,y-1);
		return;
	}
}
int main(){
	//freopen("data.in","r",stdin);
	memset(path,-1,sizeof(path));
	scanf("%s\n%s",str1,str2);
	int len1=strlen(str1),len2=strlen(str2);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				path[i][j]=0;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j]=dp[i-1][j];
					path[i][j]=1;
				}
				else{
					dp[i][j]=dp[i][j-1];
					path[i][j]=2;
				}
			}
		}
	}
	// /cout<<dp[len1][len2]<<endl; 
	out(len1,len2);
	cout<<"\n";
    return 0;
}