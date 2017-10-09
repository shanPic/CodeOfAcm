/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星初赛\1005.cpp
* @Author: Pic
* @Date:   2017-08-12 15:29:27
* @Last Modified time: 2017-08-12 15:40:04
*/
#include <bits/stdc++.h>
using namespace std;

// int cal(int year,int month,int day)
// {
//     if (month < 3） {
//         year -= 1;
//         month += 12;
//     }
//     //charb[7][10] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
//     int c = int(year / 100)，y = year - 100 * c;
//     int w = int(c / 4） -2 * c + y + int(y / 4)+（26 * (month + 1) / 10） +day - 1;
//     w = (w % 7 + 7） % 7;
//     //cout << b[w] << endl;
//     return w;
// }
int cal(int year,int month,int day)
{
	if(month<3){
		year -= 1;
		month += 12;
	}
	int c=int(year/100),y=year-100*c;
	int w=int(c/4) - 2*c +y +int(y/4)+(26*(month+1)/10) +day-1;
	w=(w%7+7)%7;
	return w;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int y,m,d,w;
		scanf("%d-%d-%d",&y,&m,&d);
		w=cal(y,m,d);
		int res=0;
		for(int i=y+1;i<=9999;i++){
			if(w==cal(i,m,d)){
				res=i;
				break;
			}
		}
		printf("%d\n",res);
	}
}