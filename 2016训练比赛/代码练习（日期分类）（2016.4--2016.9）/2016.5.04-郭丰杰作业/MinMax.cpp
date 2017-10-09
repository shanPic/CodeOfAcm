/*#include<iostream>
#include<limits.h>
using namespace std;
int MIN(int x,int y){
	return x>y?y:x;
}
int MAX(int x,int y){
	return x>y?x:y;
}
int main(){
	int a[3],tem;
	while(cin>>a[0]>>a[1]>>a[2]){
		tem=INT_MIN;
		for(int i=0;i<3;i++)
			tem=MAX(tem,a[i]);
		cout<<tem<<endl;
		tem=INT_MAX;
		for(int i=0;i<3;i++)
			tem=MIN(tem,a[i]);
		cout<<tem<<endl;
	}
}
*/

#include<iostream>
using namespace std;
int MAX(int x,int y){
	if(x>y)
		return x;
	else return y;
}
int MIN(int x,int y){
	if(x<y)
		return x;
	else return y;
}
int main(){
	int a[3],tem=-10000;
	cin>>a[0]>>a[1]>>a[2];
		for(int i=0;i<3;i++)
			tem=MAX(tem,a[i]);
		cout<<tem<<endl;
		tem=10000;
		for(int i=0;i<3;i++)
			tem=MIN(tem,a[i]);
		cout<<tem<<endl;
	
}