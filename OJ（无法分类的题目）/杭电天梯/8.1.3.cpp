#include<bits/stdc++.h>
using namespace std;
const int MAXN=210;
double s[MAXN];
char sg[MAXN];
void print(int a,int b)
{
    for(int i=0;i<a;i++){
        cout<<s[i]<<sg[i];
    }
    cout<<endl;
}
int main()
{
	string str;
	while(getline(cin,str)&&str!="0"){
//	    memset(s,0,sizeof(s));
//        memset(sg,0,sizeof(sg));
        str+=" ";
		int cou=0;
		int cou2=0;
		double tmp;
		for(auto ite=str.begin();ite!=str.end();ite++){
            if(*ite!=' ')
			if(isdigit(*ite)){
				s[cou++]=(*ite-'0');
			}
			else{
				switch(*ite){
					case '-':sg[cou2++]=*ite;break;
					case '+':sg[cou2++]=*ite;break;
					case '*':tmp=s[--cou]*(*(ite+2)-'0');s[cou++]=tmp;ite+=2;break;
					case '/':tmp=s[--cou]/(*(ite+2)-'0');s[cou++]=tmp;ite+=2;break;
				}
			}
		}
		//cout<<cou<<"\t"<<cou2<<endl;
		double res=s[0];
		for(int i=1,j=0;i<cou&&j<cou2;j++,i++){
			switch(sg[j]){
				case '-':res-=s[i];break;
				case '+':res+=s[i];break;
			}
		}
		//print(cou,cou2);
		//cout<<res<<endl;
		printf("%.2lf\n",res);
	}
}
