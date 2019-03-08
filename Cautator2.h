#ifndef CAUTATOR2_H
#define CAUTATOR2_H

#include "Cautator.h"

class Cautator2:public Cautator
{
public:
    Cautator2();
    void muta(char **,int);
    int cautapoz(char **,int)const;
    char obtinculoare()const;
    ~Cautator2();
    friend class Tabla;
protected:
private:
};

#endif // CAUTATOR2_H
