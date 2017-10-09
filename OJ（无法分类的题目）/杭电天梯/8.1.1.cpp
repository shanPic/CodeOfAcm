#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000;
int a[MAXN];
int main()
{
    //freopen("data.in","r",stdin);
	int t;
	cin>>t;
	string tp;
	bool flag;
	int cou;
	int sum;
	while(t--){
		int n,tmp;
		cou=0;sum=0;
		cin>>n;
		cin>>tp;
		if(tp=="FIFO") flag=1;
		else flag=0;
		for(int i=0;i<n;i++){
			cin>>tp;
			if(tp=="IN"){
				cin>>tmp;
				a[sum++]=tmp;
				if(flag==0) cou++;
			}
			else{
				//if(cou>=sum||cou<0) cout<<"None"<<endl;
				if(flag==0){
                    if(cou<1)cout<<"None"<<endl;
                    else {cout<<a[cou-1]<<endl;cou--;sum--;}
				}
				else{
                    if(cou>=sum) cout<<"None"<<endl;
                    else {
                        cout<<a[cou]<<endl;
                        cou++;
                    }
				}
			}
		}
		//cout<<sum<<"\t"<<cou<<endl;
	}
}
