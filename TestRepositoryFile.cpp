#include "TestRepositoryFile.h"
#include <assert.h> 



TestRepositoryFile::TestRepositoryFile()
{

	assert(repo.size() == 0);
}

void TestRepositoryFile::testLoadFromFile()
{
	repo.loadFromFile("TestMovie.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testAddElem()
{
	repo.loadFromFile("TestMovie.txt");
	repo.addElem(Movie("Avengers", 19,"aventura"));
	assert(repo.size() == 5);
	repo.saveToFile();
}

void TestRepositoryFile::testFindElem()
{
	repo.loadFromFile("TestMovie.txt");
	assert(repo.findElem(Movie("Frozen", 19,"drama")) == 1);
	assert(repo.findElem(Movie("Hobbit", 12,"SF")) == -1);
	repo.saveToFile();
}

void TestRepositoryFile::testDelElem()
{
	repo.loadFromFile("TestMovie.txt");
	repo.delElem(Movie("Avengers", 19,"aventura"));
	assert(repo.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testGetAll()
{
	repo.loadFromFile("TestMovie.txt");
	vector<Movie> rez = repo.getAll();
	assert(rez.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testUpdateElem()
{
	repo.loadFromFile("TestMovie.txt");
	repo.updateElem(Movie("Frozen 1", 19,"drama"), "Frozen 2", 20,"drama");
	assert(repo.findElem(Movie("Frozen 1", 20,"drama")) == 1);
	repo.saveToFile();
}

void TestRepositoryFile::testElemAtPos()
{
	repo.loadFromFile("TestMovie.txt");
	assert(repo.elemAtPos(1) == Movie("Frozen 1", 19,"drama"));
	repo.saveToFile();
}

void TestRepositoryFile::testSize()
{
	repo.loadFromFile("TestMovie.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testSaveToFile()
{
	repo.loadFromFile("TestMovie.txt");
	int n = repo.size();
	repo.addElem(Movie("Avengers", 19,"aventura"));
	repo.saveToFile();
	repo.loadFromFile("TestMovie.txt");
	assert(repo.getAll().size() == (n + 1));

}


TestRepositoryFile::~TestRepositoryFile()
{
}
