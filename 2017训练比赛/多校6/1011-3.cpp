/*
* @Author: Lyucheng
* @Date:   2017-08-10 11:13:25
* @Last Modified by:   Lyucheng
* @Last Modified time: 2017-08-10 13:27:04
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
    // freopen("data.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        while(n--){
	            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
	            int tot=a+b+c-ab-ac-bc+abc;
	            int aob=a+b-ab;
	            int boc=b+c-bc;
	            int aoc=a+c-ac;
	            int oa=tot-boc;
	            int ob=tot-aoc;
	            int oc=tot-aob;
	            int oab=ab-abc;
	            int oac=ac-abc;
	            int obc=bc-abc;
	     		if(tot<0||aob<0||boc<0||aoc<0||oa<0||ob<0||oc<0||oab<0||oac<0||obc<0||abc<0) continue;
	     		if(oa+ob+oc+oab+oac+obc+abc!=tot) continue;
	     		maxn=max(maxn,tot);
	     		//cout<<11111<<endl;
            }
        printf("%d\n",maxn);
    }
    return 0;
}