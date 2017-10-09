/*
* @FileName: D:\代码与算法\2017训练比赛\9.24南宁网络赛\1001.cpp
* @Author: Pic
* @Created Time: 2017/9/24 11:57:05
*/
#include <bits/stdc++.h>
using namespace std;

double mp[6][6];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			scanf("%lf",&mp[i][j]);
		}
	}	
	string str;
	getchar();
	for(int i=0;i<2;i++){
		getline(cin,str);
		stringstream s(str);
		int x,y;
		double gl=1.0;
		s>>x;
		while(s>>y){
			gl*=mp[x][y];
			x=y;
		}
		printf("%.8f\n",gl);
	}
	return 0;
}
