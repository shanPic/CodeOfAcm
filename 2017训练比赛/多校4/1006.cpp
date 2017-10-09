/*
* @FileName: D:\代码与算法\2017训练比赛\多校4\1006.cpp
* @Author: Pic
* @Date:   2017-08-03 12:26:16
* @Last Modified time: 2017-08-03 12:54:09
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
struct Matrix {
    int a[280][280];
};
int n,m,k;
Matrix res;
Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c.a[i][j] += a.a[i][k] + b.a[k][j];
            }
            if(c.a[i][j]!=0) c.a[i][j]=1;
        }
    }
    return c;
}
Matrix operator ^ (Matrix& a, int k) {
    Matrix c;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == j)
                c.a[i][j] = 1;
    while (k) {
        if (k&1)
            c = c * a;
        k >>= 1;
        a = a * a;
    }
    return c;
}
int main(){
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	Matrix ma;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&ma.a[i][j]);
			}
		}
		int x,y;
		for(int i=0;i<m;i++){
			res=ma;
			int resn=0;
			scanf("%d",&k);
			for(int i=0;i<k;i++){
				scanf("%d%d",&x,&y);
				x++,y++;
				ma.a[x][y]=(ma.a[x][y]^1);
			}
			ma=ma^n;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					resn+=ma.a[i][j];
				}
			}
			printf("%d\n",resn);
		}
	}
    return 0;
}