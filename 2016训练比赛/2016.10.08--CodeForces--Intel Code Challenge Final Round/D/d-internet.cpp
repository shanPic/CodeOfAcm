#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	string news = "";
	int i = -1;
	int mx = -1;
	while (i + n < s.size())
	{
		int m = i + n;
		for (int j = m; j > i; j--)
			if (s[j] < s[m])
				m = j;
		i = m;
		news += s[i];
	}
	sort(news.begin(), news.end());

	string m = "";
	for (int i = news.size() - 1; news[i] == news[news.size() - 1]; i--)
		m += news[i];
	for (int i = 0; i < s.size(); i++)
		if (s[i] < m[0])
			m += s[i];
	sort(m.begin(), m.end());
	cout << m;
}
