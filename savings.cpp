#include <cstdlib>
#include <iostream>
#include <string>
#include"savingsAccount.h"
using namespace std;

savingsAccount::savingsAccount () {
	sfName = "First name";
	slName = "Last name";
	sAccountNum = 0;
	aAddress = "123 none street";
	sCurrentBalance = 0.00;
	sNewTrans = 0.00;
}

void savingsAccount::setsfName(string Fnam) {
	sfName = Fnam;
}

void savingsAccount::setslName(string Lnam) {
	slName = Lnam;
}

void savingsAccount::setsAccountNum(int aNum) {
	sAccountNum = aNum;
}
void savingsAccount::setsAddress(string aD) {
	aAddress = aD;
}

void savingsAccount::setsAcurrentBalance(double cB) {
	sCurrentBalance = cB;
}

void savingsAccount::setsnewTrans(double nT) {
	sNewTrans = nT;
}

string savingsAccount::getsfName() {
	return sfName;
}

string savingsAccount::getslname() {
	return slName;
}

int savingsAccount::getsAccountNum() {
	return sAccountNum;
}

string savingsAccount::getsAddress() {
	return aAddress;
}

double savingsAccount::getssAcurrentBalance() {
	return sCurrentBalance;
}

double savingsAccount::getsNewTrans() {
	return sNewTrans;
}

 savingsAccount::~savingsAccount() {
	cout << " Your account data is saved " << endl;
}