#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	long long int T,a,b,n,sum,tem1,tem2;
	vector<int> fenjie;
	vector<int> v;
	cin>>T;
	for(int j=0;j<T;j++){
		sum=0;
		cin>>a>>b>>n;
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0)
			fenjie.insert(i);
		}
	}
	for(int k=a;k<=b;k++)
		if()
		v.insert(k);
	for

}

fenjie:
for(int i=2;i<=sqrt(n);i++){
	if(n%i==0){
		fenjie.insert(i);
	}
}