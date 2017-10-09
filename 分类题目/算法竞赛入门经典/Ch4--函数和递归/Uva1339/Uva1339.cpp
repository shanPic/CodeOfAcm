#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("data.in","r",stdin);
    char a[110];
    char b[110];
    bool flag;
    int len;
    while(scanf("%s%s",a,b)==2){
        len=strlen(a);
        sort(a,a+len);
        sort(b,b+len);
        flag=1;
        char tema=a[0];
        char temb=b[0];
        int i=1,j=1;
        while(i<len&&j<len){
            while(a[i]==tema){
                i++;
            }
            tema=a[i];
            i++;
            while(b[j]==temb){
                j++;
            }
            temb=b[j];
            j++;
            if(i!=j){
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
