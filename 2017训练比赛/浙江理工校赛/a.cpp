#include <bits/stdc++.h>
using namespace std;
char a[50005],b[50005];
int t;
int len=0;
void init(){
	len=0;
}
int main(){
	// freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%s",b);
		int n=strlen(b);
		if(n<=2){
			puts("NO");
			continue;
		}
		for(int i=0;i<n;i++){
            a[i]=b[n-i-1];
		}
		for(int i=0;i<n/2;i++){
            if(a[i]!=b[i] )
                break;
			len++;
		}
		if(len==0){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}
