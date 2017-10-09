#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2,a="",b="";
		cin>>s1>>s2;
		a+=s1[0];
		for(int i=1;i<s1.length();i++)
		  if(s1[i]!=a[a.length()-1])
			a+=s1[i];
		b+=s2[0];
		for(int i=1;i<s2.length();i++)
			if(s2[i]!=b[b.length()-1])
			b+=s2[i];
		if(a==b)
		  puts("Yes");
		else
		  puts("No");

	}
	return 0;
}