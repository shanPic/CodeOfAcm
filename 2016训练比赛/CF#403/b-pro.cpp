/*
��ȻҲ�������֣����������һ�ֶ���ʱ��ķ���
�ķ�ĳһ��ʱ��ʱ��������ϱ߿��Ե���ĵ㼰��˿��Ե���ĵ�
���н���ʱ��˵�������Ե���
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=60000+100;
const double EPS=1e-6;
int x[MAXN],v[MAXN];
int main()
{
   // freopen("data.in","r",stdin);
    int n;
    cin>>n;
    int xss=0x3f3f3f3f,xnn=-1;
    for(int i=0;i<n;i++){
        cin>>x[i];
        xss=min(xss,x[i]);
        xnn=max(xnn,x[i]);
    }
    int vmin=0x3f3f3f3f,vmax=-1;
    for(int i=0;i<n;i++){
        cin>>v[i];
        vmin=min(vmin,v[i]);
        vmax=max(vmax,v[i]);
    }
    double l=0,r=(xnn-xss)*1.0/2/vmin+1;//��ʼ��l��r��С������Χ��Ҳ�ɲ���ʼ����ֱ�Ӹ�rһ����������
    double res=0;
    double mid;
    double tmp;
    while(fabs(r-l)>=EPS){
        mid=(l+r)/2.0;
        //cout<<fixed<<setprecision(6)<<mid<<endl;
        double xn=0x3f3f3f3f,xs=-1;
        for(int i=0;i<n;i++){
                xs=max(xs,x[i]*1.0-v[i]*mid);
                xn=min(xn,x[i]*1.0+v[i]*mid);
        }
        if(xn>xs){
           r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<fixed<<setprecision(12)<<mid<<endl;

}
