#include "Movie.h"
#include <string.h>
#include <sstream>
using namespace std;

Movie::Movie() {
	titlu = NULL;
	data_lansarii = 0;
	gen = NULL;

}

Movie::Movie(const char* titlu, int data_lansarii, const char* gen) {
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	this->data_lansarii = data_lansarii;
	this->gen = new char[strlen(gen) + 1];
	strcpy_s(this->gen, strlen(gen) + 1, gen);
}

Movie::Movie(const Movie& m) {
	this->titlu = new char[strlen(m.titlu) + 1];
	strcpy_s(this->titlu, strlen(m.titlu) + 1, m.titlu);
	this->data_lansarii = m.data_lansarii;
	this->gen = new char[strlen(m.gen) + 1];
	strcpy_s(this->gen, strlen(m.gen) + 1, m.gen);
}
Movie::Movie(string linie)
{
	std::istringstream iss(linie);
	string tok1, tok2,tok3;
	iss >> tok1 >> tok2>>tok3;
	titlu = new char[tok1.length() + 1];
	strcpy_s(titlu, tok1.length() + 1, tok1.c_str());
	data_lansarii = stoi(tok2);
	gen = new char[tok3.length() + 1];
	strcpy_s(gen, tok3.length() + 1, tok3.c_str());

}

int Movie::getData_Lansarii() {
	return data_lansarii;
}

void Movie::setData_Lansarii(int d) {
	data_lansarii = d;
}

char* Movie::getTitlu() {
	return titlu;

}

void Movie::setTitlu(const char* n) {
	if (titlu) delete[]titlu;
	titlu = new char[strlen(n) + 1];
	strcpy_s(titlu, strlen(n) + 1, n);
}

Movie::~Movie() {
	if (titlu) delete[]titlu;
	titlu = NULL;
	data_lansarii = -1;
	gen = NULL;

}


Movie& Movie::operator=(const Movie& m) {
	if (this == &m) return *this; //self-assignment 

	if (titlu) delete[] titlu;
	titlu = new char[strlen(m.titlu) + 1];
	strcpy_s(titlu, strlen(m.titlu) + 1, m.titlu);
	data_lansarii = m.data_lansarii;
	gen = new char[strlen(m.gen) + 1];
	strcpy_s(gen, strlen(m.gen) + 1, m.gen);
	return *this;
}

bool Movie::operator==(const Movie& m) {
	return (strcmp(titlu,m.titlu) == 0) and (data_lansarii == m.data_lansarii) and (gen,m.gen==0);
}

bool Movie::operator<(const Movie& m)
{
	return (strcmp(titlu, m.titlu) < 0);

}

ostream& operator<<(ostream& os, Movie m) {
	os << m.titlu << " " <<m.data_lansarii <<m.gen<< endl;
	return os;
}

istream& operator>>(istream& is, Movie& m)
{
	cout << "Dati titlu: ";
	char* titlu = new char[10];
	is >> titlu;
	cout << "Dati data lansarii: ";
	int d;
	cin >> d;
	cout << "Dati genul: ";
	char* gen = new char[10];
	is >> gen;
	m.setTitlu(titlu);
	m.setData_Lansarii(d);
	m.setGen(gen);
	delete[] titlu;
	return is;
}


