#include"account.h"
#include"function.h"
#include<iostream>
using namespace std;

int main() {
	account a;
	//a.create_acc();
	//a.show_acc();
	//a.des(5000);
	//a.show_acc();
	int opt;
	string key;
	system("cls");
	intro();
	system("cls");

	do {
		system("cls");
		cout << "||==============MENU=============||" << endl;
		cout << "|| 1. CREATE ACCOUNT             ||" << endl;
		cout << "|| 2. SHOW ACCOUNT               ||" << endl;
		cout << "|| 3. MODIFY ACCOUNT             ||" << endl;
		cout << "|| 4. DEPOSIT                    ||" << endl;
		cout << "|| 5. WITHDRAW                   ||" << endl;
		cout << "|| 6. DELETE ACCOUNT             ||" << endl;
		cout << "|| 7. REPORT                     ||" << endl;
		cout << "|| 8. EXIT                       ||" << endl;
		cout << "||===============================||" << endl;
		cout << "\n Select your option: ";
		cin >> opt;
		system("cls");
		switch (opt)
		{
		case 1:
			write_acc();
			break;
		case 2:
			cout << "Insert Account number: ";
			fflush(stdin);
			cin >> key;
			cin.ignore();
			show_acc(key);
			break;
		case 3:
			cout << "Insert Account number: ";
			cin >> key;
			modify(key);
			break;
		case 4:
			cout << "Insert Account Number: ";
			fflush(stdin);
			cin >> key;
			cin.ignore();
			deposit(key);
			break;
		case 5:
			float wit;
			cout << "Insert Account Number: ";
			fflush(stdin);
			cin >> key;
			cin.ignore();
			withdraw(key);
			break;
		case 6:
			cout << "Insert Account Number: ";
			fflush(stdin);
			cin >> key;
			cin.ignore();
			delete_acc(key);
			break;
		case 7:
			report();
			break;
		case 8:
			cout << "Thanks for using my system!" << endl;
			break;
		default:
			break;
		}
	} while (opt != 8);
	return 0;
}