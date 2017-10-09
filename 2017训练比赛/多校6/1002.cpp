/*
* @Author: Lyucheng
* @Date:   2017-08-10 14:02:59
* @Last Modified by:   Lyucheng
* @Last Modified time: 2017-08-10 16:23:19
*/

/*
 P Q 所在直线在圆中的割线，和中线到 P Q 和的大小就可以
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

#define eps 1e-8

using namespace std;

int t;
double px, py,qx,qy, r, R;
double l1;
double l2;
double Min(double a,double b){
    if(a-b>eps) return b;
    else return a;
}


int main(){
     freopen("data.in","r",stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--){

        scanf("%lf", &R);
        scanf("%lf%lf", &px, &py);
        scanf("%lf%lf", &qx, &qy);

        double PQ=sqrt((qx-px)*(qx-px)+(qy-py)*(qy-py));

        //小圆半径
        r=sqrt(px*px+py*py);

        //圆点到PQ距离
        double d=sqrt(r*r-PQ*PQ/4);

        //切点PQ所在直线在R内的割线长度
        l1=2*sqrt(R*R-d*d);

        //PQ中线到PQ的距离
        l2=2*sqrt((R-d)*(R-d)+PQ*PQ/4);
        
        printf("%.6f\n",Min(l1,l2));
    }
}