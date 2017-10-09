/*
#初步思路：最后一定会剩下一个数
 我们记录一下当前的剩下的那个数，若下个数和这个数相同，则给它的计数器+1，若不同，则-1
 最后剩下的即为结果
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
