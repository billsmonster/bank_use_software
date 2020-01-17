#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>  // included libraries
#include <fstream>
#include"checkingAccount.h"
#include"savingsAccount.h"

using namespace std;

char ChoiceMenu(char& i);
void inputDecision(char& i, char& b, checkingAccount a1, savingsAccount s1);
char checkingChoice(char& a, checkingAccount a1);
void accountEntry();
void printCAccountData(checkingAccount a1);
void ifcorrect(checkingAccount a1);
void sAccountEntry(savingsAccount s1);
char savingsChoice(char& b, savingsAccount s1);
void sAccountEntry(savingsAccount s1);  // included prototypes
void printsQccountData(savingsAccount s1);
void sifcorrect(savingsAccount s1);
void personalloan();
void mortgage();

int main() { //driver program
	char i ,b ;
	checkingAccount a1; // declaring variables
	savingsAccount s1; 
	i = ChoiceMenu(i); //the function calls
	inputDecision(i,b,a1,s1);


	system("pause");
	return 0;// This is for running
}

char ChoiceMenu(char& i) { // decide where to go for checking account
	
		cout << "Welcome to Lenz National Bank " << endl;
		cout << "Please choose a character for the part of the system you want to access \n "
			"To access checking accounts enter c \n "
			"To access savings account(s) enter s \n " // could add any choices per clients (banks) wish
			"To access personal loan account(s) enter p \n "
			"To access mortgage loan account enter m \n " << endl;// can also add the features for a credit card acoount , safty depsoit box , CD ,etc.
		    
		cin >> i;
	
	return i;
}


void inputDecision( char& i, char& b, checkingAccount a1, savingsAccount s1) {
	if ((i == 'c') || (i == 'C')) { // wanted to represent if logic , could also use a switch
		checkingChoice(i, a1);
	}
	else if ((i == 's') || (i == 'S')) {
		savingsChoice(i, s1);
	}
	else if ((i == 'p') || (i == 'P')) {
		personalloan();
	}
	else if ((i == 'm') || (i == 'M')) {
		mortgage();
	}
	
	else
		cout << "Please try again" << endl;
	}


char checkingChoice(char& a ,checkingAccount a1) { //choose what to do with account 
	cout << "If you want to add a new account enter n \n"
		"If you want to work with current account enter c\n";
	cin >> a;
	if (a == 'n') {
		accountEntry();
	}
	else if (a == 'c') {
		cout << "Welcome Back"; //as program is currently running must enter account data first

		printCAccountData(a1);
	}
	else
		cout << "Please enter a valid choice" << endl;
	return a;
}
 


void accountEntry() {// saving the information to a class 
	string fNam ,lNam ,aDd;
	int aNumb;
	double bal;
	checkingAccount a1;
	cout << "Please enter your first name" << endl;
	cin >> fNam;
	a1.setfName(fNam);
	cout << "Please enter your last name" << endl;
	cin >>lNam;
	a1.setlName(lNam);
	cout << "Please enter your address" << endl;
	cin.ignore();
	getline(cin, aDd);
	a1.setaddress(aDd);
	aNumb = rand() * 11111;
	cout << "Please enter your opening balance" << endl;
	cin >> bal;
	a1.setcurrentBalance(bal);

	cout << "\n Your account number is : " << aNumb<<endl;
	a1.setaccountNum(aNumb);
	printCAccountData(a1);

	ifcorrect(a1);
	
}

void printCAccountData(checkingAccount a1) {// caN USE THIS  functionTO CALL  anytime needed
	//cout << "Please double check your information " << endl;
	cout << "Your first name is : " << a1.getfName() << endl;  
	cout << "Your last name is : " << a1.getlname() << endl;
	cout << "Your account number is : " << a1.getaccountNum() << endl;
	cout << "The opening balance is : $" << a1.gercurrentBalance() << endl;
}


