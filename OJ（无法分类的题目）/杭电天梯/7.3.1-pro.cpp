#include <cstdio>
#include <cstring>
#define M 8005

int vis[M];//标记可以组合的数；

int main()
{
    int num_1,num_2,num_5;
    while(true)
    {
        scanf("%d %d %d",&num_1,&num_2,&num_5);
        if(num_1 + num_2 + num_5 == 0) break;
        memset(vis,0,sizeof(vis));
        for(int i = 0; i <= num_1; i++)
            vis[i] = 1;
        for(int j = 0; j <= num_2 * 2; j += 2)
        {
            for(int k = 0; k <= num_1; k++)
            {
                vis[j + k] = 1;
            }
        }
        for(int j = 0; j <= num_5 * 5; j += 5)
        {
            for(int k = 0; k <= num_1 + num_2 * 2; k++)
            {
                if(vis[k]) //如果当前数可以组合，则加上；
                {
                    vis[k + j] = 1;
                }
            }
        }
        int i;
        for(i = 1; i <= num_1 + num_2 * 2 + num_5 * 5; i++)
        {
            if(vis[i] == 0)
            {
                break;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}
