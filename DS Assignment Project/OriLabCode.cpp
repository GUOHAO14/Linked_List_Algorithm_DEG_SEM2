//#include <iostream>
//using namespace std;
//
//struct student {
//	int student_id, age;
//	string name;
//	struct student* next;
//
//	student(int id, string name1, int age1) {
//		student_id = id;
//		name = name1;
//		age = age1;
//		next = nullptr;
//	}
//};
//
//class Student {
//private:
//	struct student* head;
//	struct student* tail;
//	int nodeCount;
//public:
//	Student() {
//		head, tail = nullptr;
//		nodeCount = 0;
//	}
//
//	void insertFront(int id, string name, int age) {
//		struct student* newNode = new student(id, name, age);
//
//		if (head == nullptr) {
//			head = tail = newNode;
//		}
//		else {
//			newNode->next = head;
//			head = newNode;
//		}
//		nodeCount++;
//		newNode = nullptr;
//	}
//
//	void insertRear(int id, string name, int age) {
//		struct student* newNode = new student(id, name, age);
//
//		if (head == nullptr) {
//			head = tail = newNode;
//		}
//		else {
//			tail->next = newNode;
//			tail = newNode;
//		}
//		nodeCount++;
//		newNode = nullptr;
//	}
//
//	struct student* deleteFront() {
//		if (head == nullptr) {
//			cout << "Cannot delete from an empty list." << endl;
//
//		}
//		else {
//			struct student* deleteNode = head;
//
//			if (head->next == nullptr) {
//				//head == tail --> one element in the list, since both pointing to the same element
//				head = tail = nullptr;
//			}
//			else {
//				head = head->next;
//				deleteNode->next = nullptr;
//			}
//			nodeCount--;
//			return deleteNode;
//		}
//		return nullptr;
//	}
//
//	struct student* deleteRear() {
//
//		if (head == nullptr) {
//			cout << "Cannot delete from an empty list." << endl;
//
//		}
//		else {
//			struct student* deleteNode = head, * prev = head;
//
//			while (deleteNode != tail) {
//				prev = deleteNode;
//				deleteNode = deleteNode->next; // deleteNode will be tail at the end of the loop
//			}
//
//			tail = prev;
//			prev->next = nullptr;
//			nodeCount--;
//			return deleteNode;
//		}
//
//		return nullptr;
//	}
//
//	struct student* deleteId(int id) {
//		struct student* deleteNode = head, * prev = head;
//
//		while (deleteNode != nullptr) {
//			if (deleteNode->student_id == id) {
//				break;
//			}
//			prev = deleteNode;
//			deleteNode = deleteNode->next; // if next loop is actual node being deleted, the previous loop have to locate it using deleteNode->next
//		}
//
//		if (deleteNode == nullptr) {
//			cout << "Student id, " << id << " is not found." << endl;
//			return deleteNode;
//		}
//		else {
//			prev->next = deleteNode->next;
//			deleteNode->next = nullptr;
//			nodeCount--;
//		}
//		prev = nullptr;
//		return deleteNode;
//	}
//
//	struct student* deleteIndex(int index) {
//		if (nodeCount <= 0) {
//			cout << "Cannot delete from an empty list" << endl;
//		}
//		else if (index < 0 || index > nodeCount - 1) {
//			cout << "Index out of bound" << endl;
//		}
//		else {
//			struct student* prev = nullptr, * deleteNode = head;
//			int i = 0;
//			while (i < index) {
//				prev = deleteNode;
//				deleteNode = deleteNode->next;
//				i++;
//			}
//			if (i == 0) {//delete front
//				if (deleteNode->next == nullptr) {
//					//head == tail --> one element in the list, since both pointing to the same element
//					head = tail = nullptr;
//				}
//				else {
//					head = head->next;
//					deleteNode->next = nullptr;
//				}
//			}
//			else if (i == nodeCount - 1) {//delete rear
//				tail = prev;
//				prev->next = nullptr;
//			}
//			else {//delete between two nodes
//				prev->next = deleteNode->next;
//				deleteNode->next = nullptr;
//			}
//			return deleteNode;
//		}
//		return nullptr;
//	}
//
//	struct student* searchID(int id) {
//		struct student* trav = head;
//
//		while (trav != nullptr) {
//			if (trav->student_id == id) {
//				return trav;
//			}
//			trav = trav->next;
//		}
//		return nullptr;
//	}
//
//	void display() {
//		struct student* trav = head;
//
//		cout << "head -> ";
//		while (trav != nullptr) {
//			cout << trav->student_id << "(" + trav->name + ", " << trav->age << ") " << " -> ";
//			trav = trav->next;
//		}
//		cout << "null" << endl;
//	}
//};
//
//int menu();
//
//int main() {
//	Student students;
//	int choice, id, age;
//	string name;
//	do {
//		choice = menu();
//
//		switch (choice) {
//		case 1:
//			cout << "Enter new student's id: ";
//			cin >> id;
//			cout << "Enter new student's name: ";
//			cin >> name;
//			cout << "Enter new student's age: ";
//			cin >> age;
//			students.insertFront(id, name, age);
//			break;
//		case 2:
//			cout << "Enter new student's id: ";
//			cin >> id;
//			cout << "Enter new student's name: ";
//			cin >> name;
//			cout << "Enter new student's age: ";
//			cin >> age;
//			students.insertRear(id, name, age);
//			break;
//		case 3:
//			students.deleteFront();
//			break;
//		case 4:
//			students.deleteRear();
//			break;
//		case 5:
//			cout << "Enter student's id: ";
//			cin >> id;
//			students.deleteId(id);
//			break;
//		case 6:
//			cout << "Enter student's id: ";
//			cin >> id;
//			students.deleteIndex(id);
//			break;
//		case 7:
//			students.display();
//			break;
//		case 9:
//			return 0;
//			break;
//		default:
//			cout << "Invalid input." << endl;
//		}
//	} while (choice != 9);
//}
//
//int menu() {
//	int choice;
//	cout << "Welcome to Week 8 Lab 20" << endl;
//	cout << "1. Add new data to front of list" << endl;
//	cout << "2. Add new data to end of list" << endl;
//	cout << "3. Delete front data" << endl;
//	cout << "4. Delete rear data" << endl;
//	cout << "5. Delete data by student id" << endl;
//	cout << "6. Delete data by index" << endl;
//	cout << "7. Display all elements" << endl;
//	cout << "9. Exit" << endl;
//	cout << "Enter choice: ";
//	cin >> choice;
//	return choice;
//}