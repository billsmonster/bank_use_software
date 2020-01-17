#include <cstdlib>
#include <iostream>
#include <string>
#include"checkingAccount.h"

using namespace std;

checkingAccount::checkingAccount() {
	fName = "First name"; 
	lName = "Last name";
	accountNum = 0;
	address = "123 none street";
	currentBalance = 0.00;
	newTrans = 0.00;
}

void checkingAccount::setfName(string Fnam) {
	fName = Fnam;
}

void checkingAccount::setlName(string Lnam) {
	lName = Lnam;
}

void checkingAccount::setaccountNum(int aNum) {
	accountNum = aNum;
}
void checkingAccount::setaddress(string aD) {
	address = aD;
}

void checkingAccount::setcurrentBalance(double cB) {
	currentBalance = cB;
}

void checkingAccount::setnewTrans(double nT) {
	newTrans = nT;
}

string checkingAccount::getfName() {
	return fName;
}

string checkingAccount::getlname() {
	return lName;
}

int checkingAccount::getaccountNum() {
	return accountNum;
}

string checkingAccount::getaddress() {
	return address;
}

double checkingAccount::gercurrentBalance() {
	return currentBalance;
}

double checkingAccount::getnewTrans() {
	return newTrans;
}

checkingAccount::~checkingAccount() {
}