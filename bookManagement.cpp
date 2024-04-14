/*
    This program manages a library of books with functionalities like:
    1. Storing predefined book data.
    2. Displaying all books.
    3. Searching books by ID or name.
    4. Updating book price or rating.
    5. Deleting a book.
    6. Finding the book with maximum price or rating.
    7. Listing top 3 books based on price or rating.
    8. Adding a new book with user input.
    
    The Book class has attributes like ID, book name, author, price, and rating. 
    It provides methods to set and get these attributes, store predefined book data, 
    and perform various operations on the book library.
    
    The main function presents a menu-driven interface to interact with the library 
    and uses dynamic memory allocation to manage the book array.
    
    Author: Ranjit Kale
*/
using namespace std;
#include<string.h>
#include<iostream>
#include<stdlib.h>
int s=8;
class book
{
	int id;
	char bookName[50];
	char author[50];
	double price;
	float rating;
	public: 
	
	void setId(int i)
	{
		this->id=i;
	}
	void setName(char* nm)
	{
		strcpy(this->bookName,nm);
	}
	void setAuthor(char* athr)
	{
		strcpy(this->author,athr);
	}
	void setPrice(double p)
	{
		this->price=p;
	}
	void setRating(float r)
	{
		this->rating=r;
	}
	int getId()
	{
		return this->id;
	}
	char* getName()
	{
		return this->bookName;
	}
	char* getAuthor()
	{
		return this->author;
	}
	double getPrice()
	{
		return this->price;
	}
	float getRating()
	{
		return this->rating;
	}
	
