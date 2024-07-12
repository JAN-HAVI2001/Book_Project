#include<iostream>
#include<string.h>
using namespace std;

struct Book
{
	int bid;
	char bName[40];
	char author[40];
	double price;
	double rating;
	
	//default constructor
	Book()
	{
		this->bid = 0;
		strcpy(this->bName, "Not Given");
		strcpy(this->author, "Not Given");
		this->price = 0.00;
		this->rating = 0.0;
	}
	
	//parameterised constructor
	Book(int id,const char* bNm,const char* au, double pri, double rat)
	{
		this->bid = id;
		strcpy(this->bName,bNm);
		strcpy(this->author,au);
		this->price = pri;
		this->rating = rat;
	}
	
	//Setters
	void setId(int id)
	{
		this->bid = id;
	}
	void setName(const char* bNm)
	{
		strcpy(this->bName, bNm);
	}
	void setAuthor(const char* au)
	{
		strcpy(this->author, au);
	} 
	void setPrice(double pri)
	{
		this->price = pri;
	}
	void setRating(double rat)
	{
		this->rating = rat;
	}
	
	//Getters
	int getId()
	{
		return this->bid;
	}
	const char* getName()
	{
		return this->bName;
	}
	const char* getAuthor()
	{
		return this->author;
	}
	double getPrice()
	{
		return this->price;
	}
	double getRating()
	{
		return this->rating;
	}
	
	//display
	void display(Book* b,int size)
	{
		cout<<"\n-----------------------------------------------------------------------------------------";
		cout<<"\n Id   |         Name            |          Author           |   Price    |      Rating   ";
		for (int i = 0; i < size; i++) 
		{
			cout<<"\n-----------------------------------------------------------------------------------------";
			cout<<"\n"<<b[i].getId()<<"\t"<<b[i].getName()<<"\t\t\t\t"<<b[i].getAuthor()<<"\t\t"<<b[i].getPrice()<<"\t\t"<<b[i].getRating();
			cout<<"\n-----------------------------------------------------------------------------------------";
        }	
	}
};

void store(Book* b,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		int idb;
		cout<<"\nEnter the Id :";
		cin>>idb;
		b[i].setId(idb);
		
		char nm[30];
		cout<<"\nEnter the Name :";
		fflush(stdin);
		gets(nm);
		b[i].setName(nm);
		
		char author[30];
		cout<<"\nEnter the Author :";
		fflush(stdin);
		gets(author);
		b[i].setAuthor(author);
		
		double pr;
		cout<<"\nEnter the Price :";
		cin>>pr;
		b[i].setPrice(pr);
		
		double ra;
		cout<<"\nEnter the Rating :";
		cin>>ra;
		b[i].setRating(ra);
	}
}

void add(Book* b,int* size)
{
	int n;
	cout<<"\nEnter how many book you add ";
	cin>>n;
	int finalsize=*size+n;
	Book* b1=new Book[finalsize];
	
	if(b1==NULL)
	{
		cout<<"\nMemory not allocated ";
	}
	int i;
	for(i=*size;i<finalsize;i++)
	{
		int idb;
		cout<<"\nEnter the Id :";
		cin>>idb;
		b[i].setId(idb);
		
		char nm[30];
		cout<<"\nEnter the Name :";
		fflush(stdin);
		gets(nm);
		b[i].setName(nm);
		
		char author[30];
		cout<<"\nEnter the Author :";
		fflush(stdin);
		gets(author);
		b[i].setAuthor(author);
		
		double pr;
		cout<<"\nEnter the Price :";
		cin>>pr;
		b[i].setPrice(pr);
		
		double ra;
		cout<<"\nEnter the Rating :";
		cin>>ra;
		b[i].setRating(ra);
	}
	cout<<"\n------------------------------*--Player Add Successfully--*---------------------------------";
	*size=finalsize;
}

void deleteb(Book* b,int* size)
{
	int id;
	cout<<"\nEnter the Id to delete ";
	cin>>id;
	
	int i;
	for(i=0;i<*size;i++)
	{
		if(b[i].getId()==id)
		{
			Book temp=b[i];
			b[i]=b[i+1];
			b[i+1]=temp;	
		}	
	}
	cout<<"\n------------------------------*--Book Delete Successfully--*---------------------------------";

}

