#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define next nxt
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
string s[5][5];//存储当前状况
struct state {
	int board[4][4];	//状态
	void print() {
		FOR(i, 1, 3) {
			FOR(j, 1, 3)cout << board[i][j] << " "; cout << endl;
		}
	}
};
bool operator < (const state& a, const state& b) {
	FOR(i, 1, 3)FOR(j, 1, 3)if (a.board[i][j] != b.board[i][j])	return a.board[i][j] < b.board[i][j];
	return false;
}
map<state, int> fwin;
state makestate() {
	state ans;
	FOR(i, 1, 3) {
		FOR(j, 1, 3) {
			if (s[i][j] == "o")	ans.board[i][j] = 0;			//o为0，x为0
			else if (s[i][j] == "x")	ans.board[i][j] = 1;
			else ans.board[i][j] = -1;
		}
	}
	return ans;
}
int check(state now) {
	FOR(i, 1, 3) { //横着三个相同
		if (now.board[i][1] == now.board[i][2] && now.board[i][1] == now.board[i][3]) {
			if (now.board[i][1] != -1)	return now.board[i][1];
		}
	}
	FOR(j, 1, 3) { //竖着三个相同
		if (now.board[1][j] == now.board[2][j] && now.board[1][j] == now.board[3][j]) {
			if (now.board[1][j] != -1)	return now.board[1][j];
		}
	}
	if (now.board[1][1] == now.board[2][2] && now.board[1][1] == now.board[3][3]) { //右斜
		if (now.board[1][1] != -1)	return now.board[1][1];
	}
	if (now.board[1][3] == now.board[2][2] && now.board[1][3] == now.board[3][1]) { //左斜
		if (now.board[1][3] != -1)	return now.board[1][3];
	}
	FOR(i, 1, 3)FOR(j, 1, 3)if (now.board[i][j] == -1)	return -1; //continue，有未填写的空白处
	return 2;//tie，平局
}
/////////////////////////////////
int search(state now, int next) { //0-win 1-tie 2-lose（tie平局）
	now.print(); cout << next << endl;
	if (fwin.find(now) != fwin.end())	return fwin[now];

	int temp = check(now);
	cout << "check " << temp << endl;
	if (temp == 2)	{fwin[now] = 1; return 1;}
	else if (temp == (next ^ 1)) {fwin[now] = 2; return 2;}
	else if (temp == next) {fwin[now] = 0; return 0;}

	int mark = 0;
	FOR(i, 1, 3) {
		FOR(j, 1, 3) {
			if (now.board[i][j] == -1) {
				state temp = now;
				temp.board[i][j] = next;
				int rst = search(temp, next ^ 1);
				mark = max(mark, rst);
			}
		}
	}
	if (mark == 0)	fwin[now] = 2;
	else if (mark == 1)	fwin[now] = 1;
	else fwin[now] = 0;

	return fwin[now];

}
int main (int argc, char *argv[])
{
    freopen("data.in","r",stdin);
	std::ios::sync_with_stdio(false);
	int noc; cin >> noc;
	while (noc--) {
		FOR(i, 1, 3)FOR(j, 1, 3) {
			cin >> s[i][j];
		}
		int fst;
		string temp, ano;
		cin >> temp;	//temp是下一步该谁走
		if (temp == "o")	fst = 0 , ano = "x";
		else fst = 1 , ano = "o";
		fwin.clear();
		int key = search(makestate(), fst);
		if (key == 0)	cout << temp << " " << "win!" << endl;
		else if (key == 1)	cout << "tie!" << endl;
		else cout << ano << " " << "win!" << endl;
	}
	return 0;
}