void ifcorrect(checkingAccount a1) {// save to local bvariable if needed 
	char n;
	const string cFname= a1.getfName(); 
	const string cLname= a1.getlname();
	const int cAnum= a1.getaccountNum();
	const double cOp= a1.gercurrentBalance();


	cout << "If the information is correct enter f to save the information " << endl;
	cout << " If informtion is incorecct enter any other charecter" << endl;
	cin >> n;

	if (n == 'f' || n == 'F') {
		cout << "Good, we will write your data to a file !" << endl; // writes this information to a file to save and clears

		ofstream checkingfile;
		checkingfile.open("checkingfile.txt");
		checkingfile<< "This is checking account data in a file form"<<endl; //saving information to a file
		checkingfile<< "Your first name is : " << a1.getfName() << endl;
		checkingfile<< "Your last name is : " << a1.getlname() << endl;
		checkingfile<< "Your account number is : " << a1.getaccountNum() << endl;
		checkingfile<< "The account balance is : $ " << a1.gercurrentBalance() << endl;
		checkingfile.close(); 
		
	}
	else
		accountEntry();


}

char savingsChoice( char& b,  savingsAccount s1) { //FUNCTION FOR CHECKING
	cout << "If you want to add a new account enter n \n"
		"If you want to work with current account enter c\n";
	cin >> b;
	if (b == 'n') {
		sAccountEntry(s1);
		
	}
	else if (b== 'c') {
		cout << "Welcome Back to savings account"; //as program is currently running must enter account data first

		
	}
	else
		cout << "Please enter a valid choice" << endl;
	return b;
}


void sAccountEntry(savingsAccount s1) {//ACCOUNT ENTRY for savings
	string sfnam, slnam, address;
	double sSbal;
	 int asnt;
	cout << "Please enter your first name" << endl;
	cin >> sfnam;
	s1.setsfName(sfnam);
	cout << "Please enter your last name" << endl;
	cin >> slnam;
	s1.setslName(slnam);
	cout << "Please enter your address" << endl;
	cin.ignore();
	getline(cin, address);
	s1.setsAddress(address);
	cout << "Please enter your opening balance" << endl;
	cin >> sSbal;
	s1.setsAcurrentBalance(sSbal);
	asnt = rand() * 22222;
	cout << "\n Your account number is : " << asnt << endl;
	s1.setsAccountNum(asnt);
}

void printsQccountData(savingsAccount s1) {// will call anytime I need savings data printed out
	cout << "Please double check your information " << endl;
	cout << "Your first name is : " << s1.getsfName() << endl;
	cout << "Your last name is : " << s1.getslname() << endl;
	cout << "Your account number is : " << s1.getsAccountNum() << endl;
	cout << "The opening balance is : $" << s1.getssAcurrentBalance()<< endl;
}

void sifcorrect(savingsAccount s1) { //check before savign to a file
	char l;
	const string csFname = s1.getsfName();
	const string csLname = s1.getslname();
	const int csAnum = s1.getsAccountNum();
	const double csOp = s1.getssAcurrentBalance();


	cout << "If the information is correct enter f to save the information " << endl;
	cout << " If informtion is incorecct enter any other charecter" << endl;
	cin >> l;

	if (l == 'f' || l== 'F') {// ciuld also use toupper
		cout << "Good, we will write your savings account data to a file !" << endl;
		ofstream savingsfile;
		savingsfile.open("checkingfile.txt");
		savingsfile << "This is checking account data in a file form" << endl;
		savingsfile << "Your first name is : " << s1.getsfName() << endl;
		savingsfile << "Your last name is : " << s1.getslname() << endl;
		savingsfile << "Your account number is : " << s1.getsAccountNum() << endl;
		savingsfile << "The account balance is : $ " << s1.getssAcurrentBalance() << endl;
		savingsfile.close();

	}
	else
		sAccountEntry(s1);


}

