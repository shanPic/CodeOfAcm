#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//////////数据类:book///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Book{
string name;
string author;
long long ISBN;
public:
	void setBookName(string a){name=a;};
	string getBookName(){return name;};
	void setBookAuthor(string a){author=a;};
	string getBookAuthor(){return author;};
	void setBook_ISBN(long long a){ISBN=a;};
	long long getBook_ISBN(){return ISBN;};

};
///////////user类//////////////////////////////////////////////////////////////////////////////////////
class User{
	string name;
	long long no;
	vector<long long> yijie;
public:
	void setUserName(string a){name=a;};
	string getUserName(){return name;};
	void setUserNo(long long a){no=a;};
	long long getUserNo(){return no;};
	viod UserSearch();//查询函数，查询要借阅的书
};
////////////////////////Date类///////////////////////////////////////////
class Date{
	int year;
	int month;
	int day;
	
};
///////////////////////////////////////////Record类///////////////////////
class Record{
	string name;
	Date begin;
	Date end;

};
///////////////BA（图书管理员）/////////////////////////////////////////////////////////////////////////////
class BA{
public:
	void jieshu(long long ISBN,long long xuehao);
	void huanshu(long long ISBN,long long xuehao);
	void search(int flag);

};
/////////SA类（系统管理员）///////////////////////////////////////////////////////////////////////////////
class SA{
	int sumBook;
	int sumUser;
	vector<Book> books;
	vector<User> users;
public:
	friend BA;
	void set_SA_sumBook(int a){sumBook=a;};
	int get_SA_sumBook(){return sumBook;};
	void set_SA_sumUser(int a){sumUser=a;};
	int grt_SA_sumUser(){return sumUser;};
	void add_SA_book();
	void add_SA_user();
	void delete_SA_book();
	void delete_SA_user();
	void query_SA_book();
	void query_SA_user();
	void change_SA_book();
	void change_SA_user();
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	Book a;
	//SA a;
	//BA a;
	//user b;
}