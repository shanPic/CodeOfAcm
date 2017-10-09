#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+30;
const int MAX=MAXN/2;
int a[MAXN];
bool vis[MAXN];
struct node
{
    int id,val;
    node(){};
    node(int _id,int _val):id(_id),val(_val){};
};
int nowN;
//int res[MAXN][MAXN];
vector< vector<int> > res;
int cnt;
int n;
void BFS(int id)
{
    cnt=1;
    vector<int> v;
    v.reserve(MAX);
    node tmp;
    queue<node> q;
    q.push(node(id,a[id]));
    vis[id]=1;
    //res[nowN][cnt++]=id+1;
    v.push_back(id+1);
    int num=0;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        num=0;
        for(int i=tmp.id+1;i<n;i++){
            if(a[i]>=tmp.val&&!vis[i]){
                num++;
                vis[i]=1;
                //res[nowN][cnt++]=i+1;
                v.push_back(i+1);
                q.push(node(i,a[i]));
            }
            if(num==2) break;
        }
    }
    //res[nowN][0]=cnt;
    res.push_back(v);
    //nowN++;
}
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        res.clear();
        res.reserve(MAXN);
        nowN=0;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int s=0;
        while(s<=n-1){
            BFS(s);
            while(vis[s]){
                s++;
            }
        }
//        printf("%d\n",nowN);
//        int r=0;
//        for(int i=0;i<nowN;i++){
//            r=res[i][0];
//            printf("%d ",r-1);
//            for(int j=1;j<r;j++){
//                printf("%d",res[i][j]);
//                if(j!=r) printf(" ");
//            }
//            printf("\n");
//        }
        int r=res.size();
        int r2;
        printf("%d\n",r);
        for(int i=0;i<r;i++){
            r2=res[i].size();
            printf("%d ",r2);
            for(int j=0;j<r2;j++){
                printf("%d",res[i][j]);
                if(j!=r2-1) printf(" ");
            }
            printf("\n");
        }
    }
}
