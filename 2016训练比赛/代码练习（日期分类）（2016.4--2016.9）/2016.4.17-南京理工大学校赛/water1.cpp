#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int a[100000][2];
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	long long int N,max,sum;
	while(cin>>N){
		//memset(a,0,sizeof(a));
		if(N==0)
			cout<<1<<endl;
		else{
			max=0;
			sum=0;
			//int a[N][2];
			for(int i=0;i<N;i++){
				cin>>a[i][0];
				cin>>a[i][1];
				if(a[i][0]>max)
					max=a[i][0];
			}
			max++;
			for(int j=0;j<N;j++){
				sum+=((max-a[j][0])*a[j][1]);
				}
				cout<<sum<<endl;
		}
	}
}