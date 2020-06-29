#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Persona {
protected:
	int aAge;
	string aName;
public:
	Persona();
	Persona(int, string);
	Persona(const Persona&);
	~Persona();
	void Push();
	virtual void View() = 0;
};

Persona::Persona(int age, string name) : aAge(age), aName(name) {}
Persona::Persona() : aAge(0), aName("???") {}
Persona::Persona(const Persona& oth) : Persona(oth.aAge, oth.aName) {}
Persona::~Persona() {}

class PersonList {
	class Node {
	public:
		Node(Persona*);
		Node();
		Node* apNext;
		Persona* apElem;
	};
	static Node* apBegin;
	static Node* apEnd;
public:
	static void PushEnd(Persona*);
	static void ViewList();
};

PersonList::Node* PersonList::apBegin = nullptr;
PersonList::Node* PersonList::apEnd = nullptr;
PersonList::Node::Node() : apNext(nullptr) {}
PersonList::Node::Node(Persona* elem) : apNext(nullptr), apElem(elem) {}
void PersonList::PushEnd(Persona* elem) {
	Node* pTemp = new Node(elem);
	if (!apBegin) apBegin = apEnd = pTemp;
	else {
		apEnd->apNext = pTemp;
		apEnd = pTemp;
	}
}

void PersonList::ViewList() {
	int i = 0;
	for (Node* pCur = apBegin; pCur; pCur = pCur->apNext) {
		cout << ++i << ") ";
		pCur->apElem->View();
	}
}

void Persona::Push() {
	PersonList::PushEnd(this);
}