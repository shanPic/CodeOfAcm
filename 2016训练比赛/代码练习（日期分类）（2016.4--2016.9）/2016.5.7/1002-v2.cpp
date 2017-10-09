#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[1000],s2[1000];
int dp[1000][1000];
int len1,len2;
void LCS()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i = 1; i<=len1; i++)
    {
        for(j = 1; j<=len2; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        LCS();
        printf("%d\n",dp[len1][len2]);
    }

    return 0;
}