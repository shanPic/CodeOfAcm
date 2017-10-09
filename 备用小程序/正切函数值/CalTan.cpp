/*
* @FileName: D:\代码与算法\备用小程序\正切函数值\CalTan.cpp
* @Author: Pic
* @Date:   2017-08-06 16:00:23
* @Last Modified time: 2017-08-06 16:02:42
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
double const Pi = acos(double(-1));
double fu(double x){return Pi/180.0*x;}
int main(){
	double a;
	while(cin>>a)
	cout<<tan(fu(a))<<endl;
    return 0;
}