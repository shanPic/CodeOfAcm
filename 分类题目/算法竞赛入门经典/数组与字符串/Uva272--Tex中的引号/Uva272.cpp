#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char ch='1';
    bool flag=0;
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    while((ch= getchar())&&ch != EOF ){
        if(ch=='"'){
            if(flag){
                //printf("''");
                cout<<"''";
                flag=0;
            }
            else{
                //printf("``");
                cout<<"``";
                flag=1;
            }
        }
        else
            printf("%c",ch);
    }
}
