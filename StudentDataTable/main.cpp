#include<iostream>
#include<string>
#include"roster.h"

using namespace std;

int main()
{
    cout << "\nCourse: C867 SCRIPTING and PROGRAMMING APPLICATIONS" <<
        "\nPROGRAMMING LANGUAGE: C++" <<  "\nSTUDENT ID: 009769427" <<"\nFULL NAME: EDUARDO RAMIREZ" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    const string astudentInfo[]=
    { "A1,\tJohn,\tSmith,\tJohn1989@gm ail.com,\t20,\t30,35,40,\t SECURITY","\nA2,\tSuzan,\tErickson,\tErickson_1990@gmailcom,\t19, \t50,30,40, \t Network","\nA3,\tJack,\tNapoli,\tThe_lawyer99yahoo.com,\t19, \t20,40,33, \t SOFTWARE",
      "\nA4,\tErin,\tBlack,\tErin.black@comcast.net,\t22, \t50,58,40, \t SECURITY","\nA5,\tEduardo,\tRamirez,\teram179@wgu.edu, \t28,\t31,87,78, \t Software"
    };
    //-------------------------------------------------------------------------------------------------------
    const int studentRecordTable = 5;
    //--------------------------------------
    Roster roster;
    for (int i = 0; i < studentRecordTable; i++) {
        roster.parse(astudentInfo[i]);
    }
    cout << "Students:" <<endl;
    roster.printAll();
    cout << "\n ---------------------------------"<< endl;
    cout << std::endl;
    //-------------------------------------------------------------------------------
    cout << "Displaying Invalid email addess: " <<endl;
    roster.printInvalidEmails();
    cout <<"\n----------------------------------"<<endl;
    //-----------------------------------------------------------------------------
    //-------------------------------------------------------------------------------
    cout << "Days Left in Course:" <<endl;
    for (int i = 0; i < studentRecordTable; i++)
    {
        roster.printDaysInCourse(roster.classRosterArray[i]->getStudentID());
    }
    cout <<"\n-----------------------------------------------"<<endl;
  //----------------------------------------------------------------------------------------------
    cout << "Software Program:" << endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;
    cout << "\n---------------------------------------------" << endl;
//---------------------------------------------------------------------------------------------
    cout << "Remove Student A3" << endl;
    roster.remove("A3");
    cout << "\n------------------------------------------------" << endl;
    cout <<"\nRemove Student A3 again"<<endl;
    roster.remove("A3");
    cout<<endl;
}
