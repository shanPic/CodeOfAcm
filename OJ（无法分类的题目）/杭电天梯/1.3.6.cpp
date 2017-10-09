#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int id;
	int s;
	node(){}
	node(int a,int b){
		id=a;
		s=b;
	}
};
bool cmp(node a,node b)
{
	return a.s<b.s;
}
int tim[3];
int conver()
{
	return tim[0]*3600+tim[1]*60+tim[2];
}
int main()
{
    //freopen("data.in","r",stdin);
	int t;
	map<int,string> ID;
	std::vector<node> r;
	std::vector<node> l;
	cin>>t;
	int n;
	string str;
	while(t--){
		r.clear();
		l.clear();
		ID.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str;
			ID.insert(make_pair(i,str));
			scanf("%d:%d:%d",tim,tim+1,tim+2);
			r.push_back(node(i,conver()));
			scanf("%d:%d:%d",tim,tim+1,tim+2);
			l.push_back(node(i,conver()));
		}
		sort(r.begin(),r.begin()+n,cmp);
		sort(l.begin(),l.begin()+n,cmp);
		cout<<ID[r[0].id]<<" "<<ID[l[n-1].id]<<endl;
	}
}
