#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int dist[MAX][MAX];
int tax[MAX];
int suffix[MAX][MAX];
int n;

void Floyd()
{
    int i,j,k;
    for (i=0; i < n; ++i)
        for (j=0; j < n; ++j)
            suffix[i][j] = j;    //记录"i->k-....->j"的后继k,也可以记录前趋，这里后继更好，因为要找最小字典序
    for (k=0; k < n; ++k)
    {
        for (i=0; i < n; ++i)
        {
            for (j=0; j < n; ++j)
            {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                {
                    if (dist[i][k]+dist[k][j]+tax[k] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k]+dist[k][j]+tax[k];
                        suffix[i][j] = suffix[i][k];
                    }
                    else if (dist[i][k]+dist[k][j]+tax[k] == dist[i][j] && suffix[i][k] < suffix[i][j])//路径相等，找最小字典序
                        suffix[i][j] = suffix[i][k];
                }
            }
        }
    }
}
void print(int s,int v)
{
    cout << "-->" << suffix[s][v]+1;
    if (suffix[s][v] != v)
        print(suffix[s][v],v);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
#endif

    int i,j,s,v;
    while(cin >> n && n != 0)
    {
        for( i = 0; i < n; ++i )
        {
            for ( j = 0; j < n; ++j )
            {
                cin >> dist[i][j];
                if (dist[i][j] == -1)
                    dist[i][j] = INT_MAX;
            }
        }
        for (i = 0; i < n; ++i)
            cin >> tax[i];

        Floyd();
        while (cin >> s >> v && !(s==-1&&v==-1))
        {
            printf("From %d to %d :\n",s,v,s);
            printf("Path: %d",s);
            if (s != v)
                print(s-1,v-1);
            printf("\nTotal cost : %d\n\n",dist[s-1][v-1]);
        }
    }
    return 0;
}
