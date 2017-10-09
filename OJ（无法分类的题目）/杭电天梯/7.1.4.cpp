#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
using namespace std;
const int MAXN = 150;
const int INF=0x3f3f3f3f;
struct node
{
	int x, y;
}a[MAXN];
stack<node> G;
node zero;
double _X(node &p1, node &p2, node &p3)
{
	return (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
}
double _X2(node &p1, node &p2, node &p3)
{
	return (p2.x - p1.x)*(p3.y - p2.y) - (p2.y - p1.y)*(p3.x - p2.x);
}
bool cmp(node &a, node &b)//a>b返回0,a<b 返回1
{
	if (a.y <= 0 && b.y>0)
		return 1;
	if (a.y>0 && b.y <= 0)
		return 0;
	if (_X(zero, a, b)>0)
		return 1;
	return 0;
    //return atan2(a.y-zero.y,a.x-zero.x)<atan2(b.y-zero.y,b.x-zero.x);
}
bool Ok(node & x)
{
	node tmp1 = G.top();
	G.pop();
	node tmp2 = G.top();
	if (_X2(tmp2, tmp1, x) > 0) {
		G.push(tmp1);
		return 1;
	}
	else {
		G.push(tmp1);
		return 0;
	}
}
int n;
void Graham()
{
	sort(a, a + n, cmp);
	zero = a[0];
	//cout<<a[0].x<<" "<<a[0].y<<endl;
	//cout<<a[n-1].x<<" "<<a[n-1].y<<endl;
	G.push(a[0]);
	G.push(a[1]);
	for (int i = 2; i<n; i++) {
		//cout << "--------------" << endl;
		while (!Ok(a[i])) {
			G.pop();
		}
		//cout << "11111111111" << endl;
		G.push(a[i]);
	}
}
void init()
{
	while (!G.empty()) {
		G.pop();
	}
}
double dis(node &a, node &b)
{
	return sqrt((b.y - a.y)*(b.y - a.y) + (b.x - a.x)*(b.x - a.x));
}
int main()
{
	//freopen("data.in", "r", stdin);
	while (cin >> n&&n != 0) {
		init();
		zero.y=INF;
		for (int i = 0; i<n; i++) {
			cin >> a[i].x >> a[i].y;
			if(a[i].y<zero.y){
                zero.x=a[i].x;
                zero.y=a[i].y;
			}
		}
		Graham();
		double res = 0;
		node tmp;
		node pre = zero;
		while (!G.empty()) {
			tmp = G.top();
			//cout<<tmp.x<<"\t"<<tmp.y<<endl;
			G.pop();
			res += (dis(pre, tmp));
			pre = tmp;
		}
		res+=dis(tmp,zero);
		res += 0.005;
		printf("%.2lf\n", res);
	}
}
