/*
* @FileName: test.cpp
* @Author: Pic
* @Date:   2017-05-27 13:27:51
* @Last Modified time: 2017-05-27 15:40:56
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<int> a,b;
	for(int i=0;i<10;i++){
		a.push_back(i);
		b.push_back(i);
	}

	cout<< (a==b) <<endl;
    return 0;
}