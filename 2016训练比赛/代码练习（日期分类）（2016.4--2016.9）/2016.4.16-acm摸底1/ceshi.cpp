#include <iostream>
#include <stdio.h>
using namespace std;

char a[]= {"-=_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?"};
char b[]= {"[]{}',.pyfgcrl/=\"<>PYFGCRL?+aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ"};
char tem;

char print(char tem)
{
    for(int i=0; a[i]; i++)
        if(a[i]==tem)
            return b[i];
    return tem;
}
int main() 
{
	//freopen("date.in","r",stdin);
//freopen("date.out","w",stdout);
    while(~scanf("%c",&tem))
    printf("%c",print(tem));

    return 0;
}