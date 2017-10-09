#include<iostream>
using namespace std;
const int MAXN=53;
string a[53]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","Aa","Ab","Ac","Ad","Ae","Af","Ag","Ah","Ai","Aj","Ak","Al","Am","An","Ao","Ap","Aq","Ar","As","At","Au","Av","Aw","Ax","Ay","Az"};

bool ok[MAXN];
int res[MAXN];
int main()
{
    int n,k;
    cin>>n>>k;
    string x;
    //memset(ok,0,sizeof(ok));
    for(int i=k;i<=n;i++){
        cin>>x;
        if(x=="YES"){
            ok[i]=1;
        }
        else{
            ok[i]=0;
        }
    }
    int tar=0;
    for(int i=0;i<k;i++) res[i]=tar++;
    for(int i=k;i<=n;i++){
        if(ok[i]){
            res[i]=tar++;
        }
        else{
            res[i]=res[i-k+1];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[res[i]]<<" ";
    }
    cout<<endl;
}