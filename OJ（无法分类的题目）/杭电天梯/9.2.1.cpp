#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m){
        printf("+");
        for(int i=0;i<n;i++) printf("-");
        printf("+\n");
        for(int i=0; i<m; i++)
        {
            printf("|");
            for(int i=0; i<n; i++) printf(" ");
            printf("|\n");
        }
        printf("+");
        for(int i=0;i<n;i++) printf("-");
        printf("+\n");
        printf("\n");
    }
}
