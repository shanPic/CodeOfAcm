#include<bits/stdc++.h>
using namespace std;
vector<string> a;
int n;
int maxlen;
void print_()
{
    for(int i=0;i<60;i++){
        cout<<'-';
    }
    cout<<endl;
}
void printOne(string &s,int n)
{
    cout<<s;
    for(int i=0;i<n-s.length();i++){
        cout<<' ';
    }
}
void printString(int col,int row)
{
    int nu;
    string pace=" ";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            nu=row*j+i;
            if(nu<n)
            printOne(a[nu],j==(col-1)?maxlen:maxlen+2);
            else printOne(pace,maxlen);
        }
        cout<<endl;
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    string tem;
    while(cin>>n){
        a.clear();
        maxlen=0;
        for(int i=0;i<n;i++){
            cin>>tem;
            a.push_back(tem);
            maxlen=max(maxlen,(int)a[i].length());
        }
        vector<string>::iterator itea=a.begin();
        sort(itea,itea+n);
        int col=(int)(62/(maxlen+2));
        int row=n/col;
        if(n%col) row++;
        print_();
        printString(col,row);
    }
}
