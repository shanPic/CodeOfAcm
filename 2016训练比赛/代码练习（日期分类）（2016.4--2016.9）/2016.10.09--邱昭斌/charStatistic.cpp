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
        cout<<"�ļ���ʧ��"<<endl;
        return -1;
    }
    char tem;
    while(infile&&infile.get(tem)){
        stat[tem]++;
        sum++;
    }
    infile.close();
    cout<<"һ��������"<<sum<<"����Ԫ"<<endl;
    for(char i='A';i<='Z';i++){
        double temsum=stat[i]+stat[i+'a'-'A'];
        cout<<i<<"���ֵĴ���Ϊ(�����ִ�Сд):"<<temsum<<"\t"<<"Ƶ��Ϊ:"<<temsum/sum<<endl;
        sumCase+=temsum;
    }
    for(char i='0';i<='9';i++){
        double temsum=stat[i];
        cout<<i<<"���ֵĴ���Ϊ:"<<temsum<<"\t"<<"Ƶ��Ϊ:"<<temsum/sum<<endl;
        sumNum+=temsum;
    }
    cout<<"�����ַ����ֵĴ���Ϊ:"<<sum-sumCase-sumNum<<endl;
    return 0;
}
