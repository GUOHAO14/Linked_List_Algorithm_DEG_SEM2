#pragma once
#include "Student.h"
#include "Programme.h"
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

bool promptStudentData(string& id, string& fullName, string& programmeCode, int& yearOfStudy, double& cgpa, string& contactNum, Student* students, Programme* programmes);
void loadStudentDataFromCSV(Student* students, string fileName);
void loadProgrammeDataFromCSV(Programme* programmes, string fileName);
bool isValidContactNum(string& contactNum);
bool isValidId(string& studentId);
bool isValidProgrammeCode(string& programmeCode);

void loadStudentDataFromCSV(Student* students, string fileName) {
	ifstream file(fileName);

	if (!file.is_open())
	{
		cout << "Failed to open \"" << fileName << "\"" << endl;
		return;
	}

	string line;
	getline(file, line); //skip first row (header) of csv

	while (getline(file, line))
	{
		stringstream ss(line);

		string studentId, fullName, programmeCode, yearOfStudyStr, cgpaStr, contactNum;

		getline(ss, studentId, ',');
		getline(ss, fullName, ',');
		getline(ss, programmeCode, ',');
		getline(ss, yearOfStudyStr, ',');
		getline(ss, cgpaStr, ',');
		getline(ss, contactNum, ',');

		int yearOfStudy = stoi(yearOfStudyStr);
		double cgpa = stod(cgpaStr);

		students->insertRear(studentId, fullName, programmeCode, yearOfStudy, cgpa, contactNum);
	}

	file.close();
}

void loadProgrammeDataFromCSV(Programme* programmes, string fileName) {
	ifstream file(fileName);

	if (!file.is_open())
	{
		cout << "Failed to open \"" << fileName << "\"" << endl;
		return;
	}

	string line;
	getline(file, line);
	int index = 0;
	while (getline(file, line))
	{
		stringstream ss(line);
		string programmeCode, programmeName, faculty, durationYearsStr;
		getline(ss, programmeCode, ',');
		getline(ss, programmeName, ',');
		getline(ss, faculty, ',');
		getline(ss, durationYearsStr, ',');

		int durationYears = stoi(durationYearsStr);

		programmes->insertRear(programmeCode, programmeName, faculty, durationYears);
	}
	file.close();
}

bool promptStudentData(string& id, string& fullName, string& programmeCode, int& yearOfStudy, double& cgpa, string& contactNum, Student* students, Programme* programmes) {
	struct programme* programme = nullptr;
	while (true) {
		cout << "Enter Student ID - e.g. TP123456 (type 0 to cancel): ";
		cin >> id;
		if (id == "0") {
			return false;
		}
		else if (!isValidId(id)) {
			cout << "Invalid input. Please enter a valid student ID." << endl;
			continue;
		}
		else if (students->linearSearch(id) != nullptr) {
			cout << "Duplicate student ID. Please enter a different ID." << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Enter Full Name (type 0 to cancel): ";
		cin.ignore();
		getline(cin, fullName);
		if (fullName == "0") {
			return false;
		}
		else if (fullName.length() > 30) {
			cout << "Invalid input. Full Name cannot be more than 30 characters." << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Enter Programme Code - e.g. CT101 (type 0 to cancel): ";
		cin >> programmeCode;
		if (programmeCode == "0") {
			return false;
		}
		else if ((programme = programmes->linearSearch(programmeCode)) == nullptr) {
			cout << "Invalid programme code. Not found in the list of programmes." << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Enter Year of Study (type -1 to cancel): ";

		if (cin >> yearOfStudy) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			if (yearOfStudy < 0 || yearOfStudy > programme->durationYears) {
				cout << "Invalid Year of Study." << endl;
				continue;
			}

			if (yearOfStudy == -1) {
				return false;
			}

			break;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (true) {
		cout << "Enter CGPA (type 0 to cancel): ";

		if (cin >> cgpa) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a decimal number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (cgpa < 1.0 || cgpa > 4.0) {
				cout << "Invalid input. CGPA must be between 1.0 and 4.0." << endl;
				continue;
			}

			if (cgpa == 0) {
				return false;
			}

			break;
		}

		cout << "Invalid input. Please enter a number." << endl;

		cin.clear(); // clear fail state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	while (true) {
		cout << "Enter Contact Number - e.g. 012-3456789 or 012-34567890 (type 0 to cancel): ";
		cin >> contactNum;
		if (contactNum == "0") {
			return false;
		}
		else if (!isValidContactNum(contactNum)) {
			cout << "Invalid input. Please enter a valid contact number." << endl;
			continue;
		}
		break;
	}
	return true;
}

bool isValidContactNum(string& contactNum) {
	regex pattern(R"(^\d{3}-\d{7,8}$)");
	return regex_match(contactNum, pattern);
}

bool isValidId(string& id) {
	regex pattern(R"(^TP\d{6}$)");
	return regex_match(id, pattern);
}