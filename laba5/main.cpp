#include <iostream>
#include "cset.h"

int main()
{
	cset set1;
	cset set2;
	cset set3;
	set1.input(2);
	set2.input(2);
	set1.print("set1");
	set2.print("set2");
	set1 = 'Y' + set1;
	set2 = 'Z' + set2;
	set1.print("set1 + Y");
	set2.print("set2 + Z");
	set3 = set1 + set2;
	set3.print("set1 + set2");
	if (set1 == set2)
		std::cout << "set1 equal set2" << std::endl;
	else
		std::cout << "set1 not equal set2" << std::endl;
	return 0;
}