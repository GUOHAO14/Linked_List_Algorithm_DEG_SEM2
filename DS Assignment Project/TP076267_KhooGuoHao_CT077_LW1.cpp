#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct student {
	string id, fullName, programmeCode, contactNum;
	int yearOfStudy;
	double cgpa;
	struct student* next;

	student(string id, string fullName, string programmeCode, int yearOfStudy, double cgpa, string contactNum) {
		this->id = id;
		this->fullName = fullName;
		this->programmeCode = programmeCode;
		this->yearOfStudy = yearOfStudy;
		this->cgpa = cgpa;
		this->contactNum = contactNum;
		next = nullptr;
	}
};

class Student {
private:
	struct student* head;
	struct student* tail;
	int nodeCount;
public:
	Student() {
		head = tail = nullptr;
		nodeCount = 0;
	}

	int printNodeCount() {
		return nodeCount;
	}

	void insertFront(string id, string fullName, string programmeCode, int yearOfStudy, double cgpa, string contactNum) {
		struct student* newNode = new student(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum);

		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		nodeCount++;
		newNode = nullptr;
	}

	void insertRear(string id, string fullName, string programmeCode, int yearOfStudy, double cgpa, string contactNum) {
		struct student* newNode = new student(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum);

		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		nodeCount++;
		newNode = nullptr;
	}

	void deleteFront() {
		if (head == nullptr) {
			cout << "Cannot delete from an empty list." << endl;
			return;
		}
		else {
			struct student* deleteNode = head;

			if (head->next == nullptr) { // one node
				head = tail = nullptr;
			}
			else {
				head = head->next;
				deleteNode->next = nullptr;
			}
			nodeCount--;
			delete deleteNode;
		}
	}

	void deleteRear() {

		if (head == nullptr) {
			cout << "Cannot delete from an empty list." << endl;
			return;
		}
		struct student* deleteNode;

		if (head == tail) { // one node
			deleteNode = head;
			head = tail = nullptr;
		}
		else {
			struct student* prev = head;
			deleteNode = head;

			while (deleteNode != tail) {
				prev = deleteNode;
				deleteNode = deleteNode->next; // deleteNode will be tail at the end of the loop
			}

			tail = prev;
			tail->next = nullptr;
		}

		nodeCount--;
		delete deleteNode;
	}

	void deleteId(string id) {
		if (head == nullptr) {
			cout << "Cannot delete from an empty list." << endl;
		}

		struct student* deleteNode = head, * prev = nullptr;

		while (deleteNode != nullptr) {
			if (deleteNode->id == id) {
				break;
			}
			prev = deleteNode;
			deleteNode = deleteNode->next; // deleteNode will be tail at the end of the loop
		}

		if (deleteNode == nullptr) { // reach end of list without finding the id
			cout << "Student id, " << id << " is not found." << endl;
		}
		else {
			if (deleteNode == head) {
				head = head->next;

				if (deleteNode == tail) { // if one node
					tail = nullptr;
				}
			}
			else if (deleteNode == tail) {
				tail = prev;
				tail->next = nullptr;
			}
			else {
				prev->next = deleteNode->next;
			}
			nodeCount--;
			delete deleteNode;
		}
	}

	struct student* deleteIndex(int index) {
		if (nodeCount <= 0) {
			cout << "Cannot delete from an empty list" << endl;
		}
		else if (index < 0 || index > nodeCount - 1) {
			cout << "Index out of bound" << endl;
		}
		else {
			struct student* prev = nullptr, * deleteNode = head;
			int i = 0;
			while (i < index) {
				prev = deleteNode;
				deleteNode = deleteNode->next;
				i++;
			}
			if (i == 0) {//delete front
				if (deleteNode->next == nullptr) {
					//head == tail --> one element in the list, since both pointing to the same element
					head = tail = nullptr;
				}
				else {
					head = head->next;
					deleteNode->next = nullptr;
				}
			}
			else if (i == nodeCount - 1) {//delete rear
				tail = prev;
				prev->next = nullptr;
			}
			else {//delete between two nodes
				prev->next = deleteNode->next;
				deleteNode->next = nullptr;
			}
			nodeCount--;
			return deleteNode;
		}
		return nullptr;
	}

