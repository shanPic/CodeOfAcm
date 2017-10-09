#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/////////类的定义//////////
class student{
	string name;
	long long number;
	//score score_e;
	double math;
	double computer;
	double english;
public:
	double ave;
	student(){};
	student(string a,long long b,double c,double d,double e){
		name=a;
		number=b;
		math=c;
		computer=d;
		english=e;
		ave_c();
	}
	void print(){
		cout<<"姓名："<<name<<" ";
		cout<<"学号："<<number<<" ";
		cout<<"math:"<<math<<" "<<"computer:"<<computer<<" "<<"english:"<<english<<" ";
		cout<<"平均分："<<ave<<endl;
	}
	void ave_c(){
		ave=(math+computer+english)/3;
	}
	long long p_number(){
		return number;
	}
	void set(double a,double b,double c){
		math=a;computer=b;english=c;
	}
};
///////////定义全局变量////////
map<long long,student> my_map;
map<double,long long> my_list;
int sum=0;
//////////////////////
////////菜单函数//////
void meau(){
	cout<<"选择你想进行的操作"<<endl;
	cout<<"1.       添加学生数据 "<<endl;
	cout<<"2.       修改学生数据 "<<endl;
	cout<<"3.       删除学生数据 "<<endl;
	cout<<"4.       查询学生数据 "<<endl;
	cout<<"5.       打印成绩表    "<<endl;
	cout<<"6.       输出数据项总数"<<endl;
	cout<<"7.       退出成绩管理系统"<<endl;
}
/////////模块化函数////////
void shuru(){
    system("Cls");
	string name;
	long long n;
	double m,c,e;
	cout<<"请依次输入学生的姓名，学号，数学成绩，计算机成绩，英语成绩（以空格键为分隔符),输入多组数据后键入“end”结束输入"<<endl;
    	while(cin>>name&&name!="end"){
    		cin>>n>>m>>c>>e;
  			student a(name,n,m,c,e);
			my_map[n]=a;
			my_list[a.ave]=n;
			sum++;
		}
	system("Cls");
	return;
}
void xiugai(){
	system("Cls");
	long long n;
	double a,b,c;
	cout<<"请输入需要修改数据的学生的学号"<<endl;
	cin>>n;
	cout<<"请依次输入要修改学生的修改后数学成绩，计算机成绩，英语成绩"<<endl;
	cin>>a>>b>>c;
	my_map[n].set(a,b,c);
	system("Cls");
}
void shanchu(){
	system("Cls");
cout<<"请输入要删除的学生的学号"<<endl;
long long n;
cin>>n;
my_map.erase(n);
system("Cls");
}
void chaxun(){
	system("Cls");
	cout<<"请输入要查询的学生的学号："<<endl;
	long long n;
	cin>>n;
	my_map[n].print();
	system("Cls");
}
void sort_xuehao(){
	for(auto it=my_map.begin();it!=my_map.end();it++)
		it->second.print();
	//cout<<"键入任意键返回主菜单"<<endl;
}
void sort_chengji(){
	int i=1;
	for(auto it=my_list.rbegin();it!=my_list.rend();it++,i++){
		cout<<"第"<<i<<"名：  ";
		my_map[it->second].print();
	}
}

void dayin(){
	system("Cls");
cout<<"选择你想使用的排序方法："<<endl<<"1.按照学号排序（由小到大） 2.按照成绩排序（由高到低）3.返回上一层 "<<endl;
int t;
cin>>t;
switch(t){
	case 1:sort_xuehao(); break;
	case 2:sort_chengji();break;
	case 3:return;
}
// getchar();
//for(int i=0;i<100;i++){
	//printf("\n");
//}
system("pause");
system("Cls");
return;
}
/////////主函数///////////
int main()
{
	
	int t=1,a;
	while(t){
		meau();
		cin>>a;
		switch(a){
			case 1:shuru();break;
			case 2:xiugai();break;
			case 3:shanchu();break;
			case 4:chaxun();break;
			case 5:dayin();break;
			case 6:system("Cls");cout<<"共录入了"<<sum<<"项数据"<<endl;system("pause");system("Cls");break;
			case 7:t=0;
		}
	}
	return 0;
}