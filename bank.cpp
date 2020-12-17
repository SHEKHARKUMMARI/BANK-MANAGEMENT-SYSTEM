#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#include<conio.h>
#include<string.h>
#define ll long long int
#include<iomanip>

class bank
{
   char name[100];
   float balance;
   ll acn;
   char pwd[100];
   public :
   	void create();
   	void display();
   	void deposite();
   	void withdraw();
   	char* returnpwd();
   	ll returnacn();
   	float returnbalance();
   	void dsp();
   	
	
};
void bank::dsp()
{
	cout<<name<<setw(30)<<acn<<setw(30)<<pwd<<setw(30)<<balance<<endl;
}
float bank::returnbalance()
{
	return balance;
}
void bank::create()
{
	
   	    cout<<"enter name :"<<endl;
		   cin.ignore();
		   cin.getline(name,100);
		   balance=0;
		   cout<<endl<<"eter acoount no : ";
		   cin>>acn;
		   cout<<endl<<" create password ";
		   cin.ignore();
		  cin.getline(pwd,100);
		   
		   
}
void bank::deposite()
{
	cout<<endl<<" enter amount :  ";
	float x;
	cin>>x;
	balance=balance+x;
	
}
void bank::withdraw()
{
	
	float x;
	cout<<endl<<"enter amount to with draw"<<endl;
		cin>>x;
	if(x>balance)
	{
	cout<<endl<<" you dont have enough balance ."<<endl;
	return;
    }
	else
	{ 
		
		balance-=x;
		
	}
	
	
}
void bank::display()
{
	cout<<endl<<"NAME : "<<name<<endl<<"ACCOUNT NUMMBER :"<<acn<<endl<<"BALANCE : "<<balance<<endl;
}
fstream fp;
char* bank::returnpwd() 
{
	return pwd;
}
ll bank::returnacn() 
{
	return acn;
}
void createaccount()
{    system("cls");
	 fp.open("bk.dat",ios::binary|ios::app|ios::out|ios::ate);
	bank b;
	b.create();
	fp.write((char*)&b,sizeof(bank));
	fp.close();
}
void displaydetails()
{  
	system("cls");
	cout<<endl<<"enter account number : ";
	ll tacn;
	cin>>tacn;
	bank b;
	 fp.open("bk.dat",ios::binary|ios::in);
	 if(!fp)
	 cout<<"No data present"<<endl;
	 else
	 {  bool flag=true;
	while(fp.read((char*)&b,sizeof(b)))
	{ if(tacn==b.returnacn())
	  {
	    flag=false;
		b.display();
		break;
	  }
	  
	}
	if(flag)
	  cout<<"acoount is not found"<<endl;
     }
    
	fp.close();
}
void depositeamount()
{  system("cls");
	
	 fp.open ("bk.dat",ios::binary|ios::in|ios::out);
	if(!fp)
	{cout<<endl<< "no data is present ."<<endl;
    }
	else
	{ cout<<endl<<"enter account number: ";
	   ll d;
	   cin>>d;
	   bank b;
	  bool flag=false;
		while( !fp.eof())
		{  fp.read((char*)&b,sizeof(bank));
			if(b.returnacn()==d)
			{   flag=true;
				cout<<endl<<"enter password : ";
				 char s[100];
				 cin.ignore();
				 cin.getline(s,100);
				 if(strcmp(s,b.returnpwd())==0)
				 {
				 
				
					b.deposite();
					int pos=-1*sizeof(b);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&b,sizeof(b));
					cout<<endl<<" your current balance : "<<b.returnbalance()<<endl;
				
				
				}
				else
				cout<<" incorrect password"<<endl;

				
			}
			if(flag)
			break;
		}
		if(flag==false)
		cout<<endl<<" account number doesnot found ."<<endl;
		
	}
	fp.close();
	
}

