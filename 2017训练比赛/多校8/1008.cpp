#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+30;
vector<int> vec;
int a[MAXN];
int main()
{
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		vec.clear();
		vec.reserve(MAXN*2);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		getchar();
		char ch;
		for(int i=0;i<n;i++){
			ch=getchar();
			getchar();
			if(ch=='L'){
				vec.push_back(a[i]);
			}
			else if(ch=='D'){
				vec.push_back(-a[i]);
			}
			else if(ch=='N'){
				vec.push_back(a[i]);
				vec.push_back(-a[i]);
			}
		}
		int len=vec.size();
/*		cout<<len<<endl;
		for(auto ite=vec.begin();ite!=vec.end();ite++){
			cout<<*ite<<endl;
		}*/
		sort(vec.begin(),vec.end());
		int l=0,r=0;
		int sum=0;
		int flag=0;
		while(1){
			while(r<len&&sum<k){
				sum+=vec[r];
				r++;
				if(sum==k){
					flag=1;
					break;
				}
			}
			if(sum<k) break;
			sum-=vec[l];
			l++;
			if(sum==k){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
}