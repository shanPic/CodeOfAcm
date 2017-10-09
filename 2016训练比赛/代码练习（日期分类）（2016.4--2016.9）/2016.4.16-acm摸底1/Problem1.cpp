#include<iostream>
using namespace std;
int main()
{
	int T,N,s,sum;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		sum=0;
		for(int j=0;j<N;j++){
			cin>>s;
			if(s>6000)
				sum++;
		}
		cout<<sum<<endl;
	}
}