void withdrawamount()
{   system("cls");
	cout<<endl<<"enter account number: ";
	ll d;
	cin>>d;
	bank b;
	fp.open("bk.dat",ios::binary|ios::in|ios::out);
	if(!fp)
	cout<<endl<<" no data is present ."<<endl;
	else
	{   bool flag=false;
		while(fp.read((char*)&b,sizeof(bank)))
		{
			if(b.returnacn()==d)
			{   flag=true;
				cout<<endl<<"enter password : ";
				char g[100];
				cin.ignore();
				cin.getline(g,100);
				if(strcmp(g,b.returnpwd())==0)
				{
					
					int pos=-1*sizeof(b);
					b.withdraw();
					fp.seekp(pos,ios::cur);
					fp.write((char*)&b,sizeof(b));
					cout<<endl<<" your current balance : "<<b.returnbalance()<<endl;
					break;
				}
				else
				{
					cout<<"\n password is incorrect \n,";
				}
				
			}
		}
		if(flag==false)
		cout<<endl<<" account number doesnot found ."<<endl;
	}
	fp.close();	
}
void disp()
{   system("cls");
	bank b;
	 fp.open("bk.dat",ios::binary|ios::in);
	 if(!fp)
	 cout<<"No data present"<<endl;
	 else
	 {cout<<"acount holder name"<<setw(25)<<"account number"<<setw(25)<<"password"<<setw(30)<<"current_balance"<<endl;
	while(fp.read((char*)&b,sizeof(b)))
	{ 
		b.dsp();
	}
     }
	fp.close();
}
void checkbalance()
{
	system("cls");
	cout<<endl<<"enter account number: ";
	ll d;
	cin>>d;
	bank b;
	fstream fp("bk.dat",ios::binary|ios::in);
	if(!fp)
	cout<<endl<<" no data is present ."<<endl;
	else
	{   bool flag=false;
		while(fp.read((char*)&b,sizeof(bank)))
		{
			if(b.returnacn()==d)
			{   flag=true;
				cout<<endl<<"enter password : ";
				char g[100];
				cin.ignore();
				cin.getline(g,100);
				if(strcmpi(g,b.returnpwd())==0)
				{
					cout<<endl<<" your current balance : "<<b.returnbalance()<<endl;
					break;
				}
				else
				{
					cout<<"\n password is incorrect \n,";
				}
				
			}
		}
		if(flag==false)
		cout<<endl<<" account number doesnot found ."<<endl;
	}
	fp.close();	
}
void del()
{   system("cls"); 
   bank b;
	fstream fp2;
	fp2.open("tmp.dat",ios::binary|ios::in|ios::out|ios::app);
	fp.open("bk.dat",ios::binary|ios::in);
	ll tacn;
	cout<<endl<<"enter the account number : "<<endl;
	cin>>tacn;
	while(fp.read((char*)&b,sizeof(bank)))
	{    if(b.returnacn()!=tacn)
		fp2.write((char*)&b,sizeof(b));
	}
	fp2.close();
	fp.close();
	remove("bk.dat");
	rename("tmp.dat","bk.dat");
	cout<<"\n account number : "<<tacn<<" is deleted succesfully"<<endl;
	getch();
	
}
void bankmanager()
{  system("cls");
	int choice;
	do
	{
	
	cout<<" \n 1.create account \n 2.display all accounts \n 3.delete account \n 4.display a account details.\n 5.return to mainmenu .\n enter your operation : ";
	cin>>choice;
	switch(choice)
	{
		case 1 : createaccount();getch();system("cls");break;
		case 4:displaydetails();break;system("cls");
		case 2: disp();getch();system("cls");break;
		case 3: del();system("cls");break;
		case 5 : return;
		default : cout<<endl<<"enter correct option ";system("cls");
	}
   }while(7);
	
}
void customer()
{
	system("cls");
	int ch;
	do
	{
	
	cout<<"\n 1.deposite money \n 2.withdraw money \n 3.check balance \n 4.return mainmenu \n 5.dsplay your details  \n enter your operation  :  ";
	cin>>ch;
	switch(ch)
	{
		
			case 3: checkbalance();getch();system("cls");break;
			case 1 : depositeamount();getch();system("cls");break;
			 case 5:displaydetails();break;system("cls");
			case 2: withdrawamount();getch();system("cls");break;
			case 4 : return;
			default : cout<<endl<<"enter correct option ";system("cls");
	}
	
  }while(7);
}
int main()
{
	do
	{
		int ch;
		cout<<"\n 1.manager mode \n 2.customer mode. \n 3.exit"<<endl<<"enter your mode : ";
		cin>>ch;
		switch(ch)
		{
			case 1:bankmanager();system("cls");break;
			case 2:customer();system("cls");break;
			case 3:exit(7);
			
		}
		
	}while(7);
}
