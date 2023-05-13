#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Student {
    

    std::string surename;
    std::string name;
    int albumId;
    std::string group;
    int year;

public:
    Student() {
        surename = "surname";
        name = "name";
        albumId = 12345;
        group = 123;
        year = 1;
    }

    friend std::istream& operator>>(std::istream& input, Student& student) {
        std::cout << "type in surname, name, albumId,group,year\n";
        input >> student.surename >> student.name >> student.albumId >> student.group >> student.year;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Student& student) {
        output << student.surename << " " << student.name << " " << student.albumId << " " << student.group << " " << student.year;
        return output;
    }


    friend std::ifstream& operator>>(std::ifstream& input, std::vector<Student>& data) {
        for (int i=0; i < data.size(); i++) {
            input >> data[i].surename >> data[i].name[i] >> data[i].albumId >> data[i].group >> data[i].year;
        }
        
        return input;
    }

    friend std::ifstream& operator>>(std::ifstream& input, Student& data) {
        input >> data.surename >> data.name >> data.albumId >> data.group >> data.year;
        return input;
    }


    friend std::ofstream& operator<<(std::ofstream& output, Student& data) {
        output << data.surename << data.name << data.albumId << data.group << data.year << "\n";
        return output;
    }

    friend std::ofstream& operator<<(std::ofstream& output, std::vector<Student>& data) {
        for (int i = 0; i < data.size(); i++) {
            output << data;
        }
        return output;
    }

    int getYear() {
        return year;
    }
};
 
