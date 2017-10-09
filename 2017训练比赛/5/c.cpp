#include<bits/stdc++.h>
using namespace std;
string str;
int vis[13];
void chuli()
{
    //cout<<"chuli"<<endl;
    while (str != "" && str.size() != 1 && *(str.begin()) == '0') {
        //cout<<11111111<<endl;
        str.erase(str.begin());
    }
    //cout<<222222<<endl;
}
int main()
{
    freopen("data.in", "r", stdin);
    int tmp;
    int sum;
    while (cin >> str) {
        memset(vis, 0, sizeof(vis));
        bool flag = 0;
        int len = str.size();
        sum = 0;
        for (int i = 0; i < len; i++) {
            //cout<<11111111<<endl;
            tmp = str[i] - '0';
            vis[tmp]++;
            sum += tmp;
        }
        int mod = sum % 3;
        if (mod == 1) {
            //cout<<"its add"<<endl;
            for (int i = 1; i < 9; i++) {
                if (i % 3) {
                    if (i % 3 == 1) {
                        if (vis[i]) {
                            str.erase(str.find('0' + i, 0) + str.begin());
                            flag = 1;
                            //cout<<11111111<<endl;
                            chuli();
                            break;
                        }
                    }
                    else {
                        if (vis[i] >= 2) {
                            str.erase(str.find('0' + i, 0) + str.begin());
                            str.erase(str.find('0' + i, 0) + str.begin());
                            flag = 1;
                            //cout<<2222222<<endl;
                            chuli();
                            break;
                        }
                    }
                }
            }
            if (flag == 0) {
                for (int i = 2; i < 9; i += 3) {
                    for (int j = i + 3; j < 9; j += 3) {
                        if (vis[i] && vis[j]) {
                            str.erase(str.find('0' + i, 0) + str.begin());
                            str.erase(str.find('0' + j, 0) + str.begin());
                            flag = 1;
                            //cout<<3333333<<endl;
                            chuli();
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
        }
        else if (mod == 2) {
            //cout<<"its even"<<endl;
            for (int i = 1; i < 9; i++) {
                if (i % 3) {
                    if (i % 3 == 1) {
                        if (vis[i] >= 2) {
                            str.erase(str.find('0' + i, 0) + str.begin());
                            str.erase(str.find('0' + i, 0) + str.begin());
                            flag = 1;
                            //cout<<444444444<<endl;
                            chuli();
                            break;
                        }
                    }
                    else {
                        if (vis[i]) {
                            str.erase(str.find('0' + i, 0) + str.begin());
                            flag = 1;
                            //cout<<55555555<<endl;
                            chuli();
                            break;
                        }
                    }
                }
            }
            if (flag == 0) {
                for (int i = 1; i < 9; i += 3) {
                    for (int j = i + 2; j < 9; j += 3) {
                        if (vis[i] && vis[j]) {
                            str.erase(str.find('0' + i, 0) + str.begin());
                            str.erase(str.find('0' + j, 0) + str.begin());
                            flag = 1;
                            cout << 66666666 << endl;
                            cout << str << endl;
                            chuli();
                            break;
                        }
                    }
                    if (flag) break;
                }
            }
        }
        else if (!mod) {
            flag = 1;
            chuli();
        }
        //cout<<777777<<endl;
        if (flag && str != "") cout << str << endl;
        else cout << "-1" << endl;
    }
}
