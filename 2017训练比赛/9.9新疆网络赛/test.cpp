#include<bits/stdc++.h>
using namespace std;

namespace IO{
    const int BUFFSIZE=20<<20;//<<10kb <<20MB
    char Buf[BUFFSIZE+1],*buf=Buf;
    size_t lastlen=0;
    void init(){lastlen=fread(Buf,1,BUFFSIZE,stdin);}
    template<class T>
    void read1(T& res){
        for(res=0;*buf<'0'||*buf>'9';buf++);
        while(*buf>='0'&&*buf<='9'){res=res*10+(*buf-'0');buf++;}
    }
    template<class T>
    void read2(T& res){
        int sgn=1;
        for(res=0;*buf<'0'||*buf>'9';buf++)if(*buf=='-')sgn=-1;
        while(*buf>='0'&&*buf<='9')res=res*10+(*buf-'0'),buf++;
        res=res*sgn;
    }

    template<class T>
    bool read3(T& res){
        for(res=0;*buf<'0'||*buf>'9';buf++);
        if(buf-Buf>=lastlen)return 0;
        while(*buf>='0'&&*buf<='9'){res=res*10+(*buf-'0');buf++;}
        return 1;
    }
    void readstring(char *c){
        for(;*buf=='\n'||*buf=='\t'||*buf==' ';buf++);
        while(((*buf!='\n')&&(*buf!='\t')&&(*buf!=' '))){*(c++)=*(buf++);}
        *c=0;
    }
}

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    IO::init();
    char str[300];
    IO::readstring(str);
    cout<<str<<endl;
    return 0;
}