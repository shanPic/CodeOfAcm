#include<bits/stdc++.h>
using namespace std;
class TheAirTripDivTwo
{
public:
    int find(vector<int> vec,int n)
    {
        int num=0;
        int tmp;
        for(auto ite=vec.begin();ite!=vec.end();ite++){
            tmp=(*ite);
            if(n>=tmp){
                num++;
                n-=tmp;
            }
            else{
                break;
            }
        }
        return num;
    }
};
int main()
{

}
