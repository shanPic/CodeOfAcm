/*
* @FileName: j.cpp
* @Author: Pic
* @Date:   2017-06-04 13:32:23
* @Last Modified time: 2017-06-04 13:38:28
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int res=0;
	for(int a=1;a<=9;a++){
		for(int b=1;b<=9;b++){
			for(int c=1;c<=9;c++){
				for(int d=1;d<=9;d++){
					for(int e=1;e<=9;e++){
						for(int f=1;f<=9;f++){
							for(int g=1;g<=9;g++){
								for(int h=1;h<=9;h++){
									for(int i=1;i<=9;i++){
										if( a%2==0 && b%2==1 && d>c && d*2==i && e%3==0 && b<f && h==f && i>1){
											res++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<res<<endl;
    return 0;
}