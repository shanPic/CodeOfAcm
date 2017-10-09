#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
int num[6];
int a[MAXN],c[MAXN];
int solve()
{
	for(int i=0;i<=num[1];i++){
		a[i]=1;
		c[i]=0;
	}
	memset(c,0,sizeof(c));
	int i=0;
	while(1){
        if(i==2||i==5){
            for(int j=0;j<=MAXN;j++){
                for(int k=0;k<=num[i]*i;k+=i){
                    c[k+j]+=a[j];
                }
            }
            for(int j=0;j<=MAXN;j++){
                a[j]=c[j];
                c[j]=0;
            }
        }
        if(i==6) {break;}
        else i++;
	}
        for(int i=1;i<MAXN;i++){
            if(a[i]==0) return i;
        }
}
void print()
{
    for(int i=0;i<num[5]*5;i++){
        cout<<a[i]<<endl;
    }
}
int main()
{
	while(cin>>num[1]>>num[2]>>num[5]){
		if(num[1]==0&&num[2]==0&&num[5]==0){
			break;
		}
		cout<<solve()<<endl;
		//print();
		memset(num,0,sizeof(num));
	}
}
