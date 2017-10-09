/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\1005-pro.cpp
* @Author: Pic
* @Date:   2017-07-22 18:50:32
* @Last Modified time: 2017-07-22 21:38:49
*/
 #include<cstdio> 
 
const int N = 100005; 
int n, m, f[N], rank[N]; 
 
inline void init(){ 
    for(int i=1; i<=n; ++i) 
        f[i]=i,rank[i]=0; 
} 
 
int find(int x){ 
    if(x==f[x])return f[x]; 
    int fa=f[x]; 
    f[x] = find(f[x]); 
    rank[x] = (rank[x]+rank[fa])&1; //这一步的作用是将Line29做的更改传递下去
    return f[x]; 
} 
 
inline bool Union(int x,int y){ 
    int a=find(x), b=find(y); 
    if(a==b) return false; 
    f[b] = a; 
    rank[b] = (rank[x]-rank[y]+1)&1; //rank[b]初始一定是0（初始化），若rank[x]与rank[y]一开始是相同的，则需要更改rank[b],否则不需要
} 

int main(){ 
    int T,a,b,fa,fb; 
    char ch; 
    scanf("%d",&T); 
    while(T--){ 
        scanf("%d%d%*c",&n,&m); 
        init(); 
        for(int i=0; i<m; ++i){ 
            scanf("%c%d%d%*c",&ch,&a,&b); 
            if(ch=='D'){ 
                Union(a,b); 
            } 
            else{ 
                fa = find(a), fb=find(b); 
                if(fa==fb){ 
                    if(rank[a]==rank[b]) puts("In the same gang."); 
                    else puts("In different gangs."); 
                } 
                else 
                    puts("Not sure yet."); 
            } 
        } 
    } 
    return 0; 
} 
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
//
//
