#include "Student.h"
#include "Programme.h"
#include "menu.h"
#include "utils.h"
#include <chrono>
using namespace std;

int main() {
	Student* students = new Student();
	Programme* programmes = new Programme();

	auto start = chrono::high_resolution_clock::now();
	string fileName = "Datasets\\students_500.csv";
	loadStudentDataFromCSV(students, fileName);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << "Time taken to load all student data from "
		<< fileName
		<< " : "
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
			// FOR MERGE SORT
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
			// FOR LINEAR SEARCH
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
			// FOR DISPLAY INFO
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