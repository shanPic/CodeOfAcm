#include<bits/stdc++.h>
using namespace std;
/*************************�ֵ���ģ��*************************/
const int maxnode=10000000,sigma_size=26;
int num;//�ڵ�����
struct Trie
{
	int c[maxnode][sigma_size];
	Trie() {
		num=1;
		memset(c[0],0,sizeof(c[0]));
	}
	int ids(char ch) {
		return ch-'0';
	}
	bool insert(string s)
	{
		int id;
		int u=0;
		for(int i=0;i<s.size();i++){
            //cout<<2222222<<endl;
			id=ids(s[i]);
			if(!c[u][id]){
                //cout<<333333<<endl;
				memset(c[num],0,sizeof(c[num]));//!!�½�һ���ڵ�ʱ,һ��Ҫע���ʼ��
				//cout<<num<<endl;
				//cout<<u<<endl;
				//cout<<id<<endl;
                //cout<<44444<<endl;
				c[u][id]=num++;
				//cout<<5555555<<endl;
			}
			else{
                return 0;
			}
			u=c[u][id];
		}
        return 1;
	}
	void init()
	{
		num=1;
		memset(c[0],0,sizeof(c[0]));
	}
}tr;
/*************************�ֵ���ģ��*************************/
int main()
{
    //freopen("data.in","r",stdin);
    int n;
    string str;
    while(cin>>n&&n){
        tr.init();
        bool ok=1;
        for(int i=0;i<n;i++){
            //cout<<1111111<<endl;
            cin>>str;
            if(tr.insert(str)==0){
                ok=0;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
