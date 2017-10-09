#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    long long sum;
    while(cin>>str){
        sum=0;
        for(char &ch : str){//?
            if(isalpha(ch)) ch=' ';
        }
        stringstream stre(str);
        string buf;
        while(stre>>buf){
            long long p=0;
            for(char ch : buf){
                if(isdigit(ch))
                p=p*10+ch-'0';
            }
            sum+=p;
        }

        vector<string> res;
        char tem[30];
        if(sum%100){
            sprintf(tem,"%02ld",sum%100);
            //tem=to_string(sum%100);
            res.push_back(tem);
            sum=sum/100;
        }
        while(sum>1000){
            sprintf(tem,"%03ld",sum%1000);
            res.push_back(tem);
            sum=sum/1000;
        }
//        string temp=to_string(sum);
//        res.push_back(temp);
        res.push_back(to_string(sum));

        reverse(res);
        int i=0;
        for(auto ite : res){
            if(i++) cout<<".";
            cout<<*ite;
        }

    }
}
