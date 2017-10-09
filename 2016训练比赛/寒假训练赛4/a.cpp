#include<bits/stdc++.h>
using namespace std;
const int MAXN=150;
int C[MAXN][MAXN];
int MN=100;
int lowbit(int x)
{
    return x&(-x);
}
void update(int X,int Y){
	int x,y;
	for (x=X; x<=MN; x+=lowbit(x))
		for (y=Y; y<=MN; y+=lowbit(y))
			C[x][y]+=1;
}
int getsum(int X,int Y){
    if(X<=0||Y<=0) return 0;
    if(X>MN) X=MN;
    if(Y>MN) Y=MN;
	int x,y,sum=0;
	for (x=X; x>0; x-=lowbit(x))
		for (y=Y; y>0; y-=lowbit(y))
			sum+=C[x][y];
	return sum;
}
void init()
{
    memset(C,0,sizeof(C));
}
int main()
{
   // freopen("data.in","r",stdin);
    int t;
    cin>>t;
    int h;
    int res,hx,hy;;
    int cou=1;
    int n;
    while(t--){
        init();
        cin>>n;
        int x,y;
        hx=hy=-1;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            hx=max(hx,x);hy=max(hy,y);
            update(x,y);
        }
        cin>>h;
        int tmp,rx=0,ry=0;
        res=-1;
        for(int i=0;i<=hx;i++){
            for(int j=0;j<=hy;j++){
                tmp=getsum(i+h,j+h)-getsum(i+h,j-1)-getsum(i-1,j+h)+getsum(i-1,j-1);
                //cout<<tmp<<endl;
                //cout<<i<<"\t"<<j<<"\t"<<h<<endl;
                //cout<<getsum(i+h,j+h)<<endl<<getsum(i+h,j-1)<<endl<<getsum(i-1,j+h)<<endl<<getsum(i-1,j-1)<<endl;
                if(tmp>res){
                    res=tmp;
                    rx=i;ry=j;
                }
            }
        }
        printf("Case %d:\n%d %d %d\n",cou++,rx,ry,res);
    }
}
