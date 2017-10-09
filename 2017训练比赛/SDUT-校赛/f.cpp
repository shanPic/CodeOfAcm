/*
* @FileName: f.cpp
* @Author: Pic
* @Date:   2017-06-04 13:24:46
* @Last Modified time: 2017-06-04 15:14:23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);

	while(t--){
		char str[13];
		int n;
		getchar();
		scanf("ma ji ya ba ku nai %s",str);
		//cout<<111111<<"\t"<<str<<endl;
		int len=strlen(str);
		if(str[0]=='0'){
			if(len==2){
				printf("21%s\n",str);
				continue;
			}
			else if(len==3){
				printf("3%s\n",str);
				continue;
			}
			else{
				printf("1%s\n",str);
				continue;
			}
		}
		if(str[0]=='2'&&len==4){
			printf("1%s\n",str);
			continue;
		}
		if(len<4){
			if(len==1){
				if(str[0]-'0'<9){
					printf("201%s\n",str);
					continue;
				}
				printf("200%s\n",str);
				continue;
			}
			if(len==2){
				printf("20%s\n",str);
				continue;
			}
			if(len==3){
				printf("2%s\n",str);
				continue;
			}
		}
		printf("%s\n",str);continue;
	}
    return 0;
}