void personalloan() {// this is for ploan section
	struct personalloandata {// using a structure to deminstrate use of 
		string Plnfnam;
		string plnam;
		string address;
		int FICO;
		double income;
		int jobLength;
		double otherDebt;
		int loanAmount;
	};
   
	personalloandata p1;
	cout << "Welcome to our personal loan department" << endl
		<< "Please enter your first name" << endl;
	cin >> p1.Plnfnam;
	cout << "Please enter your last name" << endl;
	cin >> p1.plnam;
	cout << "Please enter your home address" << endl;
    
	cin.ignore();
	getline(cin, p1.address);
	cout << "Plese enter your FICO score" << endl;
	cin >> p1.FICO;
	cout << "Please enter your yearly income" << endl;
	cin >> p1.income;
	cout << "How Long have you been at curretn job" << endl;
	cin >> p1.jobLength;
	cout << "How much total other debt do you have, not including your house ?"<< endl;
	cin >> p1.otherDebt;
	
	if (p1.jobLength > 2) { // this is do deminstrate nested if logic, couls also have the head banker cin the data  if needed
		if (p1.FICO <= 650)
			cout << "You do not qualify for a personal loan" << endl;
		else if (p1.FICO >= 651 && p1.FICO <= 700) {
			if (p1.income <= 25, 000)
				cout << "You do not qualify" << endl;
			else if (p1.income > 25, 000 && p1.income <= 50, 000 &&p1.otherDebt <= 12, 000) {
				cout << "Congradulatiuons you qualify for a $5,000 loan" << endl;
				p1.loanAmount = 5000;
			}
			else if (p1.income > 50001 && p1.income <= 100000 && p1.otherDebt <= 15000) {
				cout << "Congradulatiuons you qualify for a $10,000 loan" << endl;
				p1.loanAmount = 10000;
			}
			else if (p1.income > 150001 && p1.income <= 200000 && p1.otherDebt <= 48000) {
				cout << "Congradulatiuons you qualify for a $20,000 loan" << endl;
				p1.loanAmount = 20000;
			}
			else if (p1.income > 200001 && p1.income <= 500000 && p1.otherDebt <= 72000) {
				cout << "Congradulatiuons you qualify for a $30,000 loan" << endl;
				p1.loanAmount = 30000;
			}
			else if (p1.income > 500001 && p1.otherDebt <= 100000) {
				cout << "Congradulatiuons you qualify for a $30,000 loan" << endl;
				p1.loanAmount = 5000;
			}
		}
		else if (p1.FICO >= 701 && p1.FICO <= 800) {
			if (p1.income <= 20, 000)
				cout << "You do not qualify" << endl;
			else if (p1.income > 25000 && p1.income <= 50000 && p1.otherDebt <= 14, 000) {
				cout << "Congradulatiuons you qualify for a $6,000 loan" << endl;
				p1.loanAmount = 6000;
			}
			else if (p1.income > 50001 && p1.income <= 100000 && p1.otherDebt <= 18000) {
				cout << "Congradulatiuons you qualify for a $12,000 loan" << endl;
				p1.loanAmount = 12000;
			}
			else if (p1.income > 150001 && p1.income <= 200000 && p1.otherDebt <= 52000) {
				cout << "Congradulatiuons you qualify for a $25,000 loan" << endl;
				p1.loanAmount = 25000;
			}
			else if (p1.income > 200001 && p1.income <= 500000 && p1.otherDebt <= 80000) {
				cout << "Congradulatiuons you qualify for a $35,000 loan" << endl;
				p1.loanAmount = 35000;
			}
			else if (p1.income > 500001 && p1.otherDebt <= 150000) {
				cout << "Congradulatiuons you qualify for a $40,000 loan" << endl;
				p1.loanAmount = 40000;
			}
		}

		else if (p1.FICO >= 800) {
			if (p1.income <= 15000) {
				cout << "You do not qualify" << endl;
			}
			else if (p1.income > 25000 && p1.income <= 50000 && p1.otherDebt <= 20, 000) {
				cout << "Congradulatiuons you qualify for a $6,000 loan" << endl;
				p1.loanAmount = 8000;
			}
			else if (p1.income > 50001 && p1.income <= 100000 && p1.otherDebt <= 25000) {
				cout << "Congradulatiuons you qualify for a $12,000 loan" << endl;
				p1.loanAmount = 14000;
			}
			else if (p1.income > 100001 && p1.income <= 150000 && p1.otherDebt <= 25000) {
				cout << "Congradulatiuons you qualify for a $17,000 loan" << endl;
				p1.loanAmount = 17000;
			}
			else if (p1.income > 150001 && p1.income <= 200000 && p1.otherDebt <= 25000) {
				cout << "Congradulatiuons you qualify for a $20,000 loan" << endl;
				p1.loanAmount = 20000;
			}
			else if (p1.income > 200001 && p1.income <= 500000 && p1.otherDebt <= 25000) {
				cout << "Congradulatiuons you qualify for a $25,000 loan" << endl;
				p1.loanAmount = 25000;
			}
			else if (p1.income > 500001 && p1.otherDebt <= 150000) {
				cout << "Congradulatiuons you qualify for a $45,000 loan" << endl;
				p1.loanAmount = 45000;
			}

		}
		else {
			cout << "You do not qualify for a personal loan" << endl;
		}
	}
	else {
		cout << "You do not qualify for a personal loan"<<endl;
	}
};

