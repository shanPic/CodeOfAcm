#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
int a[M];
int sum[M];
int q[M];
int n;
int head,tail;
int main()
{
    int res;
    while(cin>>n){
        res=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("d",&a[i]);
            a[i+n]=a[i];
        }
        int nn=n<<1;
        for(int i=0;i<=nn;i++){
            sum[i]=sum[i-1]+a[i];
        }
        head=0;
        tail=-1;
        for(int i=0;i<nn;i++){
            while(head<=tail&&sum[q[tail]]>=sum[i])
                tail--;
            tail++;
            q[tail]=i;
            if(i>=n&&sum[q[head]]>sum[i-n])
             res++;
            if(q[head]==i-n)
                head++;
        }
        cout<<res<<endl;
    }
}
