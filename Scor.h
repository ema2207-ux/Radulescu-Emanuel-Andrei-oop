#ifndef SCOR_H
#define SCOR_H

#include <vector>

class Scor {
private:
    int punctaj;
    std::vector<int> premii;

public:
    static int numarJocuri;

    Scor();
    int obtinePremiu() const;
    void adaugaPuncte();
    static void afiseazaNumarJocuri();
    void afiseazaScorFinal() const;
};

#endif // SCOR_H
