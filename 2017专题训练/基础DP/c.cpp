/*
先将一个方块拓展为3个方块，然后对x排序，再对y求最大上升子序列
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300;
struct node
{
    int x, y, z;
};
node block[MAXN];
bool cmp(node a, node b)
{
    return a.x >= b.x;
}
int dp[MAXN];
int main()
{
    freopen("data.in", "r", stdin);
    int n;
    int cou = 0;
    while (cin >> n && n) {
        int x, y, z;
        for (int j = 0; j < n; j++) {
            cin >> x >> y >> z;
            int i = j * 6 + 1;
            block[i].x = x, block[i].y = y, block[i].z = z;
            block[i + 1].x = y, block[i + 1].y = x, block[i + 1].z = z;
            block[i + 2].x = z, block[i + 2].y = x, block[i + 2].z = y;
            block[i + 3].x = x, block[i + 3].y = z, block[i + 3].z = y;
            block[i + 4].x = y, block[i + 4].y = z, block[i + 4].z = x;
            block[i + 5].x = z, block[i + 5].y = y, block[i + 5].z = x;
        }
        n = n * 6;
        sort(block + 1, block + n + 1, cmp);
        memset(dp, 0, sizeof(dp));
        int res = -1;
        dp[1] = block[1].z;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (block[i].y < block[j].y && block[i].x < block[j].x) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += block[i].z;
            res = max(res, dp[i]);
        }
        printf("Case %d: maximum height = %d\n", ++cou, res);
    }
}
