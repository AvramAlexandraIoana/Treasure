#include "Cautator.h"
#include <iostream>
#include <cstring>

using namespace std;

Cautator::Cautator()
{
    informatie=0;
    culoare=NULL;
    linie=0;
    coloana=0;
}

int Cautator::obtinlinie()const//returnez linia curenta a cautatorului
    return linie;
}
int Cautator::obtincoloana()const//returnez coloana curenta a cautatorului
{
    return coloana;
}
int Cautator::obtininfo()const//returnez informatia cautatorului(1 daca a gasit comoara,0 altfel)
{
    return informatie;
}
void Cautator::setezlinie(int val)//setez linia
{
    linie=val;
}
void Cautator::setezcoloana(int val)//setez coloana
{
    coloana=val;
}
void Cautator::setezinfo(int x)//setez informatia
{
    informatie=x;
}
void Cautator::initializare(int i,int j)//initializez linia si coloana pentru fiecare cautator
{
    setezlinie(i);
    setezcoloana(j);
}
int Cautator::verificpoz(int i,int j,int nr)const//verific daca pozitia e valida
{
    if(i>=0 && i<nr && j>=0 && j<nr) return 1;
    return 0;
}
Cautator::~Cautator()
{
    informatie=0;
    linie=0;
    coloana=0;
    culoare=NULL;
}
