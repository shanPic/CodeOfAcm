#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > a;
bool tongji(vector<int> &a)
{
    int sum=0;
    for(vector<int>::iterator ite=a.begin();ite!=a.end();ite++){
        if(*ite!=(ite-a.begin()+1)){
            sum++;
            if(sum>2)
                break;
        }
    }
    if(sum==0||sum==2)
        return 1;
    else return 0;
}
void swapx(int i,int j)
{
    for(int x=0;x<n;x++){
        swap(a[x][i],a[x][j]);
    }
}
bool OK()
{
    bool flag=1;
    for(int i=0;i<n;i++){
        if(tongji(a[i])==0){
            flag=0;
            break;
        }
    }
    if(flag)
        return 1;
    else return 0;
}
int main()
{
    //freopen("data.in","r",stdin);
    int tem;
    bool flag;
    while(cin>>n>>m){
        flag=0;
        a.clear();
        for(int i=0;i<n;i++){
            vector<int> temv;
            a.push_back(temv);
            for(int j=1;j<=m;j++){
                cin>>tem;
                a[i].push_back(tem);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                swapx(i,j);
                if(OK()){
                    flag=1;
                    break;
                }
                swapx(i,j);
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
