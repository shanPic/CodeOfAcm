#include<iostream>
#include<stdint.h>
#include<stdio.h>
using namespace std;
#define MAX(a,b) a>b?a:b;
int a[100010];
int Si[100010];
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N,max,case2=0,b,e;
	cin>>N;
	while(N--){
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		Si[0]=a[0];
		for(int l=1;l<m;l++){
			Si[l]=Si[l-1]+a[l];
		}
		//for(int x=0;x<m;x++)
		//	cout<<Si[x]<<'\t';
		//cout<<endl;
		max=INT32_MIN;
		//max=-1000;
		for(int j=0;j<m;j++)
			for(int k=j;k<m;k++){
				if((Si[k]-Si[j]+a[j])>max){
					b=j+1;e=k+1;
					max=Si[k]-Si[j]+a[j];
				}
				//cout<<Si[j]<<'\t'<<Si[k]<<endl;
				//cout<<Si[k]-Si[j]<<endl;
			}
		case2++;
		printf("Case %d:\n%d %d %d\n",case2,max,b,e);
	}			
}