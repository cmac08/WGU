//
//  roster.cpp
//  c867
//
//  Created by McGarry, Christine on 12/26/22.
//
#include <iostream>
#include <stdio.h>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

Roster::Roster(){};

void Roster::add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourseArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
	classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, email, age, daysInCourseArray, degreeProgram);
	cout << "Student added to class roster at row " << lastIndex + 1 << endl;
	
}

void Roster::parse(string row)
{
	stringstream ss(row);
	string token;
	string studentData[9];
	int i = 0;
	while (getline(ss, token, ',')) {
		studentData[i++] = token;
	}
	try {
		int age = stoi(studentData[4]);
		DegreeProgram degreeProgram;
		string degreeString = studentData[8];
		cout << degreeString << endl;
		std::transform(degreeString.begin(), degreeString.end(), degreeString.begin(), ::toupper);
		if (degreeString == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}
		else if (degreeString == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (degreeString == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else {
			degreeProgram = DegreeProgram::UNDECIDED;
		}
		add(studentData[0], studentData[1], studentData[2], studentData[3], age, stoi(studentData[5]), stoi(studentData[6]), stoi(studentData[7]), degreeProgram);
	}
	catch (invalid_argument& e) {
		cout << "Invalid argument: " << e.what() << endl;
	}
	catch (out_of_range& e) {
		cout << "Out of range: " << e.what() << endl;
	}
	catch (...) {
		cout << "Unexpected Error Time" << endl;
	}
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= lastIndex; i++) {
		Roster::getStudents()[i]->print();
		//Roster::classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	Student::printHeader();
	for (int i = 0; i <= lastIndex; i++)
		if (Roster::getStudents()[i]->getDegreeProgram() == degreeprogram) classRosterArray[i]->print();
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		string studentEmail = Roster::getStudents()[i]->Student::getEmail();
		if (studentEmail.find(' ') != string::npos || studentEmail.find('@') == string::npos || studentEmail.find('.') == string::npos)
			cout << studentEmail << " is Invalid" << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (Roster::getStudents()[i]->getStudentId() == studentId)
		{
			cout << "Average days for " << studentId << ": ";
			cout << (Roster::getStudents()[i]->getDaysToComplete()[0] +
					 Roster::getStudents()[i]->getDaysToComplete()[1] +
					 Roster::getStudents()[i]->getDaysToComplete()[2]) / 3.0 << endl;
		}
	}
}

void Roster::remove(string studentID)
{
	bool studentFound = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (Roster::getStudents()[i]->getStudentId() == studentID)
		{
			studentFound = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numberOfStudents -1];
			classRosterArray[numberOfStudents - 1] = temp;
			//Decrement last index and the removed student never shows again
			Roster::lastIndex--;

		}
	}
	if (studentFound)
	{
		cout << "Student " << studentID << " removed" << endl;
		printAll();
	}
	else
	{
		cout << "Student " << studentID << " not found" << endl;
	}
}

Roster::~Roster()
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "Destructor called for " << classRosterArray[i]->getStudentId() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

