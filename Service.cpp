#include "Service.h"
#include <algorithm> 

Service::Service()
{
}

Service::Service(const RepositoryFile& r)
{
	repo = r;
}

void Service::setRepo(const RepositoryFile& r)
{
	repo = r;
}



void Service::addMovie(Movie& m)
{
	repo.addElem(m);
}

int Service::delMovie(Movie& m)
{
	return repo.delElem(m);
}

vector<Movie> Service::getAll()
{
	return repo.getAll();
}

Movie Service::update(Movie m, char* t, int d, char* g)
{
	repo.updateElem(m, t, d, g);
	return m;
}

bool Service::findOne(Movie m)
{
	return repo.findElem(m);
}


void Service::delByDate(int date)
{
	vector<Movie> elem;
	vector<Movie>::iterator it = elem.begin();
	if ((*it).getData_Lansarii() < date) {
		delMovie(*it);
		it++;
	}
}


void Service::showByGenre(const char* genre) {
	vector<Movie> elem;
	vector<Movie>::iterator it = elem.begin();
	if ((*it).getGen() == genre) {
		cout << *it << endl;
		it++;
	}
}
Service::~Service()
{
}
