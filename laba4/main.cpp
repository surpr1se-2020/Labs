#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

class Student {
private:
    char* name;
    int course;
    bool sex;
    void allocateChars(const char* _name);

public:
    Student();
    Student(const char* _name, int _course, bool _sex);
    Student(const Student&);
    ~Student();
    void print();
};

void Student::allocateChars(const char* _name) { // Выделяем память
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Student::Student() { // Конструктор без параметров
	allocateChars("Unnamed");
	std::cout << "Create class Student without constructor params." << std::endl;
}

Student::Student(const char* _name, int _course, bool _sex) { // Конструктор с 3 параметрами
	allocateChars(_name);
	course = _course;
	sex = _sex;
	std::cout << "Create class Student with 3 constructor params." << std::endl;
}

Student::Student(const Student& _Student) { // Конструктор копирования
	allocateChars(_Student.name);
	course = _Student.course;
	sex = _Student.sex;
	std::cout << "Create class Student with copy constructor." << std::endl;
}

Student::~Student() { // Деструктор
	std::cout << "Call Student class \"" << name << "\" desctructor." << std::endl;
	delete[] name;
}

void Student::print() { // Вывод
	std::cout << "\nName: " << name << "\nCourse: " << course
		<< "\nSex: "; if (sex) std::cout << "female"; else std::cout << "male";
	std::cout << "\n" << std::endl;
}

int main() {
    Student* Student1 = new Student("Nikolay", 2, 0);
    Student Student2;
    Student Student3(*Student1);

	Student1->print();
	Student2.print();
	Student3.print();

	delete(Student1);

    return 0;
}