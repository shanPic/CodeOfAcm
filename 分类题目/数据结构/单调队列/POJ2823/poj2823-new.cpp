#include<iostream>
#include<stdio.h>
using namespace std;
const int M=1000010;
int a[M];
int q[M];
int n,k;
void Min()
{
    int head=0,tail=-1;
    for(int i=0;i<k-1;i++){
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        tail++;
        q[tail]=i;
    }
    for(int i=k-1;i<n;i++){
        while(head<=tail&&a[q[tail]]>=a[i])
            tail--;
        tail++;
        q[tail]=i;
        while(q[head]<i-k+1) head++;
        printf("%d ",a[q[head]]);
    }
    printf("\n");
}
void Max()
{
    int head=0,tail=-1;
    int i;
    for(i=0;i<k-1;i++){
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        tail++;
        q[tail]=i;
    }
    for(;i<n;i++){
        while(head<=tail&&a[q[tail]]<=a[i])
            tail--;
        tail++;
        q[tail]=i;
        while(q[head]<i-k+1) head++;
        printf("%d ",a[q[head]]);
    }
    printf("\n");
}
int main()
{
    //freopen("data.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Min();
    Max();
}
