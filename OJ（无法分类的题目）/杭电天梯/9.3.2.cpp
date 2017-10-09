#include<bits/stdc++.h>
using namespace std;
int mod;
class matrix
{
    public:
	int a[6][6];
	matrix()
	{
	    memset(a,0,sizeof(a));
	    for(int i=0;i<5;i++){
            a[i][i]=1;
	    }
	}
	friend matrix operator^(matrix aa,matrix bb)
	{
        matrix tmp;
        //memset(tmp.a,0,sizeof(tmp.a));
        int sum;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                sum=0;
                for(int k=0;k<4;k++){
                    sum=sum+((aa.a[i][k]%mod*bb.a[k][j]%mod)%mod);
                }
                tmp.a[i][j]=sum%mod;
            }
        }
        return tmp;
	}
	void print(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
	}
};
matrix powm(matrix m,int p)
{
    //matrix via;
    matrix res;
    while(p){
       //via=via^m;
       if(p&1){
        //cout<<11111111<<endl;
        res=res^m;
       }
       m=m^m;
       p=p>>1;
    }
    return res;
}
int main()
{
    matrix base;
    memset(base.a,0,sizeof(base.a));
    base.a[0][0]=1,base.a[0][2]=1,base.a[0][3]=1;
    for(int i=1; i<4; i++)
    {
        base.a[i][i-1]=1;
    }
    matrix b;
    memset(b.a,0,sizeof(b.a));
    b.a[0][0]=9,b.a[1][0]=6,b.a[2][0]=4,b.a[3][0]=2;
    int l;
    while(cin>>l>>mod){
        if(l==4){
            cout<<9%mod<<endl;
        }
        else if(l==3){
            cout<<6%mod<<endl;
        }
        else if(l==2){
            cout<<4%mod<<endl;
        }
        else if(l==1){
            cout<<2%mod<<endl;
        }
        else if(l==0){
            cout<<1%mod<<endl;
        }
        else{
            matrix res=powm(base,l-4);
            //res.print();
            res=res^b;
            cout<<res.a[0][0]%mod<<endl;
        }
    }
}
