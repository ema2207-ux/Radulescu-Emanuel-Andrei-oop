#include "Scor.h"
#include <iostream>

int Scor::numarJocuri = 0;

Scor::Scor() : punctaj(0) {
    premii = {0, 100, 200, 300, 500, 1000, 1500, 3000, 5000, 7500, 15000, 25000, 50000, 100000, 250000, 1000000};
    numarJocuri++;
}

int Scor::obtinePremiu() const {
    if (punctaj < premii.size()) {
        return premii[punctaj];
    }
    return 0;
}

void Scor::adaugaPuncte() {
    punctaj++;
}

void Scor::afiseazaNumarJocuri() {
    std::cout << "Numarul de jocuri jucate pana acum: " << numarJocuri << std::endl;
}

void Scor::afiseazaScorFinal() const {
    std::cout << "Ai castigat: " << obtinePremiu() << " RON!" << std::endl;
}
