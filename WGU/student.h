//
//  student.h
//  c867
//
//  Created by M, Christine on 12/26/22.
//

#ifndef student_h
#define student_h

#include <iostream>
#include "degree.h"

using namespace std;

class Student
{
public:
	const static int daysToCompleteArraySize = 3;
private:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[daysToCompleteArraySize];
	DegreeProgram degreeProgram;
public: //method constructors
Student();
	//Full Constructor
Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degeeProgram);
~Student(); //Destructor

//getters
string getStudentId();
string getFirstName();
string getLastName();
string getEmail();
int getAge();
const int* getDaysToComplete();
DegreeProgram getDegreeProgram();

//setters
void setStudentId(string studentId);
void setFirstName(string firstName);
void setLastName(string lastName);
void setEmail(string email);
void setAge(int age);
void setDaysToComplete(const int days[]);
void setDegreeProgram(DegreeProgram degreeProgram);

static void printHeader();

void print();

};



#endif /* student_h */
