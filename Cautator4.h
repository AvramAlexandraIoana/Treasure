#ifndef CAUTATOR4_H
#define CAUTATOR4_H
#include "Cautator.h"

class Cautator4:public Cautator
{
public:
    Cautator4();
    void muta(char **,int);
    int cautapoz(char **,int)const;
    char obtinculoare()const;
    ~Cautator4();
    friend class Tabla;
protected:
private:
};

#endif // CAUTATOR4_H
