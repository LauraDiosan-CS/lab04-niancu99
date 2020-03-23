#include "Movie.h"
#include <iostream>
#include <string.h>
using namespace std;

Movie::Movie() {
	this->title = NULL;
	this->date = 0;
	this->gen = NULL;
}

Movie::Movie(char* title, int date, char* gen)
{
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, 1 + strlen(title), title);
	
	this->date = date;

	this->gen = new char[strlen(gen) + 1];
	strcpy_s(this->gen, 1 + strlen(gen), gen);
}

Movie::Movie(const Movie& m) {
	this->title = new char[strlen(m.title) + 1];
	strcpy_s(this->title, 1 + strlen(m.title), m.title);
	
	this->date = m.date;

	this->gen = new char[strlen(m.gen) + 1];
	strcpy_s(this->title, 1 + strlen(m.gen), m.gen);
}

Movie::~Movie() {
	if (this->title) {
		delete[] this->title;
		this->title = NULL;
	}
	this->date = 0;
	if (this->gen) {
		delete[] gen;
		gen = NULL;
	}
}

char* Movie::getTitle() {
	return this->title;
}

int Movie::getDate() {
	return this->date;
}

char* Movie::getGen() {
	return this->gen;
}

void Movie::setTitle(char* title) {
	if (this->title) {
		delete[] this->title;
	}
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);

}

void Movie::setDate(int date) {
	this->date = date;
}

void Movie::setGen(char* gen) {
	if (this->gen) {
		delete[] this->gen;
	}
	this->gen = new char[strlen(gen) + 1];
	strcpy_s(this->gen, strlen(gen) + 1, gen);
}

