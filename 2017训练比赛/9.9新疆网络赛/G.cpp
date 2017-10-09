#include <bits/stdc++.h>
  
#define INT_INF 0x3fffffff  
#define LL_INF 0x3fffffffffffffff  
#define EPS 1e-12
#define MOD 1000000007  
#define PI 3.141592653579798  
#define N 300  
  
using namespace std;  
  
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

const int maxn=20000+30;
struct data  
{  
    int st,en,val,next;  
} edge[20005+300];//e[100005];  
  
int head[maxn],tot;
  //,h[1005]
bool vs[maxn];  
int dis[maxn];  
  
struct node  
{  
	int flag=0;
    //int fa;
    int id,len,h;  
    int vis[maxn];
    node():flag(0){};
    bool operator <(const node &a) const  
    {  
        if(a.len+a.h==len+h) return a.len<len;  
        else return a.len+a.h<len+h;  
    }  
};  
  
void add_edge(int st,int en,int val)  
{  
    edge[tot].st=st;  
    edge[tot].en=en;  
    edge[tot].val=val;  
    edge[tot].next=head[st];  
    head[st]=tot++;  
}  
  
/*对反向边求一次 dijstra ，求得各个点到终点的最短距离，也就是我们 A* 的估价函数中的 h 函数*/  
void dijstra(int st,int n)  
{  
    memset(vs,0,sizeof(vs));  
    for(int i=1;i<=n;i++)  
        dis[i]=INT_INF;  
    for(int i=head[st];i!=-1;i=edge[i].next)  
    {  
        dis[edge[i].en]=edge[i].val;  
    }  
    dis[st]=0;  
    while(1)  
    {  
        int k=-1 , Min=INT_INF;  
        for(int i=1;i<=n;i++)  
            if(!vs[i] && dis[i]<Min)  
            {  
                k=i;  
                Min=dis[i];  
            }  
        if(k==-1) break;  
        vs[k]=1;  
        for(int i=head[k];i!=-1;i=edge[i].next)  
            if(!vs[edge[i].en] && dis[edge[i].en]>dis[k]+edge[i].val)  
                dis[edge[i].en]=dis[k]+edge[i].val;  
    }  
}  
int sflag=0;
int totnum=0;
/*对起点 s 终点 t 求第 k 短路，如果找不到，返回 -1*/   
int kth_path(int s,int t,int k)  
{  
    memset(vs,0,sizeof(vs));  
    if(dis[s]==INT_INF) return -1;  
    //if(s==t) k++;  
    priority_queue<node> q;  
    node now;  
    now.id=s; now.len=0; now.h=dis[s];  
    if(now.id==sflag) now.flag=1;
    else now.flag=0;
    memset(now.vis,0,sizeof(now.vis));
    now.vis[s]=1;
    q.push(now);  
    int cnt=0;
    while(!q.empty())  
    {  
        node now=q.top(); q.pop();
        if(now.id==t){
			cnt++; 
			if(now.flag==1){
				return now.len;
			}
        } 
        if(cnt==k) return -1;
        node new_v;
        new_v.flag=now.flag;
        //new_v.vis=now.vis;
        for(int i=0;i<=totnum;i++){
            new_v.vis[i]=now.vis[i];
        }
        //int u=now.id;
        int v;
        for(int i=head[now.id];i!=-1;i=edge[i].next)  
        {   
            v=edge[i].en;
            if(!now.vis[v]){
                new_v.vis[v]=1;
                new_v.id=v; new_v.len=now.len+edge[i].val; new_v.h=dis[edge[i].en]; 
                if(new_v.id==sflag) new_v.flag=1;
                //new_v.fa=u;
                q.push(new_v);  
                new_v.flag=now.flag;      
                new_v.vis[v]=0;      
            }
        }  
        //vs[u]=1;
    }  
    return -1;  
}  
void init()
{
	memset(head,-1,sizeof(head));
	tot=0;
}
unordered_map<string,int> mp;
//map<string,int> mp;
int main()  
{  
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		mp.clear();
		int w;
		string stra,strb;
		int a,b;
		tot=1;
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			//cin>>stra>>strb;
            read1(stra);
            read1(strb);
			scanf("%d",&w);
			if(mp.find(stra)==mp.end()){
				mp.insert(make_pair(stra,totnum));
				a=totnum++;
			}
			else{
				a=mp[stra];
			}
			if(mp.find(strb)==mp.end()){
				mp.insert(make_pair(strb,totnum));
				b=totnum++;
			}
			else{
				b=mp[strb];
			}
			add_edge(a,b,w);
            add_edge(b,a,w);
		}
		int s=mp["Dalian"],t=mp["Xian"];
		sflag=mp["Shanghai"];
		dijstra(t,totnum-1);
        //cnt=0;
		int ans=kth_path(s,t,3);
        //cout<<cnt<<"\t";
		printf("%d\n",ans);
	}
}  
