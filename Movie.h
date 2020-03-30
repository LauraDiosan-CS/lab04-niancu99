#pragma once
#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
	char* titlu;
	int data_lansarii;
	char* gen;
	
public:
	Movie();
	Movie(const char*, int, const char*);
	Movie(const Movie&);
	Movie(string);//constructor de conversie
	Movie& operator=(const Movie&);
	char* getTitlu();
	char* getGen();
	int getData_Lansarii();
	void setTitlu(const char*);
	void setGen(const char*);
	void setData_Lansarii(int);
	bool operator==(const Movie&);
	bool operator<(const Movie&);
	~Movie();
	friend ostream& operator<<(ostream& os, Movie s);
	friend istream& operator>>(istream&, Movie&);
};
