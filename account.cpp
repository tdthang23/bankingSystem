#include "account.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

account::account() {
	acc_number = " ";
	name = " ";
	acc_balance = 0;
}

void account::set_acc_num() {
	cout << "Account number: ";
	fflush(stdin);
	cin >> acc_number;
	cin.ignore();
}

void account::set_name() {
	cout << "Account Holder's Name: ";
	fflush(stdin);
	getline(cin, name);
}

void account::set_deposit() {
	cout << "Deposit: ";
	cin >> acc_balance;
	cin.ignore();
}

void account::create_acc(){
	cout << "Insert account information:" << endl;
	set_acc_num();
	set_name();
	set_deposit();
}

void account::show_acc() const {
	cout << "Account No. : " << acc_number << endl;
	cout << "Account Name: " << name << endl;
	cout << "Account Balance: " << acc_balance << endl;
}

void account::modify() {
	cout << "Modify Account No: ";
	fflush(stdin);
	cin >> acc_number;
	cin.ignore();
	cout << "Modify Account holder's name: ";
	fflush(stdin);
	getline(cin, name);
	cin.ignore();
}

void account::deposit(float n){
	acc_balance += n;
}

void account::withdraw(float n) {
	acc_balance -= n;
}

string account::get_acc_num() {
	return acc_number;
}
string account::get_name() {
	return name;
}
float account::get_acc_balance() {
	return acc_balance;
}