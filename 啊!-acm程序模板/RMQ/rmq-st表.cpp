const int maxn;
int dp[maxn][40];  
int len;  //总的长度
  
void rmq_init(int* A, int n){  
    for (int i = 0; i < n; ++i) dp[i][0] = A[i];  
    for (int j = 1; (1<<j) <= n; ++j)  
        for (int i = 0; i + (1<<j) - 1 < n ; ++i)  
            dp[i][j] = min(dp[i][j-1], dp[i + (1<< (j-1))][j-1]);  
}  
  
int ASK(int l,int r){  
    int k = 0;  
    while((1<<(k+1)) <= r-l + 1) ++k;  
    return min(d[l][k], d[r-(1<<k) + 1][k]);  
}  
  
int ask(int l,int r){  
    if (l == r) return dp[l][0]; /// l == r 
    return ASK(l + 1, r); ///否则在rmq查询。  
}  