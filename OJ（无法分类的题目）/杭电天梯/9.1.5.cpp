#include<bits/stdc++.h>
using namespace std;
struct node
{
	int pre;
	//int rank;
	int tail;
};
node a[30100];
int n=30010,p;
void init()
{
	for(int i=0;i<=n;i++){
		a[i].pre=i;
		//a[i].rank=0;
		a[i].tail=i;
	}
}
int find(int x)
{
	while(a[x].pre!=x){
		x=a[x].pre;
	}
	return x;
}
int f_rank(int x)
{
    int r=0;
    while(a[x].pre!=x){
        x=a[x].pre;
        r++;
    }
    return r;
}
void merg(int x,int y)
{
	int aa=find(x),bb=find(y);
	if(aa==bb) return;

	a[aa].pre=a[bb].tail;
    //int tmp=a[aa].tail;
	a[bb].tail=a[aa].tail;

//	int t=a[bb].rank+1;
//	while(tmp!=a[tmp].pre){
//		a[tmp].rank+=t;
//		tmp=a[tmp].pre;
//	}
//	a[tmp].rank+=t;
}
int main()
{
    //freopen("data.in","r",stdin);
	while(cin>>p){
        init();
		char ch;
		int x,y;
		for(int i=0;i<p;i++){
            //cout<<111111111<<endl;
			cin>>ch;
			if(ch=='M'){
				cin>>x>>y;
				merg(x,y);
			}
			else if(ch=='C'){
				cin>>x;
				cout<<f_rank(x)<<endl;
			}
		}
	}
}
