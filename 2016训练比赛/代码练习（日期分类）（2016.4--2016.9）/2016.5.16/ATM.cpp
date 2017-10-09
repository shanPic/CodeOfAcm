#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Time//时间类，重载了与时间相关的一些操作
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int sec;
public:
	Time(){};
	Time(int y, int mo, int d,int h,int m,int s) :year(y), month(mo), day(d),hour(h),minute(m),sec(s){};
	////////////必要的运算符重载///////
	friend ostream& operator<<(ostream &output,const Time &);
	friend ofstream& operator<<(ofstream &output, const Time&);
	friend istream& operator>>(istream &in, Time &a);
	friend ifstream& operator>>(ifstream &in,Time &a);
	void operator=(Time &b){b.year = this->year;b.month = this->month;b.day = this->day;}
	friend bool operator<(const Time& cmp1,const Time& cmp2);
	friend bool operator==(const Time&cmp1, const Time&cmp);
};
////////
ofstream& operator<<(ofstream &output, const Time &a){
	output << a.year << "\t" << a.month << "\t" << a.day << "\t"<<a.hour<<"\t"<<a.minute<<"\t"<<a.sec;
	return output;
}
////////
ostream& operator<<(ostream &output,const Time &a){
	cout<<a.year<<"年"<<a.month<<"月"<<a.day<<"日"<<a.hour<<"时"<<a.minute<<"分"<<a.sec<<"秒"<<endl;
	return output;
}
////////
istream& operator>>(istream &in, Time &a){
	int y,m,d,h,s;
	while(1){
		cout<<"请依次输入年月日时分秒，以空格为分隔符"<<endl;
		in >> a.year >> a.month >> a.day>>a.hour>>a.minute>>a.sec;
		if(a.year<2016||a.month>12||a.day>30||a.minute>60||a.sec>60){
			cout<<"输入有误，请重输"<<endl;
			//system("cls");
		}
		else break;
}
	return in;
}
////////
ifstream& operator>>(ifstream &in,Time &a){
	in >> a.year >> a.month >> a.day>>a.hour>>a.minute>>a.sec;
	return in;
}
////////
bool operator==(const Time&cmp1, const Time&cmp){
	if (cmp1.day == cmp.day&&cmp1.month == cmp.month&&cmp1.year == cmp.year)
		return true;
	else return false;
}
///////
bool operator<(const Time&cmp1,const Time& cmp){
	if (cmp1.year < cmp.year || (cmp1.month < cmp.month&&cmp1.year == cmp.year) || (cmp1.year == cmp.year&&cmp1.month == cmp.month&&cmp1.day < cmp.day))
		return true;
	else return false;
}
class Record{
	int flag;//标记变量，表明此记录是存款还是取款，1为存款，0为取款
	Time nowtime;
	long long no;//产生此记录的用户编号
	double changeMount;
	double sum;
public:
	Record(){};
	Record(long long no, double c, double sum) :no(no), changeMount(c), sum(sum){};
	long long getNO(){ return no; }
	double getSum(){ return sum; }
	Time getTime(){ return nowtime; }
	friend ostream& operator<<(ostream&, Record &);
	//friend ofstream& operator<<(ofstream&, Record &);
	friend fstream& operator>>(fstream& in, Record & r);
};
ostream& operator<<(ostream &out, Record &r){
	out<<r.nowtime<<"\t"<<r.no<<"\t"<<r.changeMount<<"\t"<<r.sum<<"\n";
	return out;
}
/*ofstream& operator<<(ofstream& file, Record & r){
	file << r.flag << " " << r.nowtime << " " << r.no << " " << r.changeMount << " " << r.sum << "\n";
	return file;
}*/
fstream& operator>>(fstream& in, Record & r){
	in << r.flag << r.nowtime << r.no << r.changeMount << r.sum;
	return in;
}
class User{
	vector<Record> log;
	bool flag;//标记变量，标记是否被冻结
	long long NO;//银行卡号
	string name;
	string IDcardNO;//身份证号
	string PassWord;//密码
	double sum;//账户余额
public:
	User(){};
	User(long long n, string name, char* IC, string pw) :NO(n), name(name), IDcardNO(IC), PassWord(pw){ sum = 0; };
	User(long long n, string name, char* IC, string pw, int s) :NO(n), name(name), sum(s), IDcardNO(IC), PassWord(pw){
	};
	~User(){
	};
	void setFlag(bool tem){ flag = tem; };//冻结与解冻账户
	void CunKuan();
	void QuKuan();
};
class UserOP{
	User *pUser;
	Time *pTime;
public:
	UserOP(){pUser=NULL;pTime=NULL};
	UserOP(User& a,Time &b){this->}
};
class guli{

};
int main() {
	Time a(2016,5,16,21,46,54);
	cout<<a;
    //cin>>a;
    cout<<a;
		Record b(a,20,10,5);
		cout<<b;
	return 0;
}
