#include<bits/stdc++.h>
using namespace std;
char a[2500];
char res[2500];
int n;
int l,r;
int main()
{
    cin>>n;
    scanf("%s",a);
    l=0;r=n-1;
    bool flag=1;
    for(int i=n-1;i>=0;i--){
        if(flag){
            res[r--]=a[i];
            flag=0;
        }
        else {
            res[l++]=a[i];
            flag=1;
        }
    }
    res[n]='\0';
    printf("%s",res);
    return 0;
}
