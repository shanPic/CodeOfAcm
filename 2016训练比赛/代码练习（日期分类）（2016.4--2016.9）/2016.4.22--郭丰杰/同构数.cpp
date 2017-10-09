#include<iostream>
using namespace std;
int main(){
	int sum=0;
	for(int i=1;i<=1000;i++){
		if(i<10){
			if(i*i%10==i)
				sum++;
		}
		else
			if(i<=100){
				if(i*i%100==i)
					sum++;
			}
			else
				if(i<=1000){
					if(i*i%1000==i)
						sum++;
				}
	}
	cout<<sum<<endl;
	return 0;
}