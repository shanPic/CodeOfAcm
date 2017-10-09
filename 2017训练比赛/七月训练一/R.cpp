/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练一\R.cpp
* @Author: Pic
* @Date:   2017-07-03 21:04:45
* @Last Modified time: 2017-07-03 21:31:26
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000+30;
char a[MAXN];
int nxt[MAXN];
int n;
void kmp_pre()
{
    int i,j;
    j=nxt[0]=-1;
    i=0;
    while (i < n)
    {
        while(-1!=j && a[i]!=a[j])
            j=nxt[j];
        nxt[++i]=++j;
    }
}
int main(){
	int t=0;
	//freopen("data.in","r",stdin);
	while(~scanf("%d",&n)&&n){
		scanf("%s",a);
		kmp_pre();
		printf("Test case #%d\n",++t);
		for(int i=1;i<=n;i++){	//由于多加了一个向右的偏移量（23行），所以需要==n
			if((i%(i-nxt[i]))==0&&nxt[i]!=0){
				printf("%d %d\n",i,i/(i-nxt[i]));
			}
		}
		printf("\n");
		//cout<<nxt[n]<<endl;
	}
    return 0;
}