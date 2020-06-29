#pragma once
#include "Persona.h"
class HeadOfDed :
	public Persona
{
protected:
	string aNameOfDep;
public:
	HeadOfDed();
	HeadOfDed(const HeadOfDed&);
	HeadOfDed(int, string, string);
	~HeadOfDed();
	void View() override;
};

HeadOfDed::HeadOfDed() : HeadOfDed(0, "???", "???") {}
HeadOfDed::HeadOfDed(int age, string name, string nameDep) :
	Persona(age, name),
	aNameOfDep(nameDep)
{}
HeadOfDed::HeadOfDed(const HeadOfDed& oth) :
	HeadOfDed(oth.aAge, oth.aName, oth.aNameOfDep)
{}

void HeadOfDed::View() {
	cout << "head of departament ->\nAge: " << aAge
		<< "\nName: " << aName << "\ndepartament: " << aNameOfDep << endl << endl;
}

HeadOfDed::~HeadOfDed() {}