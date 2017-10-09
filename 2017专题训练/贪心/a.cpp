#include<bits/stdc++.h>
using namespace std;
const int MAXN = 130;
int row[MAXN];
int col[MAXN];
int a[MAXN][MAXN];
	int n, m;
bool checkrow(){
	bool flag=0;
	for(int i=0;i<n;i++){
		if(row[i]==-1||row[i]==1){
			flag=1;
			break;
		}
	}
	return flag;
}
bool checkcol()
{
	bool flag=0;
	for(int i=0;i<m;i++){
		if(col[i]==-1||col[i]==1){
			flag=1;
			break;
		}
	}
	return flag;
}
int main()
{
	memset(row, -1, sizeof(row));
	memset(col, -1, sizeof(col));
	cin >> n >> m;
	int flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (flag) {
				if (a[i][j] == 0) {
					if (row[i] == -1) {
						row[i] = 0;
					}
					if(col[j]==-1){
						col[j]=0;
					}
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1){
				if(row[i]==0&&col[j]==0){
					flag=0;
					break;
				}
				if(row[i]==-1){
					if(checkcol())
						row[i]=1;
					else{
						flag=0;
						break;
					}
				}
				if(col[j]==-1){//?
					if(checkrow())
						col[j]=1;
					else{
						flag=0;
						break;
					}
				}
			}
		}
		if(!flag) break;
	}
	if(!flag) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			if(row[i]==0){
				for(int j=0;j<m;j++){
					cout<<0<<" ";
				}
				cout<<endl;
			}
			else{
				for(int j=0;j<m;j++){
					if(col[j]==0){
						cout<<0<<" ";
					}
					else{
						cout<<1<<" ";
					}
				}
				cout<<endl;
			}
		}
	}
	return 0;
}