#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	for(int i=12;i<150;i++)
		if((i+20)/i==2&&(i+20)%i==0)
			cout<<i<<"\t"<<i+20<<endl;
}