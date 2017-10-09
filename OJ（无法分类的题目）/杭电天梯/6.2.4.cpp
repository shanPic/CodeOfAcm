#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 2000
#define INF 0x7ffffff
int d[MAXN][MAXN];
int fee[MAXN];
int pre[MAXN][MAXN];
int n;
void floyd()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j]=j;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(d[j][i]!=INF&&d[i][k]!=INF){
                    if(d[j][k]>d[j][i]+d[i][k]+fee[i])
                    {
                        d[j][k]=d[j][i]+d[i][k]+fee[i];
                        pre[j][k]=pre[j][i];
                    }
                    else if(d[j][k]==(d[j][i]+d[i][k]+fee[i])&&pre[j][k]>pre[j][i])
                    {
                        pre[j][k]=pre[j][i];
                    }
                }
            }
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    //cout<<11111<<endl;
    while(cin>>n&&n!=0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>d[i][j];
                if(d[i][j]==-1) d[i][j]=INF;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>fee[i];
        }
        floyd();
        int a,b;
        while(cin>>a>>b){
            if(a==-1&&b==-1) break;
            cout<<"From "<<a<<" to "<<b<<" :"<<endl;
            cout<<"Path: ";
            cout<<a;
            int k=pre[a][b];
            while(k!=b){
                cout<<"-->"<<k;
                k=pre[k][b];
            }
            cout<<"-->"<<b;
            cout<<endl;
            cout<<"Total cost : ";
            cout<<d[a][b]<<endl<<endl;
        }
    }
}
