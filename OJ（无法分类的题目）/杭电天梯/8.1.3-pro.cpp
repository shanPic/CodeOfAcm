#include<bits/stdc++.h>
using namespace std;
const int MAXN=210;
int num[MAXN];
char f[MAXN];
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
		stringstream stm(str);
		int i=1,j=0;
		int sum_num=0;
		stm>>num[0];
		while(stm>>f[j]>>num[i]){
			j++;
			i++;
			sum_num++;
		}
		int cou=0,cou2=0;
		double tmp=0;
		s[cou++]=num[0];
		for(i=1,j=0;j<sum_num;i++,j++){
			switch(f[j]){
				case '+':s[cou++]=num[i];sg[cou2++]=f[j];break;
				case '-':s[cou++]=num[i];sg[cou2++]=f[j];break;
				case '*':tmp=s[--cou]*num[i];s[cou++]=tmp;break;
				case '/':tmp=s[--cou]/(num[i]*1.0);s[cou++]=tmp;break;
			}
		}
		double res=s[0];
		for(i=1,j=0;j<cou2;j++,i++){
			switch(sg[j]){
				case '+':res+=s[i];break;
				case '-':res-=s[i];break;
			}
		}
		//print(cou,cou2);
		printf("%.2lf\n",res);
		//cout<<res<<endl;
	}
}
