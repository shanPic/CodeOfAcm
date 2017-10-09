/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1012.cpp
* @Author: Pic
* @Date:   2017-07-18 18:33:34
* @Last Modified time: 2017-07-18 23:34:26
*/

#include <cstdio>
#include<algorithm>
using namespace std;
const int MAXN=30;
struct node
{
	int p,n;
};
node a[MAXN];
bool cmp(node a,node b)
{
	return a.p>b.p;
}
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安
//暴力大法保平安

int main(){
	//freopen("data.in","r",stdin);
	int n,c;
	while(~scanf("%d%d",&n,&c)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].p,&a[i].n);
		}
		sort(a,a+n,cmp);
		int res=0;
		while(1){
			int tot=0,num=0;
			for(int i=0;i<n;i++){
				if(a[i].n&&tot+a[i].p<=c){
					tot+=a[i].p;
					a[i].n--;
				}
				// if(tot>=c){
				// 	num++;
				// 	break;
				// }
			}
			if(tot>=c){
				res++;
			}
			else{
				for(int i=n-1;i>=0;i--){
					while(a[i].n&&tot<c){
						tot+=a[i].p;
						a[i].n--;
					}
					// if(tot>=c){
					// 	num++;
					// 	break;
					// }
				}
				if(tot>=c){
					res++;
				}
				else{
					break;
				}
				//break;
			}
		}
		printf("%d\n",res);
	}
    return 0;
}