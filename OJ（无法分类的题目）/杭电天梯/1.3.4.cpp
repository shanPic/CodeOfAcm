#include<iostream>
#include<algorithm>
using namespace std;
vector<int> str;
int main()
{
	int n;
	int tmp;
	while(cin>>n){
        str.clear();
		for(int i=0;i<n;i++){
			cin>>tmp;
			str.push_back(tmp);
		}
		sort(str.begin(),str.begin()+n);
		if(n!=0){
            int l=0,r=n-1;
            for(;l!=r;){
                cout<<str[r]<<" ";
                r--;
                if(r!=l){
                    cout<<str[l]<<" ";
                    l++;
                }
            }
            cout<<str[l]<<endl;
		}
		else{
            continue;
		}
	}
	return 0;
}
