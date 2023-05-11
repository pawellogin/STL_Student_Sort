#pragma once
#include "Student.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

string check_name(vector<student>& student_list, string name) {
	bool name_exists = true;
	int suffix = 0;

	while (name_exists) {
		name_exists = false;
		for (student f : student_list) {
			if (f.name == name) {
				name_exists = true;
				suffix++;
				name = name + "_" + to_string(suffix);
				break;
			}
		}
	}
	return name;
}

void add_student(vector<student>& student_list) {

	string new_name = "student" + to_string(1 + student_list.size());

	bool name_exists = true;
	int suffix = 0;
	while (name_exists) {
		name_exists = false;
		for (student f : student_list) {
			if (f.name == new_name) {
				name_exists = true;
				suffix++;
				new_name = new_name + "_" + to_string(suffix);
				break;
			}
		}
	}

	student_list.push_back(*(new student(new_name)));

	system("cls");
}


void delete_student(vector<student>& student_list) {
	string student_name = "";
	system("cls");
	Sleep(300);

	for (auto i : student_list) {
		cout << i.name << endl;
	}

	cout << "enter student name you want to delete" << endl;
	cin >> student_name;

	auto it = find_if(student_list.begin(), student_list.end(),
		[student_name](const student p) { return p.name == student_name; });

	if (it != student_list.end()) {
		student_list.erase(it);
	}

	system("cls");
}

void open_student(vector<student>& student_list) {
	string student_name = "";
	int choice = 0;
	system("cls");
	Sleep(300);

	for (auto i : student_list) {
		cout << i.name << endl;
	}

	cout << "enter student name you want to open" << endl;
	cin >> student_name;
	system("cls");
	auto it = find_if(student_list.begin(), student_list.end(),
		[student_name](const student p) { return p.name == student_name; });

	if (it != student_list.end()) {
		cout << (*it).data << endl;
	}

	cout << "1. edit name" << endl;
	cout << "2. edit data" << endl;
	cout << "3. delete student" << endl;
	cout << "4. return" << endl;

	cin >> choice;

	switch (choice) {
	case 1:(*it).edit_name(); break;
	case 2:(*it).edit_data(); break;
	case 3:
		if (it != student_list.end()) {
			student_list.erase(it);
			system("cls");
		} break;
	case 4:system("cls"); return; break;
	}
}

void load_students(const std::string& folderPath, std::vector<student>& student_list) {
	try {
		for (const auto& entry : fs::directory_iterator(folderPath)) {
			if (entry.is_regular_file()) {
				std::ifstream student(entry.path());
				if (student.is_open()) {
					student_list.emplace_back();
					student_list.back().name = check_name(student_list, entry.path().stem().string());
					student_list.back().data = std::string((std::istreambuf_iterator<char>(student)), std::istreambuf_iterator<char>());
					student.close();
				}
			}
		}
	}
	catch (const std::exception& ex) {
		std::cout << "Error: " << ex.what() << std::endl;
	}
	Sleep(500);
	system("cls");
}

void save_students(const std::string& folderPath, vector<student>& student_list) {

	fs::create_directory(folderPath);

	for (const auto& student : student_list) {
		std::string studentPath = folderPath + "\\" + student.name + ".txt";
		std::ofstream outputstudent(studentPath);

		if (outputstudent.is_open()) {
			outputstudent << student.data;
			outputstudent.close();
			std::cout << "student saved successfully: " << studentPath << std::endl;
			Sleep(200);
		}
		else {
			std::cout << "Failed to open the student: " << studentPath << std::endl;
			Sleep(200);
		}
	}
	Sleep(500);
	system("cls");
}

void changePaths(string& savePath, string& loadPath) {
	cout << "current save path : " << savePath << endl;
	cout << "current load path : " << loadPath << endl;
	cout << "1. change save path\n2. change load path\n3. return\n";

	int choice = 0;
	cin >> choice;

	switch (choice) {
	case 1: cout << "enter new save path : "; cin >> savePath; break;
	case 2: cout << "enter new load path : "; cin >> loadPath; break;
	case 3: return; break;
	}
}



