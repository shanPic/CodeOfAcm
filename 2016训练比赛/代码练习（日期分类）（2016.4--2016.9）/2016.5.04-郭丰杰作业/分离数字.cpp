/*#include<iostream>
using namespace std;
int main(){
	int a;
	while(cin>>a){
		for(int i=1;i<=1000;i*=10){
			cout<<a%(i*10)/i;
		}
		cout<<endl;
}*/

		
#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int b=1;
	for(int i=0;i<4;i++){
			cout<<a%(b*10)/b;
			b*=10;
		}
	return 0;
}