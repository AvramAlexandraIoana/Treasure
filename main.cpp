#include <iostream>
#include "Tabla.h"


using namespace std;
int main()
{

    int n;
    cout<<"INTRODUCETI DIMENSIUNEA MATRICII"<<'\n';
    cin>>n;
    Tabla o1(n);
    o1.marcarecautatori();
    o1.marcarecomori();
    o1.meniu();

    return 0;
}
