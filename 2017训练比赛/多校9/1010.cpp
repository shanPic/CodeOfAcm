/*
* @FileName: D:\代码与算法\2017训练比赛\多校9\1010.cpp
* @Author: Pic
* @Date:   2017-08-22 13:09:42
* @Last Modified time: 2017-08-22 22:21:12
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2500+30;
/*matchhere ：在text的开头查找regexp*/
int matchhere(char* regexp,char* text);
int matchstar(int c,char* regexp,char* text);
/*match ：在text中查找regexp*/
int match(char* regexp,char* text)
{
    if(matchhere(regexp,text))
        return 1;
    else
    	return 0;
}
/*matchhere ：在text的开头查找regexp*/
int matchhere(char* regexp,char* text)
{
    if(regexp[0] == '\0' && text[0] == '\0')
        return 1;
    if(regexp[0]!='.' && regexp[1]=='*'){
    	return matchstar(regexp[0],regexp+2,text);
    }
    if(regexp[0]=='.' && regexp[1] == '*'){
    	int flag=0;
    	regexp[0]=text[0];
        if(matchstar(regexp[0],regexp+2,text)) flag=1;
        regexp[0]='.';
        if(!flag)
        	if(matchhere( regexp+2, text) ) flag=1;
		return flag;
    }
    if(*text != '\0' && (regexp[0] == '.' || regexp[0] == *text)){
        return matchhere(regexp+1,text+1);
    }
    if((regexp[0]=='\0' && text[0]!='\0')||(regexp[0]!='\0'&& text[0]=='\0')){
    	return 0;
    }
    return 0;
}
/*matchstar :在text的开头查找c*regexp*/
int matchstar(int c,char* regexp,char* text)
{
    do{ /*通配符×匹配零个或多个实例*/

        if(matchhere(regexp,text) /*&& flag*/ ){
            return 1;
        }
    }while(*text != '\0' && (*text++ == c) /*&& chuli()*/ );
    return 0;
}

char a[MAXN],b[MAXN];
int main()
{
	 // freopen("data.out","r",stdin);
  //    freopen("data2.out","w",stdout);
	 // clock_t startTime,endTime;  
  //    startTime = clock();
    int t;
    scanf("%d\n",&t);
    //getchar();
    while(t--){
        //b[0]='\0';a[0]='\0';
        // memset(b,'\0',sizeof(b));
        // memset(a,'\0',sizeof(a));
        // gets(b);
        // gets(a);
        // cin.getline(b,MAXN-1);
        // cin.getline(a,MAXN-1);
        scanf("%s%s",b,a);
        // if(strlen(b)==0&&(strcmp(a,".*")==0)){
        // 	printf("yes\n");
        // 	continue;
        // }
        if(match(a,b)){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
     // endTime = clock();  
     // cout << "Totle Time : " <<(double)(endTime - startTime)<< "ms" << endl;
         return 0;
}