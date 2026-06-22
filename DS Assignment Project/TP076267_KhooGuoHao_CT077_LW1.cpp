#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <regex>
#include <chrono>
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

struct programme {
	string programmeCode, programmeName, faculty;
	int durationYears;
	struct programme* next;
};

class Programme {
private:
	struct programme* head;
	struct programme* tail;
	int nodeCount;
public:
	Programme() {
		head = tail = nullptr;
	}
	void insertRear(string programmeCode, string programmeName, string faculty, int durationYears) {
		struct programme* newNode = new programme(programmeCode, programmeName, faculty, durationYears);
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

	void displayProgrammeHeader() {
		cout << string(149, '=') << endl;
		cout << "| ";
		cout << left << setw(3) << "No.";
		cout << " | ";
		cout << left << setw(14) << "Programme Code";
		cout << " | ";
		cout << left << setw(62) << "Programme Name";
		cout << " | ";
		cout << left << setw(40) << "Faculty";
		cout << " | ";
		cout << left << setw(14) << "Duration Years";
		cout << " |";
		cout << endl;
		cout << string(149, '=') << endl;
	}

	void displayProgrammeFormat(int count, struct programme* p) {
		cout << "| ";
		cout << left << setw(3) << count;
		cout << " | ";
		cout << left << setw(14) << p->programmeCode;
		cout << " | ";
		cout << left << setw(62) << p->programmeName;
		cout << " | ";
		cout << left << setw(40) << p->faculty;
		cout << " | ";
		cout << left << setw(14) << p->durationYears;
		cout << " |" << endl;
	}

	void displayAllProgrammes() {
		struct programme* trav = head;
		int count = 0;
		displayProgrammeHeader();
		while (trav != nullptr) {
			count++;
			displayProgrammeFormat(count, trav);
			trav = trav->next;
		}
		cout << string(149, '=') << endl;
	}

	struct programme* linearSearch(string id) {
		struct programme* trav = head;

		while (trav != nullptr) {

			if (trav->programmeCode == id) {
				return trav;
			}

			trav = trav->next;
		}

		return nullptr;
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

	int getNodeCount() {
		return nodeCount;
	}

	void displayNodeCount() {
		cout << "Number of nodes: " << nodeCount << endl;
	}

	struct student* getHead() {
		return head;
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

	struct student* insertByIndex(int index, string id, string fullName, string programmeCode, int yearOfStudy, double cgpa, string contactNum) {
		if (index < 0 || index > nodeCount) {
			cout << "Index out of bound." << endl;
			return nullptr;
		}

		struct student* newNode = new student(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum);

		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		else if (index == nodeCount) {
			newNode->next = nullptr;
			tail->next = newNode;
			tail = newNode;
		}
		else {
			struct student* prev = nullptr, *after = head;
			int i = 0;
			while (i < index) {
				prev = after;
				after = prev->next;
				i++;
			}

			prev->next = newNode;
			newNode->next = after;
		}
		nodeCount++;
		return newNode;
	}

	void deleteFront() {
		if (head == nullptr) {
			cout << "Cannot delete from an empty list." << endl;
			return;
		}
		struct student* deleteNode = head;
		string deletedId;

		if (head->next == nullptr) { // one node
			head = tail = nullptr;
		}
		else {
			head = head->next;
			deleteNode->next = nullptr;
		}
		nodeCount--;
		deletedId = deleteNode->id;
		delete deleteNode;
		cout << "Student with ID \'" << deletedId << "\' is deleted." << endl;
	}

	void deleteRear() {
		if (head == nullptr) {
			cout << "Cannot delete from an empty list." << endl;
			return;
		}

		struct student* deleteNode;
		string deletedId;
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
		deletedId = deleteNode->id;
		delete deleteNode;
		cout << "Student with ID \'" << deletedId << "\' is deleted." << endl;
	}

	void deleteById(string id) {
		if (head == nullptr) {
			cout << "Cannot delete from an empty list." << endl;
		}

		struct student * prev = nullptr, * deleteNode = head;

		while (deleteNode != nullptr) {
			if (deleteNode->id == id) {
				break;
			}
			prev = deleteNode;
			deleteNode = deleteNode->next; // deleteNode will be tail at the end of the loop
		}

		if (deleteNode == nullptr) { // reach end of list without finding the id
			cout << "Student ID \"" << id << "\" is not found." << endl;
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
			cout << "Student with ID \'" << id << "\' is deleted." << endl;
		}
	}

	void deleteByIndex(int index) {
		if (nodeCount <= 0) {
			cout << "Cannot delete from an empty list." << endl;
		}
		else if (index < 0 || index > nodeCount - 1) {
			cout << "Index out of bound." << endl;
		}
		else {
			struct student* deleteNode = head, * prev = nullptr;
			string deletedId;
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
			deletedId = deleteNode->id;
			delete deleteNode;
			cout << "Student with ID \'" << deletedId << "\' is deleted." << endl;
		}
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

	void displayStudentHeader() {
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
	}

	void displayStudentFormat(int count, struct student* s) {
		cout << "| ";
		cout << left << setw(3) << count;
		cout << " | ";
		cout << left << setw(10) << s->id;
		cout << " | ";
		cout << left << setw(30) << s->fullName;
		cout << " | ";
		cout << left << setw(14) << s->programmeCode;
		cout << " | ";
		cout << left << setw(13) << s->yearOfStudy;
		cout << " | ";
		cout << left << setw(6) << s->cgpa;
		cout << " | ";
		cout << left << setw(14) << s->contactNum;
		cout << " |";
		cout << endl;
	}

	void displayAllStudents() {
		struct student* trav = head;
		int count = 0;
		displayStudentHeader();
		while (trav != nullptr) {
			count++;
			displayStudentFormat(count, trav);
			trav = trav->next;
		}
		cout << string(112, '=') << endl;
	}

	student* mergeSort(student* head, bool asc) {
		if (!head || !head->next) {
			return head; // 0 or 1 element already sorted
		}

		student* left;
		student* right;

		split(head, &left, &right);

		left = mergeSort(left, asc);
		right = mergeSort(right, asc);

		return merge(left, right, asc);
	}

	void split(student* head, student** left, student** right) {
		student* slow = head;
		student* fast = head->next;

		// fast moves 2 steps, slow moves 1 step
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		*left = head;
		*right = slow->next;
		slow->next = nullptr;
	}

	student* merge(student* left, student* right, bool asc) {
		if (!left) return right;
		if (!right) return left;

		student dummy("", "", "", 0, 0.0, "");
		student* tail = &dummy;

		while (left && right)
		{
			bool takeLeft;

			if (asc)
				takeLeft = left->cgpa <= right->cgpa;
			else
				takeLeft = left->cgpa >= right->cgpa;

			if (takeLeft)
			{
				tail->next = left;
				left = left->next;
			}
			else
			{
				tail->next = right;
				right = right->next;
			}

			tail = tail->next;
		}

		if (left)
			tail->next = left;
		else
			tail->next = right;

		return dummy.next;
	}


	// Public wrapper to sort the list by CGPA and update head/tail
	void sortByCGPA(bool asc) {
		head = mergeSort(head, asc);
		// update tail to the last node after sorting
		tail = head;
		while (tail && tail->next) {
			tail = tail->next;
		}
	}
};

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

int mainMenu();
int insertMenu();
int deleteMenu();
int sortMenu();
int displayMenu();
bool promptStudentData(string& id, string& fullName, string& programmeCode, int& yearOfStudy, double& cgpa, string& contactNum, Student* students, Programme* programmes);
void loadStudentDataFromCSV(Student* students, string fileName);
void loadProgrammeDataFromCSV(Programme* programmes, string fileName);
bool isValidContactNum(string& contactNum);
bool isValidId(string& studentId);
bool isValidProgrammeCode(string& programmeCode);

int main() {
	Student* students = new Student();
	Programme* programmes = new Programme();

	auto start = chrono::high_resolution_clock::now();
	string fileName = "Datasets\\students_8000.csv";
	loadStudentDataFromCSV(students, fileName);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << "Time taken to load all student data: "
		<< duration.count()
		<< " microseconds" << endl;

	string fileName1 = "Datasets\\programmes.csv";
	loadProgrammeDataFromCSV(programmes, fileName1);
	cout << endl;

	int choice, subchoice;

	// variables to hold student data for insert and delete operations
	int yearOfStudy, index;
	double cgpa;
	string id, fullName, programmeCode, contactNum;

	do {
		choice = mainMenu();

		switch (choice) {
		case 1:
			// FOR INSERT
			do {
				subchoice = insertMenu();
				bool success;

				switch (subchoice) {
				case 1:
					success = promptStudentData(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum, students, programmes);
					if (success) {
						start = chrono::high_resolution_clock::now();
						students->insertFront(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum);
						end = chrono::high_resolution_clock::now();
						duration = chrono::duration_cast<chrono::microseconds>(end - start);
						cout << "Time taken to insert front: "
							<< duration.count()
							<< " microseconds" << endl;

						cout << "Student with ID \'" << id << "\' is inserted." << endl;
					}
					break;
				case 2:

					success = promptStudentData(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum, students, programmes);
					if (success) {

						while (true) {
							cout << "Enter Index Position of New Student (type -1 to cancel): ";

							if (!(cin >> index)) {
								cout << "Invalid Input.\n";
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								continue;
							}

							if (index < -1) {
								cout << "Invalid Index.\n";
								continue;
							}

							if (index == -1) {
								break;
							}
							else {
								start = chrono::high_resolution_clock::now();
								struct student* newStudent = students->insertByIndex(index, id, fullName, programmeCode, yearOfStudy, cgpa, contactNum);
								if (newStudent != nullptr) {

									end = chrono::high_resolution_clock::now();
									duration = chrono::duration_cast<chrono::microseconds>(end - start);
									cout << "Time taken to insert at index " << index << " :"
										<< duration.count()
										<< " microseconds" << endl;

									cout << "Student with ID \'" << id << "\' is inserted." << endl;
									break;
								}
							}
						}
					}
					break;
				case 3:
					success = promptStudentData(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum, students, programmes);
					if (success) {
						start = chrono::high_resolution_clock::now();

						students->insertRear(id, fullName, programmeCode, yearOfStudy, cgpa, contactNum);

						end = chrono::high_resolution_clock::now();

						duration = chrono::duration_cast<chrono::microseconds>(end - start);

						cout << "Time taken to insert rear: "
							<< duration.count()
							<< " microseconds" << endl;
						cout << "Student with ID \'" << id << "\' is inserted." << endl;
					}
					break;
				case 4:
					cout << "Back to Main Menu" << endl;
					break;
				default:
					cout << "Invalid Input. Please enter numbers from 1 - 4." << endl;
					break;
				}
			} while (subchoice != 4);
			break;
		case 2:
			//FOR DELETE
			do {
				subchoice = deleteMenu();
				switch (subchoice) {
				case 1:
					start = chrono::high_resolution_clock::now();
					students->deleteFront();
					end = chrono::high_resolution_clock::now();

					duration = chrono::duration_cast<chrono::microseconds>(end - start);

					cout << "Time taken to delete front: "
						<< duration.count()
						<< " microseconds" << endl;

					break;
				case 2:
					start = chrono::high_resolution_clock::now();
					students->deleteRear();
					end = chrono::high_resolution_clock::now();

					duration = chrono::duration_cast<chrono::microseconds>(end - start);

					cout << "Time taken to delete rear: "
						<< duration.count()
						<< " microseconds" << endl;
					break;
				case 3:
					cout << "Enter Student ID to Delete (type 0 to cancel): ";
					cin >> id;
					if (id != "0") {
						start = chrono::high_resolution_clock::now();
						students->deleteById(id);
						end = chrono::high_resolution_clock::now();

						duration = chrono::duration_cast<chrono::microseconds>(end - start);

						cout << "Time taken to delete by ID \"" << id << ": "
							<< duration.count()
							<< " microseconds" << endl;
					}
					break;
				case 4:
					while (true) {
						cout << "Enter Index Position of Student to Delete (type -1 to cancel): ";

						if (!(cin >> index)) {
							cout << "Invalid Input.\n";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							continue;
						}

						if (index < -1) {
							cout << "Invalid Index.\n";
							continue;
						}


						if (index != -1) {
							start = chrono::high_resolution_clock::now();
							students->deleteByIndex(index);
							end = chrono::high_resolution_clock::now();

							duration = chrono::duration_cast<chrono::microseconds>(end - start);

							cout << "Time taken to delete at index " << index << ": "
								<< duration.count()
								<< " microseconds" << endl;
						}

						break;

					}
					break;
				case 5:
					cout << "Back to Main Menu" << endl;
					break;
				default:
					cout << "Invalid Input. Please enter numbers from 1 - 5." << endl;
					break;
				}
			} while (subchoice != 5);
			break;
		case 3:
			do {
				subchoice = sortMenu();

				switch (subchoice) {
				case 1:
					start = chrono::high_resolution_clock::now();
					cout << "Started sorting." << endl;
					students->sortByCGPA(true);
					cout << "Finished sorting." << endl;
					end = chrono::high_resolution_clock::now();

					duration = chrono::duration_cast<chrono::microseconds>(end - start);
					students->displayAllStudents();

					cout << "Time taken to merge sort (ascending), not counting display: "
						<< duration.count()
						<< " microseconds" << endl;
					break;
				case 2:
					start = chrono::high_resolution_clock::now();
					students->sortByCGPA(false);
					end = chrono::high_resolution_clock::now();

					duration = chrono::duration_cast<chrono::microseconds>(end - start);
					students->displayAllStudents();

					cout << "Time taken to merge sort (descending), not counting display: "
						<< duration.count()
						<< " microseconds" << endl;
					break;
				case 3:
					cout << "Back to Main Menu" << endl;
					break;
				default:
					cout << "Invalid Input. Please enter numbers from 1 - 3." << endl;
					break;
				}
			} while (subchoice != 3);
			break;
		case 4: {
			cout << "Enter Student ID to Search (type 0 to cancel): ";
			cin >> id;
			if (id == "0") {
				break;
			}
			start = chrono::high_resolution_clock::now();
			struct student* student = students->linearSearch(id);
			end = chrono::high_resolution_clock::now();

			duration = chrono::duration_cast<chrono::microseconds>(end - start);

			if (student != nullptr) {
				cout << "Time taken to find student (linear search): "
					<< duration.count()
					<< " microseconds" << endl;
				students->displayStudentHeader();
				students->displayStudentFormat(1, student);
				cout << string(112, '=') << endl;
			}
			else {
				cout << "Student ID \"" << id << "\" is not found." << endl;
			}
			break;
		}
		case 5:
			do {
				subchoice = displayMenu();

				switch (subchoice) {
				case 1:
					cout << endl << "Student Records: " << endl;
					start = chrono::high_resolution_clock::now();
					students->displayAllStudents();
					end = chrono::high_resolution_clock::now();

					duration = chrono::duration_cast<chrono::microseconds>(end - start);
					cout << "Time taken to display all student records: "
						<< duration.count()
						<< " microseconds" << endl;
					break;
				case 2:
					cout << endl << "Number of Students: " << students->getNodeCount() << endl;
					break;
				case 3:
					cout << endl << "Programme Records: " << endl;
					programmes->displayAllProgrammes();
					break;
				case 4:
					cout << "Back to Main Menu" << endl;
					break;
				default:
					cout << "Invalid Input. Please enter numbers from 1 - 4." << endl;
					break;
				}
			} while (subchoice != 4);
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "Invalid input. Please enter numbers from 1 - 6." << endl;
		}
		cout << endl;
	} while (choice != 9);
}

int mainMenu() {
	int choice, subchoice;
	cout << endl << "Student Records Management - Main Menu" << endl;
	cout << "1. Add New Student Record" << endl;
	cout << "2. Delete Student Record" << endl;
	cout << "3. Sort Student Records by CGPA" << endl;
	cout << "4. Search Student Record (Linear Search)" << endl;
	cout << "5. Display All Student Records" << endl;
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
	cout << "2. Insert Middle - Add new data to the middle of the list using index position" << endl;
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

bool promptStudentData(string& id, string& fullName, string& programmeCode, int& yearOfStudy, double& cgpa, string& contactNum, Student* students, Programme* programmes) {
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
		else if (programmes->linearSearch(programmeCode) == nullptr) {
			cout << "Invalid programme code. Not found in the list of programmes." << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Enter Year of Study (type 0 to cancel): ";

		if (cin >> yearOfStudy) {
			char extra;

			if (cin.get(extra) && extra != '\n') {
				cout << "Invalid input. Please enter a number.\n";

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			if (yearOfStudy == 0) {
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
			if (cgpa < 0.0 || cgpa > 4.0) {
				cout << "Invalid input. CGPA must be between 0.0 and 4.0." << endl;
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