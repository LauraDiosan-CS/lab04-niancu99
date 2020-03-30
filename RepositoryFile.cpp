#include "RepositoryFile.h"
#include <fstream>
#include <string>
using namespace std;


RepositoryFile::RepositoryFile()
{

}

RepositoryFile::RepositoryFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	int data_lansarii;
	char* gen = new char[10];
	while (!f.eof()) {
		f >>titlu >> data_lansarii >> gen;
		if (titlu != "") {
			Movie m(titlu,data_lansarii,gen);
			elem.push_back(m);
		}
	}
	delete[] titlu;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* titlu = new char[10];
	int data_lansarii;
	char* gen = new char[10];
	while (!f.eof()) {
		f >> titlu >> data_lansarii >> gen;
		if (strcmp(titlu, "") != 0) {
			Movie m(titlu, data_lansarii,gen);
			elem.push_back(m);
		}
	}
	delete[] titlu;
	f.close();
}

void RepositoryFile::addElem(Movie m)
{
	elem.push_back(m);
}

void RepositoryFile::updateElem(Movie m, const char* newTitlu, int newData_Lansarii,const char* newGen)
{
	vector<Movie>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		(*it).setTitlu(newTitlu);
		(*it).setData_Lansarii(newData_Lansarii);
		(*it).setGen(newGen);

	}

}

//returneaza pozitia la care se gaseste studentul s, sau -1, daca acesta nu apare
int RepositoryFile::findElem(Movie m)
{
	vector<Movie>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

//sterge elementul s din repository, returneaza 0 la succes, -1 altfel
int RepositoryFile::delElem(Movie m)
{
	vector<Movie>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}

Movie RepositoryFile::elemAtPos(int i)
{
	if (i < 0 or i >= elem.size()) return Movie("", -1,"");
	return elem[i];
}

vector<Movie> RepositoryFile::getAll()
{
	return elem;
}

int RepositoryFile::size()
{
	return elem.size();
}

void RepositoryFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}


RepositoryFile::~RepositoryFile()
{

}