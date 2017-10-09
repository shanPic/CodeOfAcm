#include<iostream>
using namespace std;
int main()
{
	for(int i=900;i<1100;i++)
		if(i%5==2&&i%7==3&&i%3==1)
			cout<<i<<endl;
}