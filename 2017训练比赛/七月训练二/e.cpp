/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\e.cpp
* @Author: Pic
* @Date:   2017-07-16 17:27:55
* @Last Modified time: 2017-07-16 17:36:01
*/

#include<cstdio>
#include<algorithm>
using namespace std;
int dig[13];
int tot(int n)
{
	int tmp[13];
	for(int i=1;i<=n;i++) tmp[i]=dig[i];
	while(n>1){
		for(int i=1;i<=n;i++){
			tmp[i]=tmp[i]+tmp[i+1];
		}
		n--;
	}
	return tmp[1];
}
int main(){
	//freopen("data.in","r",stdin);
	int n,sum;
	while(~scanf("%d%d",&n,&sum)){
		for(int i=1;i<=n;i++){
			dig[i]=i;
		}
		do{
			if(tot(n)==sum){
				break;
			}
		}while(next_permutation(dig+1,dig+n+1));
		for(int i=1;i<=n;i++){
			printf("%d ",dig[i]);
		}
		printf("\n");
	}
    return 0;
}