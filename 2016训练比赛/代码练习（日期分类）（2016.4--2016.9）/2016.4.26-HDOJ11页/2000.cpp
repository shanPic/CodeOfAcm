#include<iostream>
using namespace std;
int main(){
	char a[4],tem;
	while(cin>>a[1]>>a[2]>>a[3]){
		for(int i=1;i<=3;i++)
			for(int j=i;j<=3;j++)
				if(a[j]<a[i]){
					tem=a[i];
					a[i]=a[j];
					a[j]=tem;
				}
		cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
	}
}
