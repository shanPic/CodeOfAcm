/*
* @FileName: f_pro.cpp
* @Author: Pic
* @Date:   2017-06-04 15:31:24
* @Last Modified time: 2017-06-04 15:51:25
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);

	while(t--){
		char str[13];
		int n;
		getchar();
		scanf("ma ji ya ba ku nai %s",str);
		//cout<<111111<<"\t"<<str<<endl;
		int len=strlen(str);
		if(len==4){
			if(str[0]=='0'||str[0]=='1'||str[0]=='2'){
				printf("1%s\n",str);
				continue;
			}
			printf("%s\n",str);
			continue;
		}
		if(len>4){
			if(str[0]=='0'){
				printf("1%s\n",str);
				continue;
			}
			printf("%s\n",str);
			continue;
		}
		if(len==2){
			if(str[0]=='0'){
				printf("21%s\n",str);
				continue;
			}
			if(str[0]=='1'){
				if(str[1]=='9'){
					printf("2019\n");
					continue;
				}
				else{
					printf("21%s\n",str);
					continue;
				}
			}
			printf("20%s\n",str);
			continue;
		}
		if(len==1){
			if(str[0]=='9'){
				printf("200%s\n",str);
				continue;
			}
			printf("201%s\n",str);
			continue;
		}
		if(len==3){
			if(str[0]=='0'||str[0]=='1'){
				printf("3%s\n",str);
				continue;
			}
			printf("2%s\n",str);
			continue;
		}
	}
    return 0;
}