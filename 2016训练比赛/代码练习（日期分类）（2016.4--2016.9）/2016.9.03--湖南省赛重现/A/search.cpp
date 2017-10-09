#include<iostream>
using namespace std;
long long res = 0;
long long m, n;
int gcd(int a,int b)
{

}
long long fen(long long x)
{

}
void solve(long long x)
{
    if(x<=2016){
        if (2016%x==0){
            res += (n / (2016/x));
        }
        else{
            res += (n / 2016);
        }
    }
    else {
        if(x%2016==0){
            res+=n;
        }
        else{
            long long tem=fen(x);
            solve(tem);
        }
    }
}
int main()
{
	while (cin >> m >> n){
		res = 0;
		for (int i = 1; i <= m; i++){
			solve(i);
		}
		cout << res << endl;
	}
}
