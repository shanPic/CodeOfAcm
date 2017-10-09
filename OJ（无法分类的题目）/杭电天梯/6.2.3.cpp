#include<cstdio>
#include<iostream>
#include<stdlib.h>
#define INF 0x7ffffff
#define MAXN 200010
using namespace std;
const double eps=1e-10;
struct node
{
    int x;
    int value;
    int next;
};
node e[60000];int st[1505];     //�洢ͼԭʼ���ݣ�ʹ�õ����ڽӱ���ʽ������ģ�⣩
int visited[1505];              //��ǽڵ�����������еĸ���
int dis[1505];                  //�洢·��
int qu[1000];                //ʹ������ģ�����
int main()
{
    int n,m,u,v,w,start,en,h,r,cur;
    freopen("data.in","r",stdin);
    //freopen("c.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<=1500; i++)
        {
            visited[i]=0;
            dis[i]=-1;//!
            st[i]=-1;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d\n",&u,&v,&w);
            e[i].x=v;
            e[i].value=w;
            e[i].next=st[u];
            st[u]=i;
        }
        //scanf("%d%d",&start,&en);
        start=m;
        visited[start]=1;
        dis[start]=0;
        h=0;
        r=1;
        qu[r]=start;
        while(h!=r)
        {
            h=(h+1)%1000;       //��ֹ����Խ��
            cur=qu[h];
            int tmp=st[cur];
            visited[cur]=0;
            while(tmp!=-1)
            {
                if (dis[e[tmp].x]>dis[cur]+e[tmp].value||dis[e[tmp].x]==-1)
                {
                    dis[e[tmp].x]=dis[cur]+e[tmp].value;//�ɳڲ���
                    if(visited[e[tmp].x]==0)
                    {
                        visited[e[tmp].x]=1;
                        r=(r+1)%1000;       //��ֹ����Խ��
                        qu [r]=e[tmp].x;
                    }
                }
                tmp=e[tmp].next;        //ʹ�õ�������ģ����ڽӱ�
            }
        }
        printf("%d\n",dis[en]);
    }
}
