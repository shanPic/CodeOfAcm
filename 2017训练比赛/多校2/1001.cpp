/*
* @FileName: D:\代码与算法\2017训练比赛\多校2\1001.cpp
* @Author: Pic
* @Date:   2017-07-28 10:28:50
* @Last Modified time: 2017-07-28 12:12:41
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=80000+30;
int a[MAXN],b[MAXN];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y;
		char ch;
		scanf("%d%d%d",&n,&x,&y);
		getchar();
		for(int i=0;i<n;i++){
			scanf("%c",&ch);
			a[i]=ch-'A';
		}
		getchar();
		for(int i=0;i<n;i++){
			scanf("%c",&ch);
			b[i]=ch-'A';
		}
		int cnts=0,cntd=0;
		for(int i=0;i<n;i++){
			if(a[i]==b[i]){
				cnts++;
			}
			else{
				cntd++;
			}
		}
		int flag=1;
		if(abs(x-y)>cntd) flag=0;
		if(x+y>2*n-cntd) flag=0;	//
		if(flag){
			printf("Not lying\n");
		}
		else{
			printf("Lying\n");
		}
	}
    return 0;
}