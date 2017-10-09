/*
* @FileName: D:\代码与算法\2017训练比赛\9.24南宁网络赛\h.cpp
* @Author: Pic
* @Created Time: 2017/9/24 14:48:53
*/
#include <bits/stdc++.h>
using namespace std;

int ad2[36];
void cal(int a)
{
	int now=0;
	while(a!=0){
		ad2[now]=a%2;
		a=a/2;
		now++;
	}
}
int two2ten(int b,int e)
{	
	int now=1,sum=0;
	for(int i=b;i<e;i++){
		sum+=(ad2[i]*now);
		now*=2;
	}
	return sum;
}
int buf[66];
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	char str[33];
	memset(buf,-1,sizeof(buf));
	int m=0,h=0;
	while(~scanf("%s",str)){
		if(str[0]=='E'){
			printf("Hit ratio = %.2f%%\n",(double)(h)/(double)(h+m)*100);
		}
		else{
			int ad=0;
			sscanf(str,"%x",&ad);
			//cout<<ad<<endl;
		//	printf("%x\n",ad);
			memset(ad2,0,sizeof(ad2));
			cal(ad);
			int line=two2ten(4,10);
			//cout<<"line is "<<line<<endl;
			int tag=two2ten(10,28);
		//	cout<<"tag is "<<tag<<endl;
			if(buf[line]==-1){
				printf("Miss\n");
				m++;
				buf[line]=tag;
			}
			else{
				if(buf[line]==tag){
					printf("Hit\n");
					h++;
				}
				else{
					printf("Miss\n");
					m++;
				}
				buf[line]=tag;
			}
		}
	}	
	return 0;
}
