#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stdio.h>
#include<fstream>
#include<algorithm>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////借阅规则类////////////////////////////////////////////////////////
class Rule{
public:
	const int days;//借阅天数
	const int books;//借阅本数
	Rule() :days(60),books(10){};
	Rule(const int a,const int b):days(a),books(b){ };
}LibraryRule;
//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////RecordList类及相关类的声明与定义////////////////////////
class Time//时间类，重载了与时间相关的一些操作,由于时间关系，+运算符只进行了声明，未定义
{
	int year;
	int month;
	int day;
public:
	Time(){};
	Time(int y, int m, int d) :year(y), month(m), day(d){};
	int getYear(){ return year; }
	int getMonth(){ return month; }
	int getDay(){ return day; }
	void setYear(int a){ year = a; }
	void setMonth(int a) { month = a; }
	void setDay(int a) { day = a; }
	////////////必要的运算符重载///////
	friend ostream& operator<<(ostream &output, const Time&);
	friend istream& operator>>(istream &in, Time &a);
	void operator=(Time &b){b.year = this->year;b.month = this->month;b.day = this->day;}
	friend bool operator<(const Time& cmp1,const Time& cmp2);
	friend bool operator==(const Time&cmp1, const Time&cmp);
	Time operator+(int a);
};
////////
istream& operator>>(istream &in, Time &a){
	in >> a.year >> a.month >> a.day;
	return in;
}
////////
bool operator==(const Time&cmp1, const Time&cmp){
	if (cmp1.day == cmp.day&&cmp1.month == cmp.month&&cmp1.year == cmp.year)
		return true;
	else return false;
}
////////
Time Time::operator+(int a){
	return *this;//////时间关系还未具体写，每个月的天数不同，还需要判断一下，用数组简便一些，纯属体力劳动，写完框架再写。。。。
}
////////
ostream& operator<<(ostream &output, const Time &a){
	output << a.year << "\t" << a.month << "\t" << a.year << "\t";
	return output;
}
///////
bool operator<(const Time&cmp1,const Time& cmp){
	if (cmp1.year < cmp.year || (cmp1.month < cmp.month&&cmp1.year == cmp.year) || (cmp1.year == cmp.year&&cmp1.month == cmp.month&&cmp1.day < cmp.day))
		return true;
	else return false;
}
////////////////////////////////////////////////////////////
class Record{
	Time begin;//借阅时间
	Time end;//理论上最晚的还书时间
	long long xuehao;//此次借阅的User对象
	long long shuhao;//此次借阅的书号
	Time returnTime;//实际还书的时间
	bool flag;//标记变量，是否还书，此变量与returnTime变量在还书函数中被修改
public:
	Record(){};
	Record(Time a, long long c, long long x) :begin(a), shuhao(c),xuehao(x),flag(false){};
	~Record(){};
	void setRecordBegin(int, int, int);
	Time getRecordBegin(){return begin;}
	void setRecordEnd(int a, int b, int c){ Time tem(a, b, c); end = tem; }
	Time getRecordEnd(){return end; }
	Time get_returnTime(){ return returnTime; }
	void setReturnTime(int a){ this->returnTime=this->begin + a; }
	void setFlag(){ flag = true; };
	void setXuehao(long long a){ xuehao = a; }
	long long getShuhao(){ return shuhao; };
	long long getXuehao(){ return xuehao; }

