#include <bits/stdc++.h>

using namespace std;

class SortingGame
{
public:
	int fewestMoves(vector <int> board, int k)
	{
		queue<vector<int>> q;
		map<vector<int>,int> vis;
		q.push(board);vis[board]=0;
		while(!q.empty()){
			cout<<11111<<endl;
			vector<int> vec=q.front();
			q.pop();
			int num=vis[vec];
			int r=vec.size();
			int i=0;
			for(i=0;i<r-1;i++){
				if(vec[i+1]<vec[i]) break;			
			}
			if(i==r-1) return num;
			for(int i=0;i+k<=r;i++){
				vector<int> tmp=vec;
				reverse(tmp.begin()+i,tmp.begin()+i+k);
				if(vis.count(tmp)==0){
					q.push(tmp);
					vis[tmp]=num+1;
				}
			}
		}
		return -1;
	}
};
int main()
{
	freopen("data.in","r",stdin);
	int n;
	cin>>n;
	int x;
	vector<int> vec;
	while(cin>>x){
		vec.push_back(x);
	}
	SortingGame sg;
	cout<<sg.fewestMoves(vec,n)<<endl;
}