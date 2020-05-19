#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int main() {
	std::string line;
	std::string spaces;
	std::ifstream textFile("code.c");
	std::vector<std::string> result;
	int pos = 0, tab_count = 0, space_count = 0;
	unsigned int counter = 0;
	if (textFile.is_open()) {
		while (getline(textFile, line)) {
			for (int i = 0; i < line.length(); i++)
				if (line[i] != 32) {
					pos = i;
					break;
				}
			if (pos == 0) {
				result.push_back(line);
				std::cout << line << std::endl;
				continue;
			}
			spaces.clear();
			space_count = pos % 8;
			tab_count = pos - space_count;
			tab_count /= 8;
			for (int i = 0; i < tab_count; i++)
				spaces += 9;
			for (int i = 0; i < space_count; i++)
				spaces += 32;
			line.erase(0, pos);
			line.insert(0, spaces);
			std::cout << line << std::endl;
			result.push_back(line);
		}
	}
	textFile.close();
	ofstream textOutput;
	textOutput.open("codeOutput.c");
	if (textOutput.is_open()) {
		textOutput.clear();
		for (int i = 0; i < result.size(); i++) {
			textOutput << result[i] << std::endl;
		}
	}
	return 0;
}
