#include<iostream>
using namespace std;
const int MAXN=1000;
struct node
{
	int x,y;
}a[MAXN];
int X(int x1,int y1,int x2,int y2)
{
	return x1*y2-y1*x2;
}
int main()
{
	int n;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y;
		}
		int flag=1;
		for(int i=0;i<n;i++){
			if(X(a[(i+1)%n].x-a[i].x,a[(i+1)%n].y-a[i].y,a[(i+2)%n].x-a[i].x,a[(i+2)%n].y-a[i].y)<0){
				flag=0;
				break;
			}
		}
		if(flag) cout<<"convex"<<endl;
		else cout<<"concave"<<endl;
	}
}