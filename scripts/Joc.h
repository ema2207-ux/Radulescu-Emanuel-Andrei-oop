#ifndef JOC_H
#define JOC_H

#include "IntrebareManager.h"
#include "Scor.h"
#include "Ajutor.h"
#include "Statistici.h"
#include <string>

class Joc {
private:
    std::string numeJucator;
    IntrebareManager intrebareManager;
    Scor scor;
    bool abandonat;
    Ajutor* ajutor;
    Statistici<int> statisticiCastiguri;
    Statistici<double> statisticiRataSucces;

public:
    Joc(const std::string& nume);
    void afiseazaAjutor50_50(Intrebare& intrebare);
    void afiseazaAjutorSunaUnPrieten(Intrebare& intrebare);
    void afiseazaAjutorIntreabaPublicul(Intrebare& intrebare);
    void ruleaza();
};

#endif // JOC_H
