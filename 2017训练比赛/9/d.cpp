/*
这个模板 字符串是从0开始的
nxt数组是从1开始的
*/
#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int N = 2*1e5+30;
int nxt[N];
int S[N], T[N];
int tmp[N];
int slen, tlen;

void getNext()
{
    int j, k;
    j = 0; k = -1; nxt[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            nxt[++j] = ++k;
        else
            k = nxt[k];

}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count()
{
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = nxt[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57)
		v = v*10+c-48, c = getchar();
	return v*f;
}
int main()
{

    slen=read();tlen=read();
    int mint=0x3f3f3f3f,mins=0x3f3f3f3f,maxs=-1,maxt=-1;
    int res=0;
    for(int i=0;i<slen;i++){
        //scanf("%d",&S[i]);
        S[i]=read();
        maxs=max(S[i],maxs);
        mins=min(S[i],mins);
    }
    for(int i=0;i<tlen;i++){
        //scanf("%d",&T[i]);
        T[i]=read();
        mint=min(T[i],mint);
        maxt=max(T[i],maxt);
    }
    //memcpy(tmp,T,sizeof(T));
    res+=KMP_Count();
    int round=abs(mins-mint);
    for(int i=1;i<=round;i++){
        for(int i=0;i<tlen;i++){
            T[i]--;
        }
        res+=KMP_Count();
    }
    for(int i=0;i<tlen;i++){
        T[i]+=round;
    }
    round=abs(maxs-maxt);
    for(int i=1;i<=round;i++){
        for(int i=0;i<tlen;i++){
            T[i]++;
        }
        res+=KMP_Count();
    }
    cout<<res<<endl;
    return 0;
}
