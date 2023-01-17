//
//  main.cpp
//  c867
//
//  Created by McGarry, Christine on 12/26/22.
//
#pragma GCC diagnostic pop

#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

int main()
{
	cout << "-------------------------------------" << endl;
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language:	C++" << endl;
	cout << "Student ID:	000235570" << endl;
	cout << "Name: Christine McGarry" << endl;
	cout << "-------------------------------------" << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Christine, McGarry,cmcgarr@wgu.edu,37,22,19,40,SOFTWARE"
	};
	
	Roster classRoster;
	
		cout << "Display the students: " << endl;
	for (int i = 0; i < numberOfStudents; ++i) {
		classRoster.parse(studentData[i]);
	}
	
	classRoster.printAll();
	
	cout << "Display students with invalid email addresses: " << endl;
	classRoster.printInvalidEmails();

	cout << "Display the average length of days to complete: " << endl;
	for (int i = 0; i < numberOfStudents; ++i) {
			 classRoster.printAverageDaysInCourse(classRoster.getStudents()[i]->getStudentId());
	}

		cout << "Display students by Degree Program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << "Removing student A3: " << endl;
	classRoster.remove("A3");

	cout << "Removing student A3 again: " << endl;
	classRoster.remove("A3");

	cout << "Finished, destructors called automatically on exit." << endl;
	return 0;
};
