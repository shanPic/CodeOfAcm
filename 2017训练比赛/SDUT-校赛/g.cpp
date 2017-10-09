/*
* @FileName: g.cpp
* @Author: Pic
* @Date:   2017-06-04 13:30:45
* @Last Modified time: 2017-06-04 16:36:43
*/

#include <bits/stdc++.h>
using namespace std;

int val[28];
struct node
{
	
};
bool cmp(char a,char b)
{
	return val[a-'a']>val[b-'a'];
}
int main(){

	while(cin>>val[0]){
		for(int i=1;i<26;i++){
			scanf("%d",&val[i]);

		}
		char str[1300];
		scanf("%s",str);
		sort(str,str+strlen(str),cmp);
		int a=strlen(str);
		double b=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			b+=val[str[i]-'a'];
		}
		b=b/60;
		double res=a*1.0/b;
		for(int i=0;i<len;i++){

		}
	}
    return 0;
}