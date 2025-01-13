#ifndef STATISTICI_H
#define STATISTICI_H

#include <vector>
#include <string>
#include <iostream>  // Adăugat pentru std::cout

template<typename T>
class Statistici {
private:
    std::vector<T> istoricCastiguri;
    std::string numeJucator;
    T castigMaxim;
    T castigMediu;

public:
    Statistici(const std::string& nume) : numeJucator(nume), castigMaxim(0), castigMediu(0) {}

    void adaugaCastig(T castig) {
        istoricCastiguri.push_back(castig);
        if (castig > castigMaxim) {
            castigMaxim = castig;
        }
        calculezaCastigMediu();
    }

    void calculezaCastigMediu() {
        if (istoricCastiguri.empty()) return;

        T suma = 0;
        for (const auto& castig : istoricCastiguri) {
            suma += castig;
        }
        castigMediu = suma / istoricCastiguri.size();
    }

    T obtineCastigMaxim() const {
        return castigMaxim;
    }

    T obtineCastigMediu() const {
        return castigMediu;
    }

    void afiseazaStatistici() const {
        std::cout << "\nStatistici pentru " << numeJucator << ":\n";
        std::cout << "Castig maxim: " << castigMaxim << "\n";
        std::cout << "Castig mediu: " << castigMediu << "\n";
        std::cout << "Istoric castiguri: ";
        for (const auto& castig : istoricCastiguri) {
            std::cout << castig << " ";
        }
        std::cout << "\n";
    }
};

#endif // STATISTICI_H