	void storedata(book* lib)
	{
		lib[0].setId(1);
		lib[0].setName("Saraswatichandra");
		lib[0].setAuthor("Govardhanram Madhavram Tripathi");
		lib[0].setPrice(150.75);
		lib[0].setRating(4.3);
		
		lib[1].setId(2);
		lib[1].setName("Mrityunjay");
		lib[1].setAuthor("Shivaji Sawant");
		lib[1].setPrice(120.50);
		lib[1].setRating(4.6);
		
		lib[2].setId(3);
		lib[2].setName("Yayati");
		lib[2].setAuthor("V.S. Khandekar");
		lib[2].setPrice(95.99);
		lib[2].setRating(4.4);
		
		lib[3].setId(4);
		lib[3].setName("Shyamchi Aai");
		lib[3].setAuthor("Sane Guruji");
		lib[3].setPrice(80.00);
		lib[3].setRating(4.8);
		
		lib[4].setId(5);
		lib[4].setName("Batatyachi Chal");
		lib[4].setAuthor("P. L. Deshpande");
		lib[4].setPrice(75.99);
		lib[4].setRating(4.2);
		
		lib[5].setId(6);
		lib[5].setName("Nathmadhav");
		lib[5].setAuthor("Nath Madhav");
		lib[5].setPrice(65.75);
		lib[5].setRating(4.5);
		
		lib[6].setId(7);
		lib[6].setName("Sukhachya Sarini He Manashi");
		lib[6].setAuthor("Vrinda Bal");
		lib[6].setPrice(50.50);
		lib[6].setRating(4.7);
		
		lib[7].setId(8);
		lib[7].setName("Vyakti Ani Valli");
		lib[7].setAuthor("P. L. Deshpande");
		lib[7].setPrice(70.00);
		lib[7].setRating(4.4);
	}
	void display(book* lib, int n)
	{
	
		int i;
		for(i=0;i<n;i++)
		{
			cout <<"+----------------------------------------------------------------+"<<endl;
			cout <<"|\tBook id    : "<<lib[i].getId()<<endl;
			cout <<"|----------------------------------------------------------------|"<<endl;
			cout <<"|\tBook Name  : "<<lib[i].getName()<<endl;
			cout <<"|----------------------------------------------------------------|"<<endl;
			cout <<"|\tAuthor Name: "<<lib[i].getAuthor()<<endl;
			cout <<"|----------------------------------------------------------------|"<<endl;
			cout <<"|\tPrice      : "<<lib[i].getPrice()<<endl;
			cout <<"|----------------------------------------------------------------|"<<endl;
			cout <<"|\tRank       : "<<lib[i].getRating()<<endl;
			cout <<"+----------------------------------------------------------------+"<<endl;
		}
	}
	int search(book* lib)
	{
		int ch;
		int a,i;
		cout<<"Press 1 for ID or press 2 for Book Name: ";
		cin>>ch;
		if(ch==1)
		{
			int n;
			cout<<"Enter the id: ";
			cin>>n;
			if(n<=s||n>=s)
			{
				for(i=0;i<s;i++)
				{
					if(n==lib[i].getId())
					{
						printf("Book found\n");
						cout <<"+----------------------------------------------------------------+"<<endl;
						cout <<"|\tBook id    : "<<lib[i].getId()<<endl;
						cout <<"|----------------------------------------------------------------|"<<endl;
						cout <<"|\tBook Name  : "<<lib[i].getName()<<endl;
						cout <<"|----------------------------------------------------------------|"<<endl;
						cout <<"|\tAuthor Name: "<<lib[i].getAuthor()<<endl;
						cout <<"|----------------------------------------------------------------|"<<endl;
						cout <<"|\tPrice      : "<<lib[i].getPrice()<<endl;
						cout <<"|----------------------------------------------------------------|"<<endl;
						cout <<"|\tRank       : "<<lib[i].getRating()<<endl;
						cout <<"+----------------------------------------------------------------+"<<endl;
						return i;
					}
				}
			}
			else
			{
				cout<<"Book not found"<<endl;
				return -1;
			}
			
		}
		else if(ch==2)
		{
			char ch[20];
			cout<<"Enter the name of book: ";
			fflush(stdin);
			cin.getline(ch,20);
			for(i=0;i<s;i++)
			{
				int n=strcasecmp(ch,lib[i].getName());
				if(n==0)
				{
					cout <<"+----------------------------------------------------------------+"<<endl;
					cout <<"|\tBook id    : "<<lib[i].getId()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tBook Name  : "<<lib[i].getName()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tAuthor Name: "<<lib[i].getAuthor()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tPrice      : "<<lib[i].getPrice()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tRank       : "<<lib[i].getRating()<<endl;
					cout <<"+----------------------------------------------------------------+"<<endl;
					return i;
				}
			}
			cout<<"Book not found."<<endl;
			return -1;	
		}
	}
	void update(book* lib)
	{
		double pr,rt;
		int n=search(lib);
		if(n!=-1)
		{
			int i,ch;
			cout<<"Press 1 to Update Price or Press 2 to update Rating: "<<endl;
			cin>>ch;
			if(ch==1)
			{
				cout<<"Enter the upadated price: ";
				cin>>pr;
				lib[n].setPrice(pr);
			}else if(ch==2)
			{
				cout<<"Enter the updated rating: ";
				cin>>rt;
				lib[n].setRating(rt);
			}
			cout<<"*************Stock after upadtes*************"<<endl;
			display(lib,s);
		}
		
	}
	int erase(book* lib)
	{
	    int n = search(lib);
	    int i,ch;
		s=s-1;
	    
	    if (n >= 0) 
	    {
	    	cout<<"Press 1 to delete book: ";
	    	cin>>ch;
	        if (ch==1)
	        {
	            for (i = n; i <s; i++)
	            {
	                lib[i] = lib[i + 1];
	            }
	            cout<<"Book erased"<<endl;
	            display(lib,s);
	        }
	    }
	    else
	    {
	        cout<<"Deletation unsuccessful."<<endl;
	    }
	}
	void maximum(book* lib)
	{
		int i=0,ch;
		cout<<"Press 1 for Price or press 2 for Rating: ";
		cin>>ch;
		double price=lib[0].getPrice();
		float rating=lib[0].getRating();
		if(ch==1)
		{
		
			while(i<=s)
			{
				if(lib[i].getPrice()>price)
				{
					price=lib[i].getPrice();
				}
				i++;
			}
			for(i=0;i<s;i++)
			{
				if(price==lib[i].getPrice())
				{
					cout <<"The book with maximum rating"<<endl;
					cout <<"+----------------------------------------------------------------+"<<endl;
					cout <<"|\tBook id    : "<<lib[i].getId()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tBook Name  : "<<lib[i].getName()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tAuthor Name: "<<lib[i].getAuthor()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tPrice      : "<<lib[i].getPrice()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tRank       : "<<lib[i].getRating()<<endl;
					cout <<"+----------------------------------------------------------------+"<<endl;
				}
			}
		}
		else if(ch==2)
		{
			while(i<=s)
			{
				if(lib[i].getRating()>rating)
				{
					rating=lib[i].getRating();
				}
				i++;
			}
			for(i=0;i<s;i++)
			{
				if(rating==lib[i].getRating())
				{
					cout <<"The book with maximum rating"<<endl;
					cout <<"+----------------------------------------------------------------+"<<endl;
					cout <<"|\tBook id    : "<<lib[i].getId()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tBook Name  : "<<lib[i].getName()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tAuthor Name: "<<lib[i].getAuthor()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tPrice      : "<<lib[i].getPrice()<<endl;
					cout <<"|----------------------------------------------------------------|"<<endl;
					cout <<"|\tRank       : "<<lib[i].getRating()<<endl;
					cout <<"+----------------------------------------------------------------+"<<endl;
				}
			}	
		}	
	}
	void top_3(book* lib)
	{
		int ch;
		cout<<"Get Top 3 books press 1 for price or press 2 for rating: "<<endl;
		cin>>ch;
		int i,j,a;
		char b[30];
		char c[30];
		double d;
		float f;
		
		if(ch==1)
		{
			for (i = 0; i < s; ++i) 
	        {
	            for (j = i + 1; j < s; ++j)
	            {
	                if (lib[i].getPrice() < lib[j].getPrice()) 
	                { 
					   a=lib[i].getId();
	                   lib[i].setId(lib[j].getId());
	                   lib[j].setId(a);
	                   strcpy(b,lib[i].getName());
	                   lib[i].setName(lib[j].getName());
	                   lib[j].setName(b);
	                   strcpy(c,lib[i].getAuthor());
	                   lib[i].setAuthor(lib[j].getAuthor());
	                   lib[j].setAuthor(c);
	                   d=lib[i].getPrice();
	                   lib[i].setPrice(lib[j].getPrice());
	                   lib[j].setPrice(d);
	                   f=lib[i].getRating();
	                   lib[i].setRating(lib[j].getRating());
	                   lib[j].setRating(f);
	                }
	            }
	        }
	        printf("Top 3 books with maximum price.\n");
	        display(lib,3);
		}else if(ch==2)
		{
			for (i = 0; i < s; ++i) 
	        {
	            for (j = i + 1; j < s; ++j)
	            {
	                if (lib[i].getRating() < lib[j].getRating()) 
	                {
					   a=lib[i].getId();
	                   lib[i].setId(lib[j].getId());
	                   lib[j].setId(a);
	                   strcpy(b,lib[i].getName());
	                   lib[i].setName(lib[j].getName());
	                   lib[j].setName(b);
	                   strcpy(c,lib[i].getAuthor());
	                   lib[i].setAuthor(lib[j].getAuthor());
	                   lib[j].setAuthor(c);
	                   d=lib[i].getPrice();
	                   lib[i].setPrice(lib[j].getPrice());
	                   lib[j].setPrice(d);
	                   f=lib[i].getRating();
	                   lib[i].setRating(lib[j].getRating());
	                   lib[j].setRating(f);
	                }
	            }
	    	}
	    	cout<<"Top 3 books with maximum rating."<<endl;
	    	display(lib,3);
		}
	}
	void addbook(book* lib)
	{
		int i,n=1,j,id;
		double pr;
		int size=s;
		char str[20];
		s=s+1;
		lib=(book*)realloc(lib,s);
		do{
			cout<<"Enter the id of book: "<<endl;
			cin>>id;
			lib[s-1].setId(id);
			for(i=0;i<size;i++)
			{
				if(lib[i].getId()==lib[s-1].getId())
				{
					cout<<"This book ID exist."<<endl;
					cout<<"Enter diffrent ID!!"<<endl;
					break;
				}
			}
		}while(i<size);
		cout<<"Enter the book name: ";
		fflush(stdin);
		cin.getline(str,20);
		lib[s-1].setName(str);
		cout<<"Enter the author name: ";
		fflush(stdin);
		cin.getline(str,20);
		lib[s-1].setAuthor(str);
		do{
			cout<<"Enter the price of book: ";
			cin>>pr;
			lib[s-1].setPrice(pr);
			for(i=0;i<size;i++)
			{
				if(lib[s-1].getPrice()==0)
				{
					cout<<"Book price should not be 0!!"<<endl;
					cout<<"Enter price again!!"<<endl;
					break;
				}
			}
		}while(i<size);
		do{
			cout<<"Enter the rating of book: ";
			cin>>pr;
			lib[s-1].setRating(pr);
			for(i=0;i<size;i++)
			{
				if(lib[s-1].getRating()>5)
				{
					cout<<"Book rating can't be below 5!!"<<endl;
					cout<<"Enter rating below 1-5!!"<<endl;
					break;
				}
			}
		}while(i<size);
		display(lib,s);
	}
};

