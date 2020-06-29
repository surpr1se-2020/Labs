#pragma once
#include "Persona.h"
class Prepod :
	public Persona
{
protected:
	string aAcademicSubject;
public:
	Prepod();
	Prepod(const Prepod&);
	Prepod(int, string, string);
	~Prepod();
	void View() override;
};

Prepod::Prepod() : Prepod(0, "???", "???") {}
Prepod::Prepod(int age, string name, string academicSubject) :
	Persona(age, name),
	aAcademicSubject(academicSubject)
{}
Prepod::Prepod(const Prepod& oth) :
	Prepod(oth.aAge, oth.aName, oth.aAcademicSubject)
{}

void Prepod::View() {
	cout << "Prepod ->\nAge: " << aAge
		<< "\nName: " << aName << "\nAcademic subject: " << aAcademicSubject << endl << endl;
}

Prepod::~Prepod() {}
