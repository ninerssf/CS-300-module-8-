//============================================================================
// Name        : PROJECT.cpp
// Author      : Thoura Ouk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style CS-300 Project 2
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Course {
	string number;
	string title;
	vector<string> prereqs;

};

map <string, course> courses;

void loadFile() {
	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;

	ifstream file(fileName);
	if (!file.is open()) {
		cout << "Error opening file.\n";
		return;
	}

	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		string item;
		vector<string> data;

		while (getline(ss, item, ',')) {
			data.push_back(item);
		}

		if (data.size() >= 2) {
			Course c;
			c.number = data;
			c.title = data[1];
			for (size t 1 = 2; i < data.size(); i++) {
				c.prereqs.push_back(data[i]);
			}
			courses[c.number] = c;
		}
	}

	file.close();
	cout << courses.size() << " courses loaded. \n\n";

}

void printList() {
	if (courses.empty()) {
		cout << "No data loaded.\n\n";
		return;

	}

	cout << "\nCourse List:\n\n";
	for (auto& pair : courses) {
		cout << pair.second.number << ", " << pair.second.title << endl;
	}
	cout << endl;
}

void printCourses() {
	string courseNum;
	cout << "Enter course number: ";
	cin >> courseNum;

	if (courses.find(courseNum) == courses.end()) {
		cout << "Course not found.\n\n";
		return;

	}

	Course c = courses[courseNum];
	cout << "\n" << c.number << ", " << c.title << endl;
	cout << "Prerequisities: ";

	if (c.prereqs.empty()) {
		cout << "None";
	} else {
		for (size_t i = 0; i < c.prereqs.size(); i++) {
			cout << c.prereqs[i];
			if (i < c.prereqs.size() - 1) cout << ", ";

		}
	}
	cout << "\n\n";
}

int main() {
	int choice = 0;

	cout << "Welcome to the course planner.\n\n";

	while (choice ! = 9) {
		cout << "1. Load Data\n";
		cout << "2. Print Course List\n";
		cout << "3. Print Course\n";
		cout << "9. Exit\n\n";
		cout << "Choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 1) {
			loadFile();
		} else if (choice == 2) {
			printList();
		} else if (choice== 3) {
			printCourse();
		} else if (choice == 9) {
			cout << "Goodbye!\n";
		} else {
			cout << "Invalid option.\n\n";
		}
	}

	return 0;
}
			}
		}


	}

}
