#include<bits/stdc++.h>
using namespace std;
int main()
{
    int set1[30],set2[30];
    char str1[110],str2[110];
    bool flag;
    while(scanf("%s%s",str1,str2)==2){
        memset(set1,0,sizeof(set1));
        memset(set2,0,sizeof(set2));
        for(int i=0;i<strlen(str1);i++){
            set1[str1[i]-'A']++;
            set2[str2[i]-'A']++;
        }
        sort(set1,set1+26);
        sort(set2,set2+26);
        flag=1;
        for(int i=0;i<26;i++){
            if(set1[i]!=set2[i]){
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
