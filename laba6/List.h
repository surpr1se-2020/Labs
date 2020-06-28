#pragma once
#include <iostream>

struct list {
	Person* Data;
	list* Next;
};

class List {
private:
	list* _Tail;
	static list* _Head;
public:
	static List		_List;

	List();
	List(const List&);
	~List();
	list* GetHead() const;
	list* GetTail() const;
	void		SetHead(list*);
	void		SetTail(list*);
	static void	CheckList();
};

List		List::_List = { };
list* List::_Head = nullptr;
List::List() {
	_Head = nullptr;
	_Tail = nullptr;
}
List::List(const List& tList) { }
List::~List() {
	while (_Head != nullptr) {
		list* Temp = _Head->Next;
		delete _Head;
		_Head = Temp;
	}
}
list* List::GetHead()	const { return _Head; }
list* List::GetTail()	const { return _Tail; }
void	List::SetHead(list* Head) { this->_Head = Head; }
void	List::SetTail(list* Tail) { this->_Tail = Tail; }
void	List::CheckList() {
	if (nullptr == List::_Head) {
		std::cout << "Items not found" << std::endl;
	}
	else {
		list* Temp = new list;
		Temp = List::_Head;
		while (Temp != nullptr) {
			Temp->Data->Show();
			Temp = Temp->Next;
		}
	}
}
