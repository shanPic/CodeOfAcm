#include<bits/stdc++.h>
using namespace std;
const int MAXN=1500;
int s[MAXN];
int a[MAXN];//-1代表左，1代表右，0代表礼物
int main()
{
    //freopen("data.in","r",stdin);
	string str;
	int n=0;
	while(getline(cin,str)){
		n=0;
		for(auto ite=str.begin();ite!=str.end();ite++){
			switch(*ite){
				case '(':a[n++]=-1;break;
				case 'B':a[n++]=0;break;
				case ')':a[n++]=1;break;
			}
		}
		int cou=0;
		bool flag=0;
		for(int i=0;i<n;i++){
			switch(a[i]){
				case 0:s[cou++]=0;flag=1;break;
				case -1:s[cou++]=-1;break;
				case 1:{
					if(s[cou-1]==-1){
						cou--;
					}
					break;
				}
			}
			if(flag){
				break;
			}
		}
		cout<<cou-1<<endl;
	}
}
