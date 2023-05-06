#include "Student.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
Student::Student(){
    this->studentID = "";
    this->FirstName = "";
    this->LastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < DaysCompleted; i++) this->DaysLeft[i] = 0;
    this->Degree = DegreeProgram::NETWORK;
}
//-----------------------------------------------------------------------------------------------
Student::Student(string studentID, string FirstName, string LastName, string email, int age, int DaysLeft[], DegreeProgram Degree)
{
    this->studentID = studentID;
    this->FirstName= FirstName;
    this->LastName= LastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < DaysCompleted; i++) this->DaysLeft[i] = DaysLeft[i];
    this->Degree =Degree;
}
//--------------------------------------------------------------------------------------

Student::~Student() {}
//accessors
string Student::getStudentID()
{ return this->studentID;
}
string Student::getFirstName()
{ return this->FirstName;
}
string Student::getLastName()
{ return this->LastName;
}
string Student::getEmail()
{ return this->email;
}
int Student::getAge()
{ return this->age;
}
int* Student::getDaysLeft() { return this->DaysLeft; }
DegreeProgram Student::getdegree()
{ return this->Degree;
}
//----------------------------------------------------------------------------------
//mutators
void Student::setStudentID(string studentID)
{ this->studentID = studentID;
}
void Student::setFirstName(string FirstName)
{ this->FirstName = FirstName;
}
void Student::setLastName(string LastName)
{ this->LastName = LastName;
}
void Student::setEmail(string email)
{ this->email = email;
}
void Student::setAge(int age)
{ this->age = age;
}
void Student::setDL(int DaysLeft[])
{
    for (int i = 0; i < DaysCompleted; i++) this->DaysLeft[i] = DaysLeft[i];
}
void Student::setDegreeProgram(DegreeProgram Degree) {
    this->Degree = Degree;
}
void Student::printHeader() {
    cout << "StudentID:" << "\tFirst Name:" << "\tLast Name:" <<"\tEmail" <<
        "\tAge:" << "\tDays Left to Complete Course:" << "\tDegree Program" <<std::endl;
}
//---------------------------------------------------------------------------------------------------

void Student::print()
{
    cout << this->getStudentID();
     cout << this->getFirstName();
     cout << this->getLastName();
    cout << this->getEmail()<< "\t";
     cout << this->getAge()<< '\t';
    cout << this->getDaysLeft()[0]<<',';
        cout << this->getDaysLeft()[1]<< ',';
        cout << this->getDaysLeft()[2]<< ','<<"\t";
        cout <<degreeTypeStrings[this->getdegree()]<<"\t";
}
