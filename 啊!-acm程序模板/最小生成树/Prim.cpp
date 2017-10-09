/*
Prim算法是一种贪心策略
维护两个集合，Vnew与Vold ，若一个点的标号为Vnew，表示其已经加入到生成的最小生成树中
1. 任取一个点加入至最小生成树中
2. 每次选择一个点在最小生成树中，一个点不在最小生成树中的边 且 权值最小 的边的未加入最小生成树的点 加入最小生成树
3. 重复第二步，直至全部点加入最小生成树种
*/
/*
设G=(V,E)是连通带权图，V= {1,2,…,n}。
        构造G的最小生成树的Prim算法的基本思想是：首先置S= {1}，然后，只要S是V的真子集，就作如下的贪心选择：
    选取满足条件iS，jV-S，且c[i][j]最小的边，将顶点j添加到S中。这个过程一直进行到S=V时为止。
在这个过程中选取到的所有边恰好构成G的一棵最小生成树。
*/
/*
以下的写法是维护一个lowval数组，
*/
int lowval[MAXN];//存储的是未
int vnew[MAXN];  //记录某点是否加入了vnew
int sum=0;       //最小生成树的权值之和
void Prim(int start)
{
    int j,mi;
    for(int i=1;i<=n;i++){
        if(i!=start){
            lowval[i]=G[start][i];
            vnew[i]=0;
        }
    }
    vnew[start]=1;
    for(int i=1;i<=n-1;i++){
        j=-1;
        mi=INF;
        for(int i=1;i<=n;i++){
            if(vnew[i]==0&&lowval[i]<mi){
                j=i;
                mi=lowval[i];
            }
        }
            vnew[j]=1;
            sum+=lowval[j];
            for(int i=1;i<=n;i++){
                if(vnew[i]==0){
                    lowval[i]=min(lowval[i],G[j][i]);
            }
        }
    }
}
