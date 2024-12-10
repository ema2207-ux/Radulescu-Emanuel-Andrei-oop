#include "Ajutor.h"
#include <iostream>
#include <cstdlib>

void Ajutor50_50::aplicaAjutor(Intrebare& intrebare) {
    std::cout << "Ajutor 50:50 activat! Eliminam doua raspunsuri gresite.\n";
    int raspunsCorect = intrebare.raspunsCorect;
    int eliminat1 = (raspunsCorect + rand() % 4) % 4;
    while (eliminat1 == raspunsCorect) eliminat1 = (raspunsCorect + rand() % 4) % 4;
    int eliminat2 = (raspunsCorect + rand() % 4) % 4;
    while (eliminat2 == raspunsCorect || eliminat2 == eliminat1) eliminat2 = (raspunsCorect + rand() % 4) % 4;

    std::cout << "Raspunsurile ramase sunt:\n";
    for (size_t i = 0; i < intrebare.raspunsuri.size(); ++i) {
        if (i != eliminat1 && i != eliminat2) {
            std::cout << i + 1 << ". " << intrebare.raspunsuri[i] << std::endl;
        }
    }
}

void AjutorSunaUnPrieten::aplicaAjutor(Intrebare& intrebare) {
    std::cout << "Prietenul spune ca raspunsul corect este: " << intrebare.raspunsuri[intrebare.raspunsCorect] << std::endl;
}

void AjutorIntreabaPublicul::aplicaAjutor(Intrebare& intrebare) {
    std::cout << "Publicul este de acord cu raspunsul corect: " << intrebare.raspunsuri[intrebare.raspunsCorect] << std::endl;
}
