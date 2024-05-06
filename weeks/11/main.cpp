#include "Patient.h"
#include "HeapMaxArray.h"
#include <iostream>
using namespace std;

int main(void) {
    Patient frank;
    frank.name = "Frank";
    frank.priority = 7;

    Patient rosie;
    rosie.name = "Rosie";
    rosie.priority = 8;

    Patient charlie;
    charlie.name = "Charlie";
    charlie.priority = 4;

    Patient henrietta;
    henrietta.name = "Henrietta";
    henrietta.priority = 1;

    HeapMaxArray<Patient> help(5);
    help.add(frank);
    help.add(rosie);
    help.add(henrietta);
    help.add(charlie);
    cout << help.peekTop().name << endl;
    help.remove();
    help.remove();
    cout << help.peekTop().name << endl;

    return 0;
}