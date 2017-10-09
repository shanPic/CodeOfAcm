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
	double score[3];//0-math,1-computer,2-english;
	//double math,computer,english;
	double ave;
	int order;
	public:
		student();
		student(string,long long,double,double,double);
		void set_name(string a){name=a;}
		string get_name(){return name;}
		void set_number(long long a){number=a;}
		void set_math(double a){score[0]=a;}
		void set_computer(double a){score[1]=a;}
		void set_english(double a){score[2]=a;}
		void average(){ave=(score[0]+score[1]+score[2])/3;};
		double get_ave(){return ave;}
		void print();
		//void set(int m);
		void set_order(int a){order=a;}
        int get_order(){return order;}
		void printList();
};

student::student(){;

score[0]=0;
score[1]=0;
score[2]=0;
ave=0}
student::student(string a,long long b,double c,double d,double e){
	name=a;
	number=b;
	score[0]=c;
	score[1]=d;
	score[2]=e;
	average();
}
void student::print(){
		cout<<"姓名："<<name<<"\t";
		cout<<"学号："<<number<<"\t";
		cout<<"math:"<<score[0]<<"\t"<<"computer:"<<score[1]<<"\t"<<"english:"<<score[2]<<"\t";
		cout<<"平均分："<<ave<<"\t";
		cout<<"名次 :"<<order<<endl;
	}
void student::printList(){
	cout<<name<<"\t"<<number<<"\t"<<score[0]<<"\t"<<score[1]<<"\t"<<score[2]<<"\t"<<ave<<"\t"<<order<<endl;
}
////////成绩单类的定义：对应于成绩单的一系列操作//////
class student_list{
	map<long long,student> students;
	map<double,long long> students_socre;
	map<string,long long> students_xingming;
	int sum;
public:
	student_list(){sum=0;};
	void add();
	void xiugai();
	void shanchu();
	void display();
	void chaxun();
	void menu();
	void sort();
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
  			students_xingming[tem.get_name()]=n;
			sum++;
			sort();
		}
	system("Cls");
	return;
}
void student_list::sort(){
	int i=1;
	for(auto it=students_socre.rbegin();it!=students_socre.rend();it++,i++){
			    students[it->second].set_order(i);
	}
}
void student_list::xiugai(){
	system("Cls");
	long long n;
	int m=1,flag=1;
	double a;
	string b;
	while(1){ 
        cout<<"请输入需要修改数据的学生的学号,返回主菜单请键入“-1”"<<endl;
        cin>>n;
        if(n==-1){
            system("Cls");
            return;
        }
        students[n].print();
        while(flag){
        	cout<<"请选择要修改的数据项\t1.数学成绩\t2.计算机成绩\t3.英语成绩\t4.姓名\t-1.返回上一层"<<endl;
            cin>>m;           
            switch(m){
                case 1:cout<<"请输入要修改后的成绩："<<endl;cin>>a;students[n].set_math(a);cout<<"数据更新：";sort();students[n].print();break;
                case 2:cout<<"请输入要修改后的成绩："<<endl;cin>>a;students[n].set_computer(a);cout<<"数据更新：";sort();students[n].print();break;
                case 3:cout<<"请输入要修改后的成绩："<<endl;cin>>a;students[n].set_english(a);cout<<"数据更新：";sort();students[n].print();break;
                case 4:cout<<"请输入要修改后的姓名："<<endl;cin>>b;students[n].set_name(b);cout<<"数据更新：";sort();students[n].print();break;
                case -1:flag=0;break;
        }
        }
	}
}
void student_list::shanchu(){
	long long n;
	char temp;
	shanchuFlag:system("Cls");
	cout<<"请输入要删除的学生的学号,返回主菜单键入“-1”"<<endl;
		cin>>n;
	if(n==-1){
		system("cls");
		return;
	}
	if(students.find(n)!=students.end()){
		students_socre.erase(students[n].get_ave());
		students_xingming.erase(students[n].get_name());
		students.erase(n);
		sort();
		sum--;
		system("Cls");
	}
	else {
		system("cls");
		cout<<"不存在此学号，请重新输入"<<endl;
		system("pause");
		goto shanchuFlag;
	}
	cout<<"学号为"<<n<<"的学生数据已删除，继续删除请键入“c”,返回主菜单键入“q”"<<endl;
	cin>>temp;
	switch(temp){
		case 'c':goto shanchuFlag;
		case 'q':system("cls");return;
	}
}
void student_list::chaxun(){
	int mode;string temp;
	system("cls");
	cout<<"选择你想使用的检索方法:\t1.按照学号\t2.按照姓名"<<endl;
	cin>>mode;
	switch(mode){
		case 1:
				system("Cls");
				chaxunFlag2:cout<<"请输入要查询的学生的学号(返回主菜单键入-1)："<<endl;
				long long n;
				chaxunFlag1:cin>>n;
				if(n==-1){
					system("cls");
					return;
				}
				if(students.find(n)!=students.end()){
					students[n].print();
					system("pause");
					system("Cls");
					goto chaxunFlag2;
			    }
			    else{
			    	system("cls");
			    	cout<<"要查询的学号不存在，请重新输入,返回主菜单请键入“-1”"<<endl;
			    	goto chaxunFlag1;
			    }
			    break;
		case 2:
				system("Cls");
				chaxunFlag4:cout<<"请输入要查询的学生的姓名(返回主菜单键入-1)："<<endl;
				chaxunFlag3:cin>>temp;
				if(temp=="-1"){
					system("cls");
					return;
				}
				if(students_xingming.find(temp)!=students_xingming.end()){
					students[students_xingming[temp]].print();
					system("pause");
					system("Cls");
					goto chaxunFlag4;
			    }
			    else{
			    	system("cls");
			    	cout<<"要查询的姓名不存在，请重新输入,返回主菜单请键入“-1”"<<endl;
			    	goto chaxunFlag3;
			    }
			    break;	
	}
}
void student_list::display(){
	system("Cls");
cout<<"选择你想使用的排序方法："<<endl<<"1.按照学号排序（由小到大） 2.按照成绩排序（由高到低）"<<endl;
int t,i=1;
cin>>t;
switch(t){
	case 1:
		cout<<"姓名"<<"\t"<<"学号"<<"\t"<<"数学"<<"\t"<<"英语"<<"\t"<<"c++"<<"\t"<<"平均分"<<"\t"<<"名次"<<endl;
		for(auto it=students.begin();it!=students.end();it++)
			it->second.printList();
			break;
	case 2:
		cout<<"姓名"<<"\t"<<"学号"<<"\t"<<"数学"<<"\t"<<"英语"<<"\t"<<"c++"<<"\t"<<"平均分"<<"\t"<<"名次"<<endl;
		for(auto it=students_socre.rbegin();it!=students_socre.rend();it++,i++){
			students[it->second].printList();
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
///////////////////////////////////////////////

