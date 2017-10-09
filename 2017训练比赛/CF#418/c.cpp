/*
* @FileName: D:\代码与算法\2017训练比赛\CF#418\c.cpp
* @Author: Pic
* @Date:   2017-06-07 21:57:08
* @Last Modified time: 2017-06-10 21:02:04
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=1503;
int a[MAXN];
int main(){
	 //freopen("data.in","r",stdin);
	int n;
	char tmp;
	scanf("%d",&n);getchar();
	for(int i=0;i<n;i++){
		scanf("%c",&tmp);
		a[i]=tmp-'a';
	}
	getchar();
	int m;
	scanf("%d",&m);
	int x,xn;
	int res=-1;
	for(int i=0;i<m;i++){
		res=-1;
		scanf("%d %c",&xn,&tmp);
		//cout<<xn<<"\t"<<tmp<<endl;
		x=tmp-'a';
		int l=0,r=0,now=0;
		while(l<n&&r<n){
			//cout<<11111<<endl;
			//cout<<l<<"\t"<<r<<endl;
			if(a[r]==x) r++;
			else if(now<xn){
				r++; now++;
			}
			else{
				//l=r;now=0;
				if(a[l]!=x) now--;
				l++;
			}
			res=max(res,r-l);
		}
		printf("%d\n",res);
	}

    return 0;
}