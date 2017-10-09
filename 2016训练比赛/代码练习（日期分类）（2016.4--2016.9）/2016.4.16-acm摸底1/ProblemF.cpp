#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
char a[]= {"-=_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?"};
char b[]= {"[]{}',.pyfgcrl/=\"<>PYFGCRL?+aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ"};
char p(char tem){
	for(int i=0;a[i];i++){
		if(tem==a[i]){
			return b[i];
		}
	}
	return tem;
}
int main(){
freopen("date.in","r",stdin);
freopen("date.out","w",stdout);
char tem;
while(~scanf("%c",&tem))
printf("%c",p(tem));
}


/*
ABCDEFuvwxyz
AXJE>Ugk,qf;

hijklmnopqrst
dchtnmbrl'poy


`~!@#$%^&*()}"']_+-=ZQqWEwe{[\|
`~!@#$%^&*()+_-={}[]:"'<>,.?/\|

ABCDEFuvwxyzhijklmnopqrst`~!@#$%^&*()}"']_+-=ZQqWEwe{[\|
AXJE>Ugk,qf;dchtnmbrl'poy`~!@#$%^&*()+_-={}[]:"'<>,.?/\|

-=_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?"
[]{}',.pyfgcrl/=\"<>PYFGCRL?+aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ"*/