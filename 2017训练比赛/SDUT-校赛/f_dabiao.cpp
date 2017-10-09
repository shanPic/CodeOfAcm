#include<bits/stdc++.h>
using namespace std;
map<string,string> ans;
set<string> v;
int main(){
    freopen("data.out","w",stdout);
    string s;
    for(int i=2009;i<=200003 ;i++){
	stringstream in;
	in<<i;
	in>>s;
	int len=s.length();
	for(int i=len-1;i>=0;i--){
	    if(v.find(s.substr(i,len))==v.end()){
		ans[s]=s.substr(i,len);
		v.insert(s.substr(i,len));
		break;
	    }
	}
	cout<<s<<" "<<ans[s]<<endl;
    }
    return 0;
}
