/*
* @FileName: D:\代码与算法\2017训练比赛\9.24南宁网络赛\j-2.cpp
* @Author: Pic
* @Created Time: 2017/9/24 13:30:15
*/
#include <bits/stdc++.h>
using namespace std;
char str1[13],str2[13];
int str[13];
int len;
int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	scanf("%d",&len);
	for(int i=0;i<5;i++){
		scanf("%s %s",str1,str2);
	//	cout<<str1<<"\t"<<str2<<endl;
		//len=strlen(str1);
		for(int i=0;i<len;i++){
			str[i]=str1[str2[i]-'0'-1]-'0';
		}
	//	for(int i=0;i<len;i++) cout<<str[i]<<" ";
	//	cout<<endl;
		int vis[13];memset(vis,0,sizeof(vis));
		int res=0;
		for(int i=0;i<len;i++){
			if(vis[str[i]]) continue;
			int num=1,ptr=str[str[i]-1];
			vis[str[i]]=1;
			int flag=0;
			if(str[i]==1) flag=1;
			while(ptr!=(str[i])){
				vis[ptr]=1;
				num++;
				if(ptr==1) flag=1;
				ptr=str[ptr-1];
			}
			if(num==1) continue;
			if(flag){
				res+=(num-1);
			}
			else{
				res+=(num+1);
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
