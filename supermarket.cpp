#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	public:
		void menu();
		void administrator();
		void customer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();

};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\t__________________________________________\n";
	cout << "\t\t\t\t									\n";
	cout << "\t\t\t\t	Supermarket Main Menu		\n";
	cout << "\t\t\t\t									\n";
	cout << "\t\t\t\t__________________________________________\n";
	cout << "\t\t\t\t									\n";
	cout << "\t\t\t\t|	1.	Administrator 		|\n";
	cout << "\t\t\t\t|					|\n";
	cout << "\t\t\t\t|	2.	Customer		|\n";
	cout << "\t\t\t\t|					|\n";
	cout << "\t\t\t\t|	3.	Exit			|\n";
	cout << "\t\t\t\t|					|\n";
	cout << "\n\t\t\t Please Select : ";
	cin >> choice;

	switch(choice)
	{
		case 1:
			cout << "							\n";
			cout << "\t\t\t		PLEASE LOGIN	\n";
			cout << "							\n";
			cout << "\t\t\tUsername/Email :";
			cin >> email;
			cout << "\n";
			cout << "\t\t\tPassword :";
			cin >> password;
			cout << "\n";

			if(email == "asd" && password == "asd")
			{
				administrator();
			}
			else
			{
				cout << "Invalid email/password";
			}
			break;

		case 2:
			customer();

		case 3:
			exit(0);

		default:
			cout << "Please select from the given options";

	}
	goto m;

}

void shopping :: administrator()
{
	m:
	int choice;
	cout << "\n\n\n\t\t\t\t	Administrator Menu	\n";
	cout << "\t\t\t\t__________________________________________\n";
	cout << "\n\t\t\t\t|	1. Add the product		|";
	cout << "\n\t\t\t\t|					|";
	cout << "\n\t\t\t\t|	2. Modify the product		|";
	cout << "\n\t\t\t\t|					|";
	cout << "\n\t\t\t\t|	3. Delete the product		|";
	cout << "\n\t\t\t\t|					|";
	cout << "\n\t\t\t\t|	4. Back to main menu		|\n";

	cout << "\n\n\t\t\t Please enter your choice :";
	cin >> choice;

	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout << "Invalid choice!";
	}
	goto m;

}

void shopping :: customer()
{
	m:
	int choice;
	cout << "\n\t\t\t\t Customer \n";
	cout << "\t\t\t\t_________________\n";
	cout << "                       \n";
	cout << "\t\t\t|  1.Buy Product		|\n";
	cout << "                       \n";
	cout << "\t\t\t|	2.Go Back		|\n";
	cout << "\t\t\t Enter your choice : ";
	cin >> choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout << "Invalild choice";
	}
	goto m;

}

void shopping :: add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;

	cout << "\n\n\t\t\t\t Add new product";
	cout << "\n\n\t\t Product code of the product: ";
	cin >> pcode;
	cout << "\n\t\t Name of the product: ";
	cin >> pname;
	cout << "\n\t\t Price of the product: ";
	cin >> price;
	cout << "\n\t\t Discount on the product: ";
	cin >> dis;

	data.open("database.txt", ios::in);
	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;

		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();

		if(token == 1)
		{
			goto m;
		}
		else
		{
			data.open("database.txt", ios::app|ios::out);
			data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			data.close();

		}
	}

	cout << "\n\n\t\t Record Inserted!";
}

void shopping :: edit()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	string n;
	float p;
	float d;

	cout << "\n\t\t\t\t Modify the record";
	cout << "\n\t\t\t Product Code: ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	while(!data.eof())
	{
		if(pkey == pcode)
		{
			cout << "\n\t\t\t Product new code: ";
			cin >> c;
			cout << "\n\t\t\t Name of the product: ";
			cin >> n;
			cout << "\n\t\t\t Price: ";
			cin >> p;
			cout << "\n\t\t\t Discount: ";
			cin >> d;
			data1 << " " << c << " " << n << " " << p << " " << d << "\n";
			cout << "\n\n\t\t Record Edited";
			token++;
		}
		else
		{
			data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		}
		data >> pcode >> pname >> price >> dis;

	}
	data.close();
	data1.close();

	remove("database.txt");
	rename("database1.txt", "database.txt");

	if(token == 0)
	{
		cout << "\n\n Record not found sorry!";
	}

}

void shopping :: rem()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\n\n\t\t\t\t Delete Product";
	cout << "\n\n\t\t\t Product code: ";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "File doesnt exist";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		data >> pcode >> pname >> price >> dis;
		while(!data.eof())
		{
			if(pcode == pkey)
			{
				cout << "\n\n\t\t Product deleted successfully";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if(token == 0)
		{
			cout << "\n\n\t\t Record not found";
		}

	}
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n|________________________________________________\n";
	cout << "ProNo\t\tName\t\tPrice\n";
	cout << "\n\n|________________________________________________\n";
	data >> pcode >> pname >> price >> dis;
	while(!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void shopping :: receipt()
{
	m:
	fstream data;

	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\n\n\t\t\t\t RECEIPT";
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\n Empty database";
	}
	else
	{
		data.close();

		list();
		cout << "\n______________________________________\n";
		cout << "\n|									 \n";
		cout << "\n|		Please place the order		 \n";
		cout << "\n|									 \n";
		cout << "\n|_____________________________________\n";

		do
		{
			cout << "\n\n Enter Product code: ";
			cin >>arrc[c];
			cout << "\n\n Enter the product quantity :";
			cin >> arrq[c];
			for(int i=0; i<c; i++)
			{
				if(arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? if yes then press y else n";
			cin >> choice;
		}
		while(choice == 'y');

		cout << "\n\n\t\t\t___________________RECEIPT___________________\n";
		cout << "\nProduct No\t Product Name\t Product quantity\t price\t Amount\t Amount with discount\n";

		for(int i=0; i<c; i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while(!data.eof())
			{
				if(pcode == arrc[i])
				{
					amount = price*arrq[i];
					dis = amount-(amount*dis/100);
					total = total+dis;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
		}
		data.close();
	}
	cout << "\n\n_______________________________________";
	cout << "\n Total Amount :" << total;
}

int main()
{
	shopping s;
	s.menu();
}
