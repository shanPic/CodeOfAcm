#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
  
int res;  
int need[25];  
  
struct node  
{  
    int val;  
    int num;  
}nod[25];  
  
int cmp(node p1,node p2)  
{  
    if(p1.val>=p2.val) return 1;  
    return 0;  
}  
  
int main()  
{  
	freopen("data.in","r",stdin);
    int n,money,i,j,t,tmp;  
    while(cin>>n>>money)  
    {  
        for(i=0;i<n;i++)  
            scanf("%d%d",&nod[i].val,&nod[i].num);  
        sort(nod,nod+n,cmp);  //面额从大到小排序  
  
        int res=0;  
        for(i=0;i<n;i++)      //第一阶段，取>=money面额的  
        {  
            if(nod[i].val<money) break;  
            res+=nod[i].num;  
        }  
        t=i;  
  
        while(1)  
        {  
            memset(need,0,sizeof(need));  
            int rest=money;         //还需要多少  
            for(i=t;i<n;i++)    //尽可能用大面值凑够,如果刚好放下就用大面额，不够用小面额凑  
            {  
                if(!nod[i].num||!rest)  
                    continue;  
                tmp=rest/nod[i].val;  
                tmp=min(nod[i].num,tmp);  
                need[i]=tmp;  
                rest-=need[i]*nod[i].val;  
            }  
  
            if(rest)    //需要小面额凑  
            {  
                for(i=n-1;i>=t;i--)  
                    if(nod[i].val>=rest&&(nod[i].num-need[i]))  
                    {  
                        need[i]++;  
                        rest=0;  
                        break;  
                    }  
                if(rest)    break;  
            }  
  
            int ans=1e9;  
            for(i=t;i<n;i++)  
                if(need[i])  
                    ans=min(ans,nod[i].num/need[i]);   //最多放多少组一样的  
            res+=ans;  
  
            for(i=t;i<n;i++)  
                nod[i].num-=ans*need[i];  
        }  
        cout<<res<<endl;  
    }  
    return 0;  
}  
  
/* 
3 50 
40 1 
20 1 
10 4 
 
4 42 
40 1 
20 1 
10 6 
5 3 
*/  