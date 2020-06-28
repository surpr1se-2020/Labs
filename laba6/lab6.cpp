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
	Student student2("Daniil", "Agaev", "Sergeevich", 51);
	Teacher teacher2("Ibragim", "Ibragimov", "Ibragimovich", "Math");
	HeadOfDepartment hOfD2("Vasilii", "Vasiliev", "Vasilievich", "OOP", "IIT");
	student1.Add();
	student2.Add();
	teacher1.Add();
	teacher2.Add();
	hOfD1.Add();
	hOfD2.Add();
}

