#include <string>

using namespace std;

#ifndef _checkingAccount
#define _checkingAccount

class checkingAccount {
private:
	string fName;
	string lName;
	int accountNum;
	string address;
	double currentBalance;
	double newTrans;
public:
	checkingAccount();
	void setfName(string Fnam);
	void setlName(string Lnam);
	void setaccountNum(int aNum);
	void setaddress(string aD);
	void setcurrentBalance(double cB);
	void setnewTrans(double nT);
	string getfName();
	string getlname();
	int getaccountNum();
	string getaddress();
	double gercurrentBalance();
	double getnewTrans();
	~checkingAccount();

};


#endif