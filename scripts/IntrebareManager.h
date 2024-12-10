#ifndef INTREBARE_MANAGER_H
#define INTREBARE_MANAGER_H

#include "Intrebare.h"
#include <vector>

class IntrebareManager {
private:
    std::vector<Intrebare> intrebari;

public:
    IntrebareManager();
    Intrebare obtineIntrebare(int index);
    static void afiseazaToateIntrebarile(const std::vector<Intrebare>& intrebari);
};

#endif // INTREBARE_MANAGER_H
