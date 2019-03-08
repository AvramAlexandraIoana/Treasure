#ifndef CAUTATOR_H
#define CAUTATOR_H


class Cautator
{
protected:
    int linie;
    int coloana;
    char culoare;
    int informatie;
public:
    Cautator();
    void initializare(int i,int j);
    int obtinlinie()const;
    int obtincoloana()const;
    int obtininfo()const;
    int verificpoz(int,int,int)const;
    void setezlinie(int);
    void setezcoloana(int);
    void setezinfo(int);
    virtual char obtinculoare()const=0;
    virtual int cautapoz(char **,int)const=0;
    virtual void muta(char **,int)=0;
    virtual ~Cautator();
    friend class Tabla;
protected:
private:
};

#endif // CAUTATOR_H
