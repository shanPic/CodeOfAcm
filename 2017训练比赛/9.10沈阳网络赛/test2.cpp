/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\test2.cpp
* @Author: Pic
* @Date:   2017-09-10 15:10:01
* @Last Modified time: 2017-09-10 15:44:25
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("data2.in","r",stdin);
	freopen("data.out","w",stdout);
	int cur1[4],cur2[4],cur3[4],cur4[4],cur5[4],cur6[4],tmp[4];
	printf("int cur1[4],cur2[4],cur3[4],cur4[4],cur5[4],cur6[4],tmp[4];\n");
	int x;
	for(int i=1;i<=3;i++){
		cin>>cur1[i];
	}
	//getchar();getchar();for(int i=1;i<=3;i++){cin>>x;}
	for(int i=1;i<=3;i++){
		cin>>cur2[i];
	}
	//getchar();getchar();for(int i=1;i<=3;i++){cin>>x;}
	for(int i=1;i<=3;i++){
		cin>>cur3[i];
	}
	for(int i=1;i<=3;i++){
		cin>>cur4[i];
	}
	//getchar();getchar();for(int i=1;i<=3;i++){cin>>x;}
	for(int i=1;i<=3;i++){
		cin>>cur5[i];
	}
	//getchar();getchar();for(int i=1;i<=3;i++){cin>>x;}
	for(int i=1;i<=3;i++){
		cin>>cur6[i];
	}
	//getchar();getchar();for(int i=1;i<=3;i++){cin>>x;}


	for(int i=1;i<=3;i++){
		printf("cur1[%d]=%d; ",i,cur1[i]);
	}
	cout<<endl;
	for(int i=1;i<=3;i++){
		printf("cur2[%d]=%d; ",i ,cur2[i]);
	}
	cout<<endl;
	for(int i=1;i<=3;i++){
		printf("cur3[%d]=%d; ",i,cur3[i]);
	}
	cout<<endl;
	for(int i=1;i<=3;i++){
		printf("cur4[%d]=%d; ",i,cur4[i]);
	}
	cout<<endl;
		for(int i=1;i<=3;i++){
		printf("cur5[%d]=%d; ",i,cur5[i]);
	}
	cout<<endl;
		for(int i=1;i<=3;i++){
		printf("cur6[%d]=%d; ",i,cur6[i]);
	}
	cout<<endl;
	printf("for(int i=1;i<=3;i++) tmp[i]=cur6[i];\n");
	for(int i=1;i<=6;i++){
		printf("for(int i=1;i<=3;i++){\n");
		printf("\tswap(d[cur%d[i]],tmp[i]);\n",i);
		printf("}\n");
	}
}