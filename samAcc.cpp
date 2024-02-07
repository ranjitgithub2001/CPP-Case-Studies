#include <iostream>
#include <string.h>
using namespace std;

class Account
{
	long long accNo;
	char holder[30];
	double balance;
	
	public:
		//parameterized constructor
		Account(const char* holder, double balance){
			static long long accNumber = 12345678901;
			this->accNo = accNumber;
			accNumber++;
			
			strcpy(this->holder, holder);
			this->balance = balance;
		}
		
		//setters & getters
		void setHolder(const char* holder){
			strcpy(this->holder, holder);
		}
		void setBalance(double balance){
			this->balance = balance;
		}
		const char* getHolder(){
			return this->holder;
		}
		double getBalance(){
			return this->balance;
		}
		long long getAccountNumber(){
			return this->accNo;
		}
		
		void deposit(double amount){
			this->balance = this->balance + amount;
			cout<<"\nAmount Deposited Successfuly.. :)\n";
		}
		virtual double withdraw(double amount) = 0;
		virtual void displayDetails(){
			cout<<"Account Number         : "<<this->accNo;
			cout<<"\nHolder Name            : "<<this->holder;
			cout<<"\nCurrent Balance        : "<<this->balance<<endl;
		}
};
class Saving:public Account
{
	double miniLimit;
	
	public:
		Saving(const char* holder, double balance):Account(holder, balance)
		{ 
			this->miniLimit = 500;
		}
		
		void setMiniLimit(double miniLimit){
			this->miniLimit = miniLimit;
		}
		double getMiniLimit(){
			return this->miniLimit;
		}
		double withdraw(double amount){
			if(amount <= (this->getBalance() - this->miniLimit)){
				this->setBalance(this->getBalance() - amount);
				cout<<"\nAmount of "<<amount<<" withdrawl Successful..\n";
			}
			else{
				cout<<"\nInsufficient balance!!!\n";
			}
		}
		void displayDetails(){
			Account::displayDetails();
			cout<<"Account type           : Saving Account\n";
			cout<<"Minimum Balance Limit  : "<<this->miniLimit<<endl;
		}
};
class Current:public Account
{
	double overDraftLimit;
	
	public:
		Current(const char* holder, double balance):Account(holder, balance)
		{ 
			this->overDraftLimit = -10000;
		}
		void setOverDraftLimit(double overDraftLimit){
			this->overDraftLimit = overDraftLimit;
		}
		double getOverDraftLimit(){
			return this->overDraftLimit;
		}
		double withdraw(double amount){
			if(this->overDraftLimit < (this->getBalance() - amount)){
				this->setBalance(this->getBalance() - amount);
				cout<<"\nAmount of "<<amount<<" withdrawl Successful..\n";
			}
			else{
				cout<<"\nInsufficient balance!!!\n";
			}
		}
		void displayDetails(){
			Account::displayDetails();
			cout<<"Account type           : Current Account\n";
			cout<<"Overdraft Balance Limit: "<<this->overDraftLimit<<endl;
		}
		
};

int searchAccNo(Account**, long long);
int n=20;
int count = -1;
int main(){
	
	Account* acc[n];
	int choice, ch;
	
	long long accNo;
	char holder[30];
	double amount;
	do{
		cout<<"\n--------------------------\n";
		cout<<"1.Create Account\n";
		cout<<"2.Deposit Balance\n";
		cout<<"3.Withdraw Balance\n";
		cout<<"4.Check Balance\n";
		cout<<"5.Account Details\n";
		
		cin>>choice;
		switch(choice){
			case 1:
				{
					cout<<"\n------Choose account type------\n";
					cout<<"1. Saving\n";
					cout<<"2. Current\n";
					cin>>choice;
					
					cout<<"Enter Account Holder name: ";
					cin.ignore();
					cin.getline(holder, sizeof(holder));
					
					if(choice == 1){
						SavingAmount:
						cout<<"Enter Amount to Deposit(minimum Deposit amount is 500.00): ";
						cin>>amount;
						if(amount<500){
							cout<<"\n!!Please enter amount greater than or equal to 500!!\n";
							goto SavingAmount;
						}
						acc[++count] = new Saving(holder, amount);
						cout<<"\nAccount created Successfully.. :)\n";
						acc[count]->displayDetails();
					}
					else if(choice == 2){
						CurrentAmount:
						cout<<"Enter Amount to Deposit(minimum amount is 2000): ";
						cin>>amount;
						if(amount<2000){
							cout<<"\n!!Please enter amount greater than or equal to 2000!!\n";
							goto CurrentAmount;
						}
						acc[++count] = new Current(holder, amount);
						cout<<"\nAccount created Successfully.. :)\n";
						acc[count]->displayDetails();
					}
					else
						cout<<"\nInvalid choice!!!\n";
				}
				break;
			case 2:
				{
					int index;
					cout<<"Enter account number: ";
					cin>>accNo;
					index = searchAccNo(acc, accNo);
					if(index != -1)
					{
						cout<<"Enter the amount to Deposit: ";
						cin>>amount;
						if(amount>0)
							acc[index]->deposit(amount);
						else
							cout<<"\nInvalid amount!!!\n";
					}
					else{
						cout<<"\nInvalid Account number!!!\n";
					}
				}
				break;
			case 3:
				{
					int index;
					cout<<"Enter the account number: ";
					cin>>accNo;
					index = searchAccNo(acc, accNo);
					if(index != -1)
					{
						cout<<"Enter the amount to withdraw: ";
						cin>>amount;
						if(amount>0)
							acc[index]->withdraw(amount);
						else
							cout<<"\nInvalid amount!!!\n";
					}
					else{
						cout<<"\nInvalid Account number!!!\n";
					}
				}
				break;
			case 4:
				{
					int index;
					cout<<"Enter Account number: ";
					cin>>accNo;
					index = searchAccNo(acc, accNo);
					if(index != -1)
					{
						cout<<"\nYour Current Balance is: "<<acc[index]->getBalance()<<" Rupees.\n";
					}
					else{
						cout<<"\nInvalid Account number!!!\n";
					}
				}
				break;
			case 5:
				{
					int index;
					cout<<"Enter Account number: ";
					cin>>accNo;
					index = searchAccNo(acc, accNo);
					if(index != -1)
					{
						cout<<"\n---------Your Account Details--------\n";
						acc[index]->displayDetails();
					}
					else{
						cout<<"\nInvalid Account number!!!\n";
					}
				}
				break;
			default:
				cout<<"\nInvalid choice!!!\n";
		}
		cout<<"\nDo you want to continue if yes enter 1 else 0: ";
		cin>>ch;
	}while(ch);
	
	cout<<"\n----------Thank you----------\n";
	return 0;
}

int searchAccNo(Account** acc, long long accNo){
	for(int i = 0;i <= count;i++){
		if(acc[i]->getAccountNumber() == accNo)
		{
			return i;
		}
	}
	return -1;
}
