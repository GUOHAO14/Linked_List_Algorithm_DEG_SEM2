#pragma once
#include <iostream>
#include <limits>
using namespace std;

int mainMenu();
int insertMenu();
int deleteMenu();
int sortMenu();
int displayMenu();

int mainMenu() {
	int choice, subchoice;
	cout << endl << "Student Records Management - Main Menu" << endl;
	cout << "1. Add New Student Record" << endl;
	cout << "2. Delete Student Record" << endl;
	cout << "3. Sort Student Records by CGPA" << endl;
	cout << "4. Search Student Record (Linear Search)" << endl;
	cout << "5. Display Information" << endl;
	cout << "6. Exit Program" << endl;

	while (true) {
		cout << "Enter choice: ";

		if (cin >> choice) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			return choice;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int insertMenu() {
	int subchoice;
	cout << endl << "Select Option to Add New Student Record:" << endl;
	cout << "1. Insert Front - Add new data to the front of list" << endl;
	cout << "2. Insert By Index (Middle) - Add new data to the middle of the list using index position" << endl;
	cout << "3. Insert Rear - Add new data to the end of list" << endl;
	cout << "4. Back" << endl;
	while (true) {
		cout << "Enter choice: ";

		if (cin >> subchoice) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			return subchoice;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int deleteMenu() {
	int subchoice;
	cout << endl << "Select Option to Delete Student Record:" << endl;
	cout << "1. Delete Front - Delete data from the front of the list" << endl;
	cout << "2. Delete Rear - Delete data from the end of the list" << endl;
	cout << "3. Delete by Student ID - Delete specific data by student ID" << endl;
	cout << "4. Delete by Index - Delete specific data by its index position in the list" << endl;
	cout << "5. Back" << endl;
	while (true) {
		cout << "Enter choice: ";

		if (cin >> subchoice) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			return subchoice;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int sortMenu() {
	int subchoice;
	cout << endl << "Select Option Sort Student Records by CGPA:" << endl;
	cout << "1. Sort Ascending" << endl;
	cout << "2. Sort Descending" << endl;
	cout << "3. Back" << endl;
	while (true) {
		cout << "Enter choice: ";

		if (cin >> subchoice) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			return subchoice;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int displayMenu() {
	int subchoice;
	cout << endl << "Select Option to Display Student Records:" << endl;
	cout << "1. Display All Student Records" << endl;
	cout << "2. Display Student Count" << endl;
	cout << "3. Display Programmes" << endl;
	cout << "4. Back" << endl;
	while (true) {
		cout << "Enter choice: ";

		if (cin >> subchoice) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";
				`	
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			return subchoice;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}