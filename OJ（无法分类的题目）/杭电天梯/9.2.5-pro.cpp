#include<iostream>  
 #include<cstdio>  
 #include<algorithm>  
 #include<cmath>  
 #include<cstring>  
 using namespace std;  
 const int maxn=20005;  
 int fa[maxn],d[maxn];  
 int n;  
 struct node  
 {  
     int a,p;  
     bool operator<(const node& b)const{  
        return p<b.p;  
     }  
 }quy[30];  
 int find(int x){  
    if(x==fa[x]) return x;  
    int y=find(fa[x]);  
    d[x]=d[x]^d[fa[x]];  
    return fa[x]=y;  
 }  
 bool Union(int a,int b,int v)  
 {  
     int pa=find(a);  
     int pb=find(b);  
     if(pa==pb){  
        return (d[a]^d[b])==v;  //若a，b两个点已经加入并查集并且根是相同的，则判断其v是否符合之前输入
     }  
     if(pa==n) swap(pa,pb);  //?
     fa[pa]=pb;  
     d[pa]=d[a]^d[b]^v;  
     return true;  
 }  
 int query(int k)  
 {  
     for(int i=0;i<k;i++)  
        quy[i].p=find(quy[i].a); //cout << quy[i].p << endl;  
     int l=0;  
     int ans=0;  
     sort(quy,quy+k);  
     while(l<k){  
        int r=l;  
        while(r<k-1 && quy[r+1].p==quy[l].p) r++;  //统计同一个根的节点的数的个数，若为奇数，则不能求值
        int num=r-l+1;  
        if(quy[l].p!=n && (num&1)) return -1;  
        for(int i=l; i<=r; i++) ans^=d[quy[i].a];  
        l=r+1;  
        //cout << -1 << endl;  
     }  
     return ans;  
 }  
 int main()  
 {  
     char str[100];  
     int Q,cas=0;  
     while(~scanf("%d%d",&n,&Q) && n+Q)  
     {  
         for(int i=0; i<=n;i++) fa[i]=i,d[i]=0;  
         printf("Case %d:\n",++cas);  
         int killid=-1,kk=0;  
         while(Q--){  
            scanf("%s",str);  
            if(str[0]=='Q'){  
               int k;  
               scanf("%d",&k);  
               for(int i=0;i<k;i++) scanf("%d",&quy[i].a);  
               if(killid !=-1) continue;  
               int ans=query(k);  
               if(ans==-1) puts("I don't know.");  
               else printf("%d\n",ans);  
            }  
            else {  
                kk++;  
                gets(str);  
                if(killid!=-1) continue;  //若前面已经发现错误，只吸收，不处理
                int a,b,c;  
                int t=sscanf(str,"%d%d%d",&a,&b,&c);  
                int res;  
                //cout << t  << endl;  
                if(t==2){  
                    res=Union(a,n,b);  
                }  
                else{  
                    res=Union(a,b,c);  
                }  
                if(!res) killid=kk;  
            }  
         }  
         if(killid != -1){  
                printf("The first %d facts are conflicting.\n",kk);  
         }  
         printf("\n");  
     }  
     return 0;  
 }  