#include "Repo.h"
#include "Film.h"
#include <iostream>
using namespace std;



int main()
{

    char titlu[100];
    int op = 0;
    cout << "1.Adaugare film"; cout << endl;
    cout << "2.Afisarea tuturor filmelor"; cout << endl;
    cout << "3.Iesire"; cout << endl;
    cout << "op=";
    cin >> op;

    switch (op) {
    case 1:
        cout << "Titlu:"; cin >> titlu;
        Film f1(titlu);

}

}

