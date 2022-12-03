#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void add();
void edit();
void view();
void Delete();
void search();

int main() {
	system("cls");
	int option;
	bool running = true;

	do {
		cout << "Address Book, created in C++!";					
		cout << "\n-----------------------------------------\n\n";
		cout << "What do you want to do?";
		cout << "\n1) Add a contact\n";
		cout << "\n2) Edit a contact\n";
		cout << "\n3) Delete a contact\n";
		cout << "\n4) View all contacts\n";
		cout << "\n5) Search\n";
		cout << "\n6) Exit\n\n";

		cout << "Make an action: ";
		cin >> option;
		cin.ignore();
		switch (option) {
			case 1:
				add();
				break;
			case 2:
				edit();
				break;
			case 3:
				Delete();
				break;
			case 4:
				view();
				break;
			case 5:
				search();
				break;
			case 6:
				running = false;
				break;
			default:
				cout << "Please choose between 1 to 6\n";
				int main();
		}
	} while (running);

	cout << "End of the program";
}

void add() {
	system("cls");
	double cnt, nr = 0;
	string f_name, l_name, address, contact, f_name2, l_name2, address2, contact2;

	cout << "Address Book, created in C++!";
	cout << "\n-----------------------------------------\n\n";
	cout << "Type 'back' at First name to exit this section\n";
	cout << "For a longer address, please use '_' instead of space\n\n";

	cout << "First name: ";
	getline(cin, f_name);
	if (f_name == "back")
		main();

	cout << "Last name: ";
	getline(cin, l_name);
	
	cout << "Address: ";
	getline(cin, address);

	cout << "Contact number: ";
	getline(cin, contact);

	ifstream fin("database.txt");
	while(fin >> cnt >> f_name2 >> l_name2 >> address2 >> contact2)
		if (cnt == 100) {
			cout << "Max number of contacts reached(100).";
			main();
		} else
			nr = cnt;

	ofstream fout("database.txt", ios::app);
	++nr;
	fout << nr << ' ' << f_name << ' ' << l_name << ' ' << address << ' ' << contact << '\n';
		
	system("pause");
	system("cls");
}

void edit() {

}

void view() {
	system("cls");
	double cnt;
	string f_name, l_name, address, contact;
	cout << "Nr." << setw(19) << "First Name" << setw(24) << "Last Name" << setw(24) << "Address" << setw(30) << "Contact\n\n";

	ifstream fin("database.txt");
	while (fin >> cnt >> f_name >> l_name >> address >> contact) 
		cout << setw(3) << cnt << setw(17) << f_name << setw(25) << l_name << setw(25) << address << setw(30) << contact << '\n';
	cout << '\n';

	system("pause");
	system("cls");
}

void Delete() {
}

void search() {
	system("cls");
	int option;
	double  cnt, nr;
	string f_name, l_name, address, contact, f_name2, l_name2, address2, contact2;

	cout << "--Search--";
	cout << "\n1) First name";
	cout << "\n2) Last name";
	cout << "\n3) Address";
	cout << "\n4) Contact\n";

	ifstream fin("database.txt");
	cout << "Enter Choice: ";
	cin >> option;
	switch (option) {
		case 1:
			cout << "First Name: ";
			cin >> f_name;
			while (fin >> cnt >> f_name2 >> l_name2 >> address2 >> contact2)
				if (f_name == f_name2)
					cout << cnt << ' ' << f_name2 << ' ' << l_name2 << ' ' << address2 << ' ' << contact2;
			break;
		case 2:
			cout << "Last Name: ";
			cin >> l_name;
			while (fin >> cnt >> f_name2 >> l_name2 >> address2 >> contact2)
				if (l_name == l_name2)
					cout << cnt << ' ' << f_name2 << ' ' << l_name2 << ' ' << address2 << ' ' << contact2;
			break;
		case 3:
			cout << "Address: ";
			cin >> address;
			while (fin >> cnt >> f_name2 >> l_name2 >> address2 >> contact2)
				if (address == address2)
					cout << cnt << ' ' << f_name2 << ' ' << l_name2 << ' ' << address2 << ' ' << contact2;
			break;
		case 4:
			cout << "Contact: ";
			cin >> contact;
			while (fin >> cnt >> f_name2 >> l_name2 >> address2 >> contact2)
				if (contact == contact2)
					cout << cnt << ' ' << f_name2 << ' ' << l_name2 << ' ' << address2 << ' ' << contact2;
			break;
		default:
			cout << "Please choose between 1 to 4";
			search();
	}
	cout << '\n';
	
	system("pause");
	system("cls");
}
