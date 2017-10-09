#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
class student
{
	string name;
	int no;
	int score[3];
	float average;
	int order;
public:
	student(int id,string na,int x,int y,int z):name(na),no(id){
				score[0]=x,score[1]=y,score[2]=z;
				order=-1,average=(score[0]+score[1]+score[2])/3;
	}
		student(){
				score[0]=score[1]=score[2]=0;
				order=-1,average=0;
	}
	int getNo(){return no;}
	float getAverage(){return average;};
	void setAverage(int avg){average=avg;}
	void setOrder(int x){order=x;}
	int getOrder(){return average;};
	string getName(){return name;}
	void setName(string name){this->name=name;}
	void display();
	
};


void student:: display()
{
	cout<<name<<"\t"<<no<<"\t"<<score[0]<<"\t"<<score[1]<<"\t"<<score[2]<<"\t"<<average<<"\t\t"<<order<<endl;
}
bool cmp1( student stu1,  student stu2) 
{
		if(stu1.getAverage()-stu2.getAverage()>=1e-9) return 1;
		else return 0;
}
bool cmp2( student stu1,  student stu2) 
{
		return stu1.getNo()<stu2.getNo();

}
class student_list
{
	student list[60];
	int n;
public:
	student_list():n(0){};	
	void add();
	void deleteStu();	
	void query();	
	void change();
	void display(int flag);//flag=1，成绩按学号排列。flag=0，成绩按名次排列
	void menuDisplay();
	void menu();	
	int search(int no);//按学号查找。找到返回在成绩表中的位置，否则返回-1
	void sortList(int flag);
};

//该函数的功能是添加一个或者多个同学基本信息。
void student_list::add()
{
	int no,x,y,z;
	string name;
	system("cls");
	cout<<" 按学号、姓名、数学、英语、c++顺序输入学生信息，学号输-1表示结束"<<endl;
	while((cin>>no)&&no!=-1)
	{
		cin>>name>>x>>y>>z;
		student s(no,name,x,y,z);
		list[n++]=s;
		sortList(1);
	}
	
}	
//该函数的功能是对改变了的成绩表进行名次更新。结果可以按名次排列也可按学号排列
void student_list::sortList(){
	sort(list,list+n,cmp1);
	int i;
	for(i=0;i<n;i++)
		list[i].setOrder(i+1);	
}

void student_list::display(int flag)//flag=1，按学号排列；flag=0，按名次排列
{
	if(flag) sort(list,list+n,cmp2);
	else sort(list,list+n,cmp1);
	cout<<"姓名"<<"\t"<<"学号"<<"\t"<<"数学"<<"\t"<<"英语"<<"\t"<<"c++"<<"\t"<<"平均成绩"<<"\t"<<"名次"<<endl;
	for (int i=0;i<n;i++)
		list[i].display();	
}
//该函数的功能是按学号查找。找到返回在成绩表中的位置，否则返回-1
int student_list::search(int no)
{
	int i;
	for( i=0;i<n;i++)
		if(list[i].getNo()==no)
			return i;
	return -1;
}
//该函数的功能是实现按学号进行的查询操作，并输出查找的结果
void student_list::query()
{
	int no,i;
	system("cls");
	cout<<"请输入要查询同学的学号，按-1结束查询:";
	while(cin>>no&&no!=-1)
	{
				i=search(no);
				if(i!=-1){
					cout<<"姓名"<<"\t"<<"学号"<<"\t"<<"数学"<<"\t"<<"英语"<<"\t"<<"c++"<<"\t"<<"平均成绩"<<"\t"<<"名次"<<endl;
					list[i].display();
					cout<<"请输入要查询同学的学号，按-1结束查询:";
				}
				else
					cout<<"学号输入有误，请重输，输入-1结束查询"<<endl;
	}
}
//该函数的功能是实现按学号进行修改操作，并输出查找的结果
void student_list::change()
{
	
}
void student_list::deleteStu()
{
	
}
void student_list::menuDisplay()
	{
		cout<<"********************************************"<<endl;
		cout<<"*"<<"      Welcome to us this simple system    "<<"*"<<endl;
		cout<<"*"<<"         0:        exit                    "<<"*"<<endl;
		cout<<"*"<<"         1:        add                    "<<"*"<<endl;
		cout<<"*"<<"         2:        delete                 "<<"*"<<endl;
		cout<<"*"<<"         3:        query                  "<<"*"<<endl;
		cout<<"*"<<"         4:        change               "<<"*"<<endl;
		cout<<"*"<<"         5:        display  by no    "<<"*"<<endl;
		cout<<"*"<<"         6:       display  by order "<<"*"<<endl;
		cout<<"********************************************"<<endl;
		return;
	}
	void student_list::menu(){
		int choose;
		while(1)
	{
		menuDisplay();
		cout<<"Please input you choice:";
		cin>>choose;
		if(!choose) break;
		switch(choose)
		{
		case 1:
			add();			
			break;
		case 2:
			deleteStu();
			break;
		case 3:
			query();
			break;
		case 4:
			change();
			break;		
		case 5:
			display(1);
			break;	
		case 6:
			display(0);
			break;		
		}
		system("pause");
		system("cls");
	}
		}


