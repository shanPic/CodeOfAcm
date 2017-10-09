#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
int n;
int a,b,c;
int main(){
	// freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=1;i<=99999999;i++){//枚举位数
		int tmp=i;
		int len=0;
		int a[10];
		while(tmp){
			a[len++]=tmp%10;
			tmp/=10;
		}
		int f1=1;
		int f2=1;
		for(int j=1;j<len;j++){
			if(a[j]-a[j-1]<0)
				f1=0;
			if(a[j]-a[j-1]>0)
				f2=0;
		}
		if(f1==0) continue;
		if(len<=8){//奇数位情况
			if(f2==0){
				for(int k=a[0];k>=0;k--){
					printf("%d",i);
					cout<<k;
					for(int j=0;j<len;j++){
						cout<<a[j];
					}
					cout<<",";
				}
			}else{
				for(int k=a[0]-1;k>=0;k--){
					printf("%d",i);
					cout<<k;
					for(int j=0;j<len;j++){
						cout<<a[j];
					}
					cout<<",";
				}
			}
		}
		if(f2==0){
			printf("%d",i);
			for(int j=0;j<len;j++){
				cout<<a[j];
			}
			cout<<",";
		}
	}
	return 0;
}
