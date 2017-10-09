/*
* @Author: 
* @Date:   2017-08-10 11:13:25
* @Last Modified by:   Lyucheng
* @Last Modified time: 2017-08-10 16:01:06
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
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        int now=0;
        while(n--){
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
            if(a+b<ab||a+c<ac||b+c<bc||ab+ac+bc<abc||a<ab||a<ac||b<ab||b<bc||c<ac||c<bc||ab<abc||ac<abc||bc<abc) continue;
            now=a+b+c-ab-ac-bc+abc;
            if(now>0)
                maxn=max(maxn,now);
        }   
        printf("%d\n",maxn);
    }
    return 0;
}