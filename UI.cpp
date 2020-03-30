#include "UI.h"
#include <iostream>
using namespace std;

void addMovie1(Service& s) {
	Movie movie;
	cout << "Dati filmul:";
	cin >> movie;
	s.addMovie(movie);
	cout << "Filmul a fost adaugat cu succes!" << endl;
}


void findMovie1(Service& serv) {
	Movie movie;
	cout << "Dati filmul:";
	cin >> movie;
	bool rez = serv.findOne(movie);
	if (rez) cout << "Filmul a fost gasit!" << endl;
	else cout << "Filmul nu a fost gasit!" << endl;
}

void delMovie1(Service& serv) {
	Movie movie;
	cout << "Dati filmul:";
	cin >> movie;
	int rez = serv.delMovie(movie);
	if (rez == 0) cout << "Filmul a fost  sters cu succes!" << endl;
	else cout << "Filmul NU a fost sters!" << endl;
}

void showAll(Service& serv) {
	vector<Movie> movie = serv.getAll();
	for (Movie m : movie)//"range based for loop"~Java,C#
		cout << m;
}

void delByDateUI(Service& serv)
{
	int date;
	cout << "Dati data: " << endl;
	cin >> date;
	serv.delByDate(date);
}

void showGenreUI(Service& serv)
{
	char* genre = new char[20];
	cout << "Dati genul: " << endl;
	cin >> genre;
	serv.showByGenre(genre);
}



void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga student " << endl;
		cout << "	2. Cauta student " << endl;
		cout << "	3. Sterge student " << endl;
		cout << "	4. Afiseaza toti studentii " << endl;
		cout << "	5. Afiseaza toate filmelor dupa un anumit gen " << endl;
		cout << "	6. Eliminarea filmelor lansate inaintea unei date calendaristice" << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addMovie1(serv); break; }
		case 2: {findMovie1(serv); break; }
		case 3: {delMovie1(serv); break; }
		case 4: {showAll(serv); break; }
		case 5: {delByDateUI(serv); break; }
		case 6: {showGenreUI(serv); break; }
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		}
	}
}
