/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星初赛\1001-pro.cpp
* @Author: Pic
* @Date:   2017-08-12 15:51:46
* @Last Modified time: 2017-08-12 15:53:15
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        if(n==1) {
        	cout<<1<<endl; 
        	continue;
        }
        n--;
        int count=2;
    	for(int i=2;i<=sqrt(n);i++){
	    if(n%i==0){
            if(i==sqrt(n) && n/i==i){ 
                 count++;   
            }
            else count+=2;
        	}
    	}
        cout<<count<<endl;
    }
}