#include<bits/stdc++.h>
using namespace std;
int solve(double k)
{
	int step=0,mod=1;
	double m=0;
	while(m<100){
		step++;
		m+=(k/mod);
		mod+=1;
	}
	return step;
}
int main()
{
	double k;
	while(~scanf("%lf",&k)){
		cout<<solve(k)<<endl;
	}
}
