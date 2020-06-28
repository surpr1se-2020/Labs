#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "HeadOfDepartment.h"
#include "List.h"

void CreateAndAddToList();

int main() {

	CreateAndAddToList();
	List::CheckList();
	return 0;
}
void CreateAndAddToList() {
	Student student1;
	Teacher teacher1;
	HeadOfDepartment hOfD1;
	Student student2("Nikolay", "Altsivanovich", "Vitalievich", 53);
	Teacher teacher2("Ivan", "Ivanov", "Ivanovich", "Math");
	HeadOfDepartment hOfD2("Olga", "Zodchenko", "Vasilievna", "OOP", "IIT");
	student1.Add();
	student2.Add();
	teacher1.Add();
	teacher2.Add();
	hOfD1.Add();
	hOfD2.Add();
}
