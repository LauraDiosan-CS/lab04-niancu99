#pragma once
#include <iostream>
using namespace std;

class Movie {
private:
	char* title; 
	int date; 
	char* gen;

public:
	Movie();
	Movie(char* title, int date, char* gen);
	Movie(const Movie& m);
	~Movie();
	char* getTitle();
	int getDate();
	char* getGen();
	void setDate(int date);
	void setTitle(char* title);
	void setGen(char* gen);
};