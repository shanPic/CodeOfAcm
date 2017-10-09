/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\test.cpp
* @Author: Pic
* @Date:   2017-09-10 15:10:01
* @Last Modified time: 2017-09-10 15:23:46
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("data2.in","r",stdin);
	freopen("data.out","w",stdout);
	int cur1[7],cur2[7],cur3[7];
	printf("int cur1[7],cur2[7],cur3[7];\n");
	for(int i=1;i<=6;i++){
		cin>>cur1[i];
	}
	for(int i=1;i<=6;i++){
		cin>>cur2[i];
	}
	for(int i=1;i<=6;i++){
		cin>>cur3[i];
	}
	for(int i=1;i<=6;i++){
		printf("cur1[%d]=%d; ",i,cur1[i]);
	}
	cout<<endl;
	for(int i=1;i<=6;i++){
		printf("cur2[%d]=%d; ",i ,cur2[i]);
	}
	cout<<endl;
	for(int i=1;i<=6;i++){
		printf("cur3[%d]=%d; ",i,cur3[i]);
	}
	cout<<endl;
	printf("for(int i=1;i<=6;i++){\n");
	printf("\tswap(d[cur1[i]],d[cur2[i]]);\n");
	printf("}\n");
	printf("for(int i=1;i<=6;i++){\n");
	printf("\tswap(d[cur1[i]],d[cur3[i]]);\n");
	printf("}\n");
}