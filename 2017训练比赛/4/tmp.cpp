#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=90;i<=555555;i+=90){
		int tmp=i/5;
		while(tmp>=0){
			if(tmp%10!=5){
				continue;
			}
			tmp/=10;
		}
		cout<<i<<endl;
	}
}