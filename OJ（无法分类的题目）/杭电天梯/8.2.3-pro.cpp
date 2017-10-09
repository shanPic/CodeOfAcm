#include<bits/stdc++.h>
using namespace std;
int f[19];
int sg[1050];
bool tmp[19];
int m,n,p;
int N;
void fi()
{
	f[0]=1;f[1]=2;
	for(int i=2;i<19;i++){
		f[i]=f[i-1]+f[i-2];
	}
}
void s()
{
	fi();
	sg[0]=0;
	for(int i=1;i<N;i++){
		memset(tmp,0,sizeof(tmp));
		for(int j=0;f[j]<=i;j++){
			tmp[sg[i-f[j]]]=1;
		}
		for(int j=0;j<19;j++){
			if(!tmp[j]){
				sg[i]=j;
				break;
			}
		}
	}
}
int main()
{
	N=1000;
	s();
	while(cin>>m>>n>>p){
		if(m==0&&n==0&&p==0)
			break;
		if(sg[m]^sg[n]^sg[p]){
			cout<<"Fibo"<<endl;
		}
		else cout<<"Nacci"<<endl;
	}
}
