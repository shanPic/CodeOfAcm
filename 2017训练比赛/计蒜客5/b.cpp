/*
* @FileName: b.cpp
* @Author: Pic
* @Date:   2017-06-03 19:29:24
* @Last Modified time: 2017-06-04 13:04:14
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=50000+3;
int a[MAXN];
int b[MAXN];
int len;
int cnt1[MAXN],cnt2[MAXN];
inline bool scan_d(int &ret) {
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0; //EOF
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
} 
inline int pp(int i,int n)
{
		int p1=0;
		for(int i=0;i<=len;i++) cnt1[i]=0;
		for(int j=i;j-i<n;j++){
			cnt1[a[j]]++;
			if(cnt1[a[j]]==1) p1++;
		}
		int p=0;
		for(int i=0;i<n;i++){
			cnt1[b[i]]--;
			if(cnt1[b[i]]==0) p++;
		}
		if(p==p1) return 1;
		else return 0;
}
int main(){
	
	//freopen("data.in","r",stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
	//cin>>len;
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		//cin>>a[i];
		//scanf("%d",&a[i]);
		scan_d(a[i]);
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int n;
		//cin>>n; 
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			//cin>>b[i]; 
			//scanf("%d",&b[i]);
			scan_d(b[i]);
		}
		if(n>len){
			//cout<<0<<endl;
			printf("0\n");
			continue;
		}
		//memset(cnt2,0,sizeof(cnt2));
		// for(int i=0;i<=len;i++) cnt2[i]=0;
		// for(int i=0;i<n;i++){
		// 	cnt2[b[i]]++;
		// }
		int res=0;

		//memset(cnt1,0,sizeof(cnt1));
		// for(int i=0;i<=len;i++) cnt1[i]=0;
		// for(int j=0;j<n;j++){
		// 	cnt1[a[j]]++;
		// }
		// int flag=1;
		// for(int i=0;i<=len;i++){
		// 	if(cnt1[i]!=cnt2[i]){
		// 		flag=0;
		// 		break;
		// 	}
		// }
		// if(flag) res++;

		for(int i=0;i+n<=len;i++){
			//cout<<1111111<<endl;
			if(pp(i,n)){
				//cout<<22222<<endl;
				res++;
			}

		}
		//cout<<res<<endl;
		printf("%d\n",res);
	}
    return 0;
}