#include<bits/stdc++.h>
using namespace std;
const int maxnod=100000;
const int sigma_size=26;
const int maxn=100000;
int nod[maxnod+9][sigma_size],f[maxn*30+9],val[maxn*30+9],last[maxn*30+9];
int sz,yes;
char ans[maxn+9];
void init(){
    sz=1;
    memset(nod[0],0,sizeof(nod[0]));
    val[0]=0;
    f[0]=last[0]=0;
}
void insert(char *s,int nu){
    int len=strlen(s);
    int rt=0;
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(nod[rt][id]==0){
            memset(nod[sz],0,sizeof(nod[sz]));
            nod[rt][id]=sz;
            val[sz++]=0;
        }
        rt=nod[rt][id];
    }
    val[rt]++;
}
void getfail(){
    queue<int>q;
    f[0]=0;
    for(int i=0;i<sigma_size;i++){
        int u=nod[0][i];
        if(u) {f[u]=0;q.push(u);last[u]=0;}
    }
    while(!q.empty()){
        int r=q.front();q.pop();
        for(int i=0;i<sigma_size;i++){
            int u=nod[r][i];
            if(!u) continue;
            q.push(u);
            int v=f[r];
            while(v&&!nod[v][i]) v=f[v];
            f[u]=nod[v][i];
            val[u]+=val[f[u]];
            val[f[u]]=0;
            last[u]=(val[f[u]]?f[u]:last[f[u]]);
        }
    }
}
void dfs(int rt,int sum,int n,int cnt)
{
    if(yes) return;
    int flag=0;
    for(int i=0;i<26;i++){
        int y=nod[rt][i];
        if(y==0) continue;
        ans[cnt+1]='a'+i;
        dfs(y,sum+val[y],n,cnt+1);
        if(yes) return;
    }
    if(flag==0){
        //cout<<sum<<" "<<key[rt]<<endl;
        if(sum==n){

            yes=1;
        }
    }
}
const int MAXS = 60*1024*1024;

char buf[MAXS];

int main()
{
	freopen("data.in","r",stdin);
	int len = fread(buf,1,MAXS,stdin);
	buf[len] = '\0';
    int n,cas;
    char s[maxn];
	int num=0;
    sscanf(buf+num,"%d",&cas);
	num+=sizeof(cas);
    while(cas--){
        init();
        sscanf(buf+num,"%d",&n);
		num+=sizeof(n);
        for(int i=1;i<=n;i++){
			sscanf(buf+num,"%s",s);
			num+=strlen(s)+1;
            insert(s,i);
        }
        getfail();
        yes=0;
		memset(ans,'\0',sizeof(ans));
        dfs(0,0,n,0);
        if(yes==0) puts("No");
		else printf("%s\n",ans+1);
    }
    return 0;
}

