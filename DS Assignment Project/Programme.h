#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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