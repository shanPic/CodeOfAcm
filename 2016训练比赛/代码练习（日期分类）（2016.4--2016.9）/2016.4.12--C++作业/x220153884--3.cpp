#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;
//////student类的定义：对应于学生这一现实中的类/////////
class student{
	string name;
	long long number;
	double math,computer,english;
	double ave;
	public:
		student();
		student(string,long long,double,double,double);
		void set_name(string a){name=a;}
		void set_number(long long a){number=a;}
		void set_math(double a){math=a;}
		void set_computer(double a){computer=a;}
		void set_english(double a){english=a;}
		void average(){ave=(math+computer+english)/3;};
		double get_ave(){return ave;}
		void print();
		void set(int m);
		void printNameNo();
};

student::student(){
math=0;
computer=0;
english=0;
ave=0;
}
student::student(string a,long long b,double c,double d,double e){
	name=a;
	number=b;
	math=c;
	computer=d;
	english=e;
	average();
}
void student::print(){
		cout<<"姓名："<<name<<" ";
		cout<<"学号："<<number<<" ";
		cout<<"math:"<<math<<" "<<"computer:"<<computer<<" "<<"english:"<<english<<" ";
		cout<<"平均分："<<ave<<endl;
	}
void student::print_l(){
cout<<name<<"\t"<< 	
}
void student::set(){
	double a;
	int m;
	cin>>n;
	cout<<"请输入要修改的数据项的序号："<<endl;
	cout<<"1.数学成绩 2.计算机成绩 3.英语成绩"<<endl;
	cin>>m;

	students[n].set_math(a);
	students[n].set_computer(b);
	students[n].set_english(c);
	system("Cls");
	}
}
////////成绩单类的定义：对应于成绩单的一系列操作//////
class student_list{
	map<long long,student> students;
	map<double,long long> students_socre;
	int sum;
public:
	student_list(){sum=0;};
	void add();
	void xiugai();
	void shanchu();
	void display();
	void chaxun();
	void menu();
};
void student_list::add(){
		system("Cls");
		string name;
		long long n;
		double math,computer,english;
		cout<<"请依次输入学生的姓名，学号，数学成绩，计算机成绩，英语成绩（以空格键为分隔符),输入多组数据后键入“end”结束输入"<<endl;
    	while(cin>>name&&name!="end"){
    		cin>>n>>math>>computer>>english;
    		student tem(name,n,math,computer,english);
  			students[n]=tem;
  			students_socre[tem.get_ave()]=n;
			sum++;
		}
	system("Cls");
	return;
}
void student_list::xiugai(){
	system("Cls");
	long long n;
	double a,b,c;
	cout<<"请输入需要修改数据的学生的学号"<<endl;
	cin>>n;
	cout<<"请依次输入要修改学生的修改后数学成绩，计算机成绩，英语成绩"<<endl;
	cin>>a>>b>>c;
	students[n].set_math(a);
	students[n].set_computer(b);
	students[n].set_english(c);
	system("Cls");
}
void student_list::shanchu(){
	system("Cls");
	cout<<"请输入要删除的学生的学号"<<endl;
	long long n;
	cin>>n;
	students.erase(n);
	sum--;
	system("Cls");
}
void student_list::chaxun(){
	system("Cls");
	cout<<"请输入要查询的学生的学号："<<endl;
	long long n;
	cin>>n;
	students[n].print();
	system("pause");
	system("Cls");
}
void student_list::display(){
	system("Cls");
cout<<"选择你想使用的排序方法："<<endl<<"1.按照学号排序（由小到大） 2.按照成绩排序（由高到低）"<<endl;
int t,i=1;
cin>>t;
switch(t){
	case 1:
		for(auto it=students.begin();it!=students.end();it++)
			it->second.print(); 
			break;
	case 2:
		for(auto it=students_socre.rbegin();it!=students_socre.rend();it++,i++){
			cout<<"第"<<i<<"名： ";
			students[it->second].print();
		}
		break;
}
system("pause");
system("Cls");
return;
}
void student_list::menu(){
	int t=1;
	int a;
	while(t){
		cout<<"                     选择你想进行的操作"<<endl;
	cout<<"              1.       添加学生数据 "<<endl;
	cout<<"              2.       修改学生数据 "<<endl;
	cout<<"              3.       删除学生数据 "<<endl;
	cout<<"              4.       查询学生数据 "<<endl;
	cout<<"              5.       打印成绩表    "<<endl;
	cout<<"              6.       输出数据项总数"<<endl;
	cout<<"              7.       退出成绩管理系统"<<endl;
		cin>>a;
		switch(a){
			case 1: add();break;
			case 2: xiugai();break;
			case 3: shanchu();break;
			case 4: chaxun();break;
			case 5: display();break;
			case 6: system("Cls");cout<<"共录入了"<<sum<<"项数据"<<endl;system("pause");system("Cls");break;
			case 7: t=0;
		}
	}
}
///////////主函数/////////
int main()
{
	student_list a;
	a.menu();
	return 0;
}