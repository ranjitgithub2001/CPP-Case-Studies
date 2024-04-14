/*
 * Toll Calculation System
 * 
 * This program calculates the toll fee for different types of vehicles based on the number of persons.
 * 
 * Features:
 * - The program supports calculating toll for Two Wheelers, Three Wheelers, Four Wheelers, and Heavy Wheelers.
 * - The toll is calculated based on a base rate plus an additional charge per extra person.
 * 
 * Vehicle Classes:
 * 1. TwoWheeler: Base toll is 20, with an additional charge of 10 for each person beyond 2.
 * 2. ThreeWheeler: Base toll is 30, with an additional charge of 20 for each person beyond 3.
 * 3. FourWheeler: Base toll is 40, with an additional charge of 40 for each person beyond 4.
 * 4. HeavyWheeler: Base toll is 60, with an additional charge of 100 for each person beyond 6.
 * 
 * How to Use:
 * - Run the program and select the type of vehicle.
 * - Enter the number of persons in the vehicle.
 * - The program will calculate and display the toll amount.
 * - The user can continue to calculate tolls for different vehicles until they choose to exit.
 * 
 * Author: Ranjit Kale 
 */

#include<iostream>
using namespace std;
class Vehicle{
	int person;
	public :
	Vehicle(int person)
	{
		this->person=person;
	}
	void setPerson(int person)
	{
		this->person=person;
	}
	int getPerson()
	{
		return this->person;
	}
	virtual int toll()=0;
};
class TwoWheeler: public Vehicle
{
	public:
	TwoWheeler(int person):Vehicle(person)
	{
	}
	int toll()
	{
		int toll=20;
		if(this->getPerson()>2)
		{
			toll=toll+(this->getPerson()-2)*10;
		}
		return toll;
	}
};
class ThreeWheeler: public Vehicle
{
	public:
	ThreeWheeler(int person):Vehicle(person)
	{
	}
	int toll()
	{
		int toll=30;
		if(this->getPerson()>3)
		{
			toll=toll+(this->getPerson()-3)*20;
		}
		return toll;
	}
};
class FourWheeler: public Vehicle
{
	public:
	FourWheeler(int person):Vehicle(person){
	}
	int toll()
	{
		int toll=40;
		if(this->getPerson()>4)
		{
			toll=toll+(this->getPerson()-4)*40;
		}
		return toll;
	}
};
class HeavyWheeler: public Vehicle{
	public:
	HeavyWheeler(int person):Vehicle(person)
	{
	}
	int toll()
	{
		int toll=60;
		if(this->getPerson()>6)
		{
			toll=toll+(this->getPerson()-6)*100;
		}
		return toll;
	}
};
int main()
{
	int exit;
	do{
		cout<<"Select the Type of Vehicle"<<endl;
		cout<<"1.Two Wheelwe"<<endl;
		cout<<"2.Three Wheeler"<<endl;
		cout<<"3.Four Wheeler"<<endl;
		cout<<"4.Heavy Wheeler"<<endl;
		int choice;
		cout<<"Enter your choice=";
		cin>>choice;
		Vehicle* v;
		switch(choice){
			case 1:{
				cout<<"Enter the number of persons=";
				int n;
				cin>>n;
				v=new TwoWheeler(n);
				cout<<"Toll="<<v->toll()<<"\n";
				break;
			}
			case 2:{
				cout<<"Enter the number of persons=";
				int n;
				cin>>n;
				v=new ThreeWheeler(n);
				cout<<"Toll="<<v->toll()<<"\n";
				break;
			}
			case 3:{
				cout<<"Enter the number of persons=";
				int n;
				cin>>n;
				v=new FourWheeler(n);
				cout<<"Toll="<<v->toll()<<"\n";
				break;
			}
			case 4:{
				cout<<"Enter the number of persons=";
				int n;
				cin>>n;
				v=new HeavyWheeler(n);
				cout<<"Toll="<<v->toll()<<"\n";
				break;
			}
			default:
				cout<<"Enter the valid option\n";
		}
		cout<<"Do you want to continue press 1 for yes and 0 for no=";
		cin>>exit;
	}while(exit);
}
