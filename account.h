#pragma once
#include<string>
#include"function.h"
using namespace std;

class account
{
private:
	string acc_number;
	string name;
	float acc_balance=0;
public:
	account();
	void set_acc_num();
	void set_name();
	void set_deposit();
	void create_acc();
	void show_acc() const;
	void modify();
	void deposit(float n);
	void withdraw(float n);
	string get_acc_num();
	string get_name();
	float get_acc_balance();
	friend void delete_acc(string key);
};

 