/*
* @FileName: D:\代码与算法\2017训练比赛\多校1\1008.cpp
* @Author: Pic
* @Date:   2017-07-25 13:19:28
* @Last Modified time: 2017-07-25 13:23:07
*/

#include<bits/stdc++.h>
using namespace std;
int A=2,B=2,C=2;
unsigned x = A, y = B, z = C;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}
int main(){
	int a[3];
	for(int i=0;i<13;i++){
		a[i]=rng61();
		cout<<a[i]<<endl;
	}
    return 0;
}
