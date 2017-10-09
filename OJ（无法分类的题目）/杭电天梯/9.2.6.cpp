#include<bits/stdc++.h>
using namespace std;
const int MAXN=1003;
int vis[MAXN][MAXN];
int tree[MAXN][MAXN];
int MN=MAXN;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int y,int val)
{
	int i,j;
	for(i=x;i<=MN;i+=lowbit(i)){
		for(j=y;j<=MN;j+=lowbit(j)){
			tree[i][j]+=val;
		}
	}
}
int query(int x,int y)
{
	int i,j;
	int res=0;
	for(i=x;i>0;i-=lowbit(i)){
		for(j=y;j>0;j-=lowbit(j)){
			res+=tree[i][j];
		}
	}
	return res;
}
void chuli(int &x1,int& x2 ,int& y1,int& y2)
{
	if(x1>x2){
		swap(x1,x2);
	}
	if(y1>y2){
		swap(y1,y2);
	}
}
int main()
{
   // freopen("data.in","r",stdin);
   memset(vis,0,sizeof(vis));
   memset(tree,0,sizeof(tree));
	int n,x,y,x1,x2,y1,y2;
	char ch;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ch;
		if(ch=='B'){
			cin>>x>>y;
			x++;y++;
			if(vis[x][y]==0){
				update(x,y,1);
				vis[x][y]=1;
			}
		}
		else if(ch=='D'){
			cin>>x>>y;
			x++;y++;
			if(vis[x][y]){
				update(x,y,-1);
				vis[x][y]=0;
			}
		}
		else if(ch=='Q'){
			cin>>x1>>x2>>y1>>y2;
			x1++;x2++;y1++;y2++;
			int ans=0;
			//chuli(x1,x2,y1,y2);
            if(x1>x2)
            {
                swap(x1,x2);
            }
            if(y1>y2)
            {
                swap(y1,y2);
            }
			ans=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
			cout<<ans<<endl;
		}
	}
}
