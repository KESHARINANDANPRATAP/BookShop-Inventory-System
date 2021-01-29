#include<iostream>
#include<string.h>
#include<stdlib.h>
#define max 100

using namespace std;

class books
{
public:
		int book_id;
		int stock = 100;
		float price;
		char* title, * author, * publisher;
	
	    books();
		void add();
		void display();
}; 

	 books::books()
	{
		book_id = 0;
		title = new char[50];
		author = new char[50];
		publisher = new char[50]; 
	}

	void books::add()
	{
		cout << "Enter book id :\t";
		cin >> book_id;
		
		cout << "Title of the book: \t";
		cin >> title;
		
		cout << "Author of the book:\t";
		cin >> author;
		
		cout << "Publisher of the book:\t";
		cin >> publisher;
		
		cout << "Enter price of the particular book: \t";
		cin >> price;
		cout << "BOOK ADDED!\n";
	}

	void books::display()
	{
		cout << "Book ID: \t" << book_id;
		cout << "\n";
		cout << "Title of the book: \t" << title;
		cout << "\n";
		cout << "Author of book: \t" << author;
		cout << "\n";
		cout << "Name of Publisher:\t" << publisher;
		cout << "\n";
		cout << "Price of book: \t" << price << "\n";
	}

	int main()
	{
		static int strans = 0;
		static int untrans = 0;

		books b[max];

		int flag = 0;
		int i, ch, n;
		float total_cost = 0;
		int id, stock = 500;

		while (1)
		{
			cout << "\nBookShop Menu: \n1.Add  \n2.Upadte \n3.Search a Book  \n4.Purchase a Book \n5.Transactions: \n6.Delete: \n7.Exit to top:";
			cout << "\n";
			cout << "\nPlease enter your selected option here: \t";
			cin >> ch;
			cout << "\n";

			switch (ch)
			{
			case 1:
				cout << "Please tell us how many book entries would you like to add here: \t";
				cin >> n;

				for (i = 0; i < n; i++)
				{
					b[i].add();
					stock++;
				}

				break;

			case 2:
				cout << "Please enter the new entry you want to update: \t";
				b[stock].add();
				stock++;

				for (i = 0; i < stock; i++)
				{
					b[i].display();
				}

				break;

			case 3:
				cout << "Enter the book ID of the book you are looking for: \t";
				cin >> id;

				for (i = 0; i < stock; i++)
				{
					if (id == b[i].book_id)
					{
						cout << "Book Found at: \t" << (i + 1);
						flag = 1;
						break;
					}

					else
						flag = -1;
				}

				if (flag == -1)
				{
					cout << "Sorry! Book not Found. \nTry another id please...";
				}

				break;

			case 4:
				cout << "Want to purchase a book?";
				cout << "Enter the book ID you want to purchase: \t";
				cin >> id;
				cout << "\n";

				for (i = 0; i < stock; i++)
				{
					if (id == b[i].book_id)
					{
						total_cost = b[i].price;
						stock--;
						strans++;
						flag = 1;
					}

					else
						flag = -1;
				}
				if (flag == -1)
				{
					untrans++;
				}

				cout << "Total cost for you: \t" << total_cost;
				cout << "\nCongratulations! PURCHASE SUCCESSFULL!\n";

				break;

			case 5:
				cout << "Enter the book ID that you want to delete: \t";
				cin >> id;

				for (i = 0; i < n; i++)
				{
					if (b[i].book_id == id)
					{
						cout << "Requested book Found!\n";
						delete b[i].title;
						delete b[i].author;
						delete b[i].publisher;
						b[i].stock = -1;
						flag = 1;
						break;
					}
					else
						flag = 0;
				}

				if (flag == 0)
				{
					cout << "Sorry! Your requested book is not found!. \nTry another book....";
				}

				break;

			case 7:
				exit(0);

			}
		}
	}
