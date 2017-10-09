/*
* @FileName: D:\代码与算法\2017训练比赛\多校2\1011-3.cpp
* @Author: Pic
* @Date:   2017-07-27 14:16:59
* @Last Modified time: 2017-07-27 15:45:33
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=500+30;
struct node 
{
	int x,y;
};
node a[MAXN];
int mp[MAXN][MAXN];
int xb[MAXN][MAXN];
int zf[MAXN][MAXN];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
double dis(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool js(int i,int j,int k)
{
	int x=-1,y=-1;
	int x1=a[i].x,y1=a[i].y,x2=a[j].x,y2=a[j].y,x3=a[k].x,y3=a[k].y;
	// if((x1==x2&&x1==x3)||(y1==y2&&y1==y3)) return 0;
	// if(x1==x2) x=x3,y=y1;
	// else if(x1==x3) x=x2,y=y2;
	// else if(x2==x3) x=x1,y=;
	if(x1!=x2){
		x=abs(x1+x2-x3);
	}else if(x1!=x3) x=abs(x1+x3-x2);
	else if(x2!=x3) x=abs(x2+x3-x1);
	if(y1!=y2) y=abs(y1+y2-y3);
	else if(y1!=y3) y=abs(y1+y3-y2);
	else if(y2!=y3) y=abs(y2+y3-y1);
	//cout<<x<<"\t"<<y<<endl;
	if(x==-1||y==-1) return 0;
	return mp[x][y]&&(dis(x,y,x1,y1)==dis(x1,y1,x2,y2));

}
int main(){
	freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].x+=100,a[i].y+=100;
			mp[a[i].x][a[i].y]=1;
		}
		//sort(a,a+n,cmp);
		int res=0;
		//int x1,x2,y1,y2;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
					for(int k=j+1;k<n;k++){
							if(js(i,j,k)){
								cout<<i<<" "<<j<<" "<<k<<endl;
								res++;
							}
						}
			}
		}
		printf("%d\n",res/2);
	}
    return 0;
}