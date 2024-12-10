#ifndef AJUTOR_H
#define AJUTOR_H

#include "Intrebare.h"

class Ajutor {
public:
    virtual void aplicaAjutor(Intrebare& intrebare) = 0;  // Funcție virtuală pură
    virtual ~Ajutor() = default;  // Destructor virtual
};

class Ajutor50_50 : public Ajutor {
public:
    void aplicaAjutor(Intrebare& intrebare) override;
};

class AjutorSunaUnPrieten : public Ajutor {
public:
    void aplicaAjutor(Intrebare& intrebare) override;
};

class AjutorIntreabaPublicul : public Ajutor {
public:
    void aplicaAjutor(Intrebare& intrebare) override;
};

#endif // AJUTOR_H
