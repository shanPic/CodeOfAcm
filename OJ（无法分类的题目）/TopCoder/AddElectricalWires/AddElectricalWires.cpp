/*
* @FileName: AddElectricalWires.cpp
* @Author: Pic
* @Date:   2017-05-29 20:47:31
* @Last Modified time: 2017-05-29 22:02:01
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=55+3;
class AddElectricalWires
{
public:
	int f[58];
	AddElectricalWires(){memset(f,-1,sizeof(f));}
	int find(int x)
	{
		if (f[x] == -1) {
			return x;
		}
		else {
			f[x] = find(f[x]);
			return f[x];
		}
	}
	int maxNewWires(vector <string> wires, vector <int> g)
	{
		memset(f,-1,sizeof(f));
		int len=wires.size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				if(wires[i][j]=='1'){
					f[find(i)]=find(j);
				}
			}
		}
		int res=0;
		int cnt[MAXN];
		memset(cnt,0,sizeof(cnt));
		vector<int> son[MAXN];
		for(int i=0;i<len;i++){
			int x=find(i);
			if (x != i) {
				cnt[x]++;
				son[x].push_back(i);
			}
		}
		int len2=g.size();
		for(int i=0;i<len2;i++){
			int tar=find(g[i]);
			int len=son[tar].size();
			for(int j=0;j<len;j++){
				for(int k=i+1;k<len;k++){
					int x=son[i][j],y=son[i][k];
					if(x!=y){
						if(wires[x][y]=='0'){
							res++;
						}
					}
				}
			}
		}
		for(int i=0;i<len;i++){
			if(f[i]==-1&&cnt[i]==0&&(std::find(g.begin(),g.end(),i)==g.end())){
				res++;
			}
		}
		return res;
	}
};

int main(){
	freopen("data.in","r",stdin);
	int n;
	cin>>n;
	string s;
	vector<string> vec;
	for(int i=0;i<n;i++){
			cin>>s;
			vec.push_back(s);
	}	
	cin>>n;
	vector<int> tar;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		tar.push_back(x);
	}
	AddElectricalWires tmp;
	cout<<tmp.maxNewWires(vec,tar)<<endl;
    return 0;
}