int main()
{
	student_list c;	
	c.add();
	c.display(1);
	c.query();
	c.display(0);
	//c.menu();
	return 0;
}



	#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
class student
{
	string name;
	int no;
	int score[3];
	float average;
	int order;
public:
	student(int id,string na,int x,int y,int z):name(na),no(id){
				score[0]=x,score[1]=y,score[2]=z;
				order=-1,average=(score[0]+score[1]+score[2])/3;
	}
		student(){
				score[0]=score[1]=score[2]=0;
				order=-1,average=0;
	}
	int getNo(){return no;}
	float getAverage(){return average;};
	void setAverage(int avg){average=avg;}
	void setOrder(int x){order=x;}
	int getOrder(){return average;};
	string getName(){return name;}
	void setName(string name){this->name=name;}
	void display();
	
};


void student:: display()
{
	cout<<name<<"\t"<<no<<"\t"<<score[0]<<"\t"<<score[1]<<"\t"<<score[2]<<"\t"<<average<<"\t\t"<<order<<endl;
}
bool cmp1( student stu1,  student stu2) 
{
		if(stu1.getAverage()-stu2.getAverage()>=1e-9) return 1;
		else return 0;
}
bool cmp2( student stu1,  student stu2) 
{
		return stu1.getNo()<stu2.getNo();

}
class student_list
{
	student list[60];
	int n;
public:
	student_list():n(0){};	
	void add();
	void deleteStu();	
	void query();	
	void change();
	void display(int flag);//flag=1£¬³É¼¨°´Ñ§ºÅÅÅÁÐ¡£flag=0£¬³É¼¨°´Ãû´ÎÅÅÁÐ
	void menuDisplay();
	void menu();	
	int search(int no);//°´Ñ§ºÅ²éÕÒ¡£ÕÒµ½·µ»ØÔÚ³É¼¨±íÖÐµÄÎ»ÖÃ£¬·ñÔò·µ»Ø-1
	void sortList(int flag);
};

//¸Ãº¯ÊýµÄ¹¦ÄÜÊÇÌí¼ÓÒ»¸ö»òÕß¶à¸öÍ¬Ñ§»ù±¾ÐÅÏ¢¡£
void student_list::add()
{
	int no,x,y,z;
	string name;
	system("cls");
	cout<<" °´Ñ§ºÅ¡¢ÐÕÃû¡¢ÊýÑ§¡¢Ó¢Óï¡¢c++Ë³ÐòÊäÈëÑ§ÉúÐÅÏ¢£¬Ñ§ºÅÊä-1±íÊ¾½áÊø"<<endl;
	while((cin>>no)&&no!=-1)
	{
		cin>>name>>x>>y>>z;
		student s(no,name,x,y,z);
		list[n++]=s;
		sortList(1);
	}
	
}	
//¸Ãº¯ÊýµÄ¹¦ÄÜÊÇ¶Ô¸Ä±äÁËµÄ³É¼¨±í½øÐÐÃû´Î¸üÐÂ¡£½á¹û¿ÉÒÔ°´Ãû´ÎÅÅÁÐÒ²¿É°´Ñ§ºÅÅÅÁÐ
void student_list::sortList(){
	sort(list,list+n,cmp1);
	int i;
	for(i=0;i<n;i++)
		list[i].setOrder(i+1);	
}

