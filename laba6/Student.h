#pragma once
#include "Persona.h"

class Student :
	public Persona {
protected:
	int aCourse;
	string aFaculty;
public:
	Student();
	Student(const Student&);
	Student(int, string, string, int);
	void View() override;
};

Student::Student(int age, string name, string facult, int course) :
	Persona(age, name),
	aFaculty(facult),
	aCourse(course)
{}

Student::Student() : Student(0, "???", "???", 0) {}

Student::Student(const Student& oth) :
	Student(oth.aAge, oth.aName, oth.aFaculty, oth.aCourse)
{}

void Student::View() {
	cout << "Student ->\nAge: " << aAge
		<< "\nName: " << aName << "\nFaculty: " << aFaculty
		<< "\nCourse: " << aCourse << endl << endl;
}
