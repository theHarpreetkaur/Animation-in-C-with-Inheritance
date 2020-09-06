
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;



class account{
	int acno;
	char name[50];
	int deposit;
	char type;


	public:
		void create_account();	//function to get data from user
		void show_account() const;	//function to show data on screen

		void dep(int);	//function to accept amount and add to balance amount
		void draw(int);	//function to accept amount and subtract from balance amount
		void report() const;	//function to show data in tabular format
		int retacno() const;	//function to return account number
		int retdeposit() const;	//function to return balance amount
		
		char rettype() const;	//function to return type of account
};

void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user


void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();

	void account::dep(int x){
		
		deposit += x;
	}


	void account::draw(int x){
		deposit -= x;

	}


void account::report() const{
	
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
	
}


int account::retacno() const{
	
	return acno;
}



char account::rettype() const{
	
	return type;
}



void write_account(){
	
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
	
}



int main(){
	char choice;
	int num;

	do{
		
		system("cls");

		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\tN. NEW ACCOUNT";
		cout << "\n\n\tD. DEPOSIT ";
		cout << "\n\n\tW. WITHDRAW ";
		cout << "\n\n\tM. MONTH ";
		cout << "\n\n\tQ. QUIT";
		cin >> choice;
		
		system("cls");
		switch (choice){
			
		case 'N':
			write_account();
			break;
		case 'D':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 1);
			break;
		case 'W':
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 2);
			break;
		case 'M':
			display_all();
			break;
	
		case 'Q':
			cout << "\n\n\tThanks for using bank  system";
			break;

		}
		
		cin.ignore();
		cin.get();
	} while (choice!= 'Q');




	return 0;
}


void account::show_account() const{
	
	
	cout << "\nAccount No. : " << acno;
	cout << "\nAccount Holder Name : ";
	cout << name;
	cout << "\nType of Account : " << type;
	cout << "\nBalance amount : " << deposit;
	
	
}



class createAccount : public account{
	
	
	cout << "\nEnter The account No. :";
	cin >> acno;
	cout << "\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name, 50);

	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	
	type = toupper(type);
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> deposit;
	
	cout << "\n\n\nAccount Created..";
	
	
}

class display : public account{
	
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile){
		
		cout << "File could not be open !! Press any Key...";
		return;
		
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(account))){
		ac.report();
		
	}
	inFile.close();
	
	
	
}


class deposit_withdraw : account{
	
	
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	
	
	
	if (!File)	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	
	
	
	
	while (!File.eof() && found == false)	{
		
		
		File.read(reinterpret_cast<char*> (&ac), sizeof(account));
	


	if (ac.retacno() == n)		{
			
			
			ac.show_account();
			if (option == 1){
				
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				ac.dep(amt);
				
			}
			if (option == 2){
				
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.draw(amt);
				
				
			}
			
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;

		}
	}
	
	
	
	File.close();	if (found == false)
		cout << "\n\n Record Not Found ";
	
	
	
	
	
}

void write_account(){
	
	
	
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
	outFile.close();
	
	
	
	
}




