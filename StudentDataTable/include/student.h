#pragma once
#include "Degree.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Student
{
public:
    const static int DaysCompleted = 3;

private:
    string studentID;
    string FirstName;
    string LastName;
    string email;
    int age;
    int DaysLeft[DaysCompleted];
    DegreeProgram Degree;
public:
    Student();
    Student(string studentID, string FirstName, string LastName, string email, int age, int DaysLeft[], DegreeProgram Degree);
    ~Student();


    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysLeft();
    DegreeProgram getdegree();

    //Mutators
    void setStudentID(string studentID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmail(string email);
    void setAge(int age);
    void setDL(int DaysLeft[]);
    void setDegreeProgram(DegreeProgram Degree);

    static void printHeader();

    void print();
};
