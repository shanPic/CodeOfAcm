/*
#����˼·�����һ����ʣ��һ����
 ���Ǽ�¼һ�µ�ǰ��ʣ�µ��Ǹ��������¸������������ͬ��������ļ�����+1������ͬ����-1
 ���ʣ�µļ�Ϊ���
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int now,cou;
    int n;
    while(cin>>n){
        if(!n)continue;
        cin>>now;
        cou=1;
        int tmp;
        for(int i=1;i<n;i++){
            cin>>tmp;
            if(!cou) {
                now=tmp;
                cou++;
            }
            else if(tmp==now) cou++;
            else if(tmp!=now) cou--;
        }
        cout<<now<<endl;
    }
}