void search(Book* b,int size)
{
	int id;
	cout<<"\nEnter the Id to search ";
	cin>>id;
		
	int i;
	for(i=0;i<size;i++)
	{
		if(b[i].getId()==id)
		{
			cout<<"\n";
			b->display(b,1);
			break;
		}    
	}
	cout<<"\n------------------------------*--Search Successfully--*---------------------------------";

}

void update(Book* b,int size)
{
	int ch;
	cout<<"\n1.Update to Price (1) \n2.Update to Rating (2) ";
	cin>>ch;
	
	if(ch==1)
	{
		int id;
		cout<<"\nEnter the Id to update ";
		cin>>id;
		
		int i;
		for(i=0;i<size;i++)
		{
			if(b[i].getId()==id)
			{
				cout<<"Update price of book ";
				cin>>b[i].price;
				break;
			}    
		}
		for(i=0;i<size;i++)
		{
			cout<<"\n";
			b->display(b,size);
			break;
		}
		cout<<"\n------------------------------*--Update Successfully--*---------------------------------";
	}
	else if(ch==2)
	{
		char updatebook[30];
		cout<<"\nEnter the book name to update ";
		fflush(stdin);
		gets(updatebook);
		
		int i;
		for(i=0;i<size;i++)
		{
			if(strcmp(b[i].getName(),updatebook)==0)
			{
				cout<<"Update Rating of book ";
				cin>>b[i].rating;
				break;
			}    
		}
		for(i=0;i<size;i++)
		{
			cout<<"\n";
			b->display(b,size);
			break;
		}
		cout<<"\n------------------------------*--Update Successfully--*---------------------------------";
	}
}

void top(Book* b,int size)
{
	int ch;
	cout<<"\n1.Top Price (1) \n2.Top Rating (2) ";
	cin>>ch;
	
	if(ch==1)
	{
		for(int i=0;i<size;i++) 
		{
        	for(int j=i+1;j<size;j++) 
			{
        	    if (b[i].getPrice()<b[j].getPrice()) 
				{
        	        Book temp=b[j];
        	        b[i]=b[j];
        	        b[j]=temp;
        	    }
        	}
    	}
		cout<<"\n------------------------------*-- Top Price --*---------------------------------";
		for(int i=0;i<3;i++)
		{
			b->display(b,1);
		}
	}
	else if(ch==2)
	{
		for(int i=0;i<size;i++) 
		{
        	for(int j=i+1;j<size;j++) 
			{
        	    if (b[i].getRating()<b[j].getRating()) 
				{
        	        Book temp=b[j];
        	        b[i]=b[j];
        	        b[j]=temp;
        	    }
        	}
    	}
		cout<<"\n------------------------------*-- Top Price --*---------------------------------";
		for(int i=0;i<1;i++)
		{
			b->display(b,3);
		}
	}
}

int main()
{
	int size=5;
	Book* b=new Book[size];
	
	char exit;
	do{
		int ch;
		cout<<"\n------------------------------------*--Menu to choice--*--------------------------------";
		cout<<"\n1. Store book ";
		cout<<"\n2. Display book list ";
		cout<<"\n3. Add a book ";
    	cout<<"\n4. Remove a book ";
    	cout<<"\n5. Search a book ";
    	cout<<"\n6. Update a book ";
    	cout<<"\n7. Top ";
    	cout<<"\n----------------------------------------------------------------------------------------";
    	cout<<"\nEnter your choice ";
    	cin>>ch;
    	
    	switch(ch)
    	{
    		case 1: {
    					cout<<"\nHow many Book you add ";
    					cin>>size;
						store(b,size);
					}
					break;
					
			case 2:	b->display(b,size);
					break;
					
			case 3: add(b,&size);
					break;
				
			case 4: deleteb(b,&size);
					break;
			
			case 5: search(b,size);
					break;
			
			case 6: update(b,size);
					break;
					
			case 7: top(b,size);
					break;
				
			default: cout<<"\nInvalid choice ";
		}
		cout<<"\n----------------------------------------------------------------------------------------";
    	cout<<"\nDo you want menu then press (y) nither (n) = ";
    	cin>>exit;
    	cout<<"\n-----------------------------------------------------------------------------------------";
	}while(exit=='y' || exit=='Y');
	cout<<"\n-------------------------------------------*--Goodbye--*----------------------------------------------";
	delete[] b;
	return 0;
}