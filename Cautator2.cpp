#include "Cautator2.h"
#include "Cautator.h"
#include <cstring>
#include <stdlib.h>

using namespace std;

Cautator2::Cautator2():Cautator()
{
}
char Cautator2::obtinculoare()const
{
    return 'G';
}
int Cautator2::cautapoz(char **tabla,int nr)const//verific daca mai e casuta valida in Sud sau Vest
{
    if(verificpoz(linie+1,coloana,nr) && tabla[linie+1][coloana]==' ') return 1;
    if(verificpoz(linie+1,coloana,nr) && tabla[linie+1][coloana]=='C') return 1;
    if(verificpoz(linie,coloana-1,nr) && tabla[linie][coloana-1]==' ') return 1;
    if(verificpoz(linie,coloana-1,nr) && tabla[linie][coloana-1]=='C') return 1;
    return 0;
}
void Cautator2::muta(char **tabla, int nr)
{
    if (!cautapoz(tabla,nr)) return;//daca nu ma mai pot deplasa
    if (obtininfo()==1) return;//daca deja a gasit o comoara
    ///linie+1,coloana
    ///linie,coloana-1
    int x=obtinlinie();//obtin linia
    int y=obtincoloana();//obtin coloana
    char z=obtinculoare();//obtin culoarea
    if(verificpoz(x+1,y,nr) && tabla[x+1][y]=='C')//verific daca ma pot deplasa spre Sud si daca acolo se gasete o comoara
    {
        setezinfo(1);//marchez ca a gasit o comoara
        tabla[x+1][y]=z;//marchez cu culoarea Cautatorului1
        setezlinie(x+1);//setez linia
        return;
    }
    if(verificpoz(x,y-1,nr) && tabla[x][y-1]=='C')//verific daca ma pot deplasa spre Vest si daca acolo se gaseste o comoara
    {
        setezinfo(1);//marchez ca a gasit o comoara
        tabla[x][y-1]=z;//marchez cu culoarea Cautatorului2
        setezcoloana(y-1);//setez coloana
        return;
    }
    if(verificpoz(x+1,y,nr) && tabla[x+1][y]==' ')//verific daca ma pot deplasa spre Sud
    {
        tabla[x+1][y]=z;//marchez cu culoarea Cautatorului2
        setezlinie(x+1);//setez linia
        return;
    }
    if(verificpoz(x,y-1,nr) && tabla[x][y-1]==' ')//verific daca ma pot deplasa spre Vest
    {
        tabla[x][y-1]=z;//marchez cu culoare Cautatorului2
        setezcoloana(y-1);//setez coloana
        return;
    }
}
Cautator2::~Cautator2()
{

}

