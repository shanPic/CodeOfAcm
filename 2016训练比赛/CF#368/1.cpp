#include<bits/stdc++.h>
using namespace std;
int cou[3]={1,2,4};
int b[3];
int m[3];
int main()
{
    cin>>b[0]>>b[1]>>b[2];
    for(int i=0;i<3;i++){
        m[i]=b[i]/cou[i];
    }
    sort(m,m+3);
    cout<<m[0]*7<<endl;
}
