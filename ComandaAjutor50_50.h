#ifndef COMANDA_AJUTOR50_50_H
#define COMANDA_AJUTOR50_50_H

#include "Ajutor50_50.h"
#include "Intrebare.h"
#include "Comanda.h"

class ComandaAjutor50_50 : public Comanda {
private:
    Ajutor50_50* ajutor;
    Intrebare& intrebare;

public:
    ComandaAjutor50_50(Intrebare& intrebare) : intrebare(intrebare) {
        ajutor = new Ajutor50_50();
    }

    void execute() override {
        ajutor->aplicaAjutor(intrebare);
    }

    ~ComandaAjutor50_50() {
        delete ajutor;
    }
};

#endif // COMANDA_AJUTOR50_50_H
