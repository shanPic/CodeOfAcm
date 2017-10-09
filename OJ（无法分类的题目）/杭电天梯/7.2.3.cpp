#include<bits/stdc++.h>
using namespace std;
struct  node
{
	int m[10][10];
	node(){
		memset(m,0,sizeof(m));
//		for(int i=0;i<10;i++){
//            for(int j=0;j<10;j++)
//                m[i][j]=0;
//		}
	}
};
	int mod;
node multi(node &a,node &b)
{
	node tmp;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			int sum=0;
			for(int k=0;k<10;k++){
				sum+=(a.m[i][k]%mod)*(b.m[k][j]%mod);
			}
			tmp.m[i][j]=sum;
		}
	}
	return tmp;
}
void e_mat(node &a)
{
	for(int i=0;i<10;i++){
		a.m[i][i]=1;
	}
}
node quick_mul(node &a,int n)
{
	node tmp=a;
	//e_mat(tmp);
	node res;
	e_mat(res);
	if(n&1){
        res=a;
	}
	n=n>>1;
	while(n!=0){
		tmp=multi(tmp,tmp);
		if(n&1){
			res=multi(res,tmp);
		}
		n=n>>1;
	}
	return res;
}
void print(node &a)
{
    cout<<"---------------------------"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<"ÐÐ"<<"\t";
        for(int j=0;j<10;j++){
            cout<<a.m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"---------------------------"<<endl;
}
int main()
{
    //freopen("data.in","r",stdin);
	int n;

	int ai[11];
	node x;
	for(int i=0;i<10;i++){
		x.m[i][0]=9-i;
	}
	while(~scanf("%d%d",&n,&mod)){
		for(int i=0;i<10;i++){
			scanf("%d",ai+i);
		}
		if(n<10){
            printf("%d\n",n);
            continue;
		}
		node a;
		//print(a);
		for(int i=0;i<10;i++){
			a.m[0][i]=ai[i];
		}
		//print(a);
		for(int i=1;i<10;i++){
			a.m[i][i-1]=1;
		}
		//print(a);
		node res=quick_mul(a,n-9);
		//print(res);
		//print(x);
		res=multi(res,x);
		//print(res);
		printf("%d\n",(res.m[0][0])%mod);
	}
}
