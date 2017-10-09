#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000+100;
int head[MAXN];
struct  edge
{
	int x,y;
	int next;
};
edge e[MAXN];
int ptr=1;
void addedge(int x,int y)
{
	e[ptr].next=head[x];
	head[x]=ptr;
	e[ptr].x=x,e[ptr].y=y;
	ptr++;
}
int s[MAXN],top=0;
bool instack[MAXN],vis[MAXN];
int DFN[MAXN],LOW[MAXN];
int index=1;
void init()
{
	top=0;
	index=1;
	memset(instack,0,sizeof(instack));
	memset(DFN,0,sizeof(DFN));
	memset(LOW,0,sizeof(LOW));
}
void tarjan(int x)
{
	vis[x]=1;
	s[top++]=x;
	DFN[x]=index,LOW[x]=index;
	index++;
	int tmp=head[x];
	while(tmp!=0){
		if(!vis[r[tmp.y]]){
			tarjan(e[tmp].y);
			//LOW[x]=min(LOW[x],LOW[tmp]);
		}
		else{
			if(instack[tmp]){
				LOW[x]=min(LOW[x],LOW[tmp]);
			}
		}
		tmp=e[tmp].next;
	}
	if(DFN[x]==LOW[x]){
		while(s[])
	}
}
int main()
{

}