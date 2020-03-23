#pragma once
#include "Movie.h"

class Repo {
private:
	Movie movies[50];
	int n;
public:
	Repo();
	~Repo();
	void addMovie(Movie m);
	Movie* getAll();
	int getSize();
};