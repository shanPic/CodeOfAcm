//�˱�̲�������ģ�����ʵ��SPFA
//Ĭ���޸�Ȧ
#include<cstdio>
using namespace std;
struct node
{
    int x;
    int value;
    int next;
};
node e[60000];int st[1505];;      //�洢ͼԭʼ���ݣ�ʹ�õ����ڽӱ���ʽ������ģ�⣩
int visited[1505];//��ǽڵ�����������еĸ���
int dis[1505];  //�洢·��
int queue[1000];//ʹ������ģ�����
int main()
{
    int n,m,u,v,w,start,h,r,cur;
//    freopen("c.in","r",stdin);
//    freopen("c.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=1500; i++)
        {
            visited[i]=0;
            dis[i]=-1;
            st[i]=-1;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d\n",&u,&v,&w);
            e[i].x=v;
            e[i].value=w;
            e[i].next=st[u];
            st[u]=i;
        }
        start=1;
        visited[start]=1;
        dis[start]=0;
        h=0;
        r=1;
        queue[r]=start;
        while(h!=r)
        {
            h=(h+1)%1000;       //��ֹ����Խ��
            cur=queue[h];
            int tmp=st[cur];
            visited[cur]=0;
            while(tmp!=-1)
            {
                if (dis[e[tmp].x]<dis[cur]+e[tmp].value)
                {
                    dis[e[tmp].x]=dis[cur]+e[tmp].value;//�ɳڲ���
                    if(visited[e[tmp].x]==0)
                    {
                        visited[e[tmp].x]=1;
                        r=(r+1)%1000;       //��ֹ����Խ��
                        queue[r]=e[tmp].x;
                    }
                }
                tmp=e[tmp].next;        //ʹ�õ�������ģ����ڽӱ�
            }
        }
        printf("%d\n",dis[n]);
    }
    return 0;
}
