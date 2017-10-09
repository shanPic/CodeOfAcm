#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
class SortingGame
{
public:
	bool ok(vector<int> &vec, int n)
	{
		if (n == 1) {
			return 1;
		}
		//int f=vec[0];
		//int flag=1;
		for (int i = 1; i<n; i++) {
			if (vec[i]<vec[i - 1]) {
				return 0;
			}
		}
		return 1;
	}
	int fewestMoves(vector <int> board, int k)
	{
		int roud = board.size();
		queue<vector<int>> q;
		queue<int> cnt;
		q.push(board); cnt.push(0);
		int tot = 0;
		while (!q.empty()&&tot<99999) {
			tot++;
			vector<int> vec = q.front();
			if (ok(vec, roud)) {
				return cnt.front();
			}
			q.pop();
			int num = cnt.front(); cnt.pop();
			for (int i = 0; i <= roud - k; i++) {
				std::vector<int> v = vec;
				reverse(v.begin() + i, v.begin() + i + k + 1);
				q.push(v); cnt.push(num + 1);
			}
		}
		return -1;
	}
};
int main()
{

}