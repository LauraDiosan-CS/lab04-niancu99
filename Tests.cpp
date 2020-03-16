#include <assert.h>
#include <string.h>
#include "Tests.h"
#include "Film.h"

void testEntity() {
	Film filme[2];
	char* titlu1 = new char[10];
	char* titlu2 = new char[10];

	strcpy_s(titlu1, sizeof "Avengers", "Avengers");
	Film f1(titlu1);

	strcpy_s(titlu2, sizeof "Frozen", "Frozen");
	Film f2(titlu2);

	filme[0] = f1;
	filme[1] = f2;
}
	