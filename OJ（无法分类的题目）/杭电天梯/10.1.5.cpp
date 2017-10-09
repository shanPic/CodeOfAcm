#include<bits/stdc++>
using namespace std;
cosnt int MAXN=10000+100;
int DFN[MAXN],LOW[MAXN];
int Stap[MAXN];
bool instack[MAXN];
void tarjan(int i)//Tarjan 
{
    int j;
    DFN[i]=LOW[i]=++Dindex;//Index 时间戳 
    instack[i]=true;//标记入栈 
    Stap[++Stop]=i;//入栈 
    for (edge *e=V[i];e;e=e->next)//枚举所有相连边 
    {
        j=e->t;//临时变量 
        if (!DFN[j])//j没有被搜索过 
        {
            tarjan(j);//递归搜索j 
            if (LOW[j]<LOW[i])//回溯中发现j找到了更老的时间戳 
                LOW[i]=LOW[j];//更新能达到老时间戳 
        }
        else if (instack[j] && DFN[j]<LOW[i])//如果已经印有时间戳 且 时间戳比较小,则有环 
            LOW[i]=DFN[j];//当前记录可追溯时间戳更新 
    }
    if (DFN[i]==LOW[i])//可追溯最老是自己,表明自己是当前强连通分量的栈底 
    {
        Bcnt++;//强连通分量数增加 
        do
        {
            j=Stap[Stop--];//出栈顶元素 
            instack[j]=false;//标记出栈 
            Belong[j]=Bcnt;//记录j所在的强连通分量编号 
        }
        while (j!=i);//如果是当前元素,弹栈完成 
    }
}
void solve()
{
    int i;
    Stop=Bcnt=Dindex=0;
    memset(DFN,0,sizeof(DFN));//标记为为搜索过 
    for (i=1;i<=N;i++)
        if (!DFN[i])
            tarjan(i);
}
int main()
{

}