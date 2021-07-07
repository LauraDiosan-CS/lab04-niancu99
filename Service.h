#pragma once
#include "RepositoryFile.h"
#include "Movie.h"
#include <vector>
using namespace std;

class Service
{
private:
	RepositoryFile repo;
public:
	Service();
	Service(const RepositoryFile&);
	void setRepo(const RepositoryFile&);
	vector<Movie> filterMovies(char* titlu, int data_lansarii ,char* gen);
	void addMovie(Movie&);
	int delMovie(Movie&);
	vector<Movie> getAll();
	Movie update(Movie, char*, int,char*);
	bool findOne(Movie);
	void delByDate(int);
	void showByGenre(const char*);
	~Service();

};

