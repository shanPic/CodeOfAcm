#include<bits/stdc++.h>
using namespace std;
	int n,k,a,b;
bool OK()
{
	if(a==0||b==0){
		if(a==0){
			if(b>k) return 0;
			else return 1;
		}
		else{
			if(a>k) return 0;
			else return 1;
		}
	}
	return 1;
}
int main()
{
	cin>>n>>k>>a>>b;//a-->G,b-->B;
	int tmp=min(a,b);
	int am=a/tmp,bm=b/tmp;//一个循环节a和b有多少
	if(OK()==0){
		cout<<"NO"<<endl;
		return 0;
	}
	if(k<max(am,bm)||k<(a%tmp)||k<(b%tmp)){
		cout<<"NO"<<endl;
		return 0;
	}
	int coun=0;
	if(b<a){
        for(int i=0;i<tmp;i++,coun++){
            for(int j=0;j<am;j++){
                cout<<"G";
            }
            for(int j=0;j<bm;j++){
                cout<<"B";
            }
        }
	}
    else{
        for(int i=0; i<tmp; i++,coun++)
        {
            for(int j=0; j<bm; j++)
            {
                cout<<"B";
            }
            for(int j=0; j<am; j++)
            {
                cout<<"G";
            }
        }
    }
	//cout<<coun<<endl;
	if((a-coun*am)!=0||(b-coun*bm)!=0){
		if(a<b){
			for(int i=coun*bm;i<b;i++){
				cout<<"B";
			}
		}
		else {
			for(int i=coun*am;i<a;i++){
				cout<<"G";
			}
		}
	}
	cout<<endl;

}
