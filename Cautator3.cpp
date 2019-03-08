#include "Cautator3.h"
#include "Cautator.h"
#include <cstring>
#include <stdlib.h>

using namespace std;

Cautator3::Cautator3():Cautator()
{
}
char Cautator3::obtinculoare()const
{
    return 'A';
}
int Cautator3::cautapoz(char **tabla,int nr)const//verific daca mai e casuta valida in Nord sau Est
{
    if(verificpoz(linie-1,coloana,nr) && tabla[linie-1][coloana]==' ') return 1;
    if(verificpoz(linie-1,coloana,nr) && tabla[linie-1][coloana]=='C') return 1;
    if(verificpoz(linie,coloana+1,nr) && tabla[linie][coloana+1]==' ') return 1;
    if(verificpoz(linie,coloana+1,nr) && tabla[linie][coloana+1]=='C') return 1;
    return 0;
}
void Cautator3::muta(char **tabla, int nr)
{
    if (!cautapoz(tabla,nr)) return;//daca nu ma mai pot deplasa
    if (obtininfo()==1) return;//daca deja a gasit o comoara
    ///linie-1,coloana
    ///linie,coloana+1
    int x=obtinlinie();
    int y=obtincoloana();
    char z=obtinculoare();
    if(verificpoz(x-1,y,nr) && tabla[x-1][y]=='C')//verific daca ma pot deplasa spre Nord si daca acolo se gasete o comoara
    {
        setezinfo(1);//marchez ca a gasit o comoara
        tabla[x-1][y]=z;//marchez cu culoarea Cautatorului3
        setezlinie(x-1);//setez linia
        return;
    }
    if(verificpoz(x,y+1,nr) && tabla[x][y+1]=='C')//verific daca ma pot deplasa spre Est si daca acolo se gaseste o comoara
    {
        setezinfo(1);//marchez ca a gasit o comoara
        tabla[x][y+1]=z;//marchez cu culoarea Cautatorului3
        setezcoloana(y+1);//setez coloana
        return;
    }
    if(verificpoz(x-1,y,nr) && tabla[x-1][y]==' ')//verific daca ma pot deplasa spre Nord
    {
        tabla[x-1][y]=z;//marchez cu culoarea Cautatorului3
        setezlinie(x-1);//setez linia
        return;
    }
    if(verificpoz(x,y+1,nr) && tabla[x][y+1]==' ')//verific daca ma pot deplasa spre Est
    {
        tabla[x][y+1]=z;//marchez cu culoarea Cautatorului3
        setezcoloana(y+1);//setez coloana
        return;
    }
}
Cautator3::~Cautator3()
{

}