void student_list::display(int flag)//flag=1£¬°´Ñ§ºÅÅÅÁÐ£»flag=0£¬°´Ãû´ÎÅÅÁÐ
{
	if(flag) sort(list,list+n,cmp2);
	else sort(list,list+n,cmp1);
	cout<<"ÐÕÃû"<<"\t"<<"Ñ§ºÅ"<<"\t"<<"ÊýÑ§"<<"\t"<<"Ó¢Óï"<<"\t"<<"c++"<<"\t"<<"Æ½¾ù³É¼¨"<<"\t"<<"Ãû´Î"<<endl;
	for (int i=0;i<n;i++)
		list[i].display();	
}
//¸Ãº¯ÊýµÄ¹¦ÄÜÊÇ°´Ñ§ºÅ²éÕÒ¡£ÕÒµ½·µ»ØÔÚ³É¼¨±íÖÐµÄÎ»ÖÃ£¬·ñÔò·µ»Ø-1
int student_list::search(int no)
{
	int i;
	for( i=0;i<n;i++)
		if(list[i].getNo()==no)
			return i;
	return -1;
}
//¸Ãº¯ÊýµÄ¹¦ÄÜÊÇÊµÏÖ°´Ñ§ºÅ½øÐÐµÄ²éÑ¯²Ù×÷£¬²¢Êä³ö²éÕÒµÄ½á¹û
void student_list::query()
{
	int no,i;
	system("cls");
	cout<<"ÇëÊäÈëÒª²éÑ¯Í¬Ñ§µÄÑ§ºÅ£¬°´-1½áÊø²éÑ¯:";
	while(cin>>no&&no!=-1)
	{
				i=search(no);
				if(i!=-1){
					cout<<"ÐÕÃû"<<"\t"<<"Ñ§ºÅ"<<"\t"<<"ÊýÑ§"<<"\t"<<"Ó¢Óï"<<"\t"<<"c++"<<"\t"<<"Æ½¾ù³É¼¨"<<"\t"<<"Ãû´Î"<<endl;
					list[i].display();
					cout<<"ÇëÊäÈëÒª²éÑ¯Í¬Ñ§µÄÑ§ºÅ£¬°´-1½áÊø²éÑ¯:";
				}
				else
					cout<<"Ñ§ºÅÊäÈëÓÐÎó£¬ÇëÖØÊä£¬ÊäÈë-1½áÊø²éÑ¯"<<endl;
	}
}
//¸Ãº¯ÊýµÄ¹¦ÄÜÊÇÊµÏÖ°´Ñ§ºÅ½øÐÐÐÞ¸Ä²Ù×÷£¬²¢Êä³ö²éÕÒµÄ½á¹û
void student_list::change()
{
	
}
void student_list::deleteStu()
{
	
}
void student_list::menuDisplay()
	{
		cout<<"********************************************"<<endl;
		cout<<"*"<<"      Welcome to us this simple system    "<<"*"<<endl;
		cout<<"*"<<"         0:        exit                    "<<"*"<<endl;
		cout<<"*"<<"         1:        add                    "<<"*"<<endl;
		cout<<"*"<<"         2:        delete                 "<<"*"<<endl;
		cout<<"*"<<"         3:        query                  "<<"*"<<endl;
		cout<<"*"<<"         4:        change               "<<"*"<<endl;
		cout<<"*"<<"         5:        display  by no    "<<"*"<<endl;
		cout<<"*"<<"         6:       display  by order "<<"*"<<endl;
		cout<<"********************************************"<<endl;
		return;
	}
	void student_list::menu(){
		int choose;
		while(1)
	{
		menuDisplay();
		cout<<"Please input you choice:";
		cin>>choose;
		if(!choose) break;
		switch(choose)
		{
		case 1:
			add();			
			break;
		case 2:
			deleteStu();
			break;
		case 3:
			query();
			break;
		case 4:
			change();
			break;		
		case 5:
			display(1);
			break;	
		case 6:
			display(0);
			break;		
		}
		system("pause");
		system("cls");
	}
		}


int main()
{
	student_list c;	
	c.add();
	c.display(1);
	c.query();
	c.display(0);
	//c.menu();
	return 0;
}



	