#include<bits/stdc++.h>
using namespace std;
const int MAXN=60;
struct step
{
	int x;
	int d;
}a[MAXN];
int x,y;
// bool OK()
// {
// 	if(y>20000) return 0;
// 	return 1;
// }
int main()
{
	//freopen("data.in","r",stdin);
	int n;
    while(cin>>n){
	y=0;
	string str;
	for(int i=0;i<n;i++){
		cin>>a[i].x;
		cin>>str;
        if(str=="North")a[i].d=1;
        else if(str=="South")a[i].d=2;
        else if(str=="West")a[i].d=3;
        else if(str=="East")a[i].d=4;
	}
	bool flag=1;
	for(int i=0;i<n;i++){
        if(y>20000||y<0){
            flag=0;
            break;
        }
        if(y==0){
            if(a[i].d!=2) {flag=0;break;}
        }
        else if(y==20000){
            if(a[i].d!=1) {flag=0;break;}
        }
		switch(a[i].d){
			case 1:y-=a[i].x;break;
			case 2:y+=a[i].x;break;
			case 3:/*x-=a[i].x;if(x>=40000) x%=40000;else if(x<0) x=40000+x;*/break;
			case 4:/*x+=a[i].x;if(x>=40000) x%=40000;else if(x<0) x=40000+x;*/break;
		}
	}
	if(y!=0)flag=0;
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
    }
	return 0;
}
