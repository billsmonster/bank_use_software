#include <string>

using namespace std;

#ifndef _savingsAccount
#define _savingsAccount

class savingsAccount {
private:
	string sfName;
	string slName;
	int sAccountNum;
	string aAddress;
	double sCurrentBalance;
	double sNewTrans;
public:
	savingsAccount();
	void setsfName(string Fnam);
	void setslName(string Lnam);
	void setsAccountNum(int aNum);
	void setsAddress(string aD);
	void setsAcurrentBalance(double cB);
	void setsnewTrans(double nT);
	string getsfName();
	string getslname();
	int getsAccountNum();
	string getsAddress();
	double getssAcurrentBalance();
	double getsNewTrans();
	~savingsAccount();
};


#endif