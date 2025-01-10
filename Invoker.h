#ifndef INVOKER_H
#define INVOKER_H

#include "Comanda.h"
#include <vector>

class Invoker {
private:
    std::vector<Comanda*> comenzi;

public:
    void adaugaComanda(Comanda* comanda) {
        comenzi.push_back(comanda);
    }

    void executaComenzi() {
        for (auto& comanda : comenzi) {
            comanda->execute();
        }
    }

    ~Invoker() {
        for (auto& comanda : comenzi) {
            delete comanda;
        }
    }
};

#endif // INVOKER_H
