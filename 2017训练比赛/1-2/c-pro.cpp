/*
���ִ�
���Ϊx����xһ��������
x*n-sum>=x
sumΪ��Ҫ����ͨ��ұ�������
ÿ���˲���x����������������Ϊx*n����ȥsum
��Ϊ����ж��ٳ�������������
�ҵ����������������С��������
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0,x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    int l=0,r=sum;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*n-sum>x){
            //l=mid+1;
            r=mid-1;
        }
        else //r=mid-1;
            l=mid+1;
    }
    cout<<r<<endl;
}
