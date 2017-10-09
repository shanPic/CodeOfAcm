#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
struct floor
{
	int x;
	int y;
	
}n1,n2,tem;
int n[201],jilu[201];
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N,A,B,flag;
	while(cin>>N&&N!=0){
		flag=0;
		cin>>A>>B;
		for(int i=1;i<=N;i++){
			cin>>n[i];
			jilu[i]=0;
		}
		n1.x=A;n1.y=0;
		queue<floor>f;
		f.push(n1);
		while(!f.empty()){
			tem=f.front();
			f.pop();
			if(tem.x==B){
				flag=1;
				break;
			}
			n1.x=tem.x+n[tem.x];
			n2.x=tem.x-n[tem.x];
			n1.y=tem.y+1;
			n2.y=tem.y+1;
			if(n1.x>0&&n1.x<=N&&!jilu[n1.x]){
				f.push(n1);
				jilu[n1.x]=1;
			}
			if(n2.x>0&&n2.x<=N&&!jilu[n2.x]){
				f.push(n2); 
				jilu[n2.x]=1;
			}
		}
		if(flag)	
			cout<<tem.y<<endl;
		else cout<<-1<<endl;
	}
}