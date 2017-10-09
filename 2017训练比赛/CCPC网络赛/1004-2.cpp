/*
* @FileName: D:\代码与算法\2017训练比赛\CCPC网络赛\1004-2.cpp
* @Author: Pic
* @Date:   2017-08-19 15:13:38
* @Last Modified time: 2017-08-19 15:26:17
*/
#include <bits/stdc++.h>
using namespace std;
const int maxnode=100000+100;
const int sigma_size=128;
struct AC_Automata
{
    int ch[maxnode][sigma_size];
    int val[maxnode];   /// 每个字符串的结尾结点都有一个非0的val
    int f[maxnode];     /// fail函数
    int last[maxnode];  /// last[i]=j表j节点表示的单词是i节点单词的后缀，且j节点是单词节点
    int sz;

    ///初始化0号根节点的相关信息
    inline void init()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        val[0]=f[0]=last[0]=0;
    }

    ///Insert负责构造ch与val数组
    ///插入字符串,v必须非0表示一个单词节点
    inline void Insert(char *s,int v)
    {
        int n=strlen(s),u=0;
        for(int i=0; i<n; i++)
        {
            int id=s[i];
            if(ch[u][id]==0)
            {
                ch[u][id]=sz;
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz++]=0;
            }
            u=ch[u][id];
			val[u]=1;
        }
    }
    ///递归打印与结点i后缀相同的前缀节点编号
    ///进入此函数前需保证val[i]>0
    inline void print(int i,set<int>&st)
    {
        if(val[i])
        {
            //printf("%d\n",val[i]);
            if(st.find(i)==st.end())st.insert(val[i]);
            print(last[i],st);
        }
    }

    /// 在s中找出 出现了哪几个模板单词
    inline void Find(char *s,set<int>&st)
    {
        int n=strlen(s),j=0;
        for(int i=0; i<n; i++)
        {
            int id=s[i];
            while(j && ch[j][id]==0) j=f[j];
            j=ch[j][id];
            if(val[j]) print(j,st);
            else if(last[j]) print(last[j],st);
        }
    }

    ///getFail函数负责构造f和last数组
    inline void getFail()
    {
        queue<int> q;
        last[0]=f[0]=0;
        for(int i=0; i<sigma_size; i++)
        {
            int u=ch[0][i];
            if(u)
            {
                f[u]=last[u]=0;
                q.push(u);
            }
        }

        while(!q.empty())/// 按BFS顺序计算fail
        {
            int r=q.front(); q.pop();
            for(int i=0; i<sigma_size; i++)
            {
                int u=ch[r][i];
                if(u==0)continue;
                q.push(u);
                int v=f[r];
                while(v && ch[v][i]==0) v=f[v];
                f[u]= ch[v][i];
                last[u] =  val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
};
AC_Automata ac;
char word[200+10];
char text[10000+10];
set<int>::iterator it;
int main()
{
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	 getchar();
	while(t--){
		init();
		int len1=-1,len2=-1;
		char ch;
		while((ch=getchar())&&ch!='\n'){
			s1[++len1]=ch;
		}
		++len1;
		s1[len1]='\0';
		reverse(s1,s1+len1);
		while((ch=getchar())&&ch!='\n'){
			s2[++len2]=ch;
		}
		++len2;
		s2[len2]='\0';
		reverse[s2,s2+len2];
		ac.insert(s2,1);
		ac.getFail();
		printf("%d\n",sum);
	}
}
