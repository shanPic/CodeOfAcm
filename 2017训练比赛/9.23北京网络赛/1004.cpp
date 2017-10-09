#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int x,y;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
		}	
		printf("%d\n",n/2);
	}
}
