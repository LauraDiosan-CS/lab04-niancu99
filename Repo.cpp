#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}

Repo::~Repo() {
	this->n = 0;
}

void Repo::addMovie(Movie m) {
	this->movies[this->n++] = m;
}

void Repo::findMovie(Movie& movie)
{
	int i = o;
	while (i < this->n)
	{
		if (movies[i] == movie)
			return i;
	}
	return -1;

}

Movie* Repo::getAll() {
	return this->movies;
}

int Repo::getSize() {
	return n;
}

void Repo::deleteMovie(Movie& movie){
	int i = finMovie(movie);
	if (i != -1)
		movies[i] = movies[n - 1];
	n--;
}


void Repo::updateMovie(Movie& movie, char* title, char* date, char* gen) {
	int i;
	for (i = 0; i < getSize(); i++)
	{
		if (movies[i == movie) {
			movies[i].setTitle(title);
			movies[i].setDate(date);
			movies[i].setGen(gen);

		}
	}
}