#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,N,R;
    char ch[]={'0','1','2','3','4','5','6',
                '7','8','9','A','B','C','D','E','F'};
    cin>>n;
    do{
        cin>>N>>R;
        bool flag=true;
        if(N<0) {flag=false; N=-N;}
        if(N==0) cout<<'0';
        string r="";
        while(N)
        {
            r+=ch[N%R];
            N=N/R;
        }
        if(flag==false) r+='-';
        for(int i=r.length()-1;i>=0;i--)
        cout<<r[i];
        cout<<endl;
        n--;
    }while(n);
    return 0;
}
