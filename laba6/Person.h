#pragma once
#include <iostream>
#include <string>



class Person {
protected:
	std::string firstName;
	std::string secondName;
	std::string lastName;
public:
	Person();
	Person(
		std::string,
		std::string,
		std::string
	);
	Person(const Person&);
	virtual void Show() = 0;
	virtual void Add() = 0;
	~Person();
};
Person::Person() {
	firstName = "UndefinedFirstName";
	secondName = "UndefinedSecondName";
	lastName = "UndefinedLastName";
}
Person::Person(std::string _firstName, std::string _secondName, std::string _lastName) {
	firstName = _firstName;
	secondName = _secondName;
	lastName = _lastName;
};
Person::Person(const Person& _Person) { };
Person::~Person() { };