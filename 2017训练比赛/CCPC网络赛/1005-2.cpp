/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1005-2.cpp
* @Author: Pic
* @Date:   2017-08-19 14:55:24
* @Last Modified time: 2017-08-19 14:55:26
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int shit[1000000];
int main() {
    int b;
    shit[4] = 2;
    shit[6] = 4;
    shit[7] = 5;
    for (int i = 8; i <= 1000000; ++i) {
        if (i % 4 == 0) {
            b = i / 4;
            shit[i] = b * b * 2;
        } else if (i % 4 == 1) {
            shit[i]=b-1 + shit[i-1];
        } else if (i%4==2) {
            shit[i]=b*2+shit[i-2];
        } else {
            shit[i]=b+shit[i-1];
        }
        if (shit[i] > 1e9) {
            break;
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        for (int i = 4; i <= 1000000; ++i) {
            if (shit[i] >= x) {
                printf("%d\n", i);
                break;
            }
        }
    }
}