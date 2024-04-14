/*
    Student Management System
    
    This program manages student records and provides functionalities like:
    1. Admission of Engineering and Medical students.
    2. Displaying individual or all student information.
    3. Calculating grades for students based on their marks.
    4. Removing a student from the system.
    
    There are two classes:
    - `Student`: Base class with common attributes and methods.
    - `EnggStudent` and `MedStudent`: Derived classes for Engineering and Medical students, respectively.
    
    The `Student` class has attributes like ID, name, age, and marks, with methods to set and get these attributes, 
    as well as to display student information and calculate grades.
    
    The derived classes (`EnggStudent` and `MedStudent`) inherit from `Student` and add additional attributes 
    like branch and internal marks (for Engineering students) and specialization and internship marks (for Medical students).
    
    The main function provides a menu-driven interface to interact with the student records:
    - Admission of students.
    - Displaying student details.
    - Calculating grades.
    - Removing a student.
    
    Author: Ranjit Kale
*/

using namespace std;
#include<iostream>
#include<string.h>
class Student
{
	int id;
	char name[20];
	int age;
	float marks;
	public:
	Student()
	{
		this->id=0;
		strcpy(this->name,"Not Given");
		this->age=0;
		this->marks=0;
	}	
	Student(int i,char* nm,int ag,float m)
	{
		this->id=i;
		strcpy(this->name,nm);
		this->age=ag;
		this->marks=m;
	}
	void setId(int i)
	{
		this->id=i;		
	}
	void setName(char* nm)
	{
		strcpy(this->name,nm);
	}
	void setAge(int ag)
	{
		this->age=ag;
	}
	void setMarks(float m)
	{
		this->marks=m;
	}
	int getId()
	{
		return this->id;
	}
	char* getName()
	{
		return this->name;
	}
	int getAge()
	{
		return this->age;
	}
	float getMarks()
	{
		return this->marks;
	}
	virtual char calGrade()=0;
	virtual void display()
	{
		cout<<"ID of Student: "<<this->getId()<<endl;
		cout<<"Name of Student: "<<this->getName()<<endl;
		cout<<"Age of Student: "<<this->getAge()<<endl;
		cout<<"Marks of Student: "<<this->getMarks()<<endl;
	}
	
};
class EnggStudent:public Student
{
	char branch[20];
	float intmark;
	public:
	EnggStudent():Student()
	{
		strcpy(this->branch,"Not Given");
		this->intmark=0;
	}
	EnggStudent(int i,char* nm,int ag,float m,char* br,float imr):Student( i, nm, ag, m)
	{
		strcpy(this->branch,br);
		this->intmark=imr;
	}
	void setBranch(char* br)
	{
		strcpy(this->branch,br);
	}
	void setIntmark(float imr)
	{
		this->intmark=imr;
	}
	char* getBranch()
	{
		return this->branch;
	}
	float getIntmark()
	{
		return this->intmark;
	}
	char calGrade()
	{
		double mark=this->getMarks()+this->getIntmark();
		if(mark<=100&&mark>=91)return 'A';
		if(mark<=90&&mark>=81)return 'B';
		if(mark<=80&&mark>=71)return 'C';
		if(mark<=70&&mark>=61)return 'D';
		if(mark<60)return 'P';
	}
	void display()
	{
		cout<<"**********************************"<<endl;
		Student::display();
		cout<<"Branch of Student: "<<this->getBranch()<<endl;
		cout<<"Internal marks of Student: "<<this->getIntmark()<<endl;
		cout<<"**********************************"<<endl;
	}
	
};
class MedStudent:public Student
{
	char spec[20];
	float moi;
	public:
	MedStudent():Student()
	{
		strcpy(this->spec,"Not Given");
		this->moi=0;
	}
	MedStudent(int i,char* nm,int ag,float m,char* spec,float moi):Student( i, nm, ag, m)
	{
		strcpy(this->spec,spec);
		this->moi=moi;
	}
	void setSpec(char* spec)
	{
		strcpy(this->spec,spec);
	}	
	void setMoi(float moi)
	{
		this->moi=moi;
	}
	char* getSpec()
	{
		return this->spec;
	}
	float getMoi()
	{
		return this->moi;
	}
	void display()
	{
		cout<<"**********************************"<<endl;
		Student::display();
		cout<<"Specialisation of Student: "<<this->getSpec()<<endl;
		cout<<"Marks of Internship of Student: "<<this->getMoi()<<endl;
		cout<<"**********************************"<<endl;
	}
	char calGrade()
	{
		double mark=this->getMarks()+this->getMoi();
		if(mark<=100&&mark>=91)return 'A';
		if(mark<=90&&mark>=81)return 'B';
		if(mark<=80&&mark>=71)return 'C';
		if(mark<=70&&mark>=61)return 'D';
		if(mark<60)return 'P';
	}
};
void getAd(Student**);
int searchStud(Student**);
void removeStud(Student**,int);
int ctr=-1;
int main()
{
	int c=0;
	Student* sp[20];
	do{
		cout<<"Press 1 for Admission"<<endl;
		cout<<"Press 2 for Display"<<endl;
		cout<<"Press 3 for Calculate Grade"<<endl;
		cout<<"Press 4 to remove student"<<endl;
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					getAd(sp);
				}
			break;
			case 2:
				{
					int ch;
					cout<<"Press 1 to Display one student info"<<endl;
					cout<<"Press 2 to display all student info"<<endl;
					cin>>ch;
					if(ch==1)
					{
						int index=searchStud(sp);
						if(index==-1)
						{
							cout<<"Student not Found";
						}
						else
						{
							sp[index]->display();
						}	
					}
					if(ch==2)
					{
						for(int i=0;i<=ctr;i++)
						{
							sp[i]->display();
						}
					}
				}
			break;
			case 3:
			{
					int ch;
					cout<<"Press 1 to Display grade of one Student"<<endl;
					cout<<"Press 2 to Display grade of all Students"<<endl;
					cin>>ch;
					if(ch==1){
						int index=searchStud(sp);
						if(index==-1)
						{
							cout<<"Student not Found";
						}
						else
						{
							cout<<"Grade is: "<<sp[index]->calGrade()<<endl;
						}
					}
					if(ch==2)
					{
						for(int i=0;i<=ctr;i++)
						{
							cout<<"Grade of "<<"ID: "<<sp[i]->getId()<<" Name: "<<sp[i]->getName()<<" is: "<<sp[i]->calGrade()<<endl;
						}
					}	
			}	
			break;
			case 4:
			{
				int index=searchStud(sp);
				if(index==-1)
				{
					cout<<"Student not Found";
				}
				else{
					removeStud(sp,index);
				}	
			}
			break;
			default:
			cout<<"Invalid Choice"<<endl;
		}
		cout <<"\nDo you want to continue and go back to the menu? Enter 1 or 0: ";
    	cin >>c;
	}while(c!=0);
	cout<<"You have exited the Website!!!!!"<<endl;
	return 0;
}
void getAd(Student** sp)
{
	cout<<"Press 1 for Engineering Student"<<endl;
	cout<<"Press 2 for Medical Student"<<endl;
					
	int ch,id,ag;
	char nm[20];
	float mr,moi,im;
	char br[20];
	char spec[20];
	cin>>ch;
	if(ch==1)
	{
		cout<<"ID of Student: ";
		cin>>id;
		cout<<"Name of Student: ";
		fflush(stdin);
		cin.getline(nm,20);
		cout<<"Age of Student: ";
		cin>>ag;
		cout<<"Marks of Student out of 80: ";
		cin>>mr;
		cout<<"Branch of Student: ";
		fflush(stdin);
		cin.getline(br,20);
		cout<<"Internal marks of Student out of 20: ";
		cin>>im;
		sp[++ctr]=new EnggStudent (id,nm,ag,mr,br,im);
	}
	if(ch==2)
	{
		cout<<"ID of Student: ";
		cin>>id;
		cout<<"Name of Student: ";
		fflush(stdin);
		cin.getline(nm,20);
		cout<<"Age of Student: ";
		cin>>ag;
		cout<<"Marks of Student out of 80: ";
		cin>>mr;
		cout<<"Specialisation of Student: ";
		fflush(stdin);
		cin.getline(spec,20);
		cout<<"Marks of Internship of Student out of 20: ";
		cin>>moi;
		sp[++ctr]=new MedStudent(id,nm,ag,mr,spec,moi);
	}
}
int searchStud(Student** sp)
{
	int id;
	cout<<"Enter the id of student: ";
	cin>>id;
	for(int i=0;i<=ctr;i++)
	{
		if(id==sp[i]->getId())
		{
			return i;
		}
	}
	return -1;
}
void removeStud(Student** sp,int index)
{
	
	for(int i=index;i<ctr;i++)
	{
		sp[index]=sp[index+1];
	}
	ctr--;
	cout<<"Student left the College"<<endl;
}