	friend ostream& operator<<(ostream &output, const Record &);
	friend istream& operator>>(istream&input, Record &r);

};
istream& operator>>(istream&in, Record &r){
	in >> r.begin >> r.end >> r.returnTime >> r.flag >> r.shuhao >> r.xuehao;
	return in;
}
ostream & operator<<(ostream &output, const Record& a){
	output << a.begin << "\t" << a.end << "\t" << a.returnTime << "\t" <<a.flag<<"\t"<< a.shuhao << "\t"<<a.xuehao<<"\t";
	return output;
}
////////////////////////////////////////////////////////////////
class RecordList//借阅记录列表，借阅记录在此类中被组织起来
{
	vector<Record> list;
	multimap<long long, int> shuhaoList;
	multimap<Time, int> TimeListOut;//按照借出时间建立索引
	multimap<Time, int> TimeListEnd;//按照应还时间建立索引
	multimap<long long, int> xuehaoList;//按照结束用户的学号建立索引
	static int sum;//记录的总数
public:
	RecordList(){};
	~RecordList(){};
	void add();
	void deleteRecord();
	//void change();
	void load();
	void save();
	vector<int> search1(long long);//按书号查找
	vector<int> search2(const Time);//按借出日期查找
	vector<int> search3(const Time);//按应还时间查找
	vector<int> search4(long long);//按学号查找
	void display();
};
int RecordList::sum = 0;
void RecordList::add(){
	system("Cls");
	long long n,x;
	int y, m, d;
	cout << "请依次输入借出书籍的书号 借出时间 借书学生学号（示例(不同类型数据之间有空格)：01456585 2016.5.1 20153884）,输入多组数据后键入“-1”结束输入" << endl;
	while (cin >> n&&n != -1){
		scanf("%d.%d.%d", &y, &m, &d);
		cin >> x;
		Time tem(y, m, d);
		Record temR(tem, n,x);
		temR.setReturnTime(LibraryRule.days);
		list.push_back(temR);
		sum++;
		shuhaoList.insert(make_pair(n, sum - 1));
	
	}
	system("Cls");
	return;
}
void RecordList::deleteRecord(){
	cout << "1.按学号删除 2.按借出日期删除 3.按应还日期删除 4.按学号删除 -1.返回" << endl;
	int m;
	long long temno;
	char temc;
	vector<int> res;
	Time tem;
	auto ittem = list.begin();
	cin >> m;
	if (m == -1)
		return;
	switch (m){
	case 1:cout << "input:"; cin >> temno; res = search1(temno); 
		for (vector<int>::iterator it = res.begin(); it != res.end(); it++){
			cout << list[*it] << "是否删除此数据？选择y/n";
				cin >> temc;
				if (temc == 'y'){
					for (auto it2 = shuhaoList.begin(); it2 != shuhaoList.end(); it2++)
						if (it2->second == *it)
							shuhaoList.erase(it2);


					//此部分的代码作用是删除索引中的对应得数据对，需要写多个，实在太多，不方便阅读，暂时省略
					ittem += *it;
					list.erase(ittem);
				}
		}
		break;

	case 2:
	case 3:
	case 4:break;//case 2，3，4与case 1大同小异，这一部分暂时省略。。。。。
	}

}
void RecordList::load(){
	Record r;
	int i = 0;
	ifstream in("RecordList.date", ios::in);
	if (!in)
		return;
	i = 0;
	while (in >> r)
	{

		list.push_back(r);
		shuhaoList.insert(make_pair(r.getShuhao(), i));
		xuehaoList.insert(make_pair(r.getXuehao(), i));
		TimeListOut.insert(make_pair(r.getRecordBegin(), i));
		TimeListEnd.insert(make_pair(r.getRecordEnd(), i));
		i++;
	}
	in.close();
}
void RecordList::save(){
	ofstream outfile("RecordList.date", ios::out);
	if (!outfile)
		return;
	for (vector<Record>::iterator itR = list.begin(); itR != list.end(); itR++)
	{
		outfile<< *itR;
	}
	outfile.close();

}
vector<int> RecordList::search1(long long n){
	vector<int> res;
	multimap<long long,int>::iterator ite = shuhaoList.find(n);
	if (ite == shuhaoList.end()){
		cout << "无此记录" << endl;
		return res;
	}
	for (; ite->first == n; ite++)
		res.push_back(ite->second);
	return res;
}
vector<int> RecordList::search2(const Time a){
	vector<int> res;
	multimap<Time, int>::iterator ite = TimeListOut.find(a);
	if (ite == TimeListOut.end()){
		cout << "无此记录" << endl;
		return res;
	}
	for (; ite->first == a; ite++)
		res.push_back(ite->second);
	return res;
}
//vector<int> RecordList::search3(const Time a){  
}
//vector<int> RecordList::search4(long long){ 
 }
//与search1和seach2的写法完全相同，暂时省略。老师不要骂我偷懒。。。
void RecordList::display(){
	for (vector<Record>::iterator itr = list.begin(); itr != list.end(); itr++)
		cout << *itr << endl;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////Book类///////////////////////////////////////////////////////
class book
{
	string name;
	string author;
	long long isbn;
	bool flag;//标记变量，表示此书是否可借，只对SA与BA可见，我的想法是User类的对象在查询时调用BA类对象的查询函数，因此此变量无需对User类可见
public:
	book();
	~book();
	book(string a, string b, long long c) :name(a), author(b), isbn(c),flag(true){};
	void setBookName(string a){ name = a; };
	string getBookName(){ return name; };
	void setBookAuthor(string a){ author = a; };
	string getBookAuthor(){ return author; };
	void setBook_ISBN(long long a){ isbn = a; };
	long long getBook_ISBN(){ return isbn; };
	void print();
};
void book::print(){
	cout << name << "\t" << author << "\t" << isbn << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////User类///////////////////////////////////////////////////////
class User
{
	string name;
	long long no;
	vector<long long> yijie;//User类对象的借阅记录，long long 变量为书号，利用此变量，可索引到book对象，并搜索 在SA中的RecordList类的对象 的成员
	int sum;
public:
	User();
	~User();
	User(string, long long);
	void setUserName(string a){ name = a; };
	string getUserName(){ return name; };
	void setUserNo(long long a){ no = a; };
	long long getUserNo(){ return no; };
	void UserSearchBook();//查询函数，查询要借阅的书,此函数去调用BA类中的查询函数
	void UserSearchRecord(const long long no);//查询函数,查询此User对象的借阅记录，通过调用SA中‘搜索RecordList’的函数实现
	void UserBorrow(long long);//借书,调用BA类中的借书函数
	void UserReturn(long long);//还书，调用BA类中的还书函数
};
User::User(string a, long long b) :name(a), no(b){};

//////////////////////////////////////////////////////主函数////////////////////////////////////////////////////
int main(){
	//Rule LibraryRule();
	Time a;
	//Record b;
	RecordList tem;
	//tem.add();
	//tem.load();
	//tem.search1(1);
	//tem.search2(a);
	tem.deleteRecord();
	system("pause");
}