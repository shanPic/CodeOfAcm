#include<bits/stdc++.h>
using namespace std;
int head;
int m,n;
char a[100];
char b[100];
bool finds(char ch)
{
    for(int i=head+1;i<m;i++){
        if(b[i]==ch){
            head=i;
            return 1;
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%s",a)){
        head=-1;
        scanf("%s",b);
        n=strlen(a);
        m=strlen(b);
        int i=0;
        while(finds(a[i])){
            i++;
            if(i>=n)
                break;
        }
        if(i==n)
            cout<<"OK!"<<endl;
        else cout<<"not OK!"<<endl;
    }
}
