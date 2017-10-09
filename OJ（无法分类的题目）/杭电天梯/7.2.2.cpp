#include<bits/stdc++.h>
using namespace std;
const int maxn=100000010;
//直接求解欧拉函数
int euler(int n){ //返回euler(n)
     int res=n,a=n;
     for(int i=2;i*i<=a;i++){
         if(a%i==0){
             res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出
             while(a%i==0) a/=i;
         }
     }
     if(a>1) res=res/a*(a-1);
     return res;
}
int main()
{
	int n;
	while(cin>>n&&n!=0){
		cout<<n-euler(n)-1<<endl;
	}
}