void mortgage() { // same as personal loan
	
	struct mortgage {
		string mPlnfnam;
		string mplnam;
		string maddress;
		int mFICO;
		double mincome;
		int jmobLength;
		double motherDebt;
		int mloanAmount;
	};
		
		mortgage m1;
		 
		cout << "Welcome to the mortgage departmernt" << endl;
		cout<< "Please enter your first name" << endl;
		cin >> m1.mPlnfnam;
		cout << "Please enter your Last name" << endl; // maybe I need option of middle name / int?
	    cin >> m1.mplnam;
		cout <<"Please enter your home address" << endl;
		cin.ignore();
		getline(cin, m1.maddress);
		cout << "Please enter your FICO score" << endl;
		cin >> m1.mFICO;
		cout << "Please enter your yearly income" << endl;
		cin >> m1.mincome;
		cout << "How Long have you been at curretn job" << endl;
		cin >> m1.jmobLength;
		cout << "How much total other debt do you have, not including your house ?" << endl;
		cin >> m1.motherDebt;

		if (m1.jmobLength > 2) {// this could also be "cin" by a user like the banker manager
			if (m1.mFICO <= 600)
				cout << "You do not qualify for a mortgage" << endl;
			else if (m1.mFICO >= 601 && m1.mFICO <= 650) {
				if (m1.mincome <= 25000) // i changed some criteria from the personal loan. 
					cout << "You do not qualify for a mortgage" << endl;
				else if (m1.mincome > 30000 && m1.mincome <= 55000 &&  m1.motherDebt <= 12000) {
					cout << "Congradulatiuons you qualify for a $80,000 mortagage loan" << endl;
					m1.mloanAmount = 80000;
				}
				else if (m1.mincome > 55000 && m1.mincome <= 70000 && m1.motherDebt <= 15000) {
					cout << "Congradulatiuons you qualify for a $100,000 mortage loan" << endl;
					m1.mloanAmount = 100000;
				}
				else if (m1.mincome > 70000 && m1.mincome <= 90000 && m1.motherDebt <= 48000) {
					cout << "Congradulatiuons you qualify for a $120,000 mortage loan" << endl;
					m1.mloanAmount = 120000;
				}
				else if (m1.mincome > 90000 && m1.mincome <= 120000 && m1.motherDebt <= 72000) {
					cout << "Congradulatiuons you qualify for a $1500,000 mortage loan" << endl;
					m1.mloanAmount = 150000;
				}
				else if (m1.mincome > 500000 && m1.motherDebt <= 100000) {
					cout << "Congradulatiuons you qualify for a $200,000 +loan" << endl;
					m1.mloanAmount = 200000;
				}
			}
			else if (m1.mFICO >= 650 && m1.mFICO <= 750) {
				if (m1.mincome <= 20000)
					cout << "You Do not qualify" << endl;
				else if (m1.mincome > 30000 && m1.mincome <= 55000 && m1.motherDebt <= 12, 000) {
					cout << "Congradulatiuons you qualify for a $90,000 mortagage loan" << endl;
					m1.mloanAmount = 90000;
				}
				else if (m1.mincome > 55000 && m1.mincome <= 70000 && m1.motherDebt <= 15000) {
					cout << "Congradulatiuons you qualify for a $110,000 mortage loan" << endl;
					m1.mloanAmount = 110000;
				}
				else if (m1.mincome > 700000 && m1.mincome <= 90000 && m1.motherDebt <= 48000) {
					cout << "Congradulatiuons you qualify for a $130,000 mortage loan" << endl;
					m1.mloanAmount = 130000;
				}
				else if (m1.mincome > 90000 && m1.mincome <= 120000 && m1.motherDebt <= 72000) {
					cout << "Congradulatiuons you qualify for a $160,000 mortage loan" << endl;
					m1.mloanAmount = 160000;
				}
				else if (m1.mincome > 120000 && m1.mincome <= 200000 && m1.motherDebt <= 85000) {
					cout << "Congradulatiuons you qualify for a $160,000 mortage loan" << endl;
					m1.mloanAmount = 190000;
				}
				else if (m1.mincome > 200000 && m1.mincome <= 500000 && m1.motherDebt <= 90000) {
					cout << "Congradulatiuons you qualify for a $160,000 mortage loan" << endl;
					m1.mloanAmount = 200000;
				}
				else if (m1.mincome > 500000 && m1.motherDebt <= 100000) {
					cout << "Congradulatiuons you qualify for a $250,000 +loan" << endl;
					m1.mloanAmount = 250000;

				}
				
			}

			else if (m1.mFICO >= 750) {
				if (m1.mincome <= 10000)
					cout << "You do not qualify" << endl;
				else if (m1.mincome >= 10000 && m1.mincome <= 55000 && m1.motherDebt <= 8000) {
					cout << "Congradulatiuons you qualify for a $90,000 mortagage loan" << endl;
					m1.mloanAmount = 90000;
				}
				else if (m1.mincome > 550000 && m1.mincome <= 70000 && m1.motherDebt <= 15000) {
					cout << "Congradulatiuons you qualify for a $120,000 mortage loan" << endl;
					m1.mloanAmount = 120000;
				}
				else if (m1.mincome > 700000 && m1.mincome <= 90000 && m1.motherDebt <= 48000) {
					cout << "Congradulatiuons you qualify for a $140,000 mortage loan" << endl;
					m1.mloanAmount = 140000;
				}
				else if (m1.mincome > 90000 && m1.mincome <= 120000 && m1.motherDebt <= 72000) {
					cout << "Congradulatiuons you qualify for a $160,000 mortage loan" << endl;
					m1.mloanAmount = 160000;
				}
				else if (m1.mincome > 120000 && m1.mincome <= 250000 && m1.motherDebt <= 72000) {
					cout << "Congradulatiuons you qualify for a $190,000 mortage loan" << endl;
					m1.mloanAmount = 190000;
				}
				else if (m1.mincome >250000 && m1.mincome <= 500000 && m1.motherDebt <= 72000) {
					cout << "Congradulatiuons you qualify for a $200,000 mortage loan" << endl;
					m1.mloanAmount = 200000;
				}
				else if (m1.mincome > 500000 && m1.motherDebt <= 1000000) {
					cout << "Congradulatiuons you qualify for a $280,000 + mortage loan" << endl;
					m1.mloanAmount = 280000;

				}
			}

			else {
				cout << "You do not qualify for a Mortgage " << endl;
			}
		}

		else {
			cout << "You do not qualify for a Mortgage" << endl;
		}

		};
