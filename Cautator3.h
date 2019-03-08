#ifndef CAUTATOR3_H
#define CAUTATOR3_H
#include "Cautator.h"

class Cautator3:public Cautator
{
public:
    Cautator3();
    void muta(char **,int);
    int cautapoz(char **,int)const;
    char obtinculoare()const;
    ~Cautator3();
    friend class Tabla;
protected:
private:
};

#endif // CAUTATOR3_H
