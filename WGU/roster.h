//
//  roster.h
//  c867
//
//  Created by McGarry, Christine on 12/29/22.
//

#ifndef roster_h
#define roster_h
#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"
#include <vector>
#include <sstream>

const static int numberOfStudents = 5;
class Roster
{
private:
	int lastIndex = -1;
	Student* classRosterArray[numberOfStudents] = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:
	Roster();
	Student** getStudents(){
		return Roster::classRosterArray;
	}
	void add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentId);
	void printAverageDaysInCourse(string studentId);
	void printAll();
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram); 
	
	void parse(string row);
	~Roster();
	
};



#endif /* roster_h */
