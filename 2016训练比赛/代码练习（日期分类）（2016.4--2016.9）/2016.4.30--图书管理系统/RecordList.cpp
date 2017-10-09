#include<iostream>
#include<vector>
using namespace std;
class Time
{
	int year;
	int month;
	int day;
public:
	int getYear(){ return year; }
	int getMonth(){ return month; }
	int getDay(){return day;}
	void setYear(int a):year(a){}
	void setMonth(int a):month(a){}
	void setDay(int a):day(a){}
	friend ostream& operator<<(ostream &output, const Time &a);
}; 
class Record{
	Time begin;
	Time end;
	long long isbn;
public:
	Record();
	Record(int,int,int,long long);
	~Record();
	void setRecordBegin(int,int,int);
	Time getRecordBegin();
	void setRecordEnd(int,int,int);
	Time getRecordEnd();
	friend ostream& operator<<(ostream &output,const Record &);

};
class RecordList
{
	vector<Record> list;


	
public:
	RecordList();
	~RecordList();
	void add
};
ostream& operator<<(ostream &output,const Time &a){
	output<<a.year<<"\t"<<a.month<<"\t"<<a.year<<"\t";
	return output;
}
//Time& operator+(i)
ostream & operator<<(ostream &output,const Record& a ){
	output<<a.begin<<"\t"<<a.end<<"\t"<<a.isbn<<"\t";
		return output;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	Time a;

}