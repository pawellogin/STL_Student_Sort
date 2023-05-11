#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include "Header.h"
#include "Student.h"

using namespace std;

int main() {
	int choice = 0;
	vector<string> options = { "1. add student","2. delete student","3. open student","4. load students ","5. save students ","6. change path","7. exit" };
	vector<student> student_list;

	string savePath = "C:\\saved_students";
	string loadPath = "C:\\students_to_load";

	//student_list.push_back(*(new student));
	//student_list.push_back(*(new student));

	while (1) {

		cout << "student list :" << endl;
		for (auto i : student_list) {
			cout << i.name << endl;
		}

		cout << endl;
		for (auto i : options) {
			cout << i << endl;
		}

		cin >> choice;

		switch (choice) {
		case 1: add_student(student_list); break;
		case 2: delete_student(student_list); break;
		case 3: open_student(student_list); break;
		case 4: load_students(loadPath, student_list); break;
		case 5: save_students(savePath, student_list); break;
		case 6: changePaths(savePath, loadPath); break;
		case 7: return 0; break;

		default: cout << "chose the correct option";
			system("cls");

		}
	}
}