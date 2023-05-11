#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>


class student {
public:
    std::string surename;
    std::string name;
    int albumId;
    std::string group;
    int year;

    student() {
        

    }

    student(string newName) {
        surename = "";
        name = newName;
        albumId = 12345;
        group = 123;
        year = 1;
    }

};

