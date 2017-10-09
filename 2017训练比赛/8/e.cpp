#include<bits/stdc++.h>
using namespace std;
const int MAXN=1030;
struct edge
{
    int e;
    int nxt;
    edge():nxt(0){};
    edge(int e2,int nxt2):e(e2),nxt(nxt2){};
}e[MAXN*MAXN];
int head[MAXN];
int tot;
int deg[MAXN];
	int n;
void add(int b,int ee)
{
	e[tot]=edge(ee,head[b]);
	head[b]=tot++;
}
std::vector<int> res;
int non[MAXN];
bool topo()
{
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=2*n;i++){ //!注意是2*n
		if(deg[i]==0){
			q.push(i);
			//res.push_back(i);
			//cout<<"push "<<i<<endl;
			non[i]=1;
		}
	}
	int t;
	int now;
	while(!q.empty()){
		t=q.top();
		q.pop();
		res.push_back(t);
		for(int i=head[t];i!=0;i=e[i].nxt){
			now=e[i].e;
			deg[now]--;
			if(!deg[now]){
				q.push(now);
			}
		}
	}
	//cout<<"size "<<res.size()<<endl;
	return res.size()==n*2;//!注意是2*n
}
void init(){
	memset(head,0,sizeof(head));
	memset(deg,0,sizeof(deg));
	tot=1;
	res.clear();
	memset(non,0,sizeof(non));
}
int main()
{
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	char ch;
	while(t--){
		init();
		scanf("%d",&n);
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ch=getchar();
				if(ch=='X'){
					add(j,i+n);deg[i+n]++;
				}
				else{
					add(i+n,j);deg[j]++;
				}
			}
			getchar();
		}
		if(!topo()){
			printf("No solution\n");
		}
		else{
			int now=0;
			int len=res.size();
			for(int i=0;i<len;i++){
				now=res[i];
				if(non[now]) continue;
				else{
					printf("%c%d%c",now>n?'R':'C',now>n?now-n:now,i==len-1?'\n':' ');
				}
			}
			//printf("\n");
		}
	}	
}
