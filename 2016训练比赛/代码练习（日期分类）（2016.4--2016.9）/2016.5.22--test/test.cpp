#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#define viod void;
#define ture true;
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
	Time();
	Time(int y, int mo, int d, int h, int m, int s) :year(y), month(mo), day(d), hour(h), minute(m), sec(s){};
	////////////必要的运算符重载///////
	friend ostream& operator<<(ostream &output, Time &);
	//friend ostream& operator<<(ostream &output, Time&);
	friend istream& operator>>(istream &in, Time &a);
	//friend ifstream& operator>>(ifstream &in, Time &a);
	void operator=(Time &b){ b.year = this->year; b.month = this->month; b.day = this->day; }
	friend bool operator<(const Time& cmp1, const Time& cmp2);
	friend bool operator==(const Time&cmp1, const Time&cmp);
};
Time::Time(){
	while (1){
		cout << "请依次输入年月日时分秒，以空格为分隔符" << endl;
		cin >> year >> month >> day >> hour >> minute >> sec;
		if (year<=2016 || month>12 || day>30 || minute>60 || sec>60){
			cout << "输入有误，请重输" << endl;
			year = 0, month = 0, day = 0, hour = 0, minute = 0, sec = 0;
			//system("cls");
		}
		else return;
	}
}
////////
ostream& operator<<(ostream &output, Time &a){
	output << a.year << "\t" << a.month << "\t" << a.day << "\t" << a.hour << "\t" << a.minute << "\t" << a.sec<<"\t";
	return output;
}
////////
/*ostream& operator<<(ostream &output, Time &a){
	cout << a.year << "年" << a.month << "月" << a.day << "日" << a.hour << "时" << a.minute << "分" << a.sec << "秒" << endl;
	return output;
}*/
////////
istream& operator>>(istream &in, Time &a){
	in >> a.year >> a.month >> a.day >> a.hour >> a.minute >> a.sec;
	return in;
}
////////
/*ifstream& operator>>(ifstream &in, Time &a){
in >> a.year >> a.month >> a.day >> a.hour >> a.minute >> a.sec;
return in;
}*/
////////
bool operator==(const Time&cmp1, const Time&cmp){
	if (cmp1.day == cmp.day&&cmp1.month == cmp.month&&cmp1.year == cmp.year)
		return true;
	else return false;
}
///////
bool operator<(const Time&cmp1, const Time& cmp){
	if (cmp1.year < cmp.year || (cmp1.month < cmp.month&&cmp1.year == cmp.year) || (cmp1.year == cmp.year&&cmp1.month == cmp.month&&cmp1.day < cmp.day))
		return true;
	else return false;
}
class Record{
	bool flag;//标记变量，表明此记录是存款还是取款，1为存款，0为取款
	Time nowtime;
	long long no;//产生此记录的用户编号
	double changeMount;
	double sum;
public:
	Record(){};
	Record(bool f, Time t, long long no, double c, double sum) :nowtime(t), no(no), changeMount(c), sum(sum), flag(f){};
	bool getFlag(){ return flag; }
	void setFlag(bool tem){ flag = tem; }
	long long getNO(){ return no; }
	double getSum(){ return sum; }
	Time getTime(){ return nowtime; }
	friend ostream& operator<<(ostream&, Record &);
	//friend ofstream& operator<<(ofstream&, Record &);
	friend istream& operator>>(istream& in, Record & r);
};
ostream& operator<<(ostream &out, Record &r){
	out << r.flag << "\t" << r.nowtime << "\t" << r.no << "\t" << r.changeMount << "\t" << r.sum << "\n";
	return out;
}
/*ofstream& operator<<(ofstream& file, Record & r){
file << r.flag << " " << r.nowtime << " " << r.no << " " << r.changeMount << " " << r.sum << "\n";
return file;
}*/
istream& operator>>(istream& in, Record& r){
	in >> r.flag >> r.nowtime >> r.no >> r.changeMount >> r.sum;
	return in;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
class User{
	vector<Record> log;
	map<Time, int> TimeMap;
	multimap<bool, int> TypeMap;
	bool flag;//标记变量，标记是否被冻结
	long long NO;//银行卡号
	string name;
	string IDcard;//身份证号
	string PassWord;//密码
	double sum;//账户余额
public:
	User(){};
	User(long long n, string name, string IC, string pw) :NO(n), name(name), IDcard(IC), PassWord(pw){ sum = 0; };
	User(long long n, string name, string IC, string pw, double s) :NO(n), name(name), sum(s), IDcard(IC), PassWord(pw){
	};
	void setFlag(bool tem){ flag = tem; };
	long long getNO(){ return NO; }
	string getname(){ return name; }
	void setname(string tem){ name = tem; }
	string getIDcard(){ return IDcard; }
	string getPassWord(){ return PassWord; }
	void setPassWord(string tem){ PassWord = tem; }
	double getsum(){ return sum; }
	void setsum(double tem){ sum = tem; }
	void setLog(){ log.clear(); TimeMap.clear(); TypeMap.clear(); }
	int addLog(Record &temr){ log.push_back(temr); TypeMap.insert(make_pair(temr.getFlag(), log.size() - 1)); TimeMap.insert(make_pair(temr.getTime(), log.size() - 1)); return log.size(); }
	Record getRecord(int i){ return log[i]; }
	map<Time, int> getTimeMap(){ return TimeMap; }
	multimap<bool, int> getTypeMap(){ return TypeMap; }
	friend ostream& operator<<(ostream&, User& tem);
	friend istream& operator>>(istream&, User& tem);
	bool operator==(User &tem);
};
ostream& operator<<(ostream& out, User& tem){
	out << tem.flag << "\t" << tem.name << "\t" << tem.IDcard << "\t" << tem.NO << "\t" << tem.PassWord << "\t" << tem.log.size() << "\n";
	for (vector<Record>::iterator ptem = tem.log.begin(); ptem != tem.log.end(); ptem++){
		out << *ptem;
	}
	/*for ( size_t i = 0; i < tem.log.size(); i++)
		out << tem.log[i];*/
	//out << "\n";
	return out;

}
istream& operator>>(istream&in, User& tem){
	in >> tem.flag >> tem.name >> tem.IDcard >> tem.NO >> tem.PassWord;
	return in;
}
bool User::operator==(User &tem){
	return this->flag == tem.flag&&this->NO == tem.NO;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
class UserOP{
	User pUser;
	map<Time, int> TimeMap;
	multimap<bool, int> TypeMap;
public:
	UserOP(){  }
	UserOP(User& a){ pUser = a;  TimeMap = a.getTimeMap(); TypeMap = a.getTypeMap(); }
	~UserOP();
	void CunKuan();
	void QuKuan();
	void searchByType(bool tem);
	void searchByTime(Time b, Time e);
	void changePassWord();
};
UserOP::~UserOP(){
	vector<User> users;
	vector<User>::iterator itu = users.begin();
	int n;
	User temU;
	Record temR;
	ifstream infile("date.dat");
	if (!infile.is_open()){
		cout << "文件打开失败！" << endl;
		return;
	}
	while (cin >> temU){
		//users.push_back(tem);
		cin >> n;
		for (int i = 0; i < n; i++){
			infile >> temR;
			temU.addLog(temR);
		}
		if (pUser == temU)
			users.push_back(pUser);
		else
			users.push_back(temU);
	}
	ofstream ofile("date.dat");
	for (itu = users.begin(); itu != users.end(); itu++){
		ofile << *itu;
	}
}
void UserOP::CunKuan(){
	double change;
	Time t;
	cin >> t;
	while (1){
		cout << "输入存款金额，键入-1结束" << endl;
		cin >> change;
		if (change == -1)break;
		Record tem(1,t, pUser.getNO(), change, pUser.getsum() + change);
		tem.setFlag(1);
		pUser.addLog(tem);
		int temsum = pUser.addLog(tem) - 1;
		pUser.setsum(pUser.getsum() - change);
		TimeMap.insert(make_pair(t, temsum));
		TypeMap.insert(make_pair(true, temsum));
	}
}
void UserOP::QuKuan(){
	double change;
	Time t;
	cin >> t;
	while (1){
		cout << "输入取款金额，键入-1结束" << endl;
		cin >> change;
		if (change == -1)return;
		if (change > pUser.getsum()){
			cout << "余额不足，请重新输入" << endl;
			break;
		}
		Record tem(0,t, pUser.getNO(), 0 - change, pUser.getsum() - change);
		tem.setFlag(0);
		int temsum = pUser.addLog(tem) - 1;
		pUser.setsum(pUser.getsum() - change);
		TimeMap.insert(make_pair(t, temsum));
		TypeMap.insert(make_pair(false, temsum));
	}
}
void UserOP::searchByType(bool tem){
	multimap<bool, int>::iterator pb, pe;
	pb = TypeMap.lower_bound(tem);
	pe = TypeMap.upper_bound(tem);
	for (multimap<bool, int>::iterator it = pb; it != pe; it++){
		cout << pUser.getRecord(it->second) << endl;
	}
	if (pb == TypeMap.end())
		cout << "不存在要查询的记录" << endl;
}
void UserOP::searchByTime(Time b, Time e){
	map<Time, int>::iterator pb, pe;
	pb = TimeMap.lower_bound(b);
	pe = TimeMap.upper_bound(e);
	for (multimap<Time, int>::iterator it = pb; it != pe; it++){
		cout << pUser.getRecord(it->second) << endl;
	}
	if (pb == TimeMap.end())
		cout << "不存在要查询的记录" << endl;
}
void UserOP::changePassWord(){
	cout << "输入修改后的密码" << endl;
	string tem;
	pUser.setPassWord(tem);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
class guanli{
	vector<User> list;
	multimap<long long, pair<int, int> > NoMap;//用户编号索引
	multimap<Time, pair<int, int> > TimeMap;
public:
	guanli();
	~guanli();
	void addUser(){};
	void deleteUser(long long no);
	void searchByTime(Time& b, Time& e);
	void searchByNo(long long tem);
	void dongjie(int i, bool m){ m ? list[i].setFlag(true) : list[i].setFlag(false); };//冻结或解冻某用户
};
guanli::guanli(){
	int n=0, m = 0;
	User temU;
	Time temm(2016, 5, 22, 21, 9, 2);
	Record temR(1,temm,0,0,0);
	ifstream infile("date.dat");
	if (!infile.is_open()){
		cout << "文件打开失败！" << endl;
		return;
	}
	while (infile >> temU){
		infile >> n;
		for (int i = 0; i < n; i++){
			infile >> temR;
			temU.addLog(temR);
			NoMap.insert(make_pair(temU.getNO(), make_pair(m, i)));
			TimeMap.insert(make_pair(temR.getTime(), make_pair(m, i)));
		}
		list.push_back(temU);
		m++;
		temU.setLog();
	}
	infile.close();
}
guanli::~guanli(){
	ofstream ofile("date.dat", ios::in);
	if (!ofile.is_open())
		cout << "文件打开错误" << endl;
	else
		for (vector<User>::iterator itu = list.begin(); itu != list.end(); itu++){
			ofile << *itu;
		}
		ofile.close();
}
void guanli::deleteUser(long long no){
	vector<User>::iterator it = list.begin();
	if (NoMap.find(no) != NoMap.end()){
		list.erase(it + NoMap.find(no)->second.first);
		return;
	}
	else{
		cout << "用户不存在" << endl;
		return;
	}
}
void guanli::searchByNo(long long no){
	multimap<long long, pair<int, int> >::iterator pb = NoMap.lower_bound(no);
	multimap<long long, pair<int, int> >::iterator pe = NoMap.upper_bound(no);
	for (multimap<long long, pair<int, int> >::iterator it = pb; it != pe; it++){
		cout << list[it->second.first].getRecord(it->second.second) << endl;
	}
	if (pb == NoMap.end())
		cout << "不存在要查询的记录" << endl;
}
void guanli::searchByTime(Time &b, Time& e){
	multimap<Time, pair<int, int> >::iterator pb = TimeMap.lower_bound(b);
	multimap<Time, pair<int, int> >::iterator pe = TimeMap.upper_bound(e);
	for (multimap<Time, pair<int, int> >::iterator it = pb; it != pe; it++){
		cout << list[it->second.first].getRecord(it->second.second) << endl;
	}
	if (pb == TimeMap.end())
		cout << "不存在要查询的记录" << endl;
}
int main() {
	//Time a(2016, 5, 16, 21, 46, 54);
	//cout << a;
	//cin>>a;
	//cout << a;
	//Record b(a, 20, 10, 5);
	//cout << b;
	//User u(20153, "lkfdj", "skjf", "sdfj");
	//cout << u;
	//UserOP op(u);
	//op.CunKuan();
	//op.QuKuan();
	guanli tem;
	//tem.searchByNo(2015);
	system("pause");
	return 0;
}
