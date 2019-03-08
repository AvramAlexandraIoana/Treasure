#include "Cautator4.h"
#include "Cautator.h"
#include <cstring>
#include <stdlib.h>

using namespace std;

Cautator4::Cautator4():Cautator()
{
}
char Cautator4::obtinculoare()const
{
    return 'V';
}
int Cautator4::cautapoz(char **tabla,int nr)const//verific daca mai e casuta valida in Nord sau Vest
{
    if(verificpoz(linie-1,coloana,nr) && tabla[linie-1][coloana]==' ') return 1;
    if(verificpoz(linie-1,coloana,nr) && tabla[linie-1][coloana]=='C') return 1;
    if(verificpoz(linie,coloana-1,nr) && tabla[linie][coloana-1]==' ') return 1;
    if(verificpoz(linie,coloana-1,nr) && tabla[linie][coloana-1]=='C') return 1;
    return 0;
}
void Cautator4::muta(char **tabla, int nr)
{
    if (!cautapoz(tabla,nr)) return;//daca nu ma mai pot deplasa
    if (obtininfo()==1) return;//daca deja a gasit o comoara
    ///linie-1,coloana
    ///linie,coloana-1
    int x=obtinlinie();//obtin linia
    int y=obtincoloana();//obtin coloana
    char z=obtinculoare();//obtin culoarea
    if(verificpoz(x-1,y,nr) && tabla[x-1][y]=='C')//verific daca ma pot deplasa spre Nord si daca acolo se gasete o comoara
    {
        setezinfo(1);//marchez ca a gasit o comoara
        tabla[x-1][y]=z;//marchez cu culoarea Cautatorului4
        setezlinie(x-1);//setez linia
        return;
    }
    if(verificpoz(x,y-1,nr) && tabla[x][y-1]=='C')//verific daca ma pot deplasa spre Vest si daca acolo se gasete o comoara
    {
        setezinfo(1);//marchez ca a gasit o comoara
        tabla[x][y-1]=z;//marchez cu culoarea Cautatorului4
        setezcoloana(y-1);//setez coloana
        return;
    }
    if(verificpoz(x-1,y,nr) && tabla[x-1][y]==' ')//verific daca mai pot deplasa spre Nord
    {
        tabla[x-1][y]=z;//marchez cu culoarea Cautatorului4
        setezlinie(x-1);//setez linia
        return;
    }
    if(verificpoz(x,y-1,nr) && tabla[x][y-1]==' ')//verific daca ma pot deplasa spre Vest
    {
        tabla[x][y-1]=z;//marchez cu culoarea Cautatorului4
        setezcoloana(y-1);//setez coloana
        return;
    }
}
Cautator4::~Cautator4()
{
}

