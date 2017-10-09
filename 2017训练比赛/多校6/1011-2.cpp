/*
* @Author: Lyucheng
* @Date:   2017-08-10 11:13:25
* @Last Modified by:   Lyucheng
* @Last Modified time: 2017-08-10 13:11:26
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define LL long long

using namespace std;

int t;
int n;
int a,b,c,ab,ac,bc,abc;
int maxn;

inline void init(){
    maxn=-1;
}

int main(){ 
     freopen("data.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        while(n--){
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
            if(a>=ab&&a>=ac&&a>=abc&&b>=ab&&b>=bc&&b>=abc&&c>=ac&&c>=bc&&c>=abc&&ab>=abc&&ac>=abc&&bc>=abc){
            	//cout<<1111<<endl;
                int res=a+b+c-ab-ac-bc+abc;
                if(a+b<2*ab||a+c<2*ac||b+c<2*bc||ab+ac+bc<abc) continue;
                if(res<a||res<b||res<c||res<ab||res<ac||res<bc||res<abc) continue;
                maxn=max(maxn,res);
                cout<<111111<<endl;
            }
        }
        printf("%d\n",maxn);
    }
    return 0;
}