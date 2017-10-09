 #include<bits/stdc++.h>
using namespace std;
const int MAXN=100100;
const int INF=0x3f3f3f3f;
struct point
{
	double x,y;
};
double dist(point &a,point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmpy(point& a,point &b)
{
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
bool cmpxy(point& a,point &b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
point a[MAXN];
point tmp[MAXN];
double Serch_closet(int left, int right)
{

	if(left==right) return INF;
	if(left-right==1)  {return dist(a[right],a[left]);}

	int mid=(left+right)/2;
	double d=min(Serch_closet(left,mid),Serch_closet(mid+1,right));
    //printf("%.2lf\n",d);
	int cou=0;
	for(int i=left;i<=right;i++){
		if(dist(a[i],a[mid])<d){
			tmp[cou++]=a[i];
		}
	}

	sort(tmp,tmp+cou,cmpy);

	for(int i=0;i<cou-1;i++){
		for(int j=i+1;j<cou&&tmp[j].y-tmp[i].y<d;j++){
			d=min(dist(tmp[i],tmp[j]),d);
		}
	}

	return d;
}
int main()
{
   // freopen("data.in","r",stdin);
	int n;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
		sort(a,a+n,cmpxy);
		printf("%.2lf\n",Serch_closet(0,n-1)/2);
	}
}
