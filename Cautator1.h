#ifndef CAUTATOR1_H
#define CAUTATOR1_H

#include "Cautator.h"

class Cautator1:public Cautator
{
public:
    Cautator1();
    void muta(char **,int);
    int cautapoz(char **,int nr)const;
    char obtinculoare()const;
    ~Cautator1();
    friend class Tabla;
protected:
private:
};

#endif // CAUTATOR1_H
