#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long ll;
const int maxn = 100009;

int t,m,n;
char str[20009];

bool solve(int len){
	int sum=0;
 	for(int i=len-1;i<n-len;i++){
 		for(int j=i+1;j<=n-len;j++){
 			sum=0;
 			for(int k=0;k<len;k++){
 				sum+=abs(str[i-k]-str[j+k]);
 			}
 			if(sum<=m) return 1;
 		}
 	}
 	return 0;
}
int main()
{
	//freopen("data.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        scanf("%s",str);
        n=strlen(str);
        int l=1,r=n;
        int mid;
        while(r-l>1){
        	mid=(l+r)/2;
        	if(solve(mid)){
        		l=mid;
        	}
        	else{
        		r=mid;
        	}
        }
        printf("%d\n",l);
    }
    return 0;
}