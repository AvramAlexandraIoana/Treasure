#ifndef TABLA_H
#define TABLA_H

#include "Cautator.h"

#include <iostream>

using namespace std;
class Tabla
{
    char **matrice;
    int dim;
    int castigator;
    Cautator **v;
public:
    Tabla(int);
    void marcarecomori();
    void marcarecautatori();
    int deplasare()const;
    int comorigasite()const;
    int joccontinuat()const;
    void runda();
    void meniu();
    friend ostream &operator<<(ostream &,Tabla &);
    virtual ~Tabla();
protected:
private:
};

#endif // TABLA_H
