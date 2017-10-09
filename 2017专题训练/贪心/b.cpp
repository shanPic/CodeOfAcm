#include<bits/stdc++.h>
using namespace std;
const int MAXN=500030;
struct order
{
	int b,e;
};
order a[MAXN];
bool cmp(order a,order b)
{
	return a.e<b.e;
}
int main()
{
	int n;
	cin>>n;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a[i].b=x;
		a[i].e=y;
	}
	sort(a,a+n,cmp);
	int res=0,last=0;
	for(int i=0;i<n;i++){
		if(a[i].b>last){
			last=a[i].e;
			res++;
		}
	}
	cout<<res<<endl;
}