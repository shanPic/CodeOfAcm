#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int MAXN = 8000;
double a[MAXN];
int main()
{
	//freopen("data.in","r",stdin);
	int n;
	cin >> n;
	double x;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	double sum = 0;
	int num = 0;
	for (int i = 0; i < 2 * n; i++) {
		x = ((int)a[i] + 1) * 1.0 - a[i];
		if (fabs(x - 1) <= eps) {
			num++;
		}
		else {
			sum += x;
		}
	}
	//cout<<num<<endl;
	//cout<<sum<<endl;
	int m = 0;
	if (num < n) {
		m = n - num;
	}
	double res = 0x3f3f3f3f * 1.0;
	for (; m <= min(2 * n - num, n); m++) {
		res = min(res, fabs(sum - m));
	}
	//printf("%.3llf\n",res);
	cout << fixed << setprecision(3) << res << endl;
}
