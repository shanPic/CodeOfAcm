#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int> stat;
    int sumCase=0,sumNum=0,sum=0;
    for(char i=32;i<127;i++){
        stat.insert(make_pair(i,0));
    }
    ifstream infile("input.txt",ios::in);
    if(!infile.is_open()){
        cout<<"文件打开失败"<<endl;
        return -1;
    }
    char tem;
    while(infile&&infile.get(tem)){
        stat[tem]++;
        sum++;
    }
    infile.close();
    cout<<"一共出现了"<<sum<<"个字元"<<endl;
    for(char i='A';i<='Z';i++){
        double temsum=stat[i]+stat[i+'a'-'A'];
        cout<<i<<"出现的次数为(不区分大小写):"<<temsum<<"\t"<<"频率为:"<<temsum/sum<<endl;
        sumCase+=temsum;
    }
    for(char i='0';i<='9';i++){
        double temsum=stat[i];
        cout<<i<<"出现的次数为:"<<temsum<<"\t"<<"频率为:"<<temsum/sum<<endl;
        sumNum+=temsum;
    }
    cout<<"其他字符出现的次数为:"<<sum-sumCase-sumNum<<endl;
    return 0;
}
