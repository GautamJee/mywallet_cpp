			    /*My wallet*/


#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
#include<time.h>

#define s 20


char ch;		//choice variable

struct trans
{
	float d;
	float w;
	float b;
}tr;

void tran_in(float d, float w, float b)
{
	int balance;
	if(d!=0||w!=0)
	{
		b=b-w;
		b=b+d;
		tr.d=d;
		tr.w=w;
		tr.b=b;
		fstream f("transaction.dat"||ios::app);
		if(!f)
		{
		cout<<"File: customer.dat Not Found!!";
		getch();
		}
		else
		{
		f.write((char *)&tr,sizeof(&tr));
		f.close();
		}
	}
}

void tran_out()
{
	fstream f("transaction.dat"||ios::app);
	if(!f)
		{
		cout<<"File: customer.dat Not Found!!";
		getch();
		}
	else
	{
	while(!f.eof())
	{
	f.read((char *)&tr,sizeof(&tr));
	cout<<"\nWithdrawl="<<tr.w<<"\tDeposit="<<tr.d<<"\tBalance="<<tr.b<<endl;
	getch();
	}
	f.close();
	}
}

void leaving()		//for quiting the s/w
{
		 cout<<"\n\n\n!!Leaving the Software.........";
		 getch();
		 exit(0);
}

class menu          		//Main menu class
{
	int getpass(char pass[s])            //password check
		{
			if(strcmp(pass,"8809606367")==0)
			return 0;
			else
			return strcmp(pass,"Gautam Kumar");

		}
	public:
		menu()                //constructor for auto calling the required program
		{
			check();
			main_menu();
		}
		void check();                  //password input
		void main_menu();              //Main Menu function
		~menu()
		{
			clrscr();
			cout<<"\n\n\n!! DEVELOPED by Gautam !!";
			getch();
		}
}m;



class wallet		//class presenting your wallet
{
	float balance;    //variable for the main balance
public:

		wallet()	//contructor to specify the primary inputs
		{
			balance=get_data();
		}
		~wallet()
		{
		}
	void pre_bal();		//to show the present balance
	void with_bal();	//withdrawing balance function
	void dep_bal();		//depositing balance function
	void put_bal(float);	//function for updating the balance in file
	float get_data();		//function for reading the balance from file
	void get_bal();
}w;

float wallet::get_data()
{
	get_bal();
	return balance;
}

void wallet::pre_bal()
{
	clrscr();
	cout<<"\nYour present balance is:"<<get_data();
	getch();
}

void wallet::get_bal()
{
	fstream f("balance.dat",ios::in);
	f.read((char*)&w,sizeof(w));
	f.close();
}

void wallet::put_bal(float balance)
{
	clrscr();
	fstream f("balance.dat",ios::out);
	if(!f)
		{
		cout<<"File: balance.dat Not Found!!";
		getch();
		m.main_menu();
		}
	else
	{
	balance=balance+w.get_data();
	f.write((char *)&w,sizeof(w));
	cout<<"\n\nWallet Updated!!\n";
	w.pre_bal();
	f.close();
	}
}

void wallet::with_bal()
{
	float with_bal;
	w.pre_bal();
	cout<<"\nEnter the amount you want from your wallet:";
	cin>>with_bal;
	balance=w.get_data();
	balance=balance-with_bal;
	w.put_bal(balance);
}

void wallet::dep_bal()
{
	float dep_bal;
	w.pre_bal();
	cout<<"\nEnter the amount you want to add to your wallet:";
	cin>>dep_bal;
	balance=w.get_data();
	balance=balance+dep_bal;
	w.put_bal(balance);
}

void menu::check()
{

			char pass[s];
			int test;
			clrscr();
			cout<<"Enter the password:";
			gets(pass);
			test=getpass(pass);
			if(test==0)
			 {
				 clrscr();
				 cout<<"\n\tPassword Matched..!!\n\n\tAccess Granted..!!";
				 getch();
			 }
			else
			 {
				 cout<<"\n\n\t\t\tAccess Denied...!!";
				 leaving();
			 }
}

void menu::main_menu()
{
	clrscr();
	cout<<"\n\t\t!!Welcome To Your Wallet!!\n1.Check Balance\n2.Amount Withdraw\n3.Amount Deposit\n4.Transactions\n0.Exit";
	cin>>ch;
	switch(ch)
	{
		case '1': w.pre_bal();
			break;
		case '2': w.with_bal();
			break;
		case '3': w.dep_bal();
			break;
		case '4': tran_out();
			getch();
			break;
		case '0': leaving();
		default: cout<<"\n\nWrong choice!!";
			 getch();
	}
	main_menu();
}

void main()
{
	menu obj;
}
