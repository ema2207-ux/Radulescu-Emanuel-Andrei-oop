#ifndef COMANDA_H
#define COMANDA_H

class Comanda {
public:
    virtual void execute() = 0;  // Funcția virtuală pură pentru executarea comenzii
    virtual ~Comanda() = default;
};

#endif // COMANDA_H
