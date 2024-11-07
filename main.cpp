#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>


struct Intrebare {
    std::string intrebare;
    std::vector<std::string> raspunsuri;
    int raspunsCorect;
};

class IntrebareManager {
private:
    std::vector<Intrebare> intrebari;

public:
    IntrebareManager() {
        intrebari = {
            {"Care este capitala Frantei?", {"Paris", "Londra", "Berlin", "Madrid"}, 0},
            {"Care este cel mai mare ocean?", {"Pacific", "Atlantic", "Indian", "Arctic"}, 0},
            {"Cine a scris 'Micul Print'?", {"Victor Hugo", "Mark Twain", "Antoine de Saint-Exupery", "Jules Verne"}, 2}
        };
    }

    std::vector<Intrebare>& getIntrebari() {
        return intrebari;
    }
};

class Scor {
private:
    int punctaj;
    std::vector<int> premii;

public:
    Scor() : punctaj(0) {
        // Premii pentru fiecare etapă
        premii = {0, 100, 200, 300, 500, 1000, 2000, 4000, 8000, 16000, 32000, 64000, 125000, 250000, 500000, 1000000};
    }

    void adaugaPuncte() {
        punctaj++;
    }

    int getPunctaj() const {
        return punctaj;
    }

    int getPremiu() const {
        if (punctaj < premii.size()) {
            return premii[punctaj];
        }
        return 0;
    }

    void afiseazaScorFinal() const {
        std::cout << "Ai castigat: " << getPremiu() << " RON!" << std::endl;
    }
};

class Joc {
private:
    std::string numeJucator;
    IntrebareManager intrebareManager;
    Scor scor;
    bool abandonat;

public:
    Joc(const std::string& nume) : numeJucator(nume), abandonat(false) {}

    void afiseazaAjutor50_50(Intrebare& intrebare) {
        std::cout << "Ajutor 50:50 activat! Eliminam doua raspunsuri gresite.\n";
        int raspunsCorect = intrebare.raspunsCorect;
        int eliminat1 = (raspunsCorect + rand() % 4) % 4;
        while (eliminat1 == raspunsCorect) eliminat1 = (raspunsCorect + rand() % 4) % 4;
        int eliminat2 = (raspunsCorect + rand() % 4) % 4;
        while (eliminat2 == raspunsCorect || eliminat2 == eliminat1) eliminat2 = (raspunsCorect + rand() % 4) % 4;

        std::cout << "Raspunsul corect este: " << intrebare.raspunsuri[raspunsCorect] << std::endl;
        std::cout << "Raspunsurile ramase sunt:\n";
        for (size_t i = 0; i < intrebare.raspunsuri.size(); ++i) {
            if (i != eliminat1 && i != eliminat2) {
                std::cout << i + 1 << ". " << intrebare.raspunsuri[i] << std::endl;
            }
        }
    }

    void ruleaza() {
        srand(time(0));
        std::vector<Intrebare>& intrebari = intrebareManager.getIntrebari();
        for (size_t i = 0; i < intrebari.size(); ++i) {
            Intrebare& intrebare = intrebari[i];

            std::cout << "\nIntrebare " << (i + 1) << ": " << intrebare.intrebare << std::endl;
            for (size_t j = 0; j < intrebare.raspunsuri.size(); ++j) {
                std::cout << j + 1 << ". " << intrebare.raspunsuri[j] << std::endl;
            }

            int raspunsUtilizator;
            std::cout << "Alegeti raspunsul (1-4): ";
            std::cin >> raspunsUtilizator;

                if (raspunsUtilizator == 5) {
                afiseazaAjutor50_50(intrebare);
                std::cout << "Alegeti din nou raspunsul (1-2): ";
                std::cin >> raspunsUtilizator;
            }

            if (raspunsUtilizator - 1 == intrebare.raspunsCorect) {
                std::cout << "Raspuns corect!" << std::endl;
                scor.adaugaPuncte();
            } else {
                std::cout << "Raspuns gresit!" << std::endl;
                break;
            }

            // Afișăm câștigurile la fiecare întrebare corectă
            std::cout << "Premiu curent: " << scor.getPremiu() << " RON\n";

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
            std::cout << "Ai abandonat jocul cu suma de: " << scor.getPremiu() << " RON\n";
        }
    }
};

int main() {
    std::string numeJucator;
    std::cout << "Introduceti numele jucatorului: ";
    std::cin >> numeJucator;
    Joc joc(numeJucator);
    joc.ruleaza();

    return 0;
}
