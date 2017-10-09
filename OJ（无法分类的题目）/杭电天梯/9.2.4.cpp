#include<iostream>
#include<stack>
#include<sstream>
#include<stdio.h>
using namespace std;
//	MAX( == -1
//  ) == -2
//	+ == -3
//	, == -4
struct node
{
	int x;
	int n;
	node(int xx, int nn)
	{
		x = xx; n = nn;
	}
	node() {};
};
stack<node> a;
node input(stringstream& ss)
{
	int x;
	node tmp;
	int flag = 0;
	int res = 0;
	while (cin >> x&&x != -4 && x != -2) {
		if (x != -3 && x != -2) {
			res += x;
		}
		if (x == -3) {
			flag++;
		}
	}
	tmp.x = res;
	tmp.n = flag;
	return tmp;
}
void init()
{
	while (!a.empty()) {
		a.pop();
	}
}
int main()
{
	freopen("data.in","r",stdin);
	int n;
	cin >> n;
	while (n--) {
		init();//stack 初始化
		string str;
		str = str + " ";
		cin >> str;
		for (auto ite = str.begin(); ite != str.end(); ite++) {
			if (isalpha(*ite)) {
				ite = str.erase(ite, ite + 4);
				str.insert(ite - str.begin(), " -1 ");
				//ite+=4;
				ite += 3;
				if (isdigit(*(ite + 1))) {
					ite++;
					str.insert(ite - str.begin(), " -11 ");
					ite += 4;
				}
			}
			else if (*ite == ')') {
				ite = str.erase(ite);
				str.insert(ite - str.begin(), " -2 ");
				//ite+=4;   最后还需要ite++
				ite += 3;
			}
			else if (*ite == '+') {
				ite = str.erase(ite);
				str.insert(ite - str.begin(), " -3 ");
				ite += 3;
			}
			else if (*ite == ',') {
				ite = str.erase(ite);
				str.insert(ite - str.begin(), " -4 ");
				ite += 3;
			}
		}
		stringstream ss(str);
		int tmp;
		while (cin >> tmp) {
			switch (tmp) {
			case -11: {node t = input(ss); a.push(t); t = input(ss); a.push(t); break; }
			case -2: {node t1 = a.top(); a.pop(); node t2 = a.top(); a.pop();
				node t3;
				if (t1.x >= t2.x) {
					t3.x = t1.x; t3.n = t1.n * 2;
				}
				else {
					t3.x = t2.x; t3.n = t2.n * 2;
				}
				a.push(t3);
				break; }
			case -3: {node t(-3, 0); a.push(t); break; }
			case -4:break;
			case -1:break;
			}
		}
		int res1 = 0, res2 = 0;
		node t;
		while (!a.empty()) {
			t = a.top(); a.pop();
			if (t.x != -3) {
				res1 += t.x;
				res2 += t.n;
			}
		}
		cout << res1 << " " << res2 << endl;
	}
}
