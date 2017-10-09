#include<bits/stdc++.h>
using namespace std;
const int MAXN=100030;
//int a[MAXN];
struct node
{
	bool have;
	bool ok;
	int pre;
	int step;
	node():pre(0),step(0),ok(1),have(0){};
};
node a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	int maxn=-1;
	int x;
	int res=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		maxn=max(x,maxn);
		if(a[x].ok){
            //cout<<11111<<endl;
			if(a[x].have==0){
			    //cout<<2222<<endl;
				a[x].pre=i;
				a[x].have=1;
				res++;
			}
			else if(a[x].step==0){
			    //cout<<333<<endl;
				a[x].step=i-a[x].pre;
				a[x].pre=i;
			}
			else if(i-a[x].pre==a[x].step){
			    //cout<<444<<endl;
				a[x].pre=i;
			}
			else{
			    //cout<<555<<endl;
				a[x].ok=0;
				res--;
			}
		}
	}
	printf("%d\n",res);
	for(int i=1;i<=maxn;i++){
		if(a[i].have&&a[i].ok){
            //cout<<00000<<endl;
			printf("%d %d\n",i,a[i].step);
		}
	}
}
