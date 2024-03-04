#pragma once
#include<cstdio>
#include "function.h"
#include"account.h"
#include<iostream>
#include<fstream> 
#include<sstream>
#include<iomanip>
using namespace std;

void intro() {
	cout << "\n\n\n BANK MANAGEMENT SYSTEM" << endl;
	cout << "\n\n MADE BY: tdt" << endl;
	cin.ignore();
}
void write_acc() {
	account a;
	ofstream outFile;
	outFile.open("account_list.txt",ios::app);
	if (!outFile.is_open()) {
		cout << "File could not be opened!! Press any key..." << endl;
		return;
	}
	a.create_acc();
	outFile.write(reinterpret_cast<char*> (&a), sizeof(account));
	cout << "Created sucessfully! Press any key..." << endl;
	cin.ignore();
	outFile.close();
}

void show_acc(string key) {
	account *a;
	bool check = false;
	ifstream inFile("account_list.txt");

	if (!inFile.is_open()) {
		cout << "File could not be opened!! Press any key..." << endl;
		return;
	}
	a = new account[sizeof(account)];
	while (!inFile.eof()) {	
		inFile.read(reinterpret_cast<char*> (a), sizeof(account));
		if (a->get_acc_num() == key) {
			a->show_acc();
			check = true;
			cout << "Press any key..." << endl;
			cin.ignore();
			break;
		}

	}
	inFile.close();
	if (check == false)
		cout <<"Account number does not exist..." << endl;
	cin.ignore();
}

void modify(string key) {
	bool found = false;
	account *a;
	fstream outFile;
	size_t pos;
	outFile.open("account_list.txt",ios::in|ios::out);
	if (!outFile.is_open()) {
		cout << "File could not be opened! Press any key..." << endl;
		return;
	}
	while (!outFile.eof()&&found==false) {
		a = new account[sizeof(account)];
		outFile.read(reinterpret_cast<char*> (a), sizeof(account));
		if (key == a->get_acc_num()) {
			pos = outFile.tellg();
			cout << "Modify your account: " << endl;
			a->modify();
			outFile.seekp(pos-sizeof(account));
			outFile.write(reinterpret_cast<char*> (a), sizeof(account));
			cout << "Record updated..." << endl;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "Account number does not exist..." << endl;
	outFile.close();

}

void deposit(string key) {
	bool found = false;
	account* a;
	fstream outFile;
	size_t pos;
	float dep;
	outFile.open("account_list.txt", ios::in | ios::out);
	if (!outFile.is_open()) {
		cout << "File could not be opened! Press any key..." << endl;
		return;
	}
	while (!outFile.eof() && found == false) {
		a = new account[sizeof(account)];
		outFile.read(reinterpret_cast<char*> (a), sizeof(account));
		if (key == a->get_acc_num()) {
			cout << "Welcome " << a->get_name() << "!" << endl;
			cout << "Deposit Amount: ";
			cin >> dep;
			cin.ignore();
			pos = outFile.tellg();
			a->deposit(dep);
			outFile.seekp(pos - sizeof(account));
			outFile.write(reinterpret_cast<char*> (a), sizeof(account));
			cout << "Deposit Succeeded! Press any key..." << endl;
			cin.ignore();
			found = true;
			break;
		}
	}
		if (found == false)
			cout << "Account number does not exist..." << endl;
		outFile.close();
		cin.ignore();
}

void withdraw(string key) {
	bool found = false;
	account* a;
	fstream outFile;
	size_t pos;
	float wit;
	outFile.open("account_list.txt", ios::in | ios::out);
	if (!outFile.is_open()) {
		cout << "File could not be opened! Press any key..." << endl;
		return;
	}
	while (!outFile.eof() && found == false) {
		a = new account[sizeof(account)];
		outFile.read(reinterpret_cast<char*> (a), sizeof(account));
		if (key == a->get_acc_num()) {
			cout << "Welcome " << a->get_name() << "!" << endl;
			cout << "Withdraw Amount: ";
			cin >> wit;
			cin.ignore();
			pos = outFile.tellg();
			a->withdraw(wit);
			outFile.seekp(pos - sizeof(account));
			outFile.write(reinterpret_cast<char*> (a), sizeof(account));
			cout << "Withdraw Succeeded! Press any key..." << endl;
			cin.ignore();
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "Account number does not exist..." << endl;
	outFile.close();
	cin.ignore();
}

void report() {
	int i = 1;
	account* a;
	fstream inFile("account_list.txt");
	if (!inFile.is_open()) {
		cout << "File could not be opened! Press any key..." << endl;
		return;
	}
	cout<<"|| " << left << setw(10) << "No." << "|| " << left << setw(20) << "Account Number" << "|| " << left << setw(40) << "Name" << "|| Account Balance" << endl;
	cin.ignore();
	while (!inFile.eof()) {
		a = new account[sizeof(account)];
		inFile.read(reinterpret_cast<char*> (a), sizeof(account));
		cout << "|| " << left << setw(10) << i << "|| " << left << setw(20) << a->get_acc_num() << "|| " << left << setw(40) << a->get_name() << "|| " << a->get_acc_balance() << endl;
		i++;
	}
	inFile.close();
	cin.ignore();
}

void delete_acc(string key) {
	bool found = false;
	bool check;
	account* a;
	size_t pos;
	fstream inFile, outFile;
	inFile.open("account_list.txt", ios::in);
	outFile.open("temp.txt", ios::out);
	if (!inFile.is_open()) {
		cout << "File could not be opened! Press any key..." << endl;
		return;
	}
	while (!inFile.eof()) {
		a = new account[sizeof(account)];
		inFile.read(reinterpret_cast<char*> (a), sizeof(account));
		if (a->get_acc_num() == key) {
			a->show_acc();
			cout << "Are you really want to delete this account?" << endl;
			cout << "1. YES" << endl;
			cout << "0. NO" << endl;
			cin >> check;
			if (check == 0)
				outFile.write(reinterpret_cast<char*> (a), sizeof(account));
			else {
				found = true;
				continue;
			}
		}
			outFile.write(reinterpret_cast<char*> (a), sizeof(account));
	}
	inFile.close();
	outFile.close();
	if (found == false)
		cout << "Account does not exist..." << endl;
	else {
		cout << "Account Deleted! Press any key..." << endl;
		cin.ignore();
	}
	remove("account_list.txt");
	rename("temp.txt", "account_list.txt");
}