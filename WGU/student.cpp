//
//  student.cpp
//  c867
//

#include <stdio.h>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() //Parameterless constructor sets all fields to default values
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysToCompleteArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = DegreeProgram::UNDECIDED;
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram myDegeeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->degreeProgram = myDegeeProgram;
	for (int i = 0; i < daysToCompleteArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	
}

Student::~Student() {}

//getters
string Student::getStudentId(){return this->studentId;}
string Student::getFirstName(){return this->firstName;}
string Student::getLastName(){return this->lastName;}
string Student::getEmail(){return this->email;}
int Student::getAge(){return this->age;}
const int* Student::getDaysToComplete(){return this->daysToComplete;}
DegreeProgram Student::getDegreeProgram(){return this->degreeProgram;}

//setters
void Student::setStudentId(string studentId){this->studentId = studentId;}
void Student::setFirstName(string firstName){this->firstName = firstName;}
void Student::setLastName(string lastName){this->lastName = lastName;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){this->age = age;}
void Student::setDaysToComplete(const int daysToComplete[])
{
	for (int i=0; i < daysToCompleteArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;}

//Prints nifty header row to name the categories - tab seperated
void Student::printHeader()
{
	cout << "StudentId\t";
	cout << "FirstName\t";
	cout << "LastName\t";
	cout << "Email\t";
	cout << "Age\t";
	cout << "Days To Complete\t";
	cout << "Degree Type\t";
	cout << endl;
}

void Student::print()
{
	cout << this->studentId << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->email << '\t';
	cout << this->age << '\t';
	cout << this->daysToComplete[0] << '\t';
	cout << this->daysToComplete[1] << '\t';
	cout << this->daysToComplete[2] << '\t';
	cout << degreeProgramStrings[(int)this->getDegreeProgram()];
	cout << endl;
}
