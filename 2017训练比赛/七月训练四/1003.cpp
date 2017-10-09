/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1003.cpp
* @Author: Pic
* @Date:   2017-07-27 10:58:04
* @Last Modified time: 2017-07-30 15:07:19
*/
#include <iostream>
#include <iomanip>
#include<cstdio>
using namespace std;
#define MAX_A 1000
#define MAX_N 1000 + 16
int N;
double A, B, H[MAX_N];
 
bool C(const double& mid)
{
	H[1] = mid;
	for (int i = 2; i < N; ++i)
	{
		H[i] = 2 * H[i - 1] + 2 - H[i - 2];
		if (H[i] < 0)
		{
			return false;
		}
	}
	B = H[N - 1];
	return true;
}
int main()
{
	//freopen("data.in","r",stdin);
	cin >> N >> A;
	H[0] = A;
	double lb = -1, ub = MAX_A + 16;
	for (int i = 0; i < 100; ++i)
	{
		double mid = (ub + lb) / 2;
		if (C(mid))
		{
			ub = mid;
		}
		else
		{
			lb = mid;
		}
	}
	cout << fixed << setprecision(2) << B << endl;
	//printf("%.2lf\n",B);
	return 0;
}