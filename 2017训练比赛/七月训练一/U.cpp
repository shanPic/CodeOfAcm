/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练一\U.cpp
* @Author: Pic
* @Date:   2017-07-06 19:08:30
* @Last Modified time: 2017-07-06 20:02:34
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000+30;
struct Trie
{
	int next[500010][26], fail[500010], end[500010];
	int root, L;//L为Trie中的字符串个数
	int newnode()
	{
		for (int i = 0; i < 26; i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L - 1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++)
		{
			if (next[now][buf[i] - 'a'] == -1)
				next[now][buf[i] - 'a'] = newnode();
			now = next[now][buf[i] - 'a'];
		}
		end[now]++;
	}
	void build()
	{
		queue<int>Q;
		fail[root] = root;
		for (int i = 0; i < 26; i++)
			if (next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		while ( !Q.empty() )
		{
			int now = Q.front();
			Q.pop();
			for (int i = 0; i < 26; i++)
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
		}
	}
	int query(char buf[])
	{
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for (int i = 0; i < len; i++)
		{
			now = next[now][buf[i] - 'a'];
			int temp = now;
			while ( temp != root )
			{
				res += end[temp];
				end[temp] = 0;
				temp = fail[temp];
			}
		}
		return res;
	}
	void debug()
	{
		for (int i = 0; i < L; i++)
		{
			printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
			for (int j = 0; j < 26; j++)
				printf("%2d", next[i][j]);
			printf("]\n");
		}
	}
};
Trie ac;
char str[50];
char buf[MAXN];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		ac.init();
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s\n",str);
			ac.insert(str);
		}
		ac.build();
		scanf("%s",buf);
		//cout<<buf<<endl;
		printf("%d\n",ac.query(buf));
	}
}	