#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 100
int res;
void LCSLength(string x, string y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;

    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
}

void PrintLCS(int b[][MAXLEN], string x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        PrintLCS(b, x, i-1, j-1);
        res++;
    }
    else if(b[i][j] == 1)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}

int main()
{
    freopen("data.in","r",stdin);
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    char x[MAXLEN];
    char y[MAXLEN];
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];
    int m, n;
    int t;
    char tem;
    cin>>t;
    while(t--){
        res=0;
        cin>>m>>n;
        for(int i=0;i<m;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        LCSLength(x, y, m, n, c, b);
        PrintLCS(b, x, m, n);
        cout<<res<<endl;
    }
    return 0;
}
