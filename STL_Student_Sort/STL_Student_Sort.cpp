#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Student.h"
#include <chrono>
#include <thread>

void clearConsole();

int main() {
	int choice = 0;

	std::vector<Student> list;
	Student studentData;

	std::ifstream ifile;
	std::ofstream ofile;


	while (1) {

		std::for_each(list.begin(), list.end(), [](Student& student)
			{
				std::cout << student<<"\n";
			});
		std::cout << "\n";

		std::cout << "1. add studnet to list\n";
		std::cout << "2. save list to file\n";
		std::cout << "3. load file to list\n";
		std::cout << "4. how meny students from year 3?\n";
		std::cout << "5. exit\n";

		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1: 
			std::cin >> studentData;
			list.push_back(studentData); 
			clearConsole();
			break;

		case 2: 
			ofile.open("studentFiles.txt");

			std::for_each(list.begin(), list.end(), [&ofile](Student& student) {
				ofile << student<<"\n";
				});
			
			ofile.close();
			clearConsole();
			 break;

		case 3:
			ifile.open("studentFiles.txt");

			while (ifile >> studentData) {
				list.push_back(studentData);
			}

			ifile.close();
			clearConsole();
			break;

		case 4:  
			std::cout << std::count_if(list.begin(), list.end(), [](Student& student) {
			return student.getYear() == 3; });
			std::this_thread::sleep_for(std::chrono::seconds(1));
			clearConsole();
			break;
			 
		case 5: return 0;
		}
	}
}

void clearConsole() {
	std::cout << "\033[2J\033[1;1H";
}