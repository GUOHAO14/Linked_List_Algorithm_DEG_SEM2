#pragma once
#include <iostream>
#include <string>
#include <iomanip>
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

	int getNodeCount() {
		return nodeCount;
	}

	void displayNodeCount() {
		cout << "Number of nodes: " << nodeCount << endl;
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
			struct student* prev = nullptr, * after = head;
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

		struct student* prev = nullptr, * deleteNode = head;

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


	// public wrapper to sort the list by CGPA and update head/tail
	void sortByCGPA(bool asc) {
		head = mergeSort(head, asc);
		// update tail to the last node after sorting
		tail = head;
		while (tail && tail->next) {
			tail = tail->next;
		}
	}
};

