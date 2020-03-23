#include <iostream>
#include "Tests.h"
#include "Movie.h"
using namespace std;

int main() {
	someTests();
	char title[100];

	cout << "Titlul: "; cin >> title;

	Movie m1(title);
	Movie m2(m1);
	Movie m3 = m1;
	Movie m4;
	m4 = m2;
	return 0;
}