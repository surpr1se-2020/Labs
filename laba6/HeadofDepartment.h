#pragma once
#include "Teacher.h"
#include "List.h"

class HeadOfDepartment :public Teacher {
protected:
	std::string department;
public:
	HeadOfDepartment();

	HeadOfDepartment(
		std::string,
		std::string,
		std::string,
		std::string,
		std::string
	);
	void Add();
	void Show();
	HeadOfDepartment(const HeadOfDepartment&);
	~HeadOfDepartment();
};
HeadOfDepartment::HeadOfDepartment() {
	department = "UndefinedDepartment";
};

HeadOfDepartment::HeadOfDepartment(std::string _firstName, std::string _secondName, std::string _lastName, std::string _subject, std::string _department)
	:Teacher(_firstName, _secondName, _lastName, _subject) {
	department = _department;
};
void HeadOfDepartment::Show() {
	std::cout << "HeadOfDepartment:\n\t" << Person::secondName << "  " << Person::firstName << "  " << Person::lastName << "  |  Subject: " << Teacher::subject << "  |  Department: " << department << std::endl << std::endl;
};
HeadOfDepartment::HeadOfDepartment(const HeadOfDepartment& _HeadOfDepartment) { };
HeadOfDepartment::~HeadOfDepartment() {};
void HeadOfDepartment::Add() {
	list* Temp = new list;
	Temp->Data = new HeadOfDepartment(
		firstName,
		secondName,
		lastName,
		subject,
		department
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

