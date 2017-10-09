#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000003;
int s[MAXN];
char a[MAXN],b[MAXN];
bool path[MAXN];
int main()
{
	int n;
	while(cin>>n){
		memset(path,-1,sizeof(path));
		scanf("%s",a);
		getchar();
		scanf("%s",b);
		int cou=-1;
		int coub=0;
		int coup=0;
		for(int i=0;i<n;i++){
			s[++cou]=a[i]-'0';
			path[coup++]=1;
			while(s[cou]==(b[coub]-'0')&&cou!=-1&&coub<n){
                //cout<<11111111<<endl;
				cou--;
				coub++;
				path[coup++]=0;
			}
		}
		if(cou!=-1)cout<<"No."<<endl;
		else{
			cout<<"Yes."<<endl;
			for(int i=0;i<2*n;i++){
				if(path[i])cout<<"in"<<endl;
				else cout<<"out"<<endl;
			}
		}
		cout<<"FINISH"<<endl;
	}
}
