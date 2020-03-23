#include <assert.h>
#include "Tests.h"
#include <string.h>
#include "Movie.h"
#include "Repo.h"

void someTests() {
	char* title1 = new char[20];
	char* title2 = new char[20];
	char* gen1 = new char[10];
	char* gen2 = new char[10];

	strcpy_s(title1, sizeof "titlu1", "titlu1");
	strcpy_s(title2, sizeof "titlu2", "titlu2");
	strcpy_s(gen1, sizeof "drama", "drama");
	strcpy_s(gen2, sizeof "actiune", "actiune");

	Movie m(title1, 30, gen2);
	assert(m.getDate() == 30);
	m.setDate(6);
	m.setTitle(title2);
	assert(m.getDate() == 6);
	assert(m.getTitle() == title2);

	Movie movie(title2, 13, gen2);
	assert(movie.getGen() == gen2);

	Movie movietest;
	movietest.setDate(26);
	movietest.setTitle(title2);
	movietest.setGen(gen1);
	assert(movietest.getDate() == 26);
	assert(movietest.getGen() == gen1);
	assert(movietest.getTitle() == title2);

	Repo r;
	r.addMovie(movietest);
	assert(r.getSize() == 1);
	assert(r.getAll()[0].getDate() == 26);
	assert(r.getAll()[0].getTitle() == title2);
	assert(r.getAll()[0].getGen() == gen1);

	r.updateMovie(movietest, title1, 20, gen2);
	assert(r.getAll()[0].getDate() == 20);
	assert(r.getAll()[0].getGen() == gen2);
	assert(r.getAll()[0].getTitle() == title1);

	r.deleteMovie(movietest);
	assert(r.getSize() == 0);
}