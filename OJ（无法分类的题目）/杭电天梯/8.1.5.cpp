#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
struct node
{
	int x;
	bool f;
};
stack<node> a[MAXN];
node res[MAXN];
int r,l;
void init()
{
	while(!a[l].empty()){
		a[l].pop();
	}
}
void l_s()
{
	node tmp;
	while(!a[l].empty()){
		tmp=a[l].top();
		a[l].pop();
		tmp.f=(!tmp.f);
		a[l+1].push(tmp);
	}
	if(l==r) r++,l++;
	else l++;
}
void r_s()
{
	node tmp;
	while(!a[r].empty()){
		tmp=a[r].top();
		a[r].pop();
		tmp.f=(!tmp.f);
		a[r-1].push(tmp);
	}
	if(l==r) l--,r--;
	else r--;
}
void print(int x)
{
	cout<<"Card "<<x<<" is a face ";
	if(res[x].f) cout<<"up ";
	else cout<<"down ";
	cout<<res[x].x<<'.'<<endl;
}
int main()
{
    //freopen("data.in","r",stdin);
	int n;
	int t=1;
	while(cin>>n&&n!=0){
        cout<<"Pile "<<t++<<endl;
		init();
		l=1;r=n;
		getchar();
		char tmp;
		node x;
		for(int i=1;i<=n;i++){
			tmp=getchar();
			if(tmp=='U'){
				x.f=1;
			}
			else x.f=0;
			x.x=i;
			a[i].push(x);
		}
		getchar();
		string str;
		getline(cin,str);
		for(auto ite=str.begin();ite!=str.end();ite++){
			if(*ite=='R') r_s();
			else l_s();
		}
		for(int i=1;i<=n;i++){
			res[i]=a[l].top();
			a[l].pop();
		}
		int m;
		cin>>m;
		int te;
		for(int i=0;i<m;i++){
			cin>>te;
			print(te);
		}
		//cout<<endl;
	}
}
