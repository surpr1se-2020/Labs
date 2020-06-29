#include <iostream>
#include "Persona.h"
#include "HeadOfDed.h"
#include "Prepod.h"
#include "Student.h"

int main() {
	Student a(19, "Nikolay", "FEIS", 2);
	Student b(a);
	HeadOfDed c(27, "Chelnov C.A.", "math");
	Prepod d(32, "Rabotich B.A.", "english language");
	a.Push();
	b.Push();
	c.Push();
	d.Push();
	PersonList::ViewList();
}