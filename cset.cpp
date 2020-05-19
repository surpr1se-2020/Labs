#include "cset.h"
#include <iostream>

cset::cset(const cset& _cset) {
	try {
		elements = new char[_cset.count];
		count = _cset.count;
		for (int i = 0; i < count; i++)
			elements[i] = _cset.elements[i];
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
}

void cset::input(int size) {
	char key;
	for (int k = 0; k < size; k++) {
		std::cout << "Enter char #" << k << ": ";
		std::cin >> key;
		this->push(key);
	}
	std::cout << "\n" << std::endl;
}

void cset::print(const char* name) {
	std::cout << name << ": " << std::endl;
	for (int i = 0; i < count; i++)
		std::cout << elements[i] << "\t";
	std::cout << "\n" << std::endl;
}

bool cset::subchar(const char item) {
	for (int i = 0; i < count; i++) {
		if (elements[i] == item)
			return 1;
	}
	return 0;
}

bool cset::isEqual(const cset& _cset) {
	if (count != _cset.count)
		return 0;
	for (int i = 0; i < count; i++) {
		if (elements[i] != _cset.elements[i])
			return 0;
	}
	return 1;
}

void cset::push(const char _element)
{
	char* p2;
	p2 = elements;
	bool isFind = false;

	try {
		if (subchar(_element))
			return;
		elements = new char[count + 1];
		for (int i = 0; i < count; i++)
			elements[i] = p2[i];
		for (int i = 0; i < count; i++) {
			if (_element < elements[i])
			{
				for (int k = count; k > i; k--)
				{
					elements[k] = elements[k - 1];
				}
				elements[i] = _element;
				isFind = true;
				break;
			}
		}
		if (!isFind)
			elements[count] = _element;
		count++;
		if (count > 0)
			delete[] p2;
	}
	catch (std::bad_alloc e) {
		std::cout << e.what() << std::endl;
		elements = p2;
	}
}

cset::~cset() {
	if (count > 0)
		delete[] elements;
}

cset& cset::operator=(const cset& obj) {
	char* val2;

	try {
		val2 = new char[obj.count];
		if (count > 0)
			delete[] elements;
		elements = val2;
		count = obj.count;
		for (int i = 0; i < count; i++)
			elements[i] = obj.elements[i];
	}
	catch (std::bad_alloc e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}

cset& cset::operator+=(const char _element) {
	push(_element);
	return *this;
}

cset& cset::operator+=(const cset& _cset) {
	for (int i = 0; i < _cset.count; i++)
		push(_cset.elements[i]);
	return *this;
}

cset operator+(const char _element, const cset& _cset) {
	cset csethelp(_cset);
	csethelp += _element;
	return csethelp;
}

cset operator+(const cset& _cset, const cset& _cset2) {
	cset csethelp(_cset);
	csethelp += _cset2;
	return csethelp;
}

bool cset::operator==(const cset& mset) {
	return isEqual(mset);
}

