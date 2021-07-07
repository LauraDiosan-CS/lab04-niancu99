#pragma once
#include "Movie.h"
#include <vector>
using namespace std;

class RepositoryFile
{
private:
	vector<Movie> elem;
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void addElem(Movie);
	void updateElem(Movie, const char*, int , const char*);
	int findElem(Movie);
	int delElem(Movie);
	Movie elemAtPos(int);
	vector<Movie> getAll();
	int size();
	void saveToFile();
	~RepositoryFile();
};
