#include "Joc.h"
#include <iostream>

Joc::Joc(const std::string& nume) : numeJucator(nume), abandonat(false), ajutor(nullptr) {
    Scor::afiseazaNumarJocuri();
}

void Joc::afiseazaAjutor50_50(Intrebare& intrebare) {
    ajutor = new Ajutor50_50();
    ajutor->aplicaAjutor(intrebare);
    delete ajutor;
}

void Joc::afiseazaAjutorSunaUnPrieten(Intrebare& intrebare) {
    ajutor = new AjutorSunaUnPrieten();
    ajutor->aplicaAjutor(intrebare);
    delete ajutor;
}

void Joc::afiseazaAjutorIntreabaPublicul(Intrebare& intrebare) {
    ajutor = new AjutorIntreabaPublicul();
    ajutor->aplicaAjutor(intrebare);
    delete ajutor;
}

void Joc::ruleaza() {
    for (int i = 0; i < 15; ++i) {
        Intrebare intrebare = intrebareManager.obtineIntrebare(i);
        std::cout << "\nIntrebare " << (i + 1) << ": " << intrebare.intrebare << std::endl;
        for (size_t j = 0; j < intrebare.raspunsuri.size(); ++j) {
            std::cout << j + 1 << ". " << intrebare.raspunsuri[j] << std::endl;
        }

        int raspunsUtilizator;
        std::cout << "Alegeti raspunsul (1-4) sau 5 pentru ajutor: ";
        std::cin >> raspunsUtilizator;

        if (raspunsUtilizator == 5) {
            int optiuneAjutor;
            std::cout << "Alegeti ajutorul:\n1. Ajutor 50:50\n2. Suna un prieten\n3. Intreaba publicul\n";
            std::cin >> optiuneAjutor;

            if (optiuneAjutor == 1) {
                afiseazaAjutor50_50(intrebare);
            } else if (optiuneAjutor == 2) {
                afiseazaAjutorSunaUnPrieten(intrebare);
            } else if (optiuneAjutor == 3) {
                afiseazaAjutorIntreabaPublicul(intrebare);
            }

            std::cout << "Alegeti din nou raspunsul (1-4): ";
            std::cin >> raspunsUtilizator;
        }

        if (raspunsUtilizator - 1 == intrebare.raspunsCorect) {
            std::cout << "Raspuns corect!" << std::endl;
            scor.adaugaPuncte();
        } else {
            std::cout << "Raspuns gresit!" << std::endl;
            break;
        }

        std::cout << "Premiu curent: " << scor.obtinePremiu() << " RON\n";

        char abandon;
        std::cout << "Vrei sa abandonezi jocul si sa pastrezi castigul? (y/n): ";
        std::cin >> abandon;
        if (abandon == 'y' || abandon == 'Y') {
            abandonat = true;
            break;
        }
    }

    if (!abandonat) {
        scor.afiseazaScorFinal();
    } else {
        std::cout << "Ai abandonat jocul cu suma de: " << scor.obtinePremiu() << " RON\n";
    }
}
