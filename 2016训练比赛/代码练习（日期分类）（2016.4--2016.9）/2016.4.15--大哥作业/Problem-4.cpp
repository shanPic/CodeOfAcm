#include<iostream>
using namespace std;
int main()
{
	for(int i=0;i<20;i++)
		for(int j=0;j<40;j++)
			for(int k=0;k<300;k+=3)
				if((i*5+j*3+k/3==100)&&(i+j+k==100))
					cout<<"公鸡："<<i<<"母鸡"<<j<<"小鸡："<<k<<endl;
}