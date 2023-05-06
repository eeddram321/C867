#pragma once
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include<stdio.h>
using namespace std;

class Roster {
public:
    int finalIndex = -1;
    const static int studentRecordTable = 5;
    Student* classRosterArray[studentRecordTable];
    //-----------------------------------------------------------------------------
    void parse(string studentrow);
    void add(string aaStudentID, string aaFirstName, string aaLastName, string aaEmail, int aaAge, int dayOne, int dayTwo,
        int dayThree, DegreeProgram Degree);
    void printAll();
    void printByDegreeProgram(DegreeProgram Degree);
    void printInvalidEmails();
    void printDaysInCourse(string studentID);
    bool remove(string studentID);



    ~Roster();

};