int main()
{
	
	book b;
	book* lib=(book*)malloc(sizeof(book)*s);
	b.storedata(lib);
	int choice;
	char c;
	do
	{
		cout <<"*************NAMASKAR*****************"<<endl;
		cout <<"Press 1 for Display books avaialable."<<endl;
		cout <<"Press 2 for Search."<<endl;
		cout <<"Press 3 for Update."<<endl;
		cout <<"Press 4 for Delete."<<endl;
		cout <<"Press 5 for Maximum."<<endl;
		cout <<"Press 6 for Top 3."<<endl;
		cout <<"Press 7 for addbook."<<endl;
		cout <<"Enter the choice to perform specific operation: ";
		cin >>choice;
		switch(choice)
		{	
			case 1:
			b.display(lib,s);
			break;
			case 2:
			b.search(lib);
			break;
			case 3:
			b.update(lib);
			break;
			case 4:
			b.erase(lib);
			break;
			case 5:
			b.maximum(lib);
			break;
			case 6:
			b.top_3(lib);
			break;
			case 7:
			b.addbook(lib);
			break;
			default:
			cout <<"Invalid Choice";
		}
		cout <<"\nDo you want to continue and go back to the menu? Enter y or n: ";
    	cin >>c;
	}
	while(c == 'y' ||  c == 'Y');
	
	cout <<"*********End of program*******"<<endl;
	cout <<"^^^^^^^^^^^Thank You^^^^^^^^^^"<<endl;
	return 0;
}


