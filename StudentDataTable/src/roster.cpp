#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
using namespace std;

void Roster::parse(string studentInfo)
{


    size_t rlim = studentInfo.find(',');
    string aaStudentID = studentInfo.substr(0, rlim);
    //----------------------------------------------------------------------
    size_t ls = rlim + 1;
    rlim = studentInfo.find(',', ls);
    string aaFirstName = studentInfo.substr(ls, rlim - ls);
    //-----------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(',', ls);
    string aaLastName = studentInfo.substr(ls, rlim - ls);
    //------------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(",", ls);
    string aaEmail = studentInfo.substr(ls, rlim - ls);
    //-----------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(",", ls);
    int aaAge = stoi(studentInfo.substr(ls, rlim - ls));
    //----------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(",", ls);
    int dayOne = stoi(studentInfo.substr(ls, rlim - ls));
    //---------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(",", ls);
    int dayTwo = stoi(studentInfo.substr(ls, rlim - ls));
    //---------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(",", ls);
    int dayThree = stoi(studentInfo.substr(ls, rlim - ls));
    //--------------------------------------------------------------------
    ls = rlim + 1;
    rlim = studentInfo.find(",", ls);
    string degreeType = studentInfo.substr(ls, rlim - ls);
    //--------------------------------------------------------------------
    DegreeProgram Degree = SOFTWARE;

    if (degreeType == "SOFTWARE") {
        Degree = SOFTWARE;
    }
    if (degreeType == "Network") {
        Degree = NETWORK;
     }
    if (degreeType == "Security") {
        Degree = SECURITY;
    }
    if (studentInfo.at(ls) == 'S' && studentInfo.at(ls + 1) == 'E') Degree = SECURITY;
    else if (studentInfo.at(ls) == 'S' && studentInfo.at(ls + 1) == 'O') Degree = SOFTWARE;
    else if (studentInfo.at(ls) == 'N') Degree = NETWORK;
    //-------------------------------------------------------------------------------------
    add( aaStudentID,  aaFirstName, aaLastName, aaEmail,  aaAge, dayOne,  dayTwo,
        dayThree, Degree);

}

//-------------------------------------------------------------------------------------------------------------------
void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int dayOne, int dayTwo,
    int dayThree, DegreeProgram Degree)
{
    int DaysCompletedArr[3] = { dayOne, dayTwo, dayThree };
    classRosterArray[++finalIndex] = new Student(StudentID, FirstName, LastName, Email, Age, DaysCompletedArr, Degree);
}
//----------------------------------------------------------------------------------------------------------------
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::finalIndex; i++) Roster::classRosterArray[i]->print();
}
//------------------------------------------------------------------------------------------------------------
void Roster::printInvalidEmails()
{
    bool EveryEmail = false;
    for (int i = 0; i <= Roster::finalIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            EveryEmail = true;
            cout << email << " " << classRosterArray[i]->getFirstName() << endl;
             }
    }
    if (!EveryEmail) cout << "Not Available" <<endl;
}
//------------------------------------------------------------------------------------------------------------

void Roster::printDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::finalIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << studentID << "  ";
            cout << (classRosterArray[i]->getDaysLeft()[0] +classRosterArray[i]->getDaysLeft()[1] +classRosterArray[i]->getDaysLeft()[2]) / 3 << endl;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------
void Roster::printByDegreeProgram(DegreeProgram Degree)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::finalIndex; i++) {
        if (Roster::classRosterArray[i]->getdegree() == Degree) classRosterArray[i]->print();
    }
    cout<<endl;
}
//------------------------------------------------------------------------------------------------------------------------
bool Roster::remove(string studentID){
    bool pass = false;
    for (int i = 0; i <= Roster::finalIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            pass = true;
            if (i < studentRecordTable - 1)
            {
                Student* nonperm = classRosterArray[i];
                classRosterArray[i] = classRosterArray[studentRecordTable - 1];
                classRosterArray[studentRecordTable - 1] = nonperm;
            }
            Roster::finalIndex--;
        }
    }
    if (!pass)
    {
        cout << studentID << " deleted from the roster." <<endl;
        this->printAll();
    }
    else cout << studentID << " not found." << std::endl << std::endl;;
    return pass;
}
//-----------------------------------------------------------------------------------------------
Roster::~Roster(){
    cout << "The Destructor Has Been Initialized" << endl;
    for (int i = 0; i < studentRecordTable; i++)
    {
        cout<<"Removing Student:"<< i +1 <<endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
