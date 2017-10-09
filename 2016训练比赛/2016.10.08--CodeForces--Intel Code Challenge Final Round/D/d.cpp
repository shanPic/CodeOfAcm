#include<bits/stdc++.h>
using namespace std;
const int M=100100;
int m;
int len;
char str[M];
char strfi[M];
char resstr[M];
char* tanxin(int po,int strp)
{
    int tem=po+1;
    if((po+m)>=len){
        for(int i=po+2;i<len;i++){
            if(str[i]<str[tem])
        }
    }
}
int main()
{
    while(cin>>m){
        scanf("%s",str);
        len=strlen(str);
        for(int i=0;i<m;i++){
            tanxin(i);
        }
    }
}
