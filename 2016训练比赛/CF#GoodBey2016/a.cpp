#include<bits/stdc++.h>
using namespace std;
int tim[15];
const int SUM=240;
void init()
{
	int res=0;
	tim[0]=0;
	for(int i=1;i<=13;i++){
		//res+=5;
		tim[i]=i*5;
	}
}
int main()
{
	//init();
	int n,k;
	int t;
	cin>>n>>k;
	t=SUM-k;
	int flag=0;
	int s=0;
	for(int i=0;i<=n;i++){
        s+=(i*5);
		if(s>t){
			break;
		}
		else{
			flag=i;
		}
	}
	cout<<flag<<endl;
}
