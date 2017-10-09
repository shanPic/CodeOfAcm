/*
* @FileName: D:\代码与算法\2017训练比赛\9.17青岛网络赛\1010.cpp
* @Author: Pic
* @Created Time: 2017/9/17 15:37:04
*/
#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
queue<int,list<int> > q;
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
   	scanf("%d",&t);
	while(t--){
		while(!q.empty()) q.pop();
		int n;
		scanf("%d",&n);
		int x;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			q.push(x);	
		}
		q.push(inf);
		int num=1;
		while(num!=0){
			int pre=-1;
			int x=0;
			num=0;
			while(q.front()!=inf){
				x=q.front();q.pop();
				if(x<pre||x>q.front()){
					num++;
				}
				else{
					q.push(x);
				}	
				pre=x;
			}
			q.pop();q.push(inf);
		}
	//	q.pop();
		printf("%d\n",q.size()-1);
		while(!q.empty()){
			x=q.front();
			if(x!=inf)
				printf("%d ",q.front());
			q.pop();
		}
		printf("\n");
	}	
	return 0;
}
