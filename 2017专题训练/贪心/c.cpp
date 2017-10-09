#include<bits/stdc++.h>
using namespace std;
string str[53]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","Aa","Ab","Ac","Ad","Ae","Af","Ag","Ah","Ai","Aj","Ak","Al","Am","An","Ao","Ap","Aq","Ar","As","At","Au","Av","Aw","Ax","Ay","Az"};
bool ok[53];
int res[53];
int main()
{
	int n,k;
	cin>>n>>k;
	string x;
	for(int i=k;i<=n;i++){
		cin>>x;
		if(x=="YES"){
			ok[i]=1;
		}
		else{
			ok[i]=0;
		}
	}
	memset(res,-1,sizeof(res));
	int tmp;
	res[0]=0;
	for(int i=1;i<k;i++){
		res[i]=i;
	}
	int c=0;
	for(int i=k;i<=n;i++){
		tmp=0;
		if(ok[i]){
			for(int j=i-k+1;j<=i;j++){
				if(res[j]==-1){
					res[j]=++tmp;
				}
				else{
					tmp=res[j];
				}
			}
		}
/*		else{
			int tar=i;
			for(;tar<=n;tar++){
				if(ok[tar]) break;
			}
			if(tar>n){
				for(;i<=n;i++){
					res[i]=res[i-1];
				}
			}
			else{
				res[i]=res[tar-k];
			}
		}*/
	}
/*	res[n+1]=res[n-k+1];
	for(int i=n;i>=1;i--){
		if(res[i]==-1){
			res[i]=res[i+1];
		}
	}*/
	for(int i=1;i<=n;i++){
		cout<<str[res[i]]<<" ";
	}
	cout<<endl;
}