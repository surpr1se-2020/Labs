#pragma once
#include "Person.h"
#include "List.h"

class Student :public Person {
protected:
	int numberOfGroup;
public:
	Student();
	Student(
		std::string,
		std::string,
		std::string,
		int
	);
	void Show();
	void Add();
	Student(const Student&);
	~Student();
};
Student::Student() {
	numberOfGroup = 0;
};

Student::Student(std::string _firstName, std::string _secondName, std::string _lastName, int _numberOfGroup)
	:Person(_firstName, _secondName, _lastName) {
	numberOfGroup = _numberOfGroup;
};
void Student::Show() {
	std::cout << "Student:\n\t" << Person::secondName << "  " << Person::firstName << "  " << Person::lastName << "  |  [Group number: " << numberOfGroup << "]\n" << std::endl;
};
Student::Student(const Student& _Student) { };
Student::~Student() {};
void Student::Add() {
	list* Temp = new list;
	Temp->Data = new Student(
		firstName,
		secondName,
		lastName,
		numberOfGroup
	);
	Temp->Next = nullptr;
	if (List::_List.GetHead() != nullptr) {
		List::_List.GetTail()->Next = Temp;
		List::_List.SetTail(Temp);

	}
	else {
		List::_List.SetHead(Temp);
		List::_List.SetTail(Temp);

	}
}