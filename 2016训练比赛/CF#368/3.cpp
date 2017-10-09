#include<bits/stdc++.h>
using namespace std;
int s,x1,x2,t1,t2,p,d;
int solve(int f)
{
    if(f==1){
        if(p<=x1){
            if(d==1) return (x2-p)*t1;
            else return (p+x2)*t1;
        }
        else if(p<x2&&p>x1){
            if(d==1) return (s-p+s+x2)*t1;
            else return (p+x2)*t1;
        }
        else{
            if(d==1) return (s-p+x2+s)*t1;
            else return (p+x2)*t1;
        }
    }
    else if(f==-1){
    	if(p<=x2){
    		if(d==-1) return (p+s+s-x2)*t1;
    		else return (s-p+x2)*t1;
    	}
    	else if(p>x2&&p<x1){
    		if(d==1) return (s-p+s-x2)*t1;
    		else return (p+s+s-x2)*t1;
    	}
    	else {
    		if(d==1) return (s-p+s-x2)*t1;
    		else return (p-x2)*t1;
    	}
    }
}
int main()
{
	//freopen("data.in","r",stdin);
    int resb,resd,resh;
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    resb=abs(x1-x2)*t2;
    if(x1<x2){
        resd=solve(1);
    }
    else{
        resd=solve(-1);
    }
    cout<<min(resb,resd)<<endl;
}
