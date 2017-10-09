#include<bits/stdc++.h>
using namespace std;
const int maxnode=40000*100+100,sigma_size=26;
int num;//节点总数
char dig[10][4]={{0,0,0,0},{0,0,0,0},'a','b','c',0,'d','e','f',0,'g','h','i',0,'j','k','l',0,'m','n','o',0,'p','q','r','s','t','u','v',0,'w','x','y','z'};
struct Trie
{
	int c[maxnode][sigma_size];
	int val[maxnode];
	Trie() {
		num=1;
		memset(c[0],0,sizeof(c[0]));
	}
	int ids(char ch) {
		return ch-'a';
	}
	void insert(string s,int v)
	{
		int id;
		int u=0;
		for(int i=0;i<s.size();i++){
			id=ids(s[i]);
			if(!c[u][id]){
				memset(c[num],0,sizeof(c[num]));//!!新建一个节点时,一定要注意初始化
				//val[num]=0;						//中间节点的值应为0
				c[u][id]=num;
			}
			val[num]+=v;
			u=c[u][id];
			num++;
		}
		val[u]+=v;							//最后一个节点的值为v
	}
	int query(string s)
	{
		int u=0;
		int id;
		for(int i=0;i<s.size();i++){
            id=ids(s[i]);
			if(c[u][id]==0){
				return 0;
			}
			u=c[u][id];
		}
		return val[u];
	}
};
Trie tr;
int qu[110];
int len;
string resstr;
int resval=-1;
int DFS(int n,string str)
{
	if(n>len){
		int tmp=tr.query(str);
		if(tmp>resval&&tmp!=0){
            resstr=str;
			resval=tmp;
			return 1;
		}
		if(tmp==0) return 0;
		return 1;
	}
	string res=str;
	int flag=0;
	for(int i=0;i<4;i++){
		if(dig[qu[n]][i]!=0){
			str+=dig[qu[n]][i];
			if(DFS(n+1,str)!=0){
				flag=1;
			}
			str.erase(n);
		}
	}
	if(flag) return 1;
	else return 0;
}
int main()
{
    //freopen("data.in","r",stdin);
	int t,n;
	cin>>t;
	int tt=1;
	while(t--){
        printf("Scenario #%d:\n",tt++);
        memset(tr.c,0,sizeof(tr.c));
        memset(tr.val,0,sizeof(tr.val));
		cin>>n;
		int v;
		string str;
		for(int i=0;i<n;i++){
			cin>>str>>v;
			tr.insert(str,v);
		}
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
            getchar();
            char ch;
            len=0;
            int flag=0;
            while((ch=getchar())&&ch!='1'){
                //cout<<111111111<<endl;
                if(flag){
                    cout<<"MANUALLY"<<endl;
                    continue;
                }
                qu[len]=ch-'0';
                resval=-1;
                if(DFS(0,"")==0){
                    cout<<"MANUALLY"<<endl;
                    flag=1;
                    continue;
                }
                cout<<resstr<<endl;
                len++;
            }
            cout<<endl;
		}
	}
}
