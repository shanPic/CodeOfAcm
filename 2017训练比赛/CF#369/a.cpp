/*
* @FileName: D:\代码与算法\2017训练比赛\CF#369\a.cpp
* @Author: Pic
* @Date:   2017-06-11 16:44:13
* @Last Modified time: 2017-06-11 16:58:21
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=2000+30;
char seat[MAXN];
int main(){
	int n;
	//char *a,*b;
	scanf("%d",&n); getchar();
	n=n*4;
	int flag=0;
	for(int i=0;i<n;i+=4){
		scanf("%c%c|%c%c",&seat[i],&seat[i+1],&seat[i+2],&seat[i+3]);
		getchar();
		if (!flag) {
			if (seat[i] == seat[i + 1] && seat[i] == 'O') {
				flag = 1;
				seat[i] = seat[i + 1] = '+';
			}
			else if (seat[i + 2] == seat[i + 3] && seat[i + 2] == 'O') {
				flag = 1;
				seat[i + 2] = seat[i + 3] = '+';
			}
		}
	}
	if(flag){
		printf("YES\n");
		for(int i=0;i<n;i+=4){
			printf("%c%c|%c%c\n",seat[i],seat[i+1],seat[i+2],seat[i+3]);
		}
	}
	else{
		printf("NO\n");
	}
    return 0;
}