#pragma once
#include <iostream>
using namespace std;

class Film {
private:
	char* titlu;
public:
	Film();
	Film(char* titlu);
	Film(const Film& f);
	~Film();
	int getSize();
};