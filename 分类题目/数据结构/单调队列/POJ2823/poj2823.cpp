#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int M = 1e6+100;
const int inf = 0x3f3f3f3f;
int val[M], qmax[M], qmin[M];
int n, k;
int head1, tail1, head2, tail2;
void Min()
{
	for (int i = 0; i<k-1; i++){
        //cout<<11111111111<<endl;
		while (head1 <= tail1&&val[qmin[tail1]] >= val[i])
			tail1--;
		tail1++;
		qmin[tail1] = i;
	}//初始将前k个元素放入单调队列中
	//printf("%d ", val[qmin[head1]]);//打印第一个窗口的最小值
	for (int i = k-1; i<n; i++){
	    //cout<<222222222<<endl;
		while (head1 <= tail1&&val[qmin[tail1]] >= val[i])
			tail1--;
		tail1++;
		qmin[tail1] = i;
		while (qmin[head1]<i - k+1)
			head1++;
		printf("%d ", val[qmin[head1]]);
	}
	cout << endl;
}
void Max()
{
	for (int i = 0; i<k-1; i++){
        //cout<<323333333<<endl;
		while (head2 <= tail2&&val[qmax[tail2]] <= val[i])
			tail2--;
		tail2++;
		qmax[tail2] = i;
	}
	//printf("%d ", val[qmax[head2]]);
	for (int i = k-1; i<n; i++){
        //cout<<44444444<<endl;
		while (head2 <= tail2&&val[qmax[tail2]] <= val[i])
			tail2--;
		tail2++;
		qmax[tail2] = i;
		while (head2 <= tail2&&qmax[head2]<i - k+1)
			head2++;
		printf("%d ", val[qmax[head2]]);
	}
	cout << endl;
}
int main()
{
	freopen("data.in", "r", stdin);
	while (cin >> n >> k){
		for (int i = 0; i<n + 10; i++){
			qmin[i] = 0;
			qmax[i] = 0;
		}
		for (int i = 0; i<n; i++){
			scanf("%d ", &val[i]);
		}
		head1 = head2 = 0;
		tail1 = tail2 = -1;
		Min();
		Max();
	}
}
