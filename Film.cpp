#include "Film.h"
#include <iostream>

Film::Film() {
	this->titlu = NULL;
}

Film::Film(char* titlu)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(titlu), titlu);
}

Film::Film(const Film& f) {
	this->titlu = new char[strlen(f.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(f.titlu), f.titlu);
}

Film::~Film() {
	if (this->titlu) {
		delete[] this->titlu;
		this->titlu = NULL;
	}
}

int Film::getSize() {
	return strlen(titlu);
}