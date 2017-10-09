#include<iostream>
#include<string.h>
using namespace std;
/*************************字典树模版*************************/
const int maxnode=10000000,sigma_size=26;
int num;//节点总数
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
				val[num]=0;						//中间节点的值应为0
				c[u][id]=num++;
			}
			u=c[u][id];	//一层层地向下查找
		}
		val[u]=v;							//最后一个节点的值为v
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
/*************************字典树模版*************************/
int main()
{

}