	struct student* linearSearch(string id) {
		struct student* trav = head;

		while (trav != nullptr) {

			if (trav->id == id) {
				return trav;
			}

			trav = trav->next;
		}

		return nullptr;
	}

	void displayAllStudents() {
		struct student* trav = head;
		int count = 0;
		cout << string(112, '=') << endl;
		cout << "| ";
		cout << left << setw(3) << "No.";
		cout << " | ";
		cout << left << setw(10) << "Student ID";
		cout << " | ";
		cout << left << setw(30) << "Full Name";
		cout << " | ";
		cout << left << setw(14) << "Programme Code";
		cout << " | ";
		cout << left << setw(13) << "Year of Study";
		cout << " | ";
		cout << left << setw(6) << "CGPA";
		cout << " | ";
		cout << left << setw(14) << "Contact Number";
		cout << " |";
		cout << endl;
		cout << string(112, '=') << endl;
		while (trav != nullptr) {
			cout << "| ";
			cout << left << setw(3) << ++count;
			cout << " | ";
			cout << left << setw(10) << trav->id;
			cout << " | ";
			cout << left << setw(30) << trav->fullName;
			cout << " | ";
			cout << left << setw(14) << trav->programmeCode;
			cout << " | ";
			cout << left << setw(13) << trav->yearOfStudy;
			cout << " | ";
			cout << left << setw(6) << trav->cgpa;
			cout << " | ";
			cout << left << setw(14) << trav->contactNum;
			cout << " |";
			cout << endl;
			trav = trav->next;
		}
		cout << string(112, '=') << endl;
	}
};

int menu();

void loadStudentDataFromCSV(Student* students, string fileName);

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

int main() {
	Student* students = new Student();
	string fileName = "Datasets\\students_500.csv";
	loadStudentDataFromCSV(students, fileName);

	cout << "Number of students loaded from CSV: ";
	cout << students->printNodeCount();
	cout << endl;

	students->displayAllStudents();
	//do {
	//	choice = menu();

	//	switch (choice) {
	//	case 1:
	//		cout << "Enter new student's id: ";
	//		cin >> id;
	//		cout << "Enter new student's name: ";
	//		cin >> name;
	//		cout << "Enter new student's age: ";
	//		cin >> age;
	//		students.insertFront(id, name, age);
	//		break;
	//	case 2:
	//		cout << "Enter new student's id: ";
	//		cin >> id;
	//		cout << "Enter new student's name: ";
	//		cin >> name;
	//		cout << "Enter new student's age: ";
	//		cin >> age;
	//		students.insertRear(id, name, age);
	//		break;
	//	case 3:
	//		students.deleteFront();
	//		break;
	//	case 4:
	//		students.deleteRear();
	//		break;
	//	case 5:
	//		cout << "Enter student's id: ";
	//		cin >> id;
	//		students.deleteId(id);
	//		break;
	//	case 6:
	//		cout << "Enter student's id: ";
	//		cin >> id;
	//		students.deleteIndex(id);
	//		break;
	//	case 7:
	//		students.displayAllStudents();
	//		break;
	//	case 9:
	//		return 0;
	//		break;
	//	default:
	//		cout << "Invalid input." << endl;
	//	}
	//} while (choice != 9);
}

int menu() {
	int choice;
	cout << "Student Records Management" << endl;
	cout << "1. Add new data to front of list" << endl;
	cout << "2. Add new data to end of list" << endl;
	cout << "3. Delete front data" << endl;
	cout << "4. Delete rear data" << endl;
	cout << "5. Delete data by student id" << endl;
	cout << "6. Delete data by index" << endl;
	cout << "7. Display all elements" << endl;
	cout << "9. Exit" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	return choice;
}