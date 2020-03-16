#pragma once
#include "Film.h"

class Repo {
private:
	Film filme[30];
	int n;
public:
	Repo();
	~Repo();
	void addFilm(Film f);
	Film* getAll();
	int getSize();
};
