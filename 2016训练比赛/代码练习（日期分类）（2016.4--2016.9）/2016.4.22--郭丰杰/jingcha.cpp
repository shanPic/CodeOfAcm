#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a[4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			a[j]=0;
		a[i]=1;
	    if(a[3]+a[1]==1&&a[1]+a[2]==1&&a[0]+a[1]==1){
			cout<<"The thief is "; 
			for(int k=0;k<4;k++) 
				if(a[k])printf("%c",k+'A');
					printf("\n");

		}
	}
	return 0;
}