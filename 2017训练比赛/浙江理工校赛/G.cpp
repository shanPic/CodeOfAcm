#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=500030;
const int MAXN2=100030;
vector<int> order[MAXN2];
int vis[100030];
int que[MAXN];
int now[MAXN2];
int len;
int main()
{
    int cnt=0;
    freopen("data.in","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        //init();
        len=0;
        for(int i=0;i<MAXN2;i++) order[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d",&que[i]);
            order[que[i]].push_back(i);
        }
        int i;
        int maxn,nowid;
        int xh;
        for( i=0;i<n;i++){
            if(!vis[que[i]]&&len<m){
                now[len++]=que[i];
                vis[que[i]]=1;
                cout<<"#"<<++cnt<<" "<<"push "<<que[i]<<endl;
            }
            else if(len>=m&&vis[que[i]]==0){
                maxn=-1;//最靠后的位置
                nowid=0;//最靠后的位置的元素在now
                int flag=0;
                for(int j=0;j<len;j++){
                    flag=0;
                    for(auto ite=order[now[j]].begin();ite!=order[now[j]].end();ite++){
                        if((*ite)>i){
                            flag=1;
                            if(maxn<(*ite)){
                                maxn=(*ite);
                                xh=now[j];
                                nowid=j;
                            }
                            break;
                        }
                    }
                    if(flag==0){
                        if(now[j]>xh){
                            xh=now[j];
                            nowid=j;
                        }
                    }
                }
                cout<<"#"<<++cnt<<" ";
                cout<<"pop "<<now[nowid]<<"\t";
                vis[now[nowid]]=0;
                cout<<"push "<<que[i]<<endl;
                now[nowid]=que[i];
                vis[now[nowid]]=1;
            }
            else{
                cout<<"#"<<++cnt<<endl;
            }
        }
        for(int i=0;i<len;i++){
            printf("%d ",now[i]);
        }
        printf("\n");
    }
}
