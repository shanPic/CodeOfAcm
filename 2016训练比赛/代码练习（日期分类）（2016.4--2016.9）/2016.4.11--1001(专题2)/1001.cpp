#include<iostream>
#include<stdio.h>
#include<cmath>
#include<iomanip>
using namespace std;
double m, res = 0;
int ji = 0;
double f(double res)
{
	return res*res*res*res * 8 + res*res*res * 7 + res*res * 2 + res * 3 + 6;
}
int main()
{
	//cin.sync_with_stdio(false);
	//freopen("date.in", "r", stdin);
	//freopen("date.out", "w", stdout);
	int N, temp;
	double b, e, tem = 50;
	scanf("%d", &N);
	for (int i = 0; i<N; i++){
		b = 0, e = 100, tem = 50;
		cin >> m;
		if (m<6 || m>807020306)
			//cout << "No solution!" << endl;
			printf("No solution!\n");
		else{
			while (fabs(f(tem) - m) >= 1e-5)
				if (f(tem)>m){
					e = tem;
					tem = (b + e) / 2;
				}
				else{
					b = tem;
					tem = (b + e) / 2;
				}
				//cout << fixed << setprecision(4) << tem << endl;
				 printf("%0.4f\n", tem);
		}
	}

}