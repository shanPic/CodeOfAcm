#include <iostream>
#include <cstring>
#include <stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
struct s{
	double b;
	double e;
}xianduan[10010];
bool cmp(s x, s y)
{
    if(x.b != y.b) return x.b < y.b;
    else return x.e < y.e;

}
int main()
{
	double x, y;
	double L, D;
	int n,tem,res;
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	while (cin>>L>>D>>n){
		for (int i = 0; i < n; i++){
			scanf("%lf%lf", &x, &y);
			tem = sqrt(D*D - y*y);
			xianduan[i].b = x - tem;
			xianduan[i].e = x + tem;
		}
		sort(xianduan, xianduan + n, cmp);
		res = 1;
		double flag = xianduan[0].e;
		for (int i = 1; i < n; i++){
			if (flag< xianduan[i].b){
				flag = xianduan[i].e;
				res++;
			}
			else flag = xianduan[i].e;
		}
		printf("%d\n", res);

	}
}
