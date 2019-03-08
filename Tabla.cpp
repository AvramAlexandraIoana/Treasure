#include "Tabla.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "Cautator1.h"
#include "Cautator2.h"
#include "Cautator3.h"
#include "Cautator4.h"

using namespace std;

Tabla::Tabla(int m)
{
    castigator=0;//initializez pe castigator cu 0
    dim=m;//initializez pe dim cu m
    matrice=(char**)malloc(dim*sizeof(char*));//aloc memorie pentru matrice
    for(int i=0; i<dim; i++)
    {
        matrice[i]=(char*)malloc(dim*sizeof(char));
        for(int j=0; j<dim; j++)
            matrice[i][j]=' ';
    }
    v=(Cautator**)malloc(4*sizeof(Cautator*));//aloc memorie pentru vectorul de pointeri de tip Cautator
    for(int i=0; i<4; i++)
        v[i]=(Cautator*)malloc(sizeof(Cautator));
    v[0]=new Cautator1();
    v[1]=new Cautator2();
    v[2]=new Cautator3();
    v[3]=new Cautator4();
}
void Tabla::marcarecomori()//marchez comorile in matrice
{
    int x,y;
    do//gasesc 2 coordonate diferite decat coordonatele din colturile matricii
    {
        x = rand()%dim;
        y = rand()%dim;
    }
    while(matrice[x][y]!=' ');
    matrice[x][y]='C';//marchez ca e comoara

    do//gasesc 2 coordonate diferite decat coordonatele din colturile matricii
    {
        x = rand()%dim;
        y = rand()%dim;
    }
    while(matrice[x][y]!=' ');
    matrice[x][y]='C';//marchez ca e comoara

    do//gasesc 2 coordonate diferite decat coordonatele din colturile matricii
    {
        x = rand()%dim;
        y = rand()%dim;
    }
    while(matrice[x][y]!=' ');
    matrice[x][y]='C';//marchez ca e comoara

}
void Tabla::marcarecautatori()
{
    //initializez cei 4 cautatori
    v[0]->initializare(0,0);
    v[1]->initializare(0,dim-1);
    v[2]->initializare(dim-1,0);
    v[3]->initializare(dim-1,dim-1);
    for(int i=0; i<4; i++)
    {
        int x=v[i]->obtinlinie();
        int y=v[i]->obtincoloana();
        char z=v[i]->obtinculoare();
        matrice[x][y]=z;// marchez in matrice coodonatele cautatorilor cu culoarea acestora
    }
}
int Tabla::comorigasite()const//determin cate comori au fost gasite
{
    int s=0;
    for(int i=0; i<4; i++)
        s=s+v[i]->obtininfo();
    return s;
}
int Tabla::deplasare()const//verific daca cel putin un cautator mai are o deplasare valida
{
    int ok=0;
    for(int i=0; i<4; i++)
        if(v[i]->cautapoz(matrice,dim))
        {
            ok=1;
            break;
        }
    return ok;
}
int Tabla::joccontinuat()const//verific daca jocul mai poate continua sau nu
{
    int x=comorigasite();
    int y=deplasare();
    if(x==3 || y==0) return 0;
    return 1;
}
void Tabla::runda()//simulez o runda
{
    for(int i=0; i<4; i++)
    {
        v[i]->muta(matrice,dim);//mut fiecare cautator intr-o casuta valida daca se poate
        if(castigator==0 && v[i]->obtininfo()==1)castigator=i+1;//verific daca avem un castigator si ii salvez ce cautator e
    }
}
void Tabla::meniu()//efectuez un meniu
{
    int optiune=0;
    do
    {
        cout<<"====================================" <<'\n';
        cout<<"Meniu:"<<'\n';
        cout<<"1:Inchide joc"<<'\n';
        cout<<"2:Simuleaza o runda"<<'\n';
        cout<<"3:Simuleaza pana la final"<<'\n';
        cout<<"4:Afiseaza harta"<<'\n';
        cout<<"5:Afiseaza castigator"<<'\n';
        cout<<"6:Afiseaza pentru fiecare cautator daca a gasit sau nu comoara"<<'\n';
        cout<<"Introduceti optiunea dorita"<<'\n';
        cin>>optiune;
        cout<<'\n'<<'\n';
        if(optiune==1)cout<<"Joc terminat!"<<'\n';
        else if(optiune==2) runda();
        else if(optiune==3)
        {
            while(joccontinuat())
                runda();

        }
        else if(optiune==4)cout<<(*this)<<'\n';
        else if(optiune==5)
        {
            if(castigator==0) cout<<"Niciun cautator nu a ajuns la vreo comoara!"<<'\n';
            else cout<<"A castigat cautatorul numarul"<<" "<<castigator<<"!"<<'\n';
        }
        else if(optiune==6)
        {
            for(int i=0; i<4; i++)
                cout<<v[i]->obtininfo()<<" ";
            cout<<'\n';
        }
        else
            cout<<"Nu ati ales o optiune potrivita!"<<'\n';
    }
    while(optiune!=1);
}
ostream &operator<<(ostream &out,Tabla &s)//supraincarc operatorul <<
{
    for(int i=0; i<s.dim; i++)
    {
        for(int j=0; j<s.dim; j++)
            out<<s.matrice[i][j]<<" ";
        out<<'\n';
    }
    return out;
}

Tabla::~Tabla()
{
    castigator=0;
    dim=0;
    for(int i=0; i<dim; i++) //dezaloc memoria
        free(matrice[i]);
    matrice=NULL;
    for(int i=0; i<4; i++) //dezaloc memoria
        free(v[i]);
    v=NULL;
}